#include <stdio.h>

int bitcount(unsigned x)
{
	int b;


	for (b = 0; x != 0; x &= (x - 1)) {
		if (x & ~0x01)
			b++;
	}
	return b;
}

int main(int argc, char **argv)
{
	unsigned x = 7;

	printf("%d\n", bitcount(x));
	return 0;
}
