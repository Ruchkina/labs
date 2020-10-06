#include <stdio.h>
#include <stdlib.h>

void inputArray(int*, int);
void printArray(int*, int);
void inputNewArray(int*, int*, int);
void orderedSort(int*, int);
void swap(int*, int*);

int main()
{
	int sizeArray;
	printf("Input size of array: ");
	scanf_s("%d", &sizeArray);
	int* inputedArray = (int*)malloc(sizeArray * sizeof(int));
	int* sortedArray = (int*)malloc(sizeArray * sizeof(int));

	inputArray(inputedArray, sizeArray);
	printf("Array:\n");
	printArray(inputedArray, sizeArray);

	inputNewArray(inputedArray, sortedArray, sizeArray);
	orderedSort(sortedArray, sizeArray);
	printf("Result:\n");
	printArray(sortedArray, sizeArray);
	free(inputedArray);
}

void inputArray(int* array, int size)
{
	printf("Enter elements:\n");
	for (int i = 0; i < size; i++) {
		printf("%d: ", i);
		scanf_s("%d", &array[i]);
	}
}
void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
void inputNewArray(int* array, int* newArray, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > 0)
		{
			newArray[j] = array[i];
			j++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (array[i] < 0)
		{
			newArray[j] = array[i];
			j++;
		}
	}
	for (; j < size; j++)
		newArray[j] = 0;
}
void orderedSort(int* array, int size)
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1] > 0)
				swap(&array[j], &array[j + 1]);
			if (array[j] < array[j + 1] && array[j] < 0 && array[j + 1] != 0)
				swap(&array[j], &array[j + 1]);
		}
	}
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
