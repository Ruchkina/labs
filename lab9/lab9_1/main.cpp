#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#include "mystring.h"

#define SIZE_TEXT 1024

int counterWords(char* str);

int main()
{
	char text[SIZE_TEXT];
	printf("Enter text: \n");
	gets_s(text, SIZE_TEXT);
	int countWords = counterWords(text);
	struct WORD* dictionary = allocate(countWords);

	int realCount = 0;
	int i = 0; 
	char temporaryWord[20];

	while (text[i] != 0)
	{
		takingWord(text, &i, temporaryWord);
		addNewWord(&realCount, dictionary, temporaryWord);
	}
	for (int q = 0; q < realCount; q++)
		printf("%s %d\n", dictionary[q].word, dictionary[q].counter);
	free(dictionary);
}

