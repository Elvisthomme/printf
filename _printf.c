#include "main.h"

/**
 * check_for_modifier - check if a string has a modifier
 * @format: values to be printed
 * Return: the index of the modifier or -1 if it is no specifier
 */
int check_for_modifier(const char *format)
{
	int i = 0;
	char c;

	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			c = *(format + i + 1);
			if (c == 'b' || c == 'c' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'S' || c == 's' || c == 'u'
			|| c == 'X' || c == 'x' || c == 'R' || c == 'r'
			|| c == 'p')
				return (i + 1);
			if (c == '%')
			{
				c = *(format + i + 2);
				if (c == 'b' || c == 'c' || c == 'd'
				|| c == 'i' || c == 'o' || c == 'S'
				|| c == 's' || c == 'u'	|| c == 'X'
				|| c == 'x' || c == 'R' || c == 'r'
				|| c == 'p')
					return (i + 2);
				else
					return (i + 1);
			}
		}
		i++;
	}
	return (-1);
}

/**
  * _printf_count - produce output according to a format
  * @format: a list of type of arguments passed to the function
  * @count: the number of printed characters
  * @ap: a va_list
  * Return: the number of character printed
  */
int _printf_count(const char *format, int count, va_list ap)
{
	char c;
	int i, j;

	j = check_for_modifier(format);
	if (j == -1)/*We haven't found specifier*/
		return (_puts_count(format, count));
	if (j >= 2)/*The string doesn't start whit he specifier*/
		write(1, format, j - 1);
	c = *(format + j);
	if (c == 'b' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
	|| c == 'S' || c == 's' || c == '%' || c == 'c' || c == 'i'
	|| c == 'd' || c == 'p')
	{
		if (c == 'c')
			i = _putchar(va_arg(ap, int));
		else if (c == 'S')
			i = _puts_special(va_arg(ap, char *));
		else if (c == 's')
			i = _puts(va_arg(ap, char *));
		else if (c == '%')
			i = _putchar('%');
		else if (c == 'i' || c == 'd')
			i = print_number(va_arg(ap, int));
		else if (c == 'r')
			i = print_rev(va_arg(ap, char *));
		else if (c == 'R')
			i = print_rot13(va_arg(ap, char *));
		else if (c == 'p')
			i = print_address(va_arg(ap, long int));
		else
			i = print_in_base(va_arg(ap, unsigned int), *(format + j));
		return (_printf_count(format + j + 1, count + j + i - 1, ap));
	}
	return (_printf_count((format + j), count + j, ap));
}
/**
  * _printf - produce output according to a format
  * @format: a list of type of arguments passed to the function
  * @...: the list of argument to print
  * Return: the number of character printed
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	if (!format)
		return (-1);
	if (*(format + 0) == '%' && !*(format + 1))
		return (1);
	count = _printf_count(format, 0, ap);
	va_end(ap);
	return (count);

}
