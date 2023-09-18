#include "main.h"

/**
 * cal_flags - Calculates the active flags
 * @format: string format that prints arguments
 * @g: get a parameter.
 * Return: Flags:
 */

int cal_flags(const char *format, int *g)
{
	int j, jun_g;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (jun_g = *g + 1; format[jun_g] != '\0'; jun_g++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[jun_g] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*g = jun_g - 1;
	return (flags);

