#include "main.h"
/**
 * print_str - to write the string str to stdout
 * @str: The string to print
 * Return:the count of characters.
 **/
int print_str(char *str)
{
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}
