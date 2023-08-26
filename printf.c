#include "main.h"
/**
 * _printf - converts formats, and prints its arguments .
 * @format: the format of data
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int ch_prntd = 0;

	va_start(args, format);

	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
			ch_prntd += print_char(*format);
		else
		{
			format++;
			if (*format == '\0' || (*format == ' ' && *(format + 1) == '\0'))
				return (-1);

			if (*format == 'c')
				ch_prntd += print_char(va_arg(args, int));
			else if (*format == 'd' || *format == 'i')
				ch_prntd += print_int(va_arg(args, int));
			else if (*format == 's')
				ch_prntd += print_str(va_arg(args, char *));
			else if (*format == '%')
				ch_prntd += print_char('%');
			else if (*format == 'b')
				ch_prntd += convert_to_binary(va_arg(args, int));
			else if (*format == 'u')
				ch_prntd += prnt_ui(va_arg(args, int));
			else
			{
				ch_prntd += print_char('%');
				ch_prntd += print_char(*format);
			}
		}
		format++;
	}
	va_end(args);
	return (ch_prntd);
}
