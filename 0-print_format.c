#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...);

/**
* _printf - this function takes number of consequential arguments
* and prints the value of the argument recived to stndard output
* it orks just like the printf function in the stadard library.
* @format: memeber parameter ofthe function that specifies the format
* of the string array passed to it and how it should be printed in standard
* output.
* Return: the value of the passed arguments and the number of characers printed.
*/


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
			char_print_counter -= 1;
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
