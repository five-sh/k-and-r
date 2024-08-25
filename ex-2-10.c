#include <stdio.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main(int argc, char **argv)
{
	int c = 'X';

	printf("%c\n", lower(c));
	return 0;
}
