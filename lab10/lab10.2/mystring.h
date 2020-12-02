#ifndef MYSTRING_H
#define MYSTRING_H

#define NAME_LEN 128

typedef struct STUDENT {
    char name[NAME_LEN];
    int marks[5];
    float arithmeticMean;
    int countOf2;
} student;

STUDENT input();
STUDENT* allocateA(int n);
void output(STUDENT* students);
float calculationOfArithmeticMean(STUDENT* student);
int calculationMarks2(STUDENT* student);
int deleteDvoeshnik(STUDENT* array, int n);
int countOfDvoeshniks(STUDENT* array, int n);

#endif

