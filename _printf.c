#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list arg_list;
    int char_count = 0;

    // Initialize arg_list to point to the first argument after format
    va_start(arg_list, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            // Handle conversion specifiers
            format++;
            if (*format == 'c')
            {
                // Print a character
                int c = va_arg(arg_list, int);
                putchar(c);
                char_count++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(arg_list, char*);
                while (*s != '\0')
                {
                    putchar(*s);
                    s++;
                    char_count++;
                }
            }
            else if (*format == '%')
            {
                // Print a percent sign
                putchar('%');
                char_count++;
            }
        }
        else
{
putchar(*format);
char_count++;
}
		format++;
}
va_end(arg_list);
return char_count;
}