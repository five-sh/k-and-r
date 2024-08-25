#include <stdio.h>

#define IN	0
#define OUT	1

int main()
{
	int c, state, i, j, wc;
	int nchars[100];

	for (i = 0; i < 100; i++)
		nchars[i] = 0;

	state = OUT;
	wc = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			wc++;
		} else if (state == OUT) {
			state = IN;
		}

		if (state == IN)
			nchars[wc]++;
	}

	for (i = 0; i < wc; i++) {
		for (j = 0; j < nchars[i]; j++)
			printf("=");
		printf("\n");
	}
	return 0;
}
