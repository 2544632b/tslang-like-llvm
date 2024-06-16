#pragma once

#include <map>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} type_string;

// typedef struct type_map = std::map<type_string, type_string>;

extern "C" void map_put(void* map, type_string* key, type_string* value);