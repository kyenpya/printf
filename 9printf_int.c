#include "main.h"

/**
 * printf_int - This prints interger
 * @args:argument to print
 * Return: the number of character that prints
 */

int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int numb, last = n % 10, digit, exp = 1;
	int  t = 1;

	n = n / 10;
	numb = n;

	if (last < 0)
	{
		_putchar('-');
		numb = -numb;
		n = -n;
		last = -last;
		t++;
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
			t++;
		}
	}
	_putchar(last + '0');

	return (t);
}

/**
 * printf_dec - prints decimal
 * @args: arguments to print
 * Return: number of characters printed
 */

int printf_dec(va_list args)
{
	int n = va_arg(args, int);
	int numb, last = n % 10, digit;
	int  t = 1;
	int exp = 1;

	n = n / 10;
	numb = n;

	if (last < 0)
	{
		_putchar('-');
		numb = -numb;
		n = -n;
		last = -last;
		t++;
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
			t++;
		}
	}
	_putchar(last + '0');

	return (t);
}
