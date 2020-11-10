#define N 30
#define LENGHT_STR 100
#define SUF 10

#include <malloc.h>
#include <stdio.h>

void deleteGap(char* string, char* strResult, int t)
{
	for (int i = 0; i < N; i++)
	{
		strResult[t] = string[i];
		if (string[i] == ' ')
		{
			while (string[i + 1] == ' ')
				i++;
		}
		t++;
	}
}

char** allocateMatrix(int column)
{       
	char** a = (char**)malloc(column * sizeof(char*));
	for (int i = 0; i < column; i++)
		a[i] = (char*)calloc(LENGHT_STR, sizeof(char));
	return a;
}

void inputArray(char** array, int column)
{
	for (int i = 0; i < column; i++)
	{
		printf("Input %d FIO: ", i);
		fgets(array[i], LENGHT_STR, stdin);
	}
}

void inputSuf(char* array)
{
	printf("Input suf: ");
	fgets(array, SUF, stdin);
}

int stringLenght(char* str)
{
	int len;
	for (len = 0; str[len]; len++);
	return (len - 1);
}

void changeBiggerForSmaller(int lenght1, int lenght2, char** array, int size, char* suffix, int indexOfSpace, int i)
{
	int l = 0;
	for (int k = lenght1; k > 0; k--)
	{
		if (l < lenght2)
		{
			array[i][indexOfSpace - k] = suffix[l];
			l++;
		}
	}
	for (int r = indexOfSpace - lenght1 + lenght2; r < 100 - lenght1 + lenght2; r++)
	{
		array[i][r] = array[i][indexOfSpace];
		indexOfSpace++;
	}
}

void changeBiggerForSmaller(char** array, int column, int lenght1, int lenght2, int indexOfSpace, char* suffix)
{
	int l = 0;
	for (int r = 99; r > indexOfSpace; r--)
		array[column][r] = array[column][r - (lenght2 - lenght1)];
	for (int k = -lenght1; k < lenght2 - 1; k++)
	{
		array[column][indexOfSpace + k] = suffix[l];
		l++;
	}
}

void freeMatrix(char** array, int n)
{
	for (int i = 0; i < n; i++)
		free(array[i]);
	free(array);
}

void printArray(char** array, int n)
{
	for (int q = 0; q < n; q++)
		puts(array[q]);
}

int findLastWords(int lenght1, char** array, char* suffix1, int indexOfSpace, int i)
{
	int flag = 0;
	int q = 0;
	for (int d = lenght1; d > 0; d--)
	{
		if (array[i][indexOfSpace - d] == suffix1[q])
		{
			/*printf("array[%d][%d - %d]: %c \n", i, indexOfSpace, d, array[i][indexOfSpace - d]);
			printf("suffix1[%d] : %c\n\n", q, suffix1[q]);*/
			flag++;
		}
		q++;
	}
	return flag;
}
