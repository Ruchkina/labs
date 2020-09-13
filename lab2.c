
#include <iostream>
#include <stdio.h>
#include <math.h> 
float calculatingValue(float);
void printMainTable(float);
void printTitleTable();
void printTailTable();
void solutionFor(int, float, float);
void solutionWhile(float, float, float);
void solutionWhileDo(float, float, float);

int main()
{
	float leftNumber, rightNumber, sizeStep;
	int quantitySteps;
	scanf_s("%f%f%d", &leftNumber, &rightNumber, &quantitySteps);
	sizeStep = (rightNumber - leftNumber) / (quantitySteps - 1);
	if (leftNumber >= 0 && rightNumber >= 0 && quantitySteps > 0)
	{
		solutionFor(quantitySteps, leftNumber, sizeStep);
		solutionWhile(leftNumber, rightNumber, sizeStep);
		solutionWhileDo(leftNumber, rightNumber, sizeStep);
	}
	else
		printf("Error");
}

float calculatingValue(float x)
{
	return tan(x) * sqrt(x);
}

void solutionFor(int countStr, float x, float step)
{
	printTitleTable();
	int i;
	for (i = 1; i <= countStr; i++)
	{
		printMainTable(x);
		x = x + step;
	}
	printTailTable();
}

void solutionWhile(float left, float right, float step)
{
	printTitleTable();
	while (left <= right)
	{
		printMainTable(left);
		left = left + step;
	}
	printTailTable();
}
void solutionWhileDo(float left, float right, float step)
{
	printTitleTable();
	do
	{
		printMainTable(left);
		left = left + step;
	} while (left <= right);
	printTailTable();
}
void printTitleTable()
{
	printf("+------------+------------+\n");
	printf("|     X      |      Y     |\n");
}
void printMainTable(float x)
{
	printf("+------------+------------+\n");
	printf("|  %7.3f   |  %7.3f   |\n", x, calculatingValue(x));
}
void printTailTable()
{
	printf("---------------------------\n");
}
