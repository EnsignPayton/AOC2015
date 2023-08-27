#!/bin/sh

# Make is confusing, just bash it

mkdir -p bin
mkdir -p obj

gcc -o obj/shared.o -c shared.c
gcc -o obj/day1.o -c day1.c
gcc -o bin/day1 obj/day1.o obj/shared.o

