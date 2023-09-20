#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int characters_printed = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			characters_printed++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				characters_printed++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				characters_printed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str != NULL)

				{
					int str_len = 0;

				while (str[str_len] != '\0')
						str_len++;
					write(1, str, str_len);
					characters_printed += str_len;
				}
				else
				{
					write(1, "(null)", 6);
					characters_printed += 6;
				}
			}
			format++;
		}
	}
	va_end(args);
	return (characters_printed);
}

