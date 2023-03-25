#include "main.h"
#include <stdarg.h>
/**
 * _printf - print to standard output based on the format provided
 * @format: format of input to be printed
 * Return: num_chars_printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int num_chars_printed = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					num_chars_printed += putchar(va_arg(args, int));
					break;
				case 's':
					num_chars_printed += printf("%s", va_arg(args, char *));
					break;
				case '%':
					num_chars_printed += putchar('%');
					break;
				default:
					/*unsupported conversion specifier*/
					return (-1);
			}
		}
		else
		{
			num_chars_printed += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (num_chars_printed);
}
