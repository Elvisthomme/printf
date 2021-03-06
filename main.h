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
int print_in_base(unsigned long int, char);
int _puts_special(const char *);
int print_num_up_to_10(unsigned int, int, char);
int print_rev(char *);
int print_rot13(char *);
int print_address(unsigned long int);
#endif
