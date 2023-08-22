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
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '\0')
		{
			char_print_counter -= 1;
			return (-1);
		}
		else if (format[i] == '%')
		{
			i += 1;

			if (format[i] == '%')
			{
				_putchar('%');
				char_print_counter += 1;
			}
			else if (format[i] == 'c')
			{
				char character_val = va_arg(format_specifier_args, int);

				if (character_val)
				{
					_putchar(character_val);
					char_print_counter += 1;
				}
				else
				{
					exit(1);
				}
			}
			else if (format[i] == 's')
			{
				char *string_arr = va_arg(format_specifier_args, char *);

				int str_idx = 0;

				int arr_len = 0;

				for (str_idx = 0; string_arr[str_idx] != '\0'; str_idx++)
				{
					_putchar(string_arr[str_idx]);
				}

				/* counts the total number of characters printed fron the string array.*/

				while (*string_arr != '\0')
				{
					arr_len += 1;
					string_arr += 1;
				}

				char_print_counter += arr_len;
			}
			else if (format[i] == 'i')
			{
				int int_len = 0;
				int integer_val = va_arg(format_specifier_args, int);

				if (!(integer_val))
				{
					return (-1);
				}

				int_len = _integer_length(integer_val);
				char_print_counter += int_len;

				_print_integer(integer_val);
			}
			else if (format[i] == 'd')
			{
				int dec_len = 0;
				int decimal_val = va_arg(format_specifier_args, int);

				if (!(decimal_val))
				{
					return (-1);
				}

				dec_len = _integer_length(decimal_val);
				_print_integer(decimal_val);
				char_print_counter += dec_len;
			}
		}
		else
		{
			_putchar(format[i]);
			char_print_counter += 1;
		}
	}

	va_end(format_specifier_args);

	return (char_print_counter);
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
 * _print_integer - this function prints the integer value
 * passed as argument
 * @integer: member parameter for the integer
 * Return: void
 */

void _print_integer(int integer)
{
	int int_idx = 0;

	int integer_arr_len = 0;

	char *integer_arr;

	integer_arr_len = _integer_length(integer);

	if (integer == 0)
	{
		_putchar('0');
		return;
	}

	integer_arr = (char *)malloc(integer_arr_len + 1);

	if (integer_arr == NULL)
	{
		return;
	}

	if (integer < 0)
	{
		_putchar('-');
		integer = -(integer);
	}

	for (int_idx = (integer_arr_len - 1); int_idx >= 0; int_idx--)
	{
		integer_arr[int_idx] = (integer % 10) + '0';
		integer = integer / 10;
	}

	for (int_idx = 0; int_idx < integer_arr_len; int_idx++)
	{
		_putchar(integer_arr[int_idx]);
	}

	free(integer_arr);
}
