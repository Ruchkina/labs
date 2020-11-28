#include "mystring.h"

#include <iostream>
#include <stdio.h>
#include <malloc.h>;p
#include <stdlib.h>
#include <string.h>

int main()
{
    int numberOfStudent;
    scanf_s("%d", &numberOfStudent);
    //STUDENT* group = new STUDENT[numberOfStudent];
    STUDENT* group = allocateA(numberOfStudent);
    for (int i = 0; i < numberOfStudent; i++)
    {
        group[i] = input();
        group[i].status = checkStatus(&group[i]);
    }
    sortByStatus(group, numberOfStudent);
    sortByABC(group, numberOfStudent);
    for (int i = 0; i < numberOfStudent; i++)
        output(&group[i]);

}
