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

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '\0')
		{
			break;
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

				_putchar(character_val);
				char_print_counter += 1;
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

				/** counts the total number of characters printed fron the string array.**/

				while (*string_arr != '\0')
				{
					arr_len += 1;
					string_arr += 1;
				}

				char_print_counter += arr_len;
			}
			else if (format[i] == 'd')
			{
				int integer_val = va_arg(format_specifier_args, int);

				_print_integer(integer_val);
				if (integer_val < 0)
				{
					char_print_counter += 2;
				}
				else
				{
					char_print_counter += 1;
				}
			}
			else if (format[i] == 'i')
			{
				int decimal_val = va_arg(format_specifier_args, int);

				_print_integer(decimal_val);
				/**checks if number is negative to count the '-' sign **/
				if (decimal_val < 0)
				{
					char_print_counter += 2;
				}
				else
				{
					char_print_counter += 1;
				}
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
* _print_integer - this function prints the integer value
* passed as argument
* @integer: member parameter for the integer
* Return: void
*/

void _print_integer(int integer)
{
	int int_idx = 0;

	char *integer_arr;

	int integer_arr_len = 0;

	int integer_inst;

	if (integer < 0)
	{
		_putchar('-');
		integer = -(integer);
	}

	if (integer == 0)
	{
		_putchar('0');
		return;
	}

	integer_inst = integer;

	do {
		integer_inst = integer_inst / 10;
		integer_arr_len += 1;
	} while (integer_inst > 0);

	integer_arr = (char *)malloc(integer_arr_len + 1);

	if (integer_arr == NULL)
	{
		return;
	}

	for (int_idx = (integer_arr_len - 1); int_idx >= 0; int_idx--)
	{
		integer_arr[int_idx] = (integer % 10) + '0';
		integer = integer / 10;
	}

	integer_arr[integer_arr_len] = '\0';

	for (int_idx = 0; int_idx < integer_arr_len; int_idx++)
	{
		_putchar(integer_arr[int_idx]);
	}

	free(integer_arr);
}
