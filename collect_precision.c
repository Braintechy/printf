#include "main.h"

/**
 * get_precision - Program that calc the precision for printing.
 * @format: The formatted string in which to put the argument.
 * @j: The list of argument to be put.
 * @list: The list of argument.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *j, va_list list)
{
	int curr_i = *j + 1;
	int precision = -1;

	if (format[curr_i] != '.')
	return (precision);
	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
	if (is_digit(format[curr_i]))
	{
	precision *= 10;
	precision += format[curr_i] - '0';
	}
	else if (format[curr_i] == '*')
	{
	curr_i++;
	precision = va_arg(list, int);
	break;
	}
	else
	break;
	}

	*j = curr_i - 1;
	return (precision);
}
