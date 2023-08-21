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
 * _printf - converts formats, and prints its arguments .
 * @format: the format of string
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int ch_print = 0;
	char c, *str;
	va_list ls_args;

	if (format == NULL)
		return (-1);

	va_start(ls_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ch_print++;
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
				write(1, format, 1);
				ch_print++;
			}
			else if (*format == 'c')
			{
				c = va_arg(ls_args, int);
				write(1, &c, 1);
				ch_print++;
			}
			else if (*format == 's')
			{
				str = va_arg(ls_args, char*);
				print_str(str);
				ch_print += strlen(str);
			}
		}
		format++;
	}
	va_end(ls_args);
	return (ch_print);
}
