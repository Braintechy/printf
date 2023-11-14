#include "main.h"

/**
 * handle_write_char - ...
 * @a: ...
 * @buffer: ...
 * @flag: ...
 * @width: ...
 * @precision: ...
 * @size: ...
 *
 * Return: ...
 */
int handle_write_char(char a, char buffer[],
int flag, int width, int precision, int size)
{
	int j = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & F_ZERO)
	padd = '0';

	buffer[j++] = a;
	buffer[j] = '\0';

	if (width > 1)
	{
	buffer[BUFF_SIZE - 1] = '\0';
	for (j = 0; j < width - 1; j++)
	buffer[BUFF_SIZE - j - 2] = padd;

	if (flag & F_MINUS)
	return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
	else
	return (write(1, &buffer[BUFF_SIZE - j - 1], width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - ...
 * @is_negative: ...
 * @ind: ...
 * @buffer: ...
 * @flag: ...
 * @width: ...
 * @precision: ...
 * @size: ....
 *
 * Return: ...
 */
int write_number(int is_negative, int ind, char buffer[],
int flag, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
	padd = '0';
	if (is_negative)
	extra_ch = '-';
	else if (flag & F_PLUS)
	extra_ch = '+';
	else if (flag & F_SPACE)
	extra_ch = ' ';

	return (write_num(ind, buffer, flag, width, precision,
	length, padd, extra_ch));
}

/**
 * write_num - ...
 * @ind: ...
 * @buffer: ...
 * @flag: ...
 * @width: ...
 * @prec: ...
 * @length: ...
 * @padd: ...
 * @extra_c: ...
 *
 * Return: ...
 */
int write_num(int ind, char buffer[],
int flag, int width, int prec, int length, char padd, char extra_c)
{
	int j, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width
	== 0)
	return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	buffer[ind] = padd = ' ';

	if (prec > 0 && prec < length)
	padd = ' ';
	while (prec > length)
	buffer[--ind] = '0', length++;
	if (extra_c != 0)
	length++;
	if (width > length)
	{
	for (j = 1; j < width - length + 1; j++)
	buffer[j] = padd;
	buffer[j] = '\0';
	if (flag & F_MINUS && padd == ' ')
	{
	if (extra_c)
	buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length) + write(1,
	&buffer[1], j - 1));
	}
	else if (!(flag & F_MINUS) && padd == ' ')
	{
	if (extra_c)
	buffer[--ind] = extra_c;
	return (write(1, &buffer[1], j - 1) + write(1,
	&buffer[ind], length));
	}
	else if (!(flag & F_MINUS) && padd == '0')
	{
	if (extra_c)
	buffer[--padd_start] = extra_c;
	return (write(1, &buffer[padd_start], j - padd_start) +
	write(1, &buffer[ind], length - (1 - padd_start)));
	}
	}
	if (extra_c)
	buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - ...
 * @is_negative: ...
 * @ind: ...
 * @buffer: ...
 * @flag: ...
 * @width: ...
 * @precision: ...
 * @size: ...
 *
 * Return: ...
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
int flag, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, j = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	return (0);

	if (precision > 0 && precision < length)
	padd = ' ';

	while (precision > length)
	{
	buffer[--ind] = '0';
	length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
	padd = '0';

	if (width > length)
	{
	for (j = 0; j < width - length; j++)
	buffer[j] = padd;

	buffer[j] = '\0';

	if (flag & F_MINUS)
	{
	return (write(1, &buffer[ind], length) + write(1,
	&buffer[0], j));
	}
	else
	{
	return (write(1, &buffer[0], j) + write(1, &buffer[ind],
	length));
	}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - ...
 * @buffer: ...
 * @ind: ...
 * @length: ...
 * @width: ...
 * @flag: ...
 * @padd: ...
 * @extra_c: ...
 * @padd_start: ...
 *
 * Return: ...
 */
int write_pointer(char buffer[], int ind, int length,
int width, int flag, char padd, char extra_c, int padd_start)
{
	int j;

	if (width > length)
	{
	for (j = 3; j < width - length + 3; j++)
	buffer[j] = padd;
	buffer[j] = '\0';
	if (flag & F_MINUS && padd == ' ')
	{
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
	buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length) + write(1,
	&buffer[3], j - 3));
	}
	else if (!(flag & F_MINUS) && padd == ' ')
	{
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
	buffer[--ind] = extra_c;
	return (write(1, &buffer[3], j - 3) + write(1,
	&buffer[ind], length));
	}
	else if (!(flag & F_MINUS) && padd == '0')
	{
	if (extra_c)
	buffer[--padd_start] = extra_c;
	buffer[1] = '0';
	buffer[2] = 'x';
	return (write(1, &buffer[padd_start], j - padd_start) +
	write(1, &buffer[ind], length - (1 - padd_start) - 2));
	}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
	buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
