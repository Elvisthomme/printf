#include "main.h"

/**
 * print_in_base - prints an integer a specifier base
 * @n: the integer to print
 * @b: the base
 * Return: the number of printed digit
 */
int print_in_base(unsigned long int n, char c)
{
	unsigned long int positive_value, b;
	long int number_of_digit = 1, divider, i, j, p, count = 0;
	char x16[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char X16[] = {'A', 'B', 'C', 'D', 'E', 'F'};

	switch (c)
	{
		case 'b':
			b = 2;
			break;
		case 'o':
			b = 8;
			break;
		case 'u':
			b = 10;
			break;
		case 'X':
		case 'x':
			b = 16;
	}
	positive_value = n;/* Count the number of digit */
	while (positive_value > b - 1)
	{
		number_of_digit++;
		positive_value /= b;
	}
	for (i = number_of_digit; i > 0; i--)
	{/*print the number starting by his first digit*/
		divider = 1;
		j = 1;
		while (j < i)
		{/* calculate the power divider = pow(b, i)*/
			divider *= b;
			j++;
		}
		if (b < 11)/*Print the first digit*/
			count += _putchar('0' + n / divider);
		else
			if ((n / divider) > 10)
				switch (c)
				{
					case 'x':
						p = (n / divider) % 10;
						count += _putchar(x16[p]);
						break;
					case 'X':
						p = (n / divider) % 10;
						count += _putchar(X16[p]);
						break;
				}
			else
				count += _putchar('0' + n / divider);
		/* get the part of the number that we have not printed*/
		n -= (n / divider) * divider;
	}
	return (count);
}
