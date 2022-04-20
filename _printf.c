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
			|| c == 'X' || c == 'x')
				return (i + 1);
			if (c == '%')
			{
				c = *(format + i + 2);
				if (c == 'b' || c == 'c' || c == 'd' || c == 'i'
				|| c == 'o' || c == 'S' || c == 's' || c == 'u'
				|| c == 'X' || c == 'x')
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
	char *str;
	int check, i;

	if (!format)
		return (count);

	check = check_for_modifier(format);

	if (check == -1)/*We haven't found specifier*/
		return (_puts_count(format, count));
	if (check >= 2)/*The string doesn't start whit he specifier*/
		write(1, format, check - 1);

	switch (*(format + check))
	{
		case 'b':
		case 'o':
		case 'u':
		case 'x':
		case 'X':
			i = print_in_base(va_arg(ap, unsigned int),
					*(format + check));
			return (_printf_count((format + check + 1),
						count + check + i - 1, ap));
		case 'c':
			_putchar(va_arg(ap, int));
			return (_printf_count((format + check + 1),
						count + check, ap));
		case 'S':
			str = va_arg(ap, char *);
			i = _puts_special(str);
			return (_printf_count((format + check + 1),
						count + check + i - 1, ap));
		case 's':
			str = va_arg(ap, char *);
			i = _puts_count(str, 0);
			return (_printf_count((format + check + 1),
						count + check + i - 1, ap));
		case '%':
			_putchar('%');
			return (_printf_count((format + check + 1),
						count + check, ap));
		case 'i':
		case 'd':
			i = print_number(va_arg(ap, int));
			return (_printf_count((format + check + 1),
						count + check + i - 1, ap));
		default:/*here the modifier is not a char nor a string*/
			return (_printf_count((format + check),
				count + check, ap));
	}
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

	if (!format || (*(format + 0) == '%' && !*(format + 1)))
		return (0);
	count = _printf_count(format, 0, ap);
	va_end(ap);
	return (count);

}
