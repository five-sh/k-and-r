#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL	100
#define BUFSIZE 100
#define MAXOP	100
#define NUMBER	'0'

int sp = 0;
double val[MAXVAL];

int bufp = 0;
char buf[BUFSIZE];

void push(double f)
{
	if (sp >= MAXVAL)
		printf("error: stack full, can't push %lf\n", f);
	else
		val[sp++] = f;
}

double pop()
{
	if (sp <= 0) {
		printf("error: stack empty\n");
		return 0.0;
	} else {
		return val[--sp];
	}
}

void peek()
{
	if (sp <= 0)
		printf("error: peeking an empty stack\n");
	else
		printf("%lf\n", val[sp - 1]);
}

void dup(double v[])
{
	int n, i;

	n = sp;
	for (i = 0; n--; i++)
		v[i] = val[n];
}

void swap()
{
	int tmp;

	tmp = val[sp - 1];
	val[sp - 1] = val[sp - 2];
	val[sp - 2] = tmp;
}

void clr()
{
	int i;

	for (i = sp - 1; i >= 0; i--)
		val[i] = 0;
	sp = 0;
}

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

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

int get_op(char s[])
{
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		/* nothing */;
	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	i = 0;
	if (c == '-')
		s[++i] = c = getch();
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			/* nothing */;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			/* nothing */;
	s[i] = '\0';

	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int main(int argc, char **argv)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = get_op(s)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 == 0.0)
				printf("error: zero divisor\n");
			else
				push(pop() / op2);
			break;
		case '%':
			op2 = pop();
			if (op2 == 0.0)
				printf("error: zero divisor\n");
			else
				push ((int)pop() % (int)op2);
			break;
		case '^':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case '\n':
			printf("\t%.8lf\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
