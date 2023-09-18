#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: format
 * @fn: associated function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: format
 * @fm_t: associated function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list,char buffer[], int wodth, int precision, int size);

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
int get_precision(const char *format, int *t, va_list list);
int get_size(const char *format, int *g);

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

#endif
