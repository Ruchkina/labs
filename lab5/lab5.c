#include <stdio.h>
#include <malloc.h>

#include "f_lab5.h"

#define UP   1
#define DOWN 0


int main() {
    int n;

    printf("Size of arrsy: ");
    scanf("%d", &n);

    int* array = (int *)malloc(n * sizeof(int));
    int* array2 = (int *)malloc(n * sizeof(int));

    int j = 0;
    int indexNeg, indexZero;

    inputArray(array, n);
    outputArray(array, n);
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (array[i] > 0) array2[j++] = array[i];
    }
    indexNeg = j;
    for (int i = 0; i < n; i++) {
        if (array[i] < 0) array2[j++] = array[i];
    }
    indexZero = j;
    
    outputArray(array2, n);

    printf("Sort of positive part:\n");
    bubbleSort(&array2[0], &array2[indexNeg-1], UP);
    outputArray(array2, n);

    printf("Sort of Neg..\n");
    bubbleSort(&array2[indexNeg], &array2[indexZero-1], UP);
    outputArray(array2, n);

    free(array);
    free(array2);
}