#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "mystring.h"

#define NAME_LEN 128


STUDENT* allocateA(int n)
{
    STUDENT* a = (STUDENT*)malloc(n * sizeof(STUDENT));
    return a;
}

STUDENT input()
{
    STUDENT students;
    printf("Enter name: \n");
    getchar();
    fgets(students.name, NAME_LEN, stdin);
    printf("Enter marks: \n");
    for (int a = 0; a < 5; a++)
        scanf_s("%d", &students.marks[a]);
    return students;
}

void output(STUDENT* students)
{
    printf("\nName:  ");
    printf("%s", students->name);
    printf("Marks:  ");
    for (int a = 0; a < 5; a++)
        printf("%d; ", students->marks[a]);
    printf("\n");
    //printf("\n%d", students->status);
}

int checkStatus(STUDENT* student)
{
    int status = 5;
    for (int i = 0; i < 5; i++)
    {
        if (student->marks[i] < status)
            status = student->marks[i];
    }
    return status;
}

void swap(STUDENT* a, STUDENT* b)
{
    STUDENT temp = *a;
    *a = *b;
    *b = temp;
}

void sortByStatus(STUDENT* array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (&array[i].status < &array[j].status)
                swap(&array[i], &array[j]);
        }
    }
}

void sortByABC(STUDENT* array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((strcmp(array[i].name, array[j].name) > 0) && (array[i].status == array[j].status))
                swap(&array[i], &array[j]);
        }
    }
}


