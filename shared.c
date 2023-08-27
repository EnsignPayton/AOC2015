#include <stdio.h>
#include <stdlib.h>

char* get_input(void) {
	FILE* pFile = fopen("input", "r");
	if (pFile == NULL) {
		fprintf(stderr, "Input file could not be opened\n");
		return NULL;
	}

	fseek(pFile, 0, SEEK_END);
	long size = ftell(pFile);
	rewind(pFile);

	int len = sizeof(char) * (size + 1);
	char* buf = malloc(len);
	int n = fread(buf, 1, len - 1, pFile);
	buf[n] = '\0';
	fclose(pFile);

	return buf;
}
