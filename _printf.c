#include "nain.h"

int print_char(int c)
{
return (write(1, &c, 1));
}

int print_str(const char *str)
{
int char_count = 0;
while (*str)
{
char_count += print_char(*str);
str++;
}
return (char_count);
}

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int char_count = 0;
while (*format)
{
if (*format == '%')
{
format++; '%'
switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
char_count += print_char(c);
break;
}
case 's':
{
const char *str = va_arg(args, const char *);
char_count += print_str(str);
break;
}
case '%':
{
char_count += print_char('%');
break;
}
default:
{
break;
}
}
}
else
{
char_count += print_char(*format);
}
format++;
}

va_end(args);
return (char_count);
}

int main(void)
}
int count = _printf("Hello, %s! The answer is %d%%\n", "world", 42);
printf("Total characters printed: %d\n", count);
return (0);
}

