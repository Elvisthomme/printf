#include "main.h"
/**
 * print_rot13 - encode a string using rot13
 * @str: the string to encode
 * Return: call a function that will return the number of printed character
 */
int print_rot13(char *str)
{
	int i = 0;

	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) = ((*(str + i) - 65 + 13) % 26) + 65;
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
			*(str + i) = ((*(str + i) - 97 + 13) % 26) + 97;
		i++;
	}
	return (_puts(str));
}
