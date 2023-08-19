#include "main.h"
#include <unistd.h>

/**
* _putchar - this function prints the character value at the address
* of the parameter c to the standard output
* @c: member parameter of the function to be returned as a char;
* Return: the value of the argument passed to the function in standard output
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
