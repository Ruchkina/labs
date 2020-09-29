#include <stdio.h>

void inputArray(float*, int);
int findSumm(float*, int, int, int);
int findMinimIndex(float*, float, int);
int findMaximIndex(float*, float, int);
int findIndex(float*, int, int);

int main() {
	const int n = 6;
	float line[n];
	inputArray(line, n);
  printf("maxIndex = %d\n", findMaximIndex(line, line[0], n));
  printf("minIndex = %d\n", findMinimIndex(line, line[0], n));
  float summa = findSumm(line, findIndex(line, n, 1), findIndex(line,n, -1), n);
	printf("Summa = %f\n", summa);
}

int  findSumm(float* line, int maximIn, int minimIn, int n) {
	float sum = 0;
	for (int i = maximIn + 1; i < n; i++)
		if (line[i] > (line[maximIn] + line[minimIn]) / 2)
			sum = sum + line[i];
	return sum;
}

void inputArray(float* array, int quantity) {
	printf("Enter elements:\n");
	for (int i = 0; i < quantity; i++) {
    printf("%d: ", i + 1);
		scanf("%f", &array[i]);
  }  
}

int findIndex(float* array, int quantity, int min_max) {
	int index = 0;
  float Element = array[0];
	for (int i = 1; i < quantity; i++) {
    switch (min_max) {
      case 1:
        if (array[i] >= Element) {
          index = i;
          Element = array[i];
        }
      case -1:
        if (array[i] <= Element)	{
          index = i;
          Element = array[i];
        }
    }
  }
	return index;
}