#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void append_spaces(char s[], int n)
{
	int i;

	for (i = strlen(s); i < n; i++)
		s[i] = ' ';
	s[i] = '\0';
}

void itoa(int n, char s[], int width)
{
	int sign, digit, i;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	if (strlen(s) < width)
		append_spaces(s, width);
	reverse(s);
}

int main(int argc, char **argv)
{
	char s[MAXLINE];
	int n = 10;

	itoa(n, s, 16);
	printf("%s\n", s);
	return 0;
}
