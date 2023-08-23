#include "main.h"
/**
 * print_int - converts formats, and prints its arguments .
 * @n: the format of string
 * Return: an integer.
 */
int print_int (int n)
{
	int count = 0, i = 1, j = 0;

	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	while (i <= n)
	{
		i *= 10;
		j++;
	}
	while (j)
	{
		i = i / 10;
		putchar(n / i + '0');
		n = n - (n / i) * i;
		count++;
		j--;
	}
	return (count);
}
