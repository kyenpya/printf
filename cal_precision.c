#include "main.h"

/**
 * cal_precision - Calculates precision for printing
 * @format: string format that prints arguments
 * @t: arguments to be printed.
 * @list: arguments to be printed.
 * Return: Precision.
 */

int cal_precision(const char *format, int *t, va_list list)
{
	int jun_g = *t + 1;
	int precision = -1;

	if (format[jun_g] != '.')
		return (precision);
	precision = 0;

	for (jun_g += 1; format[jun_g] != '\0'; jun_g++)
	{
		if (is_digit(format[jun_g]))
		{
			precision *= 10;
			precision += format[jun_g] - '0';
		}

		else if (format[jun_g] == '*')
		{
			jun_g++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*t = jun_g - 1;
	return (precision);

