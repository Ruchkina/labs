#include <stdio.h>
#include <malloc.h>

void inputArray(int**, int, int);
void printArray(int**, int, int);
void squareTransponMatrix(int**, int, int, int);
void freeMatrix(int**, int);
int** allocateMatrix(int row, int column);

int main()

{
    int m, n;
    printf("Input dimention matrix (row/col):");
    // m - row
    // n - column
    scanf_s("%d/%d", &m, &n);

    int** a = allocateMatrix(m, n);
    inputArray(a, m, n);
    printArray(a, m, n);
    if (m <= n)
    {
        squareTransponMatrix(a, m, 0, 0);
    }
    if (n < m)
    {
        squareTransponMatrix(a, m, m - n, 0);
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

void squareTransponMatrix(int** array, int size, int x0, int y0)
{
    int tmp;
    for (int i = x0; i < size - 1; i++)
    {
        for (int j = y0; j < size - i; j++)
        {
            tmp = array[i][j];
            array[i][j] = array[size - j - 1][size - i - 1];
            array[size - j - 1][size - i - 1] = tmp;
        }
    }
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
