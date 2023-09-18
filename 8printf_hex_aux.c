#include "main.h"

/**
 * printf_hex_aux - This prints an hexgecimal number.
 * @num:arguments.
 * Return: counter.
 */

int printf_hex_aux(unsigned long int num)
{
	long int t;
	long int *array;
	long int counter = 0;
	unsigned long int temp = numb;

	while (numb / 16 != 0)
	{
		numb /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

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
