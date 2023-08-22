#include "main.h"
/**
 * print_str - writes the string str to stdout
 * @str: The string to print
 * Return: On success 1.
 * on error, -1 is returned, and errno is set appropriately.
 **/
int print_str(char *str)
{
		return (write(1, str, strlen(str)));
}
/**
 * null_format - writes the string str to stdout
 * @str: The string to print
 * Return: On success 1.
 * on error, -1 is returned, and errno is set appropriately.
 **/
int null_format(const char *str)
{
	if (str == NULL)
		return (-1);
	return (0);
}
/**
 * print_notpercent - writes the string str to stdout
 * @str: The string to print
 * @c : 2 param
 * Return: On success 1.
 * on error, -1 is returned, and errno is set appropriately.
 **/
int print_notpercent(const char *str, int *c)
{
	if (*str != '%')
	{
		c++;
		return (write(1, str, 1));
	}
	return (0);
}
/**
 * print_percent - writes the string str to stdout
 * @str: The string to print
 * @c : 2 param
 * Return: On success 1.
 * on error, -1 is returned, and errno is set appropriately.
 **/
int print_percent(const char *str, int *c)
{
	str++;
	if (*str == '\0')
		return (-1);
	if (*str == '%')
	{
		c++;
		return (write(1, str, 1));
	}
	return (0);
}
/**
 * _printf - converts formats, and prints its arguments .
 * @format: the format of string
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int ch_count = 0;
	char c, *str;
	va_list ls_args;

	null_format(format);
	va_start(ls_args, format);
	while (*format)
	{
		print_notpercent(format, &ch_count);
		if (*format == '%')
		{
			print_percent(format, &ch_count);
			if (*format == 'c')
			{
				c = va_arg(ls_args, int);
				write(1, &c, 1);
				ch_count++;
			}
			else if (*format == 's')
			{
				str = va_arg(ls_args, char*);
				print_str(str);
				ch_count += strlen(str);
			}
			else
				write(1, format, 1);
		}
		format++;
	}
	va_end(ls_args);
	return (ch_count);
}
