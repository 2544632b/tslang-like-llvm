#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "type_string.h"

type_string *integer2string(long number);

type_string *integer2ascii(long number);

type_string *float2string(double number);

long string2integer(type_string *str);

double string2float(type_string *str);

void print_number(long number);

void print_number_ln(long number);

void print_float(double number);

void print_float_ln(double number);

void print_string(type_string *str);

void print_string_ln(type_string *str);

void print_ln();