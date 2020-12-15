#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "mystring.h"


WORD* allocate(int n)
{
	WORD* a = (struct WORD*)calloc(n, sizeof(WORD));
	return a;
}

int counterWords(char* str)
{
	int flag = 0;
	int counter = 0;
	for (int p = 0; str[p] != 0; p++)
	{
		if (str[p] != ' ' && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (str[p] == ' ')
			flag = 0;
	}
	return counter;
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

void addNewWord (int* realCount, WORD* a, char* word)
{
	int flag = 0;
		for (int t = 0; t < *realCount; t++)
			if (strcmp(a[t].word, word) == 0)
			{
				flag = 1;
				a[t].counter++;
			}
		if (flag == 0)
		{
			strcpy(a[*realCount].word, word);
			a[*realCount].counter++;
			(*realCount)++;
		}
}
