#include <stdio.h>

#define MAXLINE		1000
#define STR_INIT	"\0"

int len(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		/* nothing */;
	return i;
}

int is_alpha(int c)
{
	return ('a' <= c && c <= 'z') ? 1 : 0;
}

int is_digit(int c)
{
	return ('0' <= c && c <= '9') ? 1 : 0;
}

void append_c(char s[], int c)
{
	s[len(s)] = c;
	s[len(s) + 1] = '\0';
}

void expand(char s1[], char s2[])
{
	int c, i = 0;

	if ((c = s2[0]) == '-') {
		append_c(s1, c);
		i++;
	}
	while (s2[i] != '\0' && i < len(s2)) {
		if (!is_alpha(s2[i]) && !is_digit(s2[i])) {
			i++;
		} else {
			while ((c = s2[i]++) <= s2[i + 2])
				append_c(s1, c);
			i += 3;
		}
	}
	if ((c = s2[len(s2) - 1]) == '-')
		append_c(s1, c);
	s1[len(s1)] = '\0';
}

int main(int argc, char **argv)
{
	char s1[MAXLINE] = STR_INIT;
	char s2[] = "a-z0-9-";

	expand(s1, s2);
	printf("%s\n", s1);
	return 0;
}
