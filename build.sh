#!/bin/sh

# Make is confusing, just bash it

mkdir -p bin
mkdir -p obj

echo "Compiling shared.c"
gcc -o obj/shared.o -c shared.c

for i in $(seq 1 30)
do
	if [ -f "day$i.c" ]; then
		echo "Compiling day$i.c"
		gcc -o "obj/day$i.o" -c "day$i.c"
		gcc -o "bin/day$i" "obj/day$i.o" "obj/shared.o"
	fi
done

echo "Done"

