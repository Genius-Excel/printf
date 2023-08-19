#include "main.h"
#include <stdio.h>

/**
* main - this is the main function that calls the _print funtion
* Return: number of characters printed
*/

int main(void)
{
	char *project = "Printf project";
	char *hobby = "Programming!";
	int my_printf = _printf("Hello this is my %s, I love %s 100%%", project, hobby);

	printf("Total characters %d\n", my_printf);

	return (0);
}
