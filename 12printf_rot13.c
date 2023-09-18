#include "main.h"

/**
 * printf_rot13 - this prints str to ROT13 place into buffer
 * @args: type struct va_arg where allocated printf arguments is
 * Return: counter
 */

int printf_rot13(va_list args)
{
	int t, g, counter = 0;
	int k = 0;
	char *s = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (t = 0; s[t]; t++)
	{
		k = 0;
		for (g = 0; alpha[g] && !k; g++)
		{
			if (s[t] == alpha[g])
			{
				_putchar(beta[g]);
				counter++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(s[t]);
			counter++;
		}
	}
	return (counter);
}
