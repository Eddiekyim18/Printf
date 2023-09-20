#include "main.h"

/**
 * get_precision - Knowing the precision
 * @format: string argument
 * @i: current fmt string
 * @list: Argument list
 * Return: eachtime precision
 */


int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
	{
		return (precision);
	}

	precision = 0;
	curr_i++;

	while (format[curr_i] != '\0')
	{
		if (isdigit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
			curr_i++;
		} else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}

		*i = curr_i - 1;

		return (precision);
	}

