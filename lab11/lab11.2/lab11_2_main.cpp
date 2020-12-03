#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

#include "Header.h"

#define N 6
#define INPUT_FILE "C:/университет/лабы/books_lab11.txt"

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("\n1 - Добавить в конец файла книгу\n");
	printf("2 - Вывести книги\n");
	printf("3 - Отсортировать книги\n");
	printf("4 - Удалить книгу\n");
	printf("5 - Выход\n\n");

	printf("Введите № операции: \n");
	int number;
	
	FILE* f;
	do
	{
		printf("Введите номер операции: ");
		scanf_s("%d", &number);
		if (number == 1)
		{
			f = fopen(INPUT_FILE, "a");
			fseek(f, 0, SEEK_END);
			AddBook(f);
			fclose(f);
		}
		if (number == 2)
		{
			f = fopen(INPUT_FILE, "r");
			Book* library = allocateA(N);
			for (int i = 0; i < N; i++)
			{
				library[i] = input(f);
				output(&library[i]);
			}
			free(library);
			rewind(f);
			fclose(f);
		}
		if (number == 3)
		{
			f = fopen(INPUT_FILE, "r+");
			Book* books = allocateA(N);
			for (int i = 0; i < N; i++)
				books[i] = input(f);
			sortByRank(books, N);
			rewind(f);
			for (int i = 0; i < N; i++)
			{
				output(&books[i]);
				fprintf(f, "%s%s%d\n%d\n", books[i].Name, books[i].Author, books[i].PageCount, books[i].Rank);
			}
			free(books);
			fclose(f);
		}
		if (number == 4)
		{
			f = fopen(INPUT_FILE, "r+");
			Book* books = allocateA(N);
			for (int i = 0; i < N; i++)
				books[i] = input(f);
			char deletedBook[len];
			getchar();
			printf("Введите название удаляемой книги: ");
			fgets(deletedBook, len, stdin);
			deleteBook(books, deletedBook);
			rewind(f);
			for (int i = 0; i < N; i++)
				fprintf(f, "%s%s%d\n%d\n", books[i].Name, books[i].Author, books[i].PageCount, books[i].Rank);
			free(books);
			fclose(f);
		}
	} while (number != 5);

}
