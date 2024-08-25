#include <stdio.h>

#define MAXLINE 1000

int main()
{
	char line[MAXLINE];
	int c, i;

	for (i = 0; i < MAXLINE - 1; i++) {
		if ((c = getchar()) == EOF)
			break;
		if (c == '\n')
			break;
		line[i] = c;
	}
	printf("%s\n", line);
	return 0;
}
