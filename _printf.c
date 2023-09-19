#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char *buffer, int *buff_ind);
void append_char(char **buffer, int *buff_ind, char c);

int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char *buffer = (char *)malloc(BUFF_SIZE * sizeof(char));

if (format == NULL || buffer == NULL)
{
free(buffer);
return (-1);
}

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
append_char(&buffer, &buff_ind, format[i]);
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, &buffer,
flags, width, precision, size);
if (printed == -1)
{
free(buffer);
va_end(list);
return (-1);
}
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
free(buffer);
va_end(list);
return (printed_chars);
}

void append_char(char **buffer, int *buff_ind, char c)
{
if (*buff_ind < BUFF_SIZE - 1)
{
(*buffer)[(*buff_ind)++] = c;
}
else
{
print_buffer(*buffer, buff_ind);
(*buffer)[(*buff_ind)++] = c;
}
}
