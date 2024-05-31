#include "type_io.h"

type_string *integer2string(long number) {
    size_t capacity = type_string_get_capacity_with_size(20);
    type_string *str = type_string_create_with_capacity(capacity);
    snprintf(str->buffer, 20, "%ld", number);
    str->size = strlen(str->buffer);
    return str;
}

type_string *float2string(double number) {
    size_t capacity = type_string_get_capacity_with_size(20);
    type_string *str = type_string_create_with_capacity(capacity);
    snprintf(str->buffer, 20, "%lf", number);
    str->size = strlen(str->buffer);
    return str;
}

long string2integer(type_string *str) {
    return strtol(str->buffer, NULL, 10);
}

double string2float(type_string *str) {
    return strtod(str->buffer, NULL);
}

void print_number(long number) {
    printf("%ld", number);
}

void print_number_ln(long number) {
    printf("%ld\n", number);
}

void print_double(double number) {
    printf("%f", number);
}

void print_double_ln(double number) {
    printf("%f\n", number);
}

void print_string(type_string *str) {
    printf("%s", str->buffer);
}

void print_string_ln(type_string *str) {
    printf("%s\n", str->buffer);
}