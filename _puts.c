#include "main.h"

void put_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function.
 * @format: The format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, put = 0, put_chars = 0;
	int flag, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
	if (format[j] != '%')
	{
	buffer[buff_ind++] = format[j];
	if (buff_ind == BUFF_SIZE)
	put_buffer(buffer, &buff_ind);
	put_chars++;
	}
	else
	{
	put_buffer(buffer, &buff_ind);
	flag = get_flag(format, &j);
	width = get_width(format, &j, list);
	precision = get_precision(format, &j, list);
	size = get_size(format, &j);
	++j;
	put = handle_put(format, &j, list, buffer, flag, width, precision, size);
	if (put == -1)
	return (-1);
	put_chars += put;
	}
	}

	put_buffer(buffer, &buff_ind);

	va_end(list);

	return (put_chars);
}

/**
 * put_buffer - Program that prints the contents of the buffer if it exit.
 * @buffer: The array of chars
 * @buff_ind: The index at which to add next char, represents the length.
 */
void put_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
