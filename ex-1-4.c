#include <stdio.h>

int main()
{
	float cels, fahr;
	int lower, upper, step;

	lower = 0;
	upper = 212;
	step = 20;

	printf("Fahrenheit\tCelsius\n");
	cels = lower;
	while (cels <= upper) {
		fahr = (9.0 / 5.0 * cels) + 32.0;
		printf("%3.0f\t\t%6.1f\n", fahr, cels);
		cels = cels + step;
	}
	return 0;
}
