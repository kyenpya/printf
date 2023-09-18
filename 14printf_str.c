#include "main.h"

/**
 * _strlen - This Returns the lenght of a string
 * @s: it Type char pointer
 * Return: v.
 */

int _strlen(char *s)
{
	int v;

	for (v = 0; s[v] != 0; v++)
		;
	return (v);

}

/**
 * _strlenc - strlenc function that is applied for constant char pointers
 * @s: Type char pointer
 * Return: v.
 */

int _strlenc(const char *s)
{
	int v;

	for (v = 0; s[v] != 0; v++)
		;
	return (v);
}
