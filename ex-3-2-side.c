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
	int i;

	for (i = 0; (to[i] = from[i]) != '\0' && i < len; i++)
		/* nothing */;
	to[i] = '\0';
}

void unescape(char s[], char t[])
{
	char tmp[MAXLINE], store[MAXLINE];
	int i;

	copy(store, t, len(t));
	for (i = 0; t[i] != '\0'; i++) {
		if (t[i] != '\\')
			continue;

		switch (t[i + 1]) {
		case 't':
			copy(tmp, t + i + 2, len(t) - i + 2);
			t[i] = '\t';
			copy(t + i + 1, tmp, len(tmp));
			break;
		case 'n':
			copy(tmp, t + i + 2, len(t) - i + 2);
			t[i] = '\n';
			copy(t + i + 1, tmp, len(tmp));
			break;
		default:
			break;
		}
	}
	copy(s, t, len(t));
	copy(t, store, len(store));
}

int main(int argc, char **argv)
{
	char t[] = "klsdjf\\nlkjdfs\\tljksdsfdjlk\\n";
	char s[MAXLINE];

	unescape(s, t);
	printf("%s\n%s\n", t, s);
	return 0;
}
