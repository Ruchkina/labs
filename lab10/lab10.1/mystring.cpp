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

STUDENT print(STUDENT students)
{
    printf("Name: \n");
    printf("%s", students.name);
    printf("Marks: \n");
    for (int a = 0; a < 5; a++)
        printf("%d", students.marks[a]);
    return students;
}
