#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 * Return: the number of printed digit
 */
int print_number(int n)
{
	int positive_value, number_of_digit = 1;
	int divider, i, j, abs_value, count = 0;

	/* print the sign and get the absolute value*/
	if (n < 0)
	{
		count += _putchar('-');
		if (n ==  -2147483648)
		{
			count += _putchar('0' + 2);
			abs_value = positive_value = 147483648;
		}
		else
			abs_value = positive_value = -n;
	}
	else
		abs_value = positive_value = n;
	/* Count the number of digit */
	while (positive_value > 9)
	{
		number_of_digit++;
		positive_value /= 10;
	}
	for (i = number_of_digit; i > 0; i--)
	{/*print the number starting by his first digit*/
		divider = 1;
		j = 1;
		while (j < i)
		{/* calculate the power divider = pow(10, i)*/
			divider *= 10;
			j++;
		}
		count += _putchar('0' + abs_value / divider);/*Print the first digit*/
		/* get the part of the number that we have not printed*/
		abs_value = abs_value - ((abs_value / divider) * divider);
	}
	return (count);
}
