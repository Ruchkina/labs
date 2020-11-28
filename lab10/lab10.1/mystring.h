#ifndef MYSTRING_H
#define MYSTRING_H

#define NAME_LEN 128

typedef struct STUDENT {
    char name[NAME_LEN];
    int marks[5];
} student;

STUDENT input();
STUDENT* allocateA(int n);
STUDENT print(STUDENT students);

#endif
