#include "main.h"
/**
 * _printf - selects  correct function which is meant to be printed.
 * @format: identifier to look for.
 * Return: length of string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int t = 0, g, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[t] != '\0')
	{
		g = 13;
		while (g >= 0)
		{
			if (m[g].id[0] == format[t] && m[g].id[1] == format[t + 1])
			{
				len += m[g].f(args);
				t = t + 2;
				goto Here;
			}
			g--;
		}
		_putchar(format[t]);
		len++;
		t++;
	}
	va_end(args);
	return (len);
}

