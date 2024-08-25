#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
		printf("%1d", (c == EOF));
	}
	return 0;
}
