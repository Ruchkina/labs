#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void deleteEmptyString(char** array, int n)           
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(array[i], "\n\0") == 0)
        {
            free(array[i]);
            array[i] = NULL;
        }
    }
}

void freeMatrix(char** array, int n)
{
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
}

char** allocatedMemory(char* str, FILE* f, int* n)
{
    char** a;
    int len_string = 0;
    while (!feof(f))
    {
        fgets(str, 500, f);
        (*n)++;
    }
    rewind(f);

    a = (char**)malloc(*n * sizeof(char*));
    for (int i = 0; i < *n; i++)
    {
        fgets(str, 500, f);
        len_string = strlen(str) + 1;
        a[i] = (char*)malloc(len_string * sizeof(char));
        strcpy(a[i], str);
    }
    return a;
}
