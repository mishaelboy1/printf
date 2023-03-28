#include "main.h"

/**
 * _print_reversed_string - Prints a string in reverse using _putchar recursively
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
static int _print_reversed_string(char *str)
{
	int printed = 0;

	if (*str)
	{
		printed += _print_reversed_string(str + 1);
		printed += _putchar(*str);
	}

	return (printed);
}

/**
 * _printf - Produces output according to a format
 * @format: A character string
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			/* handle flag characters */
			while (*format == '0' || *format == '-')
			{
				format++;
			}

			switch (*format)
			{
			case 'c':
				printed += _putchar(va_arg(args, int));
				break;

			case 's':
				str = va_arg(args, char *);
				if (!str)
				{
					str = "(null)";
				}
				printed += _puts(str);
				break;

			case '%':
				printed += _putchar('%');
				break;

			case 'd':
			case 'i':
				printed += _print_number(va_arg(args, int));
				break;

			case 'u':
				printed += _print_unsigned_number(va_arg(args, unsigned int));
				break;

			case 'o':
				printed += _print_octal_number(va_arg(args, unsigned int));
				break;

			case 'x':
				printed += _print_hex_number(va_arg(args, unsigned int), 0);
				break;

			case 'X':
				printed += _print_hex_number(va_arg(args, unsigned int), 1);
				break;

			case 'r':
				str = va_arg(args, char *);
				if (!str)
				{
					str = "(null)";
				}
				printed += _print_reversed_string(str);
				break;

			default:
				_putchar('%');
				_putchar(*format);
				printed += 2;
				break;
			}
		}
		else
		{
			printed += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (printed);
}

