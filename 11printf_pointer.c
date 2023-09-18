#include "main.h"

/**
 * printf_pointer - this prints an hexgecimal number
 * @val: arguments.
 * Return: counter
 */

int printf_pointer(va_list val)
{
	void *p;
	char *s = "(nil)";
	long int y;
	int x;
	int g;

	p = va_arg(val, void*);
	if (p == NULL)
	{
		for (g = 0; s[g] != '\0'; g++)
		{
			_putchar(s[g]);
		}
		return (g);
	}

	y = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	x = printf_hex_aux(y);
	return (x + 2);
}
