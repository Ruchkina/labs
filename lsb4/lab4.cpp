#include <iostream>

int main()
{
	const int quantity = 6;
	float line[quantity];
	scanf_s("%f", &line[0]);
	float maximElement = line[0];
	float minimElement = line[0];
	int indexMaximElement = -1;
	float summa = 0;

	printf("Enter elements");
	for (int i = 1; i < quantity; i++)
	{
		scanf_s("%f", &line[i]);
		if (line[i] > maximElement)
		{
			indexMaximElement = i;
			maximElement = line[i];
		}
		if (line[i] < minimElement)
		{
			maximElement = line[i];
		}
	}
	for (int i = indexMaximElement + 1; i < quantity; i++)
	{
		if (line[i] > (maximElement + minimElement) / 2)
			summa = summa + line[i];
	}
	printf("Summa = %f", summa);
}
