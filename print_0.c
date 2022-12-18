#include "main.h"

/**
* print_char - Prints a char
*
* @types: args list
* @buffer: string array for printing
* @flags: handles flags
* @width: handles width
* @precision: specifies precision
* @size: specifies size
*
* Return: no of characters printed
*/

int print_char(va_list types, char buffer[], int flags, int width,
               int precision, int size)
{
        char c = va_arg(types, int);

r eturn (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
* print_string - prints a string
*
* @types: args list
* @buffer: string array for printing
* @flags: handles flags
* @width: handles width
* @precision: specifies precision
* @size: specifies
*
* Return: no of characters printed
*/

int print_string(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
int length = 0, i;
char *str = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}

while (str[length] != '\0')
length++;

if (precision >= 0 && precision < length)
length = precision;

if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}

for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}

return (write(1, str, length));
}
