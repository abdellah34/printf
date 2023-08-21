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
/**
 * print_char - to write the character.
 * @c: The charactr to print
 * Return: 1.
 **/
int print_char(char c)
{
	putchar(c);
	return (1);
}
/**
 * _printf - converts formats, and prints its arguments .
 * @format: the format of string
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int ch_print = 0;
	int c;
	char *str;
	va_list ls_args;

	va_start(ls_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ch_print += print_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				ch_print += print_char('%');
			}
			else if (*format == 'c')
			{
				c = va_arg(ls_args, int);
				ch_print += print_char(c);
			}
			else if (*format == 's')
			{
				str = va_arg(ls_args, char*);
				ch_print += print_str(str);
			}
		}
		format++;
	}
	va_end(ls_args);
	return (ch_print);
}
