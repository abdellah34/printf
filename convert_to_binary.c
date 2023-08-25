#include "main.h"
/**
 * convert_to_binary - convertthe integer from dicimal to binary.
 * @a: the integer to convert.
 * Return: the number of digits in binary base.
 **/

int convert_to_binary(unsigned int a)
{
	unsigned int q = a;
	int tab[64];
	int i = 0, count;

	if(a == 0 )
	{
		putchar('0');
		return (1);
	}
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
