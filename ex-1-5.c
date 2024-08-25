#include <stdio.h>

int main()
{
	float fahr;

	printf("Farenheit\tCelsius\n");
	for (fahr = 300.0; fahr >= 0.0; fahr = fahr - 20)
		printf("%3.0f\t\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	return 0;
}
