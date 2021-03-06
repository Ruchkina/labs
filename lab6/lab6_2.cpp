//вариант0
#include <iostream>
#include <stdio.h>
#include <malloc.h>

void inputArray(int**, int, int);
void printArray(int**, int, int);
void transponElements(int**, int, int, int*, int*, int*, int*);
void findMaxMin(int**, int, int, int*, int*, int*, int*);
void freeMatrix(int**, int);
int** allocateMatrix(int row, int column);

int main()
{
    int n, m;
    int indexIMax; //индекс i максимального эл
    int indexJMax; //индекс j минимального эл
    int indexIMin; //индекс i максимального эл
    int indexJMin; //индекс j минимального эл
    printf("Input dimention matrix (row/col): ");
    scanf_s("%d/%d", &m, &n);
    int** a = allocateMatrix(m, n);
    inputArray(a, m, n);
    printArray(a, m, n);
    if (n >= m) {
        findMaxMin(a, m, 0, &indexIMax, &indexJMax, &indexIMin, &indexJMin);
        transponElements(a, m, 0, &indexIMax, &indexJMax, &indexIMin, &indexJMin);
    }
    else if (m > n) {
        findMaxMin(a, n, m - n, &indexIMax, &indexJMax, &indexIMin, &indexJMin);
        transponElements(a, n, m - n, &indexIMax, &indexJMax, &indexIMin, &indexJMin);
    }
    printArray(a, m, n);
    freeMatrix(a, m);
}

void inputArray(int** array, int row, int column)
{
    printf("Enter elements:\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            scanf_s("%d", &array[i][j]);
}

void printArray(int** array, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%d  ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

void findMaxMin(int** array, int size, int numderRowStart, int* iMax, int* jMax, int* iMin, int* jMin)
{
    *iMax = numderRowStart;
    *jMax = 0;
    *iMin = numderRowStart;
    *jMin = 0;
    for (int i = numderRowStart; i < size + numderRowStart; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (array[i][j] > array[*iMax][*jMax])
            {
                *iMax = i;
                *jMax = j;
            }
            if (array[i][j] < array[*iMin][*jMin])
            {
                *iMin = i;
                *jMin = j;
            }
        }
    }
}

void transponElements(int** array, int size, int numderRowStart, int* iMax, int* jMax, int* iMin, int* jMin)
{
    int tmpMax = array[*iMax][*jMax];
    array[*iMax][*jMax] = array[size - *jMax - 1 + numderRowStart][size - *iMax - 1 + numderRowStart];
    array[size - *jMax - 1 + numderRowStart][size - *iMax - 1 + numderRowStart] = tmpMax;

    int tmpMin = array[*iMin][*jMin];
    array[*iMin][*jMin] = array[size - *jMin - 1 + numderRowStart][size - *iMin - 1 + numderRowStart];
    array[size - *jMin - 1 + numderRowStart][size - *iMin - 1 + numderRowStart] = tmpMin;
}

void freeMatrix(int** array, int n)
{
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
}


int** allocateMatrix(int row, int column)
{
    int** a = (int**)malloc(row * sizeof(int*));
    for (int c = 0; c < row; c++)
        a[c] = (int*)malloc(column * sizeof(int));
    return a;
}
