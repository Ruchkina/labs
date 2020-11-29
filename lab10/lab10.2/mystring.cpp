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

void output(STUDENT* student)
{
    printf("\n\nName:  ");
    printf("%s", student->name);
    printf("Marks:  ");
    for (int a = 0; a < 5; a++)
        printf("%d; ", student->marks[a]);
    printf("\nArithmetic Means:  %f", student->arithmeticMean);
    printf("\nnumber of marks 2:  %d", student->countOf2);
    printf("\n");
}

float calculationOfArithmeticMean(STUDENT* student)
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
        sum += student->marks[i];
    printf("Sum: %f\n", sum);
    return (sum / 5.0);
}


int calculationMarks2(STUDENT* student)
{
    student->countOf2 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (student->marks[i] == 2)
            student->countOf2 = student->countOf2 + 1;
    }
    return student->countOf2;
}

int deleteDvoeshnik(STUDENT* array, int n)
{
    int countDvoeshnik = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i].countOf2 >= 2)
        {
            for (int j = i; j < n; j++)
                array[j] = array[j + 1];
        }
    }
    return countDvoeshnik;
}

int countOfDvoeshniks(STUDENT* array, int n)
{
    int countDvoeshnik = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i].countOf2 >= 2)
            countDvoeshnik++;
    }
    return countDvoeshnik;
}



