#ifndef MYSTRING_H
#define MYSTRING_H

#define NAME_LEN 128

typedef struct STUDENT 
{
    char name[NAME_LEN];
    int marks[5];
    int status;
} student;

STUDENT input();
STUDENT* allocateA(int n);
void output(STUDENT* students);
int checkStatus(STUDENT* student);
void swap(STUDENT* a, STUDENT* b);
void sortByStatus(STUDENT* group, int n);
void sortByABC(STUDENT* array, int n);

#endif
