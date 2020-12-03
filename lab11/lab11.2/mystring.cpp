#define  _CRT_SECURE_NO_WARNINGS
#define N 6

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#include "Header.h"

Book* allocateA(int n)
{
    Book* a = (Book*)malloc(n * sizeof(Book));
    return a;
}

Book input(FILE* file)
{
    Book book;
    fgets(book.Name, len, file);
    fgets(book.Author, len, file);
    fscanf_s(file, "%i", &book.PageCount);
    fscanf_s(file, "%i", &book.Rank);
    fgetc(file);
    return book;
}

void output(Book* book)
{
    printf("Name: %s", book->Name);
    printf("Author: %s", book->Author);
    printf("PageCount: %d\n", book->PageCount);
    printf("Rank: %d\n", book->Rank);
    printf("\n");
}

void AddBook(FILE* file)
{
    char a[len];
    int m ;
    printf("Введите название: ");
    getchar();
    fgets(a, len, stdin);
    fprintf(file, "\n%s", a);
    printf("Введите автора: ");
    getchar();
    fgets(a, len, stdin);
    fprintf(file, "%s", a);
    printf("Введите кол-во стр: ");
    scanf_s("%d", &m);
    fprintf(file, "%d", m);
    printf("Введите рейтинг: ");
    scanf_s("%d", &m);
    fprintf(file, "\n%d", m);
}

void sortByRank(Book* array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i].Rank < array[j].Rank)
                swap(&array[i], &array[j]);
        }
    }
}

void swap(Book* a, Book* b)
{
    Book temp = *a;
    *a = *b;
    *b = temp;
}

Book* creatureArray(FILE* file)
{
    Book * a = allocateA(N);
    for (int i = 0; i < N; i++)
        a[i] = input(file);
    return a;
}

void deleteBook(Book* array, char* strName)
{
    for (int i = 0; i < N; i++)
    {
        if (strcmp(array[i].Name, strName) == 0)
            for (int j = i; j < N; j++)
                array[j] = array[j + 1];
    }
}
