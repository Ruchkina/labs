#include <stdio.h>

void inputArray(float*, int);
int findSumm(float*, int, int, int);
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

// Поиск суммы
// Функция приниммает:
// - указательна массив
// - значение ммаксимального элемента
// - значение минимального элемента
// - кол-во элементов массива
int findSumm(float* line, int maximIn, int minimIn, int quantity) {
	float sum = 0;
	for (int i = maximIn + 1; i < quantity; i++)
		if (line[i] > (line[maximIn] + line[minimIn]) / 2)
			sum = sum + line[i];
	return sum;
}

// Ввод массива
void inputArray(float* array, int quantity) {
	printf("Enter elements:\n");
	for (int i = 0; i < quantity; i++) {
// Вывод номера элемента    
    printf("%d: ", i + 1);
// Ввод значения элемента
		scanf("%f", &array[i]);
  }  
}

// Функция поиска индекса.
// Принимает:
// - указательна массива
// - кол-во элементов массива
// - min_max - переключатель "что ищем"
//   "1"  - ищем максимум
//   "-1" - ищем минимум
int findIndex(float* array, int quantity, int min_max) {
// Для начала искомый элемент равен первому элементу массива
	int index = 0;
  float Element = array[index];

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