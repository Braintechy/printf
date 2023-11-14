#include "main.h"

/**
 * get_flag - Program that calc active flag.
 * @format: The formatted string in which to put the arguments.
 * @j: The take a param.
 * Return: Flag.
 */
int get_flag(const char *format, int *j)
{
	int i, curr_i;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE,
	0};

	for (curr_i = *j + 1; format[curr_i] != '\0'; curr_i++)
	{
	for (i = 0; FLAG_CH[i] != '\0'; i++)
	if (format[curr_i] == FLAG_CH[i])
	{
	flag |= FLAG_ARR[i];
	break;
	}
	if (FLAG_CH[i] == 0)
	break;
	}

	*j = curr_i - 1;

	return (flag);
}
