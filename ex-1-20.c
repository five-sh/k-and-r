#include <stdio.h>

#define MAXLINE 10000

static int get_line(char line[], int maxlen)
{
	int c, i;

	for (i = 0; i < maxlen && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}

static void copy(char to[], char from[], int len)
{
	int i = 0;

	while ((to[i] = from[i]) != '\0' && i < len)
		i++;
	to[i] = '\0';
}

static int slen(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return i;
}

static void detab(char line[], int tab_width)
{
	char tmp[MAXLINE];
	int i = 0, j;

	while (line[i] != '\0') {
		if (line[i] == '\t') {
			copy(tmp, line + i + 1, slen(line) - i - 1);
			for (j = 0; j < tab_width; j++)
				line[i + j] = ' ';
			copy(line + i + tab_width, tmp, slen(tmp));
		}
		i++;
	}
}

int main()
{
	char line[] = "ljksdf\t\t\t\tjklfds";

	detab(line, 8);
	printf("%s\n", line);
	return 0;
}
