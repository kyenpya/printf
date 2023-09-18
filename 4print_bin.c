#include "main.h"

/**
 * printf_bin - this prints a binary number
 * @val: arguments.
 * Return: 1.
 */

int printf_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int t, x = 1, y;
	unsigned int number = va_arg(val, unsigned int);
	unsigned int g;

	for (t = 0; t < 32; t++)
	{
		g = ((x << (31 - t)) & number);
		if (g >> (31 - t))
			flag = 1;
		if (flag)
		{
			y = g >> (31 - t);
			_putchar(y + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}
