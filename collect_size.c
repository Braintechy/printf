#include "main.h"

/**
 * get_size - Program that calc the size tom cast the argument.
 * @format: The formatted string in which to put the arguments
 * @j: The list of argument.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *j)
{
	int curr_i = *j + 1;
	int size = 0;

	if (format[curr_i] == '1')
	size = S_LONG;
	else if (format[curr_i] == 'h')
	size = S_SHORT;

	if (size == 0)
	*j = curr_i - 1;
	else
	*j = curr_i;
	return (size);
}
