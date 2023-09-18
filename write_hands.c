#include "main.h"

/**
 * handle_char - prints string
 * @c: char types
 * @buffer: handles print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: specifies precision
 * @size: specifies size
 * Return: printed no of chars
 */

int handle_char(char c, buffer[], int flags, int width, int precision, int size)
{
	char pad = '';
	int ind = 0;

	UNUSED (precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';
	buffer[ind++] = c;
	buffer[ind] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (ind = 0; ind < width - 1; ind++)
			buffer[BUFF_SIZE - ind - 2] = pad;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - ind - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - ind - 1], width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_num - prints string
 * @is_neg: list of args
 * @ind: char type
 * @buffer: handles print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: specifies precision
 * @size: specifies size
 * Return: printed no of chars
 */

int write_num(int is_neg, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char exchar = 0, pad = '';

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_neg)
		exchar = '-';
	else if (flags & F_PLUS)
		exchar = '+';
	else if (flags & F_SPACE)
		exchar = '';
	return (write_nos(ind, buffer, flags, width, precision, len, pad, exchar));
}

/**
 * write_nos - writes num using buffer
 * @ind: index where num starts from
 * @buffer: buffer
 * @flags: flags active
 * @width: gets width
 * @precision: specifies precision
 * @len: length of number
 * @pad: char padding
 * @exchar: extra character
 * Return: printed no of chars
 */

int write_nos(int ind, char buffer[], int flags, int width, int precision, int len, char pad, char exchar)
{
	int pad_st = 1, i;

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = '';
	if (precision > 0 && precision < len)
		pad = '';
	while (precision > len)
		buffer[--ind] = '0', len++;
	if (exchar != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == '')
		{
			if (exchar)
				buffer[--ind] = exchar;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == '')
		{
			if (exchar)
				buffer[--ind] = exchar;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (exchar)
				buffer[--pad_st] = exchar;
			return (write(1, &buffer[pad_st], i - pad_st) + write(1, &buffer[ind], len - (1 - pad-st)));
		}
	}
	if (exchar)
		buffer[--ind] = exchar;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsigned - prints unsigned num
 * @is_neg: shows negative num
 * @ind: index
 * @buffer: char array
 * @flags: specifies flags
 * @width: specifies width
 * @precision: specifies precision
 * @size: specifies size
 * Return: written number of chars
 */

int write_unsigned(int is_neg, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int len2 = BUFF_SIZE - ind - 1;
	int i;
	char pad = '';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < len2)
		pad = '';
	while (precision > len2)
	{
		buffer[--ind] = '0';
		len2++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (width > len2)
	{
		for (i = 0; 1 < width - len2; i++)
			buffer[i] = pad;
		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len2) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len2));
		}
	}
	return (write(1, &buffer[ind], len2));
}

/**
 * write_ptr - prints a memory address
 * @buffer: char of array
 * @ind: index
 * @len: number length
 * @width: specifies width
 * @flags: specifies flags
 * @pad: reps padding
 * @extra: extra char
 * @pad_start: padding start
 * @Return: number of chars written
 */

int write_ptr(char buffer[], int ind, int len, int width, int flags, char pad, char extra, int pad_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == '')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra)
				buffer[--ind] = extra;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pad == '')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra)
				buffer[--ind] = extra;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && pad == '\0')
		{
			if (extra)
				buffer[--pad_start] = extra;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) + write(1, &buffer[ind], len - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra)
		buffer[--ind] = extra;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
}
