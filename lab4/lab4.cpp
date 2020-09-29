#include <iostream>
//#define quantity2 = 6
void inputArray(float*, int);
int findSumm(float*, int, int, float);
int findMinimIndex(float*, float, int);
int findMaximIndex(float*, float, int);

void main()
{
	int quantity2 = 6;
	float line[6];
	inputArray(line, quantity2);
	float summa = findSumm(line, findMaximIndex(line, line[0], quantity2), findMinimIndex(line, line[0], quantity2), quantity2);
	printf("Summa = %f\n", summa);
}

int  findSumm(float* line, int maximIn, int minimIn, float quantity2)
{
	float sum = 0;
	for (int i = maximIn + 1; i < quantity2; i++)
		if (line[i] > (line[maximIn] + line[minimIn]) / 2)
			sum = sum + line[i];
	return sum;
}

void inputArray(float* array, int quantity)
{
	printf("Enter elements:\n");
	for (int i = 0; i < quantity; i++)
		scanf_s("%f", &array[i]);
}

int findMaximIndex(float* array, float maximElement, int quantity)
{
	int maximIndex = 0;
	for (int i = 1; i < quantity; i++)
		if (array[i] >= maximElement)
		{
			maximIndex = i;
			maximElement = array[i];
		}
	return maximIndex;
}

int findMinimIndex(float* array, float minimElement, int quantity)
{
	int minimIndex = 0;
	for (int i = 1; i < quantity; i++)
		if (array[i] <= minimElement)
		{
			minimIndex = i;
			minimElement = array[i];
		}
	return minimIndex;
}