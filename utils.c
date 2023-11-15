#include "main.h"

/**
 * is_printable - Program that handle ...
 * @a: ...
 *
 * Return: ....
 */
int is_printable(char a)
{
	if (a >= 32 && a < 127)
	return (1);

	return (0);
}

/**
 * append_hexa_code - ...
 * @buffer: ...
 * @j: ...
 * @ascii_code: ...
 * Return: ...
 */
int append_hexa_code(char ascii_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	ascii_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[ascii_code / 16];
	buffer[j] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - ...
 * @a: ...
 *
 * Return: ...
 */
int is_digit(char a)
{
	if (a >= '0' && a <= '9')
	return (1);

	return (0);
}

/**
 * convert_size_number - ...
 * @num: ...
 * @size: ...
 *
 * Return: ...
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size == S_SHORT)
	return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - ...
 * @num: ...
 * @size: ...
 *
 * Return: ...
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size == S_SHORT)
	return ((unsigned short)num);

	return ((unsigned int)num);
}
