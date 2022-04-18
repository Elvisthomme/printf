#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *);
void check_for_modifiers(const char *format, va_list list, int *i, int *count);
#endif
