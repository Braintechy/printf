#include "main.h"

/**
 * get_width - Program that calc the width for puting.
 * @format: The formatted string in which to put the argument.
 * @j: The list of argument to be putted.
 * @list: The list of argument.
 *
 * Return: Width.
 */
int get_width(const char *format, int *j, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *j + 1; format[curr_i] != '\0'; curr_i++)
	{
	if (is_digit(format[curr_i]))
	{
	width *= 10;
	width += format[curr_i] - '0';
	}
	else if (format[curr_i] == '*')
	{
	curr_i++;
	width = va_arg(list, int);
	break;
	}
	else
	break;
	}

	*j = curr_i - 1;

	return (width);
}
