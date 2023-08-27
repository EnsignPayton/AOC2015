#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared.h"

long long solve1(char* input) {
	long long result = 0;

	if (input == NULL) {
		fprintf(stderr, "Input string was null\n");
		return 0;
	}

	char* token = strtok(input, "\n");;
	while (token != NULL) {
		printf("Token: %s\n", token);

		int i = 0, l = 0, w = 0, h = 0;

		while (isdigit(token[i])) {
			l *= 10;
			l += (token[i] - '0');
			i++;
		}

		if (token[i] == 'x') {
		   i++;
		} else {
			fprintf(stderr, "Unexpected character: %d\n", token[i]);
			break;
		}

		while (isdigit(token[i])) {
			w *= 10;
			w += (token[i] - '0');
			i++;
		}

		if (token[i] == 'x') {
		   i++;
		} else {
			fprintf(stderr, "Unexpected character: %d\n", token[i]);
			break;
		}

		while (isdigit(token[i])) {
			h *= 10;
			h += (token[i] - '0');
			i++;
		}

		int surface_area = (2*l*w) + (2*w*h) + (2*h*l);
		int smallest_area = l*w;
		if (smallest_area > w*h) smallest_area = w*h;
		if (smallest_area > h*l) smallest_area = h*l;
		int paper_amount = surface_area + smallest_area;
		result += paper_amount;

		printf("%d + %d = %d --> %lld\n", surface_area, smallest_area, paper_amount, result);

		token = strtok(NULL, "\n");
	}

	return result;
}

long long solve2(char* input) {
	long long result = 0;

	if (input == NULL) {
		fprintf(stderr, "Input string was null\n");
		return 0;
	}

	char* token = strtok(input, "\n");;
	while (token != NULL) {
		printf("Token: %s\n", token);

		int i = 0, l = 0, w = 0, h = 0;

		while (isdigit(token[i])) {
			l *= 10;
			l += (token[i] - '0');
			i++;
		}

		if (token[i] == 'x') {
		   i++;
		} else {
			fprintf(stderr, "Unexpected character: %d\n", token[i]);
			break;
		}

		while (isdigit(token[i])) {
			w *= 10;
			w += (token[i] - '0');
			i++;
		}

		if (token[i] == 'x') {
		   i++;
		} else {
			fprintf(stderr, "Unexpected character: %d\n", token[i]);
			break;
		}

		while (isdigit(token[i])) {
			h *= 10;
			h += (token[i] - '0');
			i++;
		}

		int smallest_perimeter = (2*l) + (2*w);
		if (smallest_perimeter > (2*w) + (2*h)) smallest_perimeter = (2*w) + (2*h);
		if (smallest_perimeter > (2*h) + (2*l)) smallest_perimeter = (2*h) + (2*l);
		int volume = l*w*h;
		int ribbon_amount = smallest_perimeter + volume;
		result += ribbon_amount;

		printf("%d + %d = %d --> %lld\n", smallest_perimeter, volume, ribbon_amount, result);

		token = strtok(NULL, "\n");
	}

	return result;
}

void print1(const char* input) {
	char buf[64];
	snprintf(buf, sizeof(buf), "%s", input);
	printf("%lld\n", solve1(buf));
}

void print2(char* input) {
	char buf[64];
	snprintf(buf, sizeof(buf), "%s", input);
	printf("%lld\n", solve2(buf));
}

int main(void) {
	// Test Cases
	print1("2x3x4");
	print1("1x1x10");
	print1("2x3x4\n1x1x10");
	print2("2x3x4");
	print2("1x1x10");
	print2("2x3x4\n1x1x10");

	// Real Input
	char* buf = get_input();

	if (buf != NULL) {
		//printf("Part 1: %lld\n", solve1(buf));
		printf("Part 2: %d\n", solve2(buf));
		free(buf);
	}

	return 0;
}
