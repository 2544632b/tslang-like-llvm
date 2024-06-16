#pragma once

#include <iostream>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} type_string;

extern "C" type_string* get_string();