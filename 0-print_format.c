#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - this function takes number of consequential arguments
 * and prints the value of the argument recived to stndard output
 * it orks just like the printf function in the stadard library.
 * @format: memeber parameter of the function that specifies the format
 * of the string array passed to it and how it should be
 * printed to standard output.
 * Return: the value of the passed arguments and
 * the number of characers printed.
 */

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
int i;

int char_print_counter = 0;

va_list format_specifier_args;

va_start(format_specifier_args, format);

if (format == NULL)
{
return (-1);
}
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[i], 1);*/
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
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

/**
 * _integer_length - this function is a supplement to
 * assist in counting the lenght of the digits
 * @integer: member parameter for which the length is to be known
 * Return: the value of the actual lenght
 */

int _integer_length(int integer)
{
int actual_length = 0;

if (integer == 0)
{
return (1);
}

if (integer < 0)
{
actual_length += 1;
integer = -(integer);
}

do {
actual_length += 1;
integer /= 10;
} while (integer > 0);

return (actual_length);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}
