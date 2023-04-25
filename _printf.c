#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    char buffer[1024];
    int buffer_len = 0;
    char c;

    while ((c = *format++) != '\0') {
        if (c == '%') {
            switch (*format++) {
                case 'c':
                    buffer[buffer_len++] = (char)va_arg(args, int);
                    break;
                case 's': {
                    const char *s = va_arg(args, const char *);
                    int len = strlen(s);
                    if (buffer_len + len > 1023) {
                        count += buffer_len;
                        buffer[buffer_len] = '\0';
                        printf("%s", buffer);
                        buffer_len = 0;
                    }
                    strcpy(buffer + buffer_len, s);
                    buffer_len += len;
                    break;
                }
                case '%':
                    buffer[buffer_len++] = '%';
                    break;
                default:
                    va_end(args);
                    return -1;
            }
        } else {
            buffer[buffer_len++] = c;
        }
        if (buffer_len == 1023) {
            count += buffer_len;
            buffer[buffer_len] = '\0';
            printf("%s", buffer);
            buffer_len = 0;
        }
    }
    if (buffer_len > 0) {
        count += buffer_len;
        buffer[buffer_len] = '\0';
        printf("%s", buffer);
    }
    va_end(args);
    return count;
}
