#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - it matches the conversion of specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: it types pointer to function for the conversion of specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_bin(va_list val);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int printf_37(void);
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);
<<<<<<< HEAD
=======
int hndl_print(const char *fmt, int *ind, va_list list,char buffer[], int wodth, int precision, int size);

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char 
flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *format, int *g);
int get_width(const char *format, int *t, va_list list);
int cal_precision(const char *format, int *t, va_list list);
int cal_size(const char *format, int *g);

int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

int handle_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_num(int is_neg, int ind, char buffer[], int flags, int width, int precision, int size);
int write_nos(int ind,char bff[], int flags, int width, int precision, int len, char pad, char exchar);
int write_ptr(char buffer[], int ind, int len, int width, int flags, char pad, char extra, int pad_start);
int write_unsigned(int is_neg, int ind, char buffer[], int flags, int width, int precision, int size);

int printable(char);
int add_hexa_code(char, char[], int);
int is_digit(char);
long int size_number(long int num, int size);
long int size_unsigned(unsigned long int num, int size);
>>>>>>> 2abe389a74d1b79e6af6cb061afa2686aff716a5

#endif

