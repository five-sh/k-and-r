#include <stdio.h>

#define MAXLINE 1000

int len(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		/* nothing */;
	return i;
}

void copy(char to[], char from[], int len)
{
	int i = 0;

	while ((to[i] = from[i]) != '\0' && i < len)
		 i++;
	to[i] = '\0';
}

void escape(char s[], char t[])
{
	char tmp[MAXLINE], store[MAXLINE];
	int i;

	copy(store, t, len(t));
	for (i = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
		case '\t':
			copy(tmp, t + i + 1, len(t) - i + 1);
			t[i] = '\\';
			t[++i] = 't';
			copy(t + i + 1, tmp, len(tmp));
			break;
		case '\n':
			copy(tmp, t + i + 1, len(t) - i + 1);
			t[i] = '\\';
			t[++i] = 'n';
			copy(t + i + 1, tmp, len(tmp));
			break;
		default:
			break;
		}
	}
	copy(s, t, len(store));
	copy(t, store, len(store));
}

int main()
{
	char t[] = "lksjdf\tjfddksj\nljdsfk";
	char s[MAXLINE];

	escape(s, t);
	printf("%s\n%s\n", t, s);
	return 0;
}
