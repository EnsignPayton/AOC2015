#include <stdio.h>
#include <stdlib.h>

char* get_input(void) {
	FILE* pFile = fopen("input", "r");
	if (pFile == NULL) {
		fprintf(stderr, "Input file could not be opened");
		return NULL;
	}

	fseek(pFile, 0, SEEK_END);
	long size = ftell(pFile);
	rewind(pFile);

	char* buf = malloc(sizeof(char) * (size + 1));
	fgets(buf, sizeof(char) * (size + 1), pFile);
	fclose(pFile);

	return buf;
}
