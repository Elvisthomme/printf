#include "main.h"

/**
 * print_binary - prints the binary value of an unsigned int
 * @n: the integer to print
 * Return: the number of printed digit
 */
int print_binary(unsigned int n)
{
	unsigned int positive_value;
	int number_of_digit = 1;
	int divider, i, j, count = 0;

	positive_value = n;
	/* Count the number of digit */
	while (positive_value > 1)
	{
		number_of_digit++;
		positive_value /= 2;
	}
	for (i = number_of_digit; i > 0; i--)
	{/*print the number starting by his first digit*/
		divider = 1;
		j = 1;
		while (j < i)
		{/* calculate the power divider = pow(10, i)*/
			divider *= 2;
			j++;
		}
		count += _putchar('0' + n / divider);/*Print the first digit*/
		/* get the part of the number that we have not printed*/
		n = n - ((n / divider) * divider);
	}
	return (count);
}
