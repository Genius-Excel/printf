#include "main.h"
#include <stdarg.h>

/**
* _printf - this function takes format specifiers as subsequential
* arguments and prints them to standard output the retrun the number
* of characters printed.
* @format: format specifier for which the passed argument is to be printed
* Return: the total number of characters printed
*/

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
	int char_print_counter = 0;

	int i;

	va_list format_specifier_args;

	va_start(format_specifier_args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i += 1;

			if (format[i] == 'd')
			{
				int decimal_val = va_arg(format_specifier_args, int);

				_print_integer(decimal_val);
				/**checks if integer is negative to count the '-' sign**/
				if (decimal_val < 0)
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
				int integer_val = va_arg(format_specifier_args, int);

				_print_integer(integer_val);

				/**checks if the number printed is negative to count '-' sign **/
				if (integer_val < 0)
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
