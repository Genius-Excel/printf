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
