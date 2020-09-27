#include <iostream>
#include <stdio.h>
#include <math.h>

// 3 лабораторная часть 1
float f(float, float);

int main()
{
	float accuracy;
	float lastNumber;
	printf("Enter accuracy: ");
	scanf_s("%f", &accuracy);
	float n = 1;
	float currentNumber = f(n, 1);
	float summa = currentNumber;
	n = 2;
	do
	{
		lastNumber = currentNumber;
		currentNumber = f(n, lastNumber);
		summa += currentNumber;
		n = n + 1;
	} while (currentNumber > accuracy);
	printf("Answer: %f", summa);
}
float f(float n, float lastElement)
{
	return lastElement / n;
}

