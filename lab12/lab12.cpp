#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include<string.h>
#include <locale.h>
#include <io.h>
#include "Header.h"

#define INPUT_FILE "C:/университет/лабы/books_lab12.txt"

int main()
{
	setlocale(LC_ALL, "Rus");
	int number;
	FILE* f;

	printf("1 - Добавить книгу\n2 - Вывести файл\n3 - Сортировать\n4 - Удалить\n\n");	
	
	printf("Введите номер операции: ");
	scanf_s("%d", &number);
	switch (number)
	{
	case 1:
		f = fopen(INPUT_FILE, "ab");
		
		fseek(f, 0, SEEK_END);
		AddBook(f);
		
		fclose(f);
		break;
	case 2:
		f = fopen(INPUT_FILE, "rb");
		for (int i = 0; i < getRecordCount(f); i++)
		{
			Book A = readBook(f, i);
			output(&A);
		}
		fclose(f);
		break;
	case 3:
		int selectingSort;
		f = fopen(INPUT_FILE, "rb+");
		printf("Choose sorting: 1/2\n 1 - по имени\n 2 - по рангу\n");
		scanf_s("%d", &selectingSort);
		
		if (selectingSort == 1)
			SortByName(f);
		if (selectingSort == 2)
			SortByRang(f);
		
		for (int i = 0; i < getRecordCount(f); i++)
		{
			Book A = readBook(f, i);
			output(&A);
		}

		fclose(f); 
		break;

	case 4:
		f = fopen(INPUT_FILE, "rb+");
		rewind(f);
		
		int CUR = 0;
		int P1 = 0;
		int sizeOneBook = sizeof(Book);
		char deletedBook[len];
		Book B;
		Book C;
		int countDeleteWords = 0;
		int n = getRecordCount(f);
		
		printf("Введите название удаляемой книги: ");
		getchar();
		gets_s(deletedBook, len);
		
		for (int y = 0; y < n; y++)
		{
			B = readFromPosition(f, sizeOneBook, CUR);
			if (strcmp(B.Author, deletedBook) == 0)
			{
				CUR++;
				countDeleteWords++;
			
			}
			B = readFromPosition(f, sizeOneBook, CUR);
			writeFromPosition(f, sizeOneBook, P1, B);
			
			P1++;
			CUR++;
			fseek(f, CUR * sizeOneBook, SEEK_SET);
		}
		fseek(f, -(countDeleteWords * sizeOneBook), SEEK_END);
		int fd = _fileno(f);
		_chsize(fd, (n - countDeleteWords) * sizeOneBook);
		
		fclose(f);
		break;
	
	}
}
					
