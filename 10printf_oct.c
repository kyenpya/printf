#include "main.h"
/**
 * printf_oct - this prints an octal number.
 * @val: arguments
 * Return: counter.
 */

int printf_oct(va_list val)
{
	int t;
	int *array;
	int counter = 0;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int temp = numb;

	while (numb / 8 != 0)
	{
		numb /= 8;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (t = 0; t < counter; t++)
	{
		array[t] = temp % 8;
		temp /= 8;
	}
	for (t = counter - 1; t >= 0; t--)
	{
		_putchar(array[t] + '0');
	}
	free(array);
	return (counter);
}
