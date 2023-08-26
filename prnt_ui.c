#include "main.h"
/**
 * prnt_ui - prints an unsigned integer .
 * @n: the anteger to print.
 * Return: the number of digit.
 */
int prnt_ui(unsigned int n)
{
	char dgt[20];
	int count = 0, i = 0;

	if (n == 0)
	{
		putchar(n + '0');
		return (1);
	}

	while (n > 0)
	{
		dgt[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	count = i;
	while (i > 0)
	{
		i--;
		putchar(dgt[i]);
	}
	return (count);
}
