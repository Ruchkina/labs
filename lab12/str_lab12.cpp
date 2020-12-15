
#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "Header.h"

void AddBook(FILE* file)
{
    Book A;
    printf("Введите название: ");
    getchar();
    gets_s(A.Name, len);
    printf("Введите автора: ");
    gets_s(A.Author, len);
    printf("Введите кол-во стр: ");
    scanf_s("%d", &A.PageCount);
    printf("Введите рейтинг: ");
    scanf_s("%d", &A.Rank);
    fwrite(&A, sizeof(Book), 1, file);
}

Book readBook(FILE* file, int numberOfStruct) //
{
    fseek(file, sizeof(Book) * numberOfStruct, SEEK_SET); //передвигаюсь на нужное место в файле
    Book C;
    fread(&C, sizeof(Book), 1, file);
    rewind(file);
    //output(&C);
    return C;
}

void deleteBook(int* CUR, int* P1, int sizeOneBook, FILE* f)
{
    fseek(f, *CUR * sizeOneBook, SEEK_SET);
    Book B = readBook(f, *CUR);
    fseek(f, *P1 * sizeOneBook, SEEK_SET);
    fwrite(&B, sizeOneBook, 1, f);
    P1++;
    CUR++;
}
void output(Book* a)
{
    printf("\nName:  %s", a->Name);
    printf("\nAuthor:  %s", a->Author);
    printf("\nPage:  %d ", a->PageCount);
    printf("\nRank:  %d", a->Rank);
    printf("\n");
}

int getRecordCount(FILE* file)
{
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    return size / sizeof(Book);
}

Book readFromPosition(FILE* file, int size, int placeRead)
{
    Book book;
    fseek(file, placeRead * size, SEEK_SET);
    fread(&book, size, 1, file);
    return book;
}

void writeFromPosition(FILE* file, int size, int placeRead, Book book)
{
    fseek(file, placeRead * size, SEEK_SET);
    fwrite(&book, size, 1, file);
}


void swap(Book* a, Book* b)
{
    Book temp = *a;
    *a = *b;
    *b = temp;
}

void SortByName(FILE* file)
{
    for (int i = 0; i < getRecordCount(file) - 1; i++)
    {
        Book M1;
        Book M2;
        M1 = readFromPosition(file, sizeof(Book), i);
        int NameM1Len = strlen(M1.Name);
        for (int j = i + 1; j < getRecordCount(file); j++)
        {
            M2 = readFromPosition(file, sizeof(Book), j);
            int NameM2Len = strlen(M2.Name);
            if (NameM1Len < NameM2Len)
            {
                writeFromPosition(file, sizeof(Book), i, M2);
                writeFromPosition(file, sizeof(Book), j, M1);
                swap(&M1, &M2);
            }
        }
    }
}

void SortByRang(FILE* file)
{
    for (int i = 0; i < getRecordCount(file) - 1; i++)
    {
        Book M1;
        Book M2;
        M1 = readFromPosition(file, sizeof(Book), i);
        for (int j = i + 1; j < getRecordCount(file); j++)
        {
            M2 = readFromPosition(file, sizeof(Book), j);
            if (M1.Rank < M2.Rank)
            {
                writeFromPosition(file, sizeof(Book), i, M2);
                writeFromPosition(file, sizeof(Book), j, M1);
                swap(&M1, &M2);
            }
        }
    }
}
