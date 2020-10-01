#include <iostream>
#define ARRAY_SIZE 6
void inputArray(float*, int);
int findSumm(float*, float);
int findMinimIndex(float*, int);
int findMaximIndex(float*, int);

void main()
{
	float line[ARRAY_SIZE]; 
	int arraySize = 6;
	inputArray(line, ARRAY_SIZE);
	float summa = findSumm(line, arraySize);
	printf("Summa = %f\n", summa);
}

int  findSumm(float* line, float size)
{
	int maximIn = findMaximIndex(line, size);
	int minimIn = findMinimIndex(line, size);
	float sum = 0;
	for (int i = maximIn + 1; i < size; i++)
		if (line[i] > (line[maximIn] + line[minimIn]) / 2)
			sum = sum + line[i];
	return sum;
}

void inputArray(float* array, int size)
{
	printf("Enter elements:\n");
	for (int i = 0; i < size; i++)
		scanf_s("%f", &array[i]);
}

int findMaximIndex(float* array, int size)
{
	float maximElement = array[0];
	int maximIndex = 0;
	for (int i = 1; i < size; i++)
		if (array[i] >= maximElement)
		{
			maximIndex = i;
			maximElement = array[i];
		}
	return maximIndex;
}

int findMinimIndex(float* array, int size)
{
	float minimElement = array[0];
	int minimIndex = 0;
	for (int i = 1; i < size; i++)
		if (array[i] <= minimElement)
		{
			minimIndex = i;
			minimElement = array[i];
		}
	return minimIndex;
}
