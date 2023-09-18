#include "main.h"

/**
 * print_string - prints a string
 * @val: argument
 * Return: string length
 */

int print_string(va_list val)
{
	char *s;
	int len, t;

	s = va_arg(val, char *);
	if (s == NULL)
	{
		s + "(null)";
		len = _strlen(s);
		for (t = 0; t < len; t++)
			_putchar(s[t]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (t = 0; t < len; t++)
			_putchar(s[t]);
		return (len);
	}
}
