#include <stdio.h>

#define MAXLINE 100

int get_line(char line[], int maxlen)
{
	int c, i;

	for (i = 0; i < maxlen && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;

	if (c == 'n') {
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}

int main()
{
	int len, i;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0)
		printf("%d %s", len, line);
	return 0;
}
