#include <iostream>
#include <math.h>

float leftQuadrangleMethod(float, float, int);

int main()
{
	float lastSquare;
	float presentSquare;
	float accuracy;
	float a;
	float b;
	int n;
	n = 1;
	printf("Enter accuracy: ");
	scanf_s("%f", &accuracy);
	printf("Enter the left number: ");
	scanf_s("%f", &a);
	printf("Enter the right number: ");
	scanf_s("%f", &b);
	presentSquare = leftQuadrangleMethod(a, b, n);
	n++;
	do
	{
		lastSquare = presentSquare;
		presentSquare = leftQuadrangleMethod(a, b, n);
		n++;
	} while (abs(lastSquare - presentSquare) > accuracy);
	printf("Answer: %f", presentSquare);
}

float leftQuadrangleMethod(float a, float b, int n)
{
	float summa = 0;
	float h = (b - a) / n;
	int i;
	for (i = 0; i < n; i++)
	{
		float square = h * log(a + h * i);
		//printf("log: %f\n", log(a + h * i))
		summa = summa + square;
	}
	return summa;
}
