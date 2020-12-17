#include <stdio.h>
#include <malloc.h>
#include <string.h>


char** allocated (int size, int n)
{
	char** strings = (char**)malloc(size * sizeof(char*));
	for (int i = 0; i < size; i++)
		strings[i] = (char*)malloc(n * sizeof(char));
	return strings;
}


void printArray(char** array, int n)
{
	for (int q = 0; q < n; q++)
		puts(array[q]);
}

int takingWord(char* str, int* i, char* word)
{
	int indexInWord = 0;
	while (str[*i] != ' ' && str[*i] != 0)
		word[indexInWord++] = str[(*i)++];
	if (str[*i] != 0)
		(*i)++;
	word[indexInWord] = '\0';
	return *i;
}

int sortingAndInput(int len, int* array, char* temporary, char* str, int numberInArrayA, int summLetters, int numberInString)
{
	while (summLetters < len)
	{
		summLetters = array[numberInArrayA] + array[numberInArrayA + 1];
		numberInArrayA++;
	}
	numberInString = numberInString + summLetters;
	int n = 0;
	for (int w = numberInString - summLetters; w < numberInString; w++)
	{
		temporary[n] = str[w];
		n++;
		temporary[n] = '\0';
	}
	printf("%s\n", temporary);
	return numberInString;
}
