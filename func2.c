#include "main.h"

/**
 * put_pointer - Program that put the value of a pointer variable.
 * @type: The list of argument.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put.
 */
int put_pointer(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
	return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
	buffer[ind--] = map_to[num_addrs % 16];
	num_addrs /= 16;
	length++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
	padd = '0';
	if (flag & F_PLUS)
	extra_c = '+', length++;
	else if (flag & F_SPACE)
	extra_c = ' ', length++;

	ind++;
	return (write_pointer(buffer, ind, length,
	width, flag, padd, extra_c, padd_start));
}

/**
 * put_non_printable - Program that put ascii cods in hexa of non printable chars
 * @type: The list of argument.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * @Return: Number ofchars put.
 */
int put_non_printable(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
	if (is_printable(str[j]))
	buffer[j + offset] = str[j];
	else
	offset += append_hexa_code(str[j], buffer, j + offset);

	j++;
	}

	buffer[j = offset] = '\0';

	return (write(1, buffer, j + offset));
}

/**
 * put_reverse - Program that put reverse string.
 * @type: The list of argument.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Numbers of chars put.
 */
int put_reverse(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(type, char *);

	if (str == NULL)
	{
	UNUSED(precision);

	str = ")NULL(";
	}
	for (j = 0; str[j]; j++)
	;
	for (j = j - 1; j >= 0; j--)
	{
	char z = str[j];

	write(1, &z, 1);
	count++;
	}
	return (count);
}

/**
 * put_rol13string - Program that put a string in rot13.
 * type: The list of arguments.
 * @buffer: The buffer array to handle put.
 * @flag: Calx active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * @Return: Number of chars put.
 */
int put_rot13string(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int j, i;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	str = "(AHYY)";
	for (j = 0; str[j]; j++)
	{
	for (i = 0; in[i]; i++)
	{
	if (in[i] == str[j])
	{
	x = out[i];
	write(1, &x, 1);
	count++;
	break;
	}
	}
	if (!in[i])
	{
		x = str[j];
		write(1, &x, 1);
		count++;
	}
	}
	return (count);
}
