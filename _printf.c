#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0;
    char c;
    while ((c = *(format++)) != '\0') {
        if (c == '%') {
            c = *(format++);
            switch (c) {
                case 'c': {
                    char ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                case 's': {
                    char* str = va_arg(args, char*);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    break;
            }
        }
        else {
            putchar(c);
            count++;
        }
    }
    
    va_end(args);
    return count;
}

