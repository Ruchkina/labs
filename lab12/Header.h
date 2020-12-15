const int len = 255;
struct Book
{
	char Name[len];
	char Author[len];
	int PageCount;
	int Rank;
};

void AddBook(FILE* file);
Book readBook(FILE* file, int numberOfStruct);
void output(Book* a);
int getRecordCount(FILE* file);
void deleteBook(int* CUR, int* P1, int sizeOneBook, FILE* f);
void swap(Book* a, Book* b);
Book readFromPosition(FILE* file, int size, int placeRead);
void writeFromPosition(FILE* file, int size, int placeRead, Book book);
void SortByName(FILE* file);
void SortByRang(FILE* file);
