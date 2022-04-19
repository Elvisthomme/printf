#include "main.h"

/**
  * _puts_count - print a string and count the printed charaters
  * @s: the string to print
  * @c: the number of printed characters
  * Return: the number of printed characters
  */
int _puts_count(const char *s, int c)
{

	while (*s != '\0')
	{
		c += _putchar(*s);
		s++;
	}
	return (c);
}

/**
  * _puts - print a string
  * @s: the string to print
  * Return: the number of printed characters
  */
int _puts(const char *s)
{
	return (_puts_count(s, 0));
}

/**
  * _puts_special - print string and hexadecimal code of non pritable char
  * @s: the string to print
  * Return: the number of printed characters
  */
int _puts_special(const char *s)
{
	int c = 0;

	while (*s != '\0')
	{
		if (*s < 32 || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (*s < 16)
				_putchar('0');
			print_in_base((unsigned long int) *s, 'X');
			c += 4;
		}
		else
			c += _putchar(*s);
		s++;
	}
	return (c);
}
