#include "main.h"

/**
  * _puts_count - print a string and count the printed charaters
  * @s: the string to print
  * @c the number of printed characters
  */
int _puts_count(char *s, int c)
{
	if (*s)
	{
		_putchar(*s);
		return (_puts_count((s + 1), (c + 1)));
	}
	return (c);
}

/**
  * _puts - print a string
  * @s: the string to print
  */
int _puts(char *s)
{
	return (_puts_count(s, 0));
}
