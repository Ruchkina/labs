#include <iostream>
//#define quantity2 = 6
int foundSumm(float[6], float, float, float, int, float);

void main()
{
	int quantity2 = 6;
	float line[6];
	printf("Enter elements");
	scanf_s("%f", &line[0]);
	float maximElement = line[0];
	float minimElement = line[0];
	int indexMaximElement = -1;
	float summa = 0;


	for (int i = 1; i < quantity2; i++)
	{
		scanf_s("%f", &line[i]);
		if (line[i] > maximElement)
		{
			indexMaximElement = i;
			maximElement = line[i];
		}
		if (line[i] <= minimElement)
		{
			minimElement = line[i];
		}
	}
	summa = foundSumm(line, maximElement, minimElement, summa, indexMaximElement, quantity2);
	printf("Summa = %f", summa);
}
int  foundSumm(float line[6], float maxim, float minim, float sum, int index, float quantity2)
{
	for (int i = index + 1; i < quantity2; i++)
		if (line[i] > (maxim + minim) / 2)
			sum = sum + line[i];
	return sum;
}
