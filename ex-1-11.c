#include <stdio.h>

#define IN 0
#define OUT 1

int main()
{
	int c, nl, nc, nw, state;

	state = OUT;
	nl = nc = nw = 0;
	while ((c = getchar()) != EOF) {
		nc++;
		if (c == '\n')
			nl++;

		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			nw++;
		}
	}
	printf("chars: %d\nwords: %d\nlines: %d\n", nc, nw, nl);
	return 0;
}
