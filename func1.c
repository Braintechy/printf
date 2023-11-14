#include "main.h"

/**
 * put_unsigned - Program that put an unsigned number.
 * @type: The list of argument.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put.
 */
int put_unsigned(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
	buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[j--] = (num % 10) + '0';
	num /= 10;
	}

	j++;
	return (write_unsgnd(0, j, buffer, flag, width, precision, size));
}

/**
 * put_octal - Program that put an unsigned number in octalnotation.
 * @type: The list of argument.
 * @buffer: The buffer array to handle pu.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put.
 */
int put_octal(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[j--] = (num % 8) + '0';
	num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
	buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flag, width, precision, size));
}

/**
 * put_hexadecimal - Program that put an unsigned number in hexadecimal notation.
 * @type: The list of arument.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put
 */
int put_hexadecimal(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	return (put_hexa(type, "0123456789abcdef", buffer,
flag, 'x', width, precision, size));
}

/**
 * put_hexa_upper - Program that put an unsigned number in upper hexadecimal
 * notation.
 * @type: The list of argument.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put.
 */
int put_hexa_upper(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	return (put_hexa(type, "0123456789ABCDEF", buffer,
flag, 'x', width, precision, size));
}

/**
 * put_hexa - Program that put a hexadecimal number in lower or upper
 * @type: The list of argument.
 * @map_to: The array of values to map the number to.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @flag_ch: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * @size: The size specification.
 * Return: Number of char put.
 */
int put_hexa(va_list type, char map_to[], char buffer[],
int flag, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
	buffer[j--] = map_to[num % 16];
	num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
	buffer[j--] = flag_ch;
	buffer[j--] = '0';
	}
	j++;
	return (write_unsgnd(0, j, buffer, flag, width, precision, size));
}
