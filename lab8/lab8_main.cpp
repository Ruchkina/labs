#include <stdio.h>
#include "mystring.h"
#include <malloc.h>
#include <stdlib.h>

int main()
{
	//лабораторная 8.1
	printf("lab8.1\n");
	int count = 0; 
	char str[N];
	char str_result[N];
	printf("Enter string: ");
	fgets(str, N, stdin);
	printf("\nEntered string %s", str);
	deleteSpace(str, str_result, count);
	printf("\n\nResult string: %s\n\n", str_result);

	//лабораторная 8.2
	printf("lab8.2\n");
	int n;
	char** list;
	char suf1[SUF];
	char suf2[SUF];

	inputSuf(suf1);
	inputSuf(suf2);

	int lenght1 = stringLenght(suf1);
	int lenght2 = stringLenght(suf2);

	printf("Count string:");
	scanf_s("%d", &n);
	getchar(); //fgetc(stdin);

	list = allocateMatrix(n);
	inputArray(list, n);
	printf("Entered list: \n");
	printArray(list, n);
	
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (list[i][j] != ' ' && list[i][j] != 0)
			j++;

		if (findLastWords(lenght1, list, suf1, j, i) == lenght1)
		{
			if (lenght1 > lenght2 || lenght1 == lenght2)
				changeBiggerForSmaller(lenght1, lenght2, list, n, suf2, j, i);

			else
				changeBiggerForSmaller(list, i, lenght1, lenght2, j, suf2);
		}
	}

	printf("\nModified list: \n");
	printArray(list, n);
	freeMatrix(list, n);

}


