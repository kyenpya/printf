#include "main.h"

/**
 * printable - checks if a char is printable
 * @c: char to be checked
 * Return: 1 if printale, otherwise 0
 */

int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * add_hexa_code - appends ascii in hexadecimal code to buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascii_code: ASCII code
 * Return: 3
 */

int add_hexa_code(char ascii_code, char buffer [], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];
	return (3);
}

/**
 * is_digit - checks if a character is a digit
 * @c: the char to be checked
 * Return: if c is digit, 1, otherwise 0.
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * size_number - casts num to the specified size
 * @num: number to cast
 * @size: indicates type to cast
 * Return: value of num casted
 */

long int size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * size_unsigned - casts num to it's specified size
 * @num: number to cast
 * @size: indicates type to cast
 * Return: value of num casted
 */

long int size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
