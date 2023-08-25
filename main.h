#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_str(char *str);
int print_char(char c);
int print_int (int n);
int convert_to_binary(unsigned int a);


#endif
