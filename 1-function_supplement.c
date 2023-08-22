#include "main.h"

/**
* unsigned_int_length - this function calculates the length of
* an unsigned integer.
* @integer: memeber parameter for which the value is to be known.
* Return:the length of the integer.
*/

int unsigned_int_length(unsigned int integer)
{
	int total_count = 0;

	if (integer == 0)
	{
		return (1);
	}

	do {
		integer = (integer / 10);
		total_count += 1;
	} while (integer > 0);

	return (total_count);
}

/**
* octal_length - this function calculates the length of
* unsigned octal integer.
* @integer: memebre parameter for which the value is to be known.
* Return: the total count of the integer.
*/

int octal_length(unsigned int integer)
{
	int total_count = 0;

	if (integer == 0)
	{
		return (1);
	}

	do {
		integer = (integer / 8);
		total_count += 1;
	} while (integer > 0);

	return (total_count);
}

/**
* hexadex_length - this function calculates the length of an hexadecimal
* @integer: memebre parameter for which the value is to be known.
* Return: the length of the hexadeciaml.
*/

int hexadex_length(unsigned int integer)
{
	int total_count = 0;

	if (integer == 0)
	{
		return (1);
	}

	do {
		integer = (integer / 16);
		total_count += 1;
	} while (integer > 0);

	return (total_count);
}
