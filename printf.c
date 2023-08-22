#include "main.h"
/**
 * _printf - converts formats, and prints its arguments .
 * @format: the format of string
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int ch_print = 0;
	char *str;

	va_list ls_args;

	if (format == NULL)
		return (-1);
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
				return (-1);
			if (*format == '%')
				ch_print += print_char('%');
			else if (*format == '!')
				ch_print += print_str("%!");
			else if (*format == 'c')
				ch_print += print_char(va_arg(ls_args, int));
			else if (*format == 's')
			{
				str = va_arg(ls_args, char*);
				if (str == NULL)
					print_str("(null)");
				ch_print += print_str(va_arg(ls_args, char*));
			}
		}
		format++;
	}
	va_end(ls_args);
	return (ch_print);
}
