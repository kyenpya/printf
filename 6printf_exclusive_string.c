#include "main.h"

/**
 * printf_exclusive_string - this prints exclusive string
 * @val:argument.
 * Return: the length of string
 */

int printf_exclusive_string(va_list val)
{
	char *s;
	int g, len = 0;
	int cast;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (g = 0; s[g] != '\0'; g++)
	{
		if (s[g] < 32 || s[g] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[g];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + printf_HEX_aux(cast);
		}
		else
		{
			_putchar(s[g]);
			len++;
		}
	}
	return (len);
}
