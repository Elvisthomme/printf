#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 *struct print_func - struct to select specific print function
 *@print_ft: format specifier
 *@p_func: pinter to function
 */
typedef struct print_func
{
	char print_ft;
	int (*p_func)(va_list l);
} pr_f;
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(const char *);
void check_for_modifiers(const char *, va_list, int *, int *);
int check_for_modifier(const char *format);
int _puts_count(const char *, int);
int print_number(int);
#endif
