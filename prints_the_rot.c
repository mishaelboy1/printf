#include "main.h"

/**
 * _rot13 - Encodes a string using rot13
 * @str: The string to encode
 *
 * Return: A pointer to the encoded string
 */
static char *_rot13(char *str)
{
	int i, j;
	char *result = malloc(sizeof(char) * (_strlen(str) + 1));

	if (result == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			result[i] = ((str[i] - 'a' + 13) % 26) + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result[i] = ((str[i] - 'A' + 13) % 26) + 'A';
		else
			result[i] = str[i];
	}
	result[i] = '\0';

	return (result);
}

/**
 * handle_custom_specifiers - Handles custom conversion specifiers
 * @specifier: The conversion specifier
 * @args: The arguments list
 * @flags: The flags to apply
 *
 * Return: The number of characters printed
 */
static int handle_custom_specifiers(char specifier, va_list args, int flags)
{
	char *str;

	switch (specifier)
	{
	case 'r':
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		_puts_rev(str);
		return (_strlen(str));
	case 'R':
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		str = _rot13(str);
		_puts(str);
		free(str);
		return (_strlen(str));
	default:
		if (specifier != '\0')
			_putchar('%');
		if (flags & FL_ZERO)
			_putchar('0');
		_putchar(specifier);
		if (specifier != '\0' && !(flags & FL_MINUS))
			_putchar('\0');
		return (specifier != '\0' ? 2 : 0);
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
	int flags = 0;

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
		{
	format++;
	flags = handle_flags(format);
	format += _num_len(flags);

	if (*format == '\0')
	break;

	if (is_conversion_specifier(*format))
	{
	printed += handle_conversion_specifier(*format, args, flags);
	}
	else if (is_custom_conversion_specifier(*format))
	{
	printed += handle_custom_specifiers(*format, args, flags);
	}
	else
	{
	if (*format != '\0')
	_putchar('%');
	if (flags & FL_ZERO)
	_putchar('0');
	_putchar(*format);
	if (*format != '\0' && !(flags & FL_MINUS))
	_putchar('\0');
	printed += (*format != '\0' ? 2 : 0);
			}
		}
		else
		{
	printed += _putchar(*format);


