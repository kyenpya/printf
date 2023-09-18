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
	int t, a = 1, b;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int p;

	for (t = 0; t < 32; t++)
	{
		p = ((a << (31 - t)) & numb);
		if (p >> (31 - t))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - t);
			_putchar(b + 48);
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
