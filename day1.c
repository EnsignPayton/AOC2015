#include <stdio.h>
#include <stdlib.h>

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
	int result = solve1(input);
	printf("%d %s\n", result, input);
}

void print2(char* input) {
	int result = solve2(input);
	printf("%d %s\n", result, input);
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
	FILE* pFile = fopen("input", "r");
	if (pFile != NULL) {
		fseek(pFile, 0, SEEK_END);
		long size = ftell(pFile);
		char* buf = malloc(sizeof(char) * (size + 1));

		rewind(pFile);
		fgets(buf, sizeof(char) * (size + 1), pFile);

		int sol1 = solve1(buf);
		printf("Part 1: %d\n", sol1);

		int sol2 = solve2(buf);
		printf("Part 2: %d\n", sol2);

		free(buf);
	   	fclose(pFile);
	} else {
		fprintf(stderr, "Input file could not be opened");
	}

	return 0;
}
