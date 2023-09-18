#include "main.h"
/**
 * printf_string - this prints a string
 * @val: argument
 * Return: lenght of string.
 */

int printf_string(va_list val)
{
	char *s;
	int t, len;

	s = va_arg(val, char *);
	if (s == NULL)
	{
		s = "(null)";
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
