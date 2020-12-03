#ifndef MYSTRING_H
#define MYSTRING_H

const int len = 255;
struct Book 
{ 
	char Name[len]; 
	char Author[len]; 
	int PageCount; 
	int Rank; 
};

Book* allocateA(int n);
Book input(FILE* file);
void output(Book* book);
void AddBook(FILE* file);
void sortByRank(Book* array, int n);
void swap(Book* a, Book* b);
Book* creatureArray(FILE* file);
void deleteBook(Book* array, char* strName);


#endif
