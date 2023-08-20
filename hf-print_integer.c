#include "main.h"

/**
* _print_integer - this function prints numbers to the standard
* output.
* @integer: integer to be printed to standard output
* Return: void
*/

void _print_integer(int integer)
{
	if (integer < 0)
	{
		_putchar('-');
		integer = -(integer);
	}

	if (integer / 10)
	{
		_print_integer(integer / 10);
	}

	_putchar((integer % 10) + 48);
}
