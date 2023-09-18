#include "main.h"

/**
 * _strlen - This Returns the lenght of a string
 * @s: it Type char pointer
 * Return: c.
 */

int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);

}

/**
 * _strlenc - strlenc function that is applied for constant char pointers
 * @s: Type char pointer
 * Return: c.
 */

int _strlenc(const char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}
