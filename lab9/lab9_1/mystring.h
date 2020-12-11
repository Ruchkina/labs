#define SIZE_TEXT 1000

struct WORD
{
	char word[20];
	int counter;
};

int countWords(char* s);
WORD* allocate(int n);
int takingWord(char* str, int* i, char* word);
void addNewWord(int* realCount, WORD* a, char* word);
