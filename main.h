#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
 * struct fmt - Struct op.
 *
 * @fmt: Format.
 * @fn: Function  associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int);
};

/**
 * typedef struct fmt fmt_t - ...
 *
 * @fmt: Format.
 * @fm_t: Function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_put(const char *fmt, int *j, va_list list, char buffer[],
int flag, int width, int precision, int size);

int put_char(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_string(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_percent(va_list type, char buffer[],
int flag, int width, int precision, int size);

int put_int(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_binary(va_list type, char buffer[],
int flags, int width, int precision, int size);

int put_int(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_binary(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_unsigned(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_octal(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_hexadecimal(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_hexa_upper(va_list type, char buffer[],
int flag, int width, int precision, int size);
int put_hexa(va_list type, char map_to[],
char buffer[], int flag, char flag_ch, int width, int precision, int
size);

int put_non_printable(va_list type, char buffer[],
int flag, int width, int precision, int size);

int put_pointer(va_list types, char buffer[],
int flag, int width, int precision, int size);

int get_flag(const char *format, int *j);
int get_width(const char *format, int *j, va_list list);
int get_precision(const char *format, int *j, va_list list);
int get_size(const char *format, int *j);

int put_reverse(va_list type, char buffer[],
int flag, int width, int precision, int size);

int put_rot13string(va_list typr, char buffer[],
int flag, int width, int precision, int size);

int handle_write_char(char a, char buffer[],
int flag, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flag, int width, int precision, int size);
int write_num(int ind, char bff[], int flag, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flag, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[], int flag, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
