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
* _print_unsigned_number - Prints an unsigned integer
* using _putchar recursively
* @n: The unsigned integer to print
*
* Return: Number of digits printed
*/
static int _print_unsigned_number(unsigned int n)
{
if (n / 10)
{
return (_print_unsigned_number(n / 10) + _putchar(n % 10 + '0'));
}
else
{
return (_putchar(n % 10 + '0'));
}
}

/**
* _print_octal_number - Prints an octal number using _putchar recursively
* @n: The unsigned octal number to print
*
* Return: Number of digits printed
*/
static int _print_octal_number(unsigned int n)
{
if (n / 8)
{
return (_print_octal_number(n / 8) + _putchar(n % 8 + '0'));
}
else
{
return (_putchar(n % 8 + '0'));
}
}

/**
* _print_hex_number - Prints a hexadecimal number using _putchar recursively
* @n: The unsigned hexadecimal number to print
* @uppercase: 1 to print uppercase letters, 0 to print lowercase letters
*
* Return: Number of digits printed
*/
static int _print_hex_number(unsigned int n, int uppercase)
{
char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
if (n / 16)
{
return (_print_hex_number(n / 16, uppercase) + _putchar(hex_digits[n % 16]));
}
else
{
return (_putchar(hex_digits[n % 16]));
}
}

/**
* _printf - Produces output according to a format
* @format: A character string
*
* Return: The number of characters printed
* (excluding the null byte used to end output to strings)
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
while (*format == '0')
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


