#include <stdio.h>

void fahr_to_celsius(float lower, float upper, int step)
{
	float fahr;

	printf("Fahrenheit\tCelsius\n");
	for (fahr = lower; fahr <= upper; fahr = fahr + step)
		printf("%3.0f\t\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}

int main()
{
	fahr_to_celsius(0.0, 100, 20);
	return 0;
}
