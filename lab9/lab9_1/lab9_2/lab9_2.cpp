#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "mystring.h"

void main()
{
	int size;
	int lenght;
	int i = 0;
	int w = 0;
	int numberInArrayA = 0;
	int summLetters = 0;
	int numberInString = 0;

	printf("Enter size: ");
	scanf_s("%d", &size);
	printf("Enter formattind lenght: ");
	scanf_s("%d", &lenght);
	getchar();

	char* string = (char*)malloc(size * sizeof(char));
	char* temporaryText = (char*)malloc(size * sizeof(char));
	char* temporaryWord = (char*)malloc((lenght + 1) * sizeof(char));
	int* A = (int*)calloc(size * sizeof(int), size);

	printf("Enter text: ");
	fgets(string, size, stdin);
	
	while (string[i] != 0)
	{
		takingWord(string, &i, temporaryWord);
		A[w] = strlen(temporaryWord);
		w++;
	}
	numberInString = 0;

	while (numberInString < strlen(string))
		numberInString = sortingAndInput(lenght, A, temporaryText, string, numberInArrayA, summLetters, numberInString);
	
	free(string);
	free(temporaryWord);
	free(A);
	free(temporaryText);
}

