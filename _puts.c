#include "main.h"

/**
  * _puts_count - print a string and count the printed charaters
  * @s: the string to print
  * @c: the number of printed characters
  * Return: the number of printed characters
  */
int _puts(char *s)
{
	  int c = 0;

	while (*s != '\0')
	{
		c += _putchar(*s);
		s++;
	}
	return (c);
}
