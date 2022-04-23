#include "main.h"

/**
 * print_address - prints an address
 * @p: the address to print
 * Return: the number of printed digit
 */
int print_address(unsigned long int p)
{
	unsigned long int c = 1;
	int i;

	for (i = 0; i < 12; i++)
		c *= 16;
	_puts("0x");
	
	while (p < c && p > 15)
	{
		_putchar('0');
		c /= 16;
	}
	print_in_base(p, 'x');
	return (14);
}
