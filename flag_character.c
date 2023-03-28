#include "main.h"

/**
 * _print_number - Prints an integer using _putchar recursively
 * @n: The integer to print
 *
 * Return: Number of digits printed
 */
static int _print_number(int n)
{
	unsigned int u;

	if (n < 0)
	{
		_putchar('-');
		u = -n;
	}
	else
	{
		u = n;
	}

	if (u / 10)
	{
		return (_print_number(u / 10) + _putchar(u % 10 + '0'));
	}
	else
	{
		return (_putchar(u % 10 + '0'));
	}
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
			int left_justify = 0;
			while (*format == '0' || *format == '-')
			{
				if (*format == '0')
					format++; /* ignore 0 flag if - flag is present */
				else if (*format == '-')
					left_justify = 1;
				format++;
			}

			/* handle field width */
			int field_width = 0;
			while (*format >= '0' && *format <= '9')
			{
				field_width = field_width * 10 + (*format - '0');
				format++;
			}

			switch (*format)
			{
			case 'c':
				if (left_justify)
					printed += _putchar(va_arg(args, int));
				for (int i = 1; i < field_width; i++)
					printed += _putchar(' ');
				if (!left_justify)
					printed += _putchar(va_arg(args, int));
				break;

			case 's':
				str = va_arg(args, char *);
				if (!str)
				{
					str = "(null)";
				}
				int len = _strlen(str);
				if (left_justify)
					printed += _puts(str);
				for (int i = len; i < field_width; i++)
					printed += _putchar(' ');
				if (!left_justify)
					printed += _puts(str);
				break;

			case '%':
				if (left_justify)
					printed += _putchar('%');
				for (int i = 1; i < field_width; i++)
					printed += _putchar(' ');
				if (!left_justify)
					printed += _putchar('%');
				break;

			case 'd':
			case 'i':
				if (left_justify)
					printed += _print_number(va_arg(args, int));
				int num_digits = _num

