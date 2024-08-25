#include <stdio.h>

int main()
{
	int c, i, j;
	int freq[26];

	for (i = 0; i < 26; i++)
		freq[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			freq[c - 'a']++;
	}

	for (i = 0; i < 26; i++) {
		for (j = 0; j < freq[i]; j++)
			printf("=");
		printf("\n");
	}
}
