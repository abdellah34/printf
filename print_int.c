#include "main.h"

/**
 * _pow - retuerns x raised of the power of y
 * @x: is the base value
 * @y: is the power value
 * Return: the result
 */
int _pow(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow(x, y - 1));
}
/**
 * count_digits - counts the digits .
 * @n: the anteger to count its digitst.
 * Return: the number of digit.
 */
int count_digits(int n)
{
	int k = 0;

	while (n > 0)
	{
		n /= 10;
		k++;
	}
	return (k);
}
/**
 * print_int - converts formats, and prints its arguments .
 * @n: the anteger to print.
 * Return: the number of digit.
 */
int print_int (int n)
{
	int count = 0, i = 1, j = 0, neg = 0;

	if (n == 0)
	{
		putchar(n + '0');
		return (1);
	}
	if (n < 0)
	{
		putchar('-');
		n = -n - 1;
		neg++;
	}
	j = count_digits(n);
	count += j  + neg;
	i = _pow(10, (j - 1));
	if (neg)
	{
		while (j - 1)
		{
			putchar(n / i + '0');
			n = n - (n / i) * i;
			j--;
			i /= 10;
		}
		putchar((n + 1) + '0');
	}
	else
	{
		while (j)
		{
			putchar(n / i + '0');
			n = n - (n / i) * i;
			j--;
			i /= 10;
		}
	}
	return (count);
}
