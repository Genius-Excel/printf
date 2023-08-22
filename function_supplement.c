#include "main.h"

/**
 * convert_to_binary - this function takes an integer as argument
 * and converts the integer to binary.
 * @decimal: member parameter for the integer to be converted
 * Return: void
 */

void convert_to_binary(unsigned int decimal)
{
	int binary_arr[32];

	int i = 0;

	int j = 0;

	if (decimal == 0)
	{
		_putchar('0');
		return;
	}

	do {
		binary_arr[i] = decimal % 2;
		decimal = (decimal / 2);
		i += 1;
	} while (decimal > 0);


	for (j = (i - 1); j >= 0; j--)
	{
		_putchar('0' + binary_arr[j]);
	}
}

/**
 * binary_counter - this function counts the number printed in binary
 * @value: binary value to be counted
 * Return: the vlue ofthe total count.
 */


int binary_counter(int value)
{
	int total_count = 0;

	if (value == 0)
	{
		return (1);
	}

	do {
		value = (value / 2);
		total_count += 1;
	} while (value > 0);

	return (total_count);
}

/**
* _print_unsigned_int - this function prints unsigned int to
* to standard output using the _putchar function
* @integer: memeber parameter for the unsigned integer
* Return: void
*/

void _print_unsigned_int(unsigned int integer)
{
	char buffer[BUFFER_SIZE];

	int buff_idx = 0;

	int i = 0;

	if (integer == 0)
	{
		_putchar('0');
		return;
	}

	do {
		buffer[buff_idx] = '0' + (integer % 10);
		integer = integer / 10;
		buff_idx += 1;
	} while (integer > 0);

	for (i = (buff_idx - 1); i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
}

/**
* _print_octal_int - this function prunts in octal
* @integer: memeber parameter for the function
* Return: void
*/

void _print_octal_int(unsigned int integer)
{
	char buffer[BUFFER_SIZE];

	int buff_idx = 0;

	int i = 0;

	if (integer == 0)
	{
		_putchar('0');
		return;
	}

	do {
		buffer[buff_idx] = '0' + (integer % 8);
		integer = (integer / 8);
		buff_idx += 1;
	} while (integer > 0);

	for (i = (buff_idx - 1); i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
}

/**
* _print_hex_form - tis function prints in hexadecimal format
* @integer: memeber parameter for the function
* @char_case: this is to know if it is in upper or lower case
* Return: void
*/

void _print_hex_form(unsigned int integer, bool char_case)
{
	char buffer[BUFFER_SIZE];

	int buff_idx = 0;

	int i = 0;

	char hex_lower[] = "0123456789abcdef";

	char hex_upper[] = "0123456789ABCDEF";

	char *hexadex;

	if (integer == 0)
	{
		_putchar('0');
		return;
	}

	if (char_case == true)
	{
		hexadex = hex_upper;
	}
	else
	{
		hexadex = hex_lower;
	}

	do {
		buffer[buff_idx] = hexadex[integer % 16];
		integer = integer / 16;
		buff_idx += 1;
	} while (integer > 0);

	for (i = (buff_idx - 1); i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
}
