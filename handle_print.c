#include "main.h"

/**
 * handle_put - Program that put an argument.
 * @fmt: ...
 * @list: ...
 * @ind: ...
 * @buffer: ...
 * @flag: ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: 1 or 2;
 */
int handle_put(const char *fmt, int *ind, va_list list, char buffer[],
int flag, int width, int precision, int size)
{
	int j, unknow_len = 0, put_chars = -1;
	fmt_t fmt_type[] = {
	{'c', put_char}, {'s', put_string}, {'%', put_percent},
	{'i', put_int}, {'d', put_int}, {'b', put_binary},
	{'u', put_unsigned}, {'o', put_octal}, {'x', put_hexadecimal},
	{'X', put_hexa_upper}, {'p', put_pointer}, {'S', put_non_printable},
	{'r', put_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (j = 0; fmt_type[j].fmt != '\0'; j++)
	if (fmt[*ind] == fmt_type[j].fmt)
	return (fmt_type[j].fn(list, buffer, flag, width,
	precision, size));

	if (fmt_type[j].fmt == '\0')
	{
	if (fmt[*ind] == '\0')
	return (-1);
	unknow_len += write(1, "%%", 1);
	if (fmt[*ind - 1] == ' ')
	unknow_len += write(1, " ", 1);
	else if (width)
	{
	--(*ind);
	while (fmt[*ind] != ' ' && fmt[*ind] != '%')
	--(*ind);
	if (fmt[*ind] == ' ')
	--(*ind);
	return (1);
	}
	unknow_len += write(1, &fmt[*ind], 1);
	return (unknow_len);
	}
	return (put_chars);
}
