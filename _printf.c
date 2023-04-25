#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
int count = 0, c;
va_list args;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
c = va_arg(args, int);
count += putchar(c);
}
else if (*format == 's')
{
count += printf("%s", va_arg(args, char *));
}
else if (*format == '%')
{
count += putchar('%');
}
else
{
count += putchar('%');
count += putchar(*format);
}
}
else
{
count += putchar(*format);
}
format++;
}
va_end(args);
return (count);
}
