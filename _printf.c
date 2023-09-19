#include "main.h"
int _printf(const char *format, ...);
{
int character_print = 0;
va_list eddie_arg;

if (format == NULL)
return (-1);

va_start(eddie_arg, format);

while (*format)
{
if (*format != '%')
{
write(1, format, 1);
character_print++;
}
else
{
format++;
if (*format == '\0')
break;

if (*format == '%')
{
write(1, format, 1);
character_print++;
}

else if (format == 'c')
{
char c = va_arg(eddie_arg, int);
write(1, &c, 1);
character_print++;
}

else if (format == 's')
{
char *str va_arg(eddie_arg, char*);
int str_len = 0
while (str(str_len) != '0')
str_len++;
write(1, str, str_len);
character_print += str_len;
}
format++;
}
va_end(eddie_arg);
}
return (character_print++);
}

int main(void)
{
_printf("Leo\n");
_printf("%c\n", 'v');
_printf("%s\n", "string");
_printf("%%/n");

return (0);
}
