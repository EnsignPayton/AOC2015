#include <stdio.h>
#include <stdlib.h>
#include "shared.h"

int solve1(char* input) {
	int floor = 0;
	int i = 0;
	char c;
	while ((c = input[i]) != '\0') {
		if (c == '(') {
			floor++;
		} else if (c == ')') {
			floor--;
		}
		i++;
	}
	return floor;
}

int solve2(char* input) {
	int floor = 0;
	int i = 0;
	char c;
	while ((c = input[i]) != '\0') {
		if (c == '(') {
			floor++;
		} else if (c == ')') {
			floor--;
		}
		i++;
		if (floor== -1) {
			return i;
		}
	}
	return -1;
}

void print1(char* input) {
	printf("%d %s\n", solve1(input), input);
}

void print2(char* input) {
	printf("%d %s\n", solve2(input), input);
}

int main(void) {
	// Test Cases
	print1("(())");
	print1("()()");
	print1("(((");
	print1("(()(()(");
	print1("))(((((");
	print1("())");
	print1("))(");
	print1(")))");
	print1(")())())");
	print2(")");
	print2("()())");

	// Real Input
	char* buf = get_input();

	if (buf != NULL) {
		printf("Part 1: %d\n", solve1(buf));
		printf("Part 2: %d\n", solve2(buf));
		free(buf);
	}

	return 0;
}
