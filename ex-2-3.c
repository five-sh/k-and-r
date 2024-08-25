#include <stdio.h>

int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

void s_lower(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		s[i] = lower(s[i]);
}

int htoi(char hex[])
{
	int n, i;

	n = 0;
	s_lower(hex);
	for (i = 0; hex[i] != '\0'; i++) {
		if (hex[i] == '0' && hex[i + 1] == 'x')
			i += 2;

		if (hex[i] >= '0' && hex[i] <= '9')
			n = 16 * n + (hex[i] - '0');
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			n = 16 * n + (hex[i] - 'a' + 10);
	}
	return n;
}

int main()
{
	char hex[][7] = { "0x000f", "0x000F", "0X000f", "0X000F", NULL };
	int i;

	for (i = 0; *hex[i]; i++)
		printf("%d\n", htoi(hex[i]));
	return 0;
}
