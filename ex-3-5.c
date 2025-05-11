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

void itob(int n, char s[], int b)
{
	int sign, digit, i;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % b + '0';
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main(int argc, char **argv)
{
	char s[MAXLINE];
	int n = 10;

	itob(n, s, 16);
	printf("%s\n", s);
	return 0;
}
