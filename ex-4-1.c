#include <stdio.h>
#include <string.h>

int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] == '\0';
	return i;
}

void reverse(char s[])
{
	int tmp, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

int strrindex(char s[], char t[])
{
	int i, j, k;

	reverse(t);
	for (i = strlen(s) - 1; i >= 0; i--) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j--, k++)
			/* nothing */;
		if (k > 0 && t[k] == '\0')
			return j + 1;
	}
	return -1;
}

int main(int argc, char **argv)
{
	char s[] = "lskdjfldksjdjflf";
	char t[] = "djfl";

	printf("%d\n", strrindex(s, t));
	return 0;
}
