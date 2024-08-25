#include <stdio.h>

#define MAXLINE 10000

static int get_line(char line[], int maxlen)
{
	int c, i;

	for (i = 0; i < maxlen && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return i;
}

static void copy(char to[], char from[], int len)
{
	int i = 0;

	while ((to[i] = from[i]) != '\0' && i < len)
		i++;
	to[i] = '\0';
}

static int slen(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return i;
}

/*
 * Is this the correct design though?  Should we instead just see
 * tab_width of spaces and place the '\t' instead of counting the blanks
 * and then placing the '\t's.
 */
static int count_cblanks(char line[], char line_off[])
{
	int count, i;

	for (i = 0; line[i] != '\0'; i++) {
		if (line[i] == ' ')
			break;
	}

	count = 0;
	while (line[i] == ' ') {
		count++;
		i++;
	}
	copy(line_off, line + i, slen(line) - i);
	return count;
}

static void entab(char line[], int tab_width)
{
	char line_off[MAXLINE];
	int count = count_cblanks(line, line_off);
	int ntabs = count / tab_width;
	int i;

	if (!ntabs)
		return;

	for (i = 0; line[i] != ' '; i++)
		;

	// i now points at the char before the spaces occur
	while (ntabs) {
		line[i] = '\\';
		line[i + 1] = 't';
		i++;
		ntabs--;
	}
	copy(line + i + 1, line_off, slen(line_off));
}

int main()
{
	char line[] = "ljksdf                   jklfds";

	entab(line, 8);
	printf("%s\n", line);
	return 0;
}
