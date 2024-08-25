#include <stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(int argc, char **argv)
{
	int v[5] = { 10, 1, 4, 5, 6 };
	int pos;

	pos = binsearch(5, v, 5);
	if (pos < 0)
		printf("not found\n");
	else
		printf("found at %d\n", pos);
	return 0;
}
