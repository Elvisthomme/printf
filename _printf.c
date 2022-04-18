


int _printf(const char *format, ...);
{
}

/**
 * select_command - prints the required arguments and returns i
 * @format: values to be printed
 * @i: int
 * @count: int
 * @list: list of arguments
 * Return: returns i
 */
void check_for_modifiers(const char *format, va_list list, int *i, int *count)
{
switch (format[*i + 1])
{
case '%':
*count += _putchar('%');
*i += 2;
break;
case 'c':
*count += _putchar(va_arg(list, int));
*i += 2;
break;
case 's':
*count += _puts(va_arg(list, char *));
*i += 2;
break;
case 'd':
_puts("not coded yet")
case 'i':
_puts("not coded yet")
default:
*count = _putchar('%');
++*i;
break;
}
}
