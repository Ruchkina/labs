#ifndef MYSTRING_H
#define MYSTRING_H

#define N 30
#define LENGHT_STR 100
#define SUF 10

void deleteWhiteSpace(char* string);
char* findString(char*, char*);
char* strcopy(char* destination, char* sourse);

void deleteSpace(char* string, char*, int t);
char** allocateMatrix(int column);
void inputArray(char** array, int column);
void inputSuf(char* array);
int stringLenght(char* str);
void changeBiggerForSmaller(int, int, char**, int, char*, int, int i);
void changeSmallerForBigger(char**, int, int, int, int, char*);
void freeMatrix(char** array, int n);
void printArray(char** array, int n);
int findLastWords(int lenght1, char** array, char* suffix1, int indexOfSpace, int i);
#endif
