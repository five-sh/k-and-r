#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	y = getbits(y, p, n);
	return x | y;
}

int main(int argc, char **argv)
{
	int x = 255;
	int y = 205;

	printf("%u\n", setbits(x, 3, 2, y));
	return 0;
}
