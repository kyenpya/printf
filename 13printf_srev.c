#include "main.h"

/**
 * printf_srev - This is the function that prints a str in reverse
 * @args: type struct va_arg where allocated printf arguments is
 * Return: string
 */

int printf_srev(va_list args)
{

	char *s = va_arg(args, char*);
	int t;
	int g = 0;

	if (s == NULL)
		s = "(null)";
	while (s[g] != '\0')
		g++;
	for (t = g - 1; t >= 0; g--)
		_putchar(s[t]);
	return (g);
}
