#include "main.h"

/**
 * put_char - Program that will put a char.
 * @type: The list a of arguments.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of char put.
 */
int put_char(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	char a = va_arg(type, int);

	return (handle_write_char(a, buffer, flag, width, precision,
	size));
}

/**
 * put_string - Program that put a string.
 * @type: The list a of arguments.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put.
 */
int put_string(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	int length = 0, j;
	char *str = va_arg(type, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
	str = "(null)";
	if (precision >= 6)
	str = "     ";
	}

	while (str[length] != '\0')
	length++;

	if (precision >= 0 && precision < length)
	length = precision;

	if (width > length)
	{
	if (flag & F_MINUS)
	{
	write(1, &str[0], length);
	for (j = width - length; j > 0; j--)
	write(1, " ", 1);
	return (width);
	}
	else
	{
	for (j = width - length; j > 0; j--)
	write(1, " ", 1);
	write(1, &str[0], length);
	return (width);
	}
	}

	return (write(1, str, length));
}

/**
 * put_percent - Program thhat put a percent sign.
 * @type: The list of arguments.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put.
 */
int put_percent(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	UNUSED(type);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * put_int - Program that put int.
 * @type: The list of argument.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of chars put.
 */
int put_int(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(type, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
	num = (unsigned long int)((-1) * n);
	is_negative = 1;
	}

	while (num > 0)
	{
	buffer[j--] = (num % 10) + '0';
	num /= 10;
	}

	j++;

	return (write_number(is_negative, j, buffer, flag, width,
precision, size));
}

/**
 * put_binary - Program that put an unsigned number.
 * @type: The list of arguments.
 * @buffer: The buffer array to handle put.
 * @flag: Calc active flag.
 * @width: Get width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: Number of char put.
 */
int put_binary(va_list type, char buffer[],
int flag, int width, int precision, int size)
{
	unsigned int n, m, j, sum;
	unsigned int c[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(type, unsigned int);
	m = 2147483648;
	c[0] = n / m;
	for (j = 1; j < 32; j++)
	{
	m /= 2;
	c[j] = (n / m) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
	sum += c[j];
	if (sum || j == 31)
	{
	char z = '0' + c[j];

	write(1, &z, 1);
	count++;
	}
	}
	return (count);
}

