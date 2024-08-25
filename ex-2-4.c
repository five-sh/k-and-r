#include <stdio.h>

void csqueeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void squeeze(char s1[], char s2[])
{
	int i;

	for (i = 0; s2[i] != '\0'; i++)
		csqueeze(s1, s2[i]);
}

int main()
{
	char s1[] = "ljksdfjlsdk";
	char s2[] = "jk";

	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}
