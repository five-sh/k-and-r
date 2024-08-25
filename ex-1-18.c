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

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		int n_trail, i;

		n_trail = 0;
		for (i = len - 1; i > 0; i--) {
			if (line[i] == ' ' || line[i] == '\t')
				n_trail++;
			else
				break;
		}
		if (n_trail == len - 1)
			continue;

		line[len - n_trail] = '\0';
		printf("%s", line);
	}
	return 0;
}
