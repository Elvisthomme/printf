#include "main.h"

/**
 * check_for_modifier - check if a string has a modifier
 * @format: values to be printed
 * Return: the index of the modifier or -1 if it is no specifier
 */
int check_for_modifier(const char *format)
{
	int i = 0;

	while (*(format + i))
	{
		if (*(format + i) == '%')
			switch (*(format + i + 1))
			{
				case '%':
				case 'c':
				case 's':
				case 'd':
				case 'i':
					return (i + 1);
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
		case 'c':
			_putchar(va_arg(ap, int));
			return (_printf_count((format + check + 1),
						count + check, ap));
		case 's':
			str = va_arg(ap, char *);
			i = _puts_count(str, 0);
			return (_printf_count((format + check + 1),
						count + check + i - 1, ap));
		case '%':
			_putchar('%');
			return (_printf_count((format + check + 1),
						count + check, ap));

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
	count = _printf_count(format, 0, ap);
	va_end(ap);
	return (count);

}
