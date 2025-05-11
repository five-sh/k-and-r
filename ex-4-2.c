#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
	double val, pwr, exp_val, exp_pwr;
	int i, j, sign, exp_sign;

	for (i = 0; isspace(s[i]); i++)
		/* nothing */;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;
	for (pwr = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		pwr *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E')
		i++;
	if (s[i] == '-') {
		exp_sign = -1;
		i++;
	}
	for (exp_val = 0.0; isdigit(s[i]); i++)
		exp_val = 10.0 * exp_val + (s[i] - '0');

	exp_pwr = 1.0;
	for (j = 1; j <= exp_val; j++)
		exp_pwr *= 10.0;

	return (exp_sign < 0) ? sign * val / (pwr * exp_pwr) :
				sign * (val * exp_pwr) / pwr;
}

int main(int argc, char **argv)
{
	char s[] = "123.45e-6";

	printf("%.10lf, %.10lf\n", atof(s), 123.45e-6);
	return 0;
}
