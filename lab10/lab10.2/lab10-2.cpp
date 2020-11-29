#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "mystring.h"

int main()
{
    int numberOfStudent;
    scanf_s("%d", &numberOfStudent);
    //STUDENT* group = new STUDENT[numberOfStudent];
    STUDENT* group = allocateA(numberOfStudent);
    for (int i = 0; i < numberOfStudent; i++)
    {
        group[i] = input();
        group[i].arithmeticMean = calculationOfArithmeticMean(&group[i]);
        group[i].countOf2 = calculationMarks2(&group[i]);
    }
    int count2 = countOfDvoeshniks(group, numberOfStudent);
    deleteDvoeshnik(group, numberOfStudent);
    for (int i = 0; i < (numberOfStudent - count2); i++)
        output(&group[i]);
    free(group);

}
