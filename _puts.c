#include "main.h"

/**
  * _puts - print a string
  * @s: the string to print
  */
void _puts(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts((s + 1));
	}
}
