#include "main.h"

/**
 * printf_hex - this prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */

int printf_hex(va_list val)
{
	int t;
	int *array;
	int counter = 0;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int temp = numb;

	while (numb / 16 != 0)
	{
		numb /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (t = 0; t < counter; t++)
	{
		array[t] = temp % 16;
		temp /= 16;
	}
	for (t = counter - 1; t >= 0; t--)
	{
		if (array[t] > 9)
			array[t] = array[t] + 39;
		_putchar(array[t] + '0');
	}
	free(array);
	return (counter);
}
