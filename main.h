#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#define BUFFER_SIZE 1024

int binary_counter(int value);
void convert_to_binary(unsigned int decimal);
int _putchar(char c);

int _printf(const char *format, ...);
void _print_integer(int integer);
int _integer_length(int integer);

void _print_unsigned_int(unsigned int integer);
void _print_octal_int(unsigned int integer);
void _print_hex_form(unsigned int integer, bool char_case);

int octal_length(unsigned int integer);
int hexadex_length(unsigned int integer);
int unsigned_int_length(unsigned int integer);

#endif
