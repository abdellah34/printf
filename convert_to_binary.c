#include "main.h"
/**
 * convert_to_binary - convertthe integer from dicimal to binary.
 * @a: the integer to convert.
 * Return: the number of digits in binary base.
 **/

int convert_to_binary(unsigned int a)
{
	unsigned int q = a;
	int i = 0, count, tab[100];

	while (q >= 1)
	{
		tab[i] = q % 2;
		q /= 2;
		i++;
	}
	count = i;
	while (i > 0)
	{
		i--;
		putchar(tab[i] + '0');
	}
	return (count);
}
