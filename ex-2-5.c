#include <stdio.h>

int find_char(char s[], int c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == c)
			return i;
	}
	return -1;
}

int any(char s1[], char s2[])
{
	int pos, i;

	for (i = 0; s2[i] != '\0'; i++) {
		pos = find_char(s1, s2[i]);

		if (pos < 0)
			continue;
		else
			return pos;
	}
	return -1;
}

int main()
{
	char s1[] = "lsjkdfjsdkl";
	char s2[] = "j";

	printf("%d\n", any(s1, s2));
	return 0;
}
