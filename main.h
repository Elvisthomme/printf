#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(const char *);
/*void check_for_modifiers(const char *format, va_list list, int *i, int *count);*/
int check_for_modifier(const char *format);
int _puts_count(const char *, int);
#endif
