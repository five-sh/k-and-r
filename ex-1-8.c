#include <stdio.h>

int main()
{
	int c, nb, nt, nl;

	nb = nt = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			nb++;
		else if (c == '\t')
			nt++;
		else if (c == '\n');
			nl++;
	}
	printf("blanks: %d\ntabs: %d\nlines: %d\n", nb, nt, nl);
	return 0;
}
