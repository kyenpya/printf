#include "main.h"
/**
 * printf_unsigned - this prints interger
 * @args: this is the argument to print
 * Return: numbers of character to be printed
 */

int printf_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int numb, last = n % 10, digit, exp = 1;
	int  k = 1;

	n = n / 10;
	numb = n;

	if (last < 0)
	{
		_putchar('-');
		numb = -numb;
		n = -n;
		last = -last;
		k++;
	}
	if (numb > 0)
	{
		while (numb / 10 != 0)
		{
			exp = exp * 10;
			numb = numb / 10;
		}
		numb = n;
		while (exp > 0)
		{
			digit = numb / exp;
			_putchar(digit + '0');
			numb = numb - (digit * exp);
			exp = exp / 10;
			k++;
		}
	}
	_putchar(last + '0');

	return (k);
}
