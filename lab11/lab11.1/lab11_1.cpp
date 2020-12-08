#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

#include "mystring.h"

#define INPUT_FILE "C:/университет/лабы/lab11_1.txt"
#define OUTPUT_FILE "C:/университет/лабы/lab11_1_out.txt"

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* f;
	f = fopen(INPUT_FILE, "r");

	char string[500];
	int row = 0;

	char** file;
	file = allocatedMemory(string, f, &row);
	fclose(f);

	deleteEmptyString(file, row);

	f = fopen(OUTPUT_FILE, "w");
	int counter = 0;
	for (int i = 0; i < row; i++)
		if (file[i] != NULL)
		{
			counter++;
			fprintf(f, "%d. ", counter);
			fprintf(f, "%s", file[i]);
		}

	fclose(f);
	freeMatrix(file, row);
}

