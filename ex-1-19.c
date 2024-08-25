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

int slen(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return i;
}

void reverse(char s[])
{
	int len, i;
	char tmp[MAXLINE];

	len = slen(s);
	for (i = 0; i < len; i++)
		tmp[i] = s[len - 1 - i];
	copy(s, tmp);
}

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}
	return 0;
}
