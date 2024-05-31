#pragma once

#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} type_string;

static size_t type_string_get_capacity_with_size(size_t size) {
    if (size == 0) {
        return 16;
    } else if (size < 16) {
        return 32;
    } else if (size < 32) {
        return 48;
    } else {
        return size * 3 / 2;
    }
}

static type_string *type_string_create_with_capacity(size_t capacity) {
    type_string *str = (type_string *) malloc(sizeof(type_string));
    if (!str) {
        return NULL;
    }
    str->buffer = (char *) calloc(capacity, 1);
    str->capacity = capacity;
    str->size = 0;
    memset(str->buffer, 0, capacity);
    return str;
}

static long type_string_grow_with_capacity(type_string *str, size_t new_capacity) {
    char *new_buffer = (char *)realloc(str->buffer, new_capacity);
    if (!new_buffer) {
        return -1;
    }
    str->buffer = new_buffer;
    str->capacity = new_capacity;
    return 0;
}

static long type_string_grow(type_string *str) {
    size_t new_capacity = str->capacity < 32 ? str->capacity + 16 : str->capacity * 3 / 2;
    return type_string_grow_with_capacity(str, new_capacity);
}

type_string *type_string_create(const char *literal);

void type_string_delete(type_string *str);

size_t type_string_get_size(type_string *str);

long type_string_append(type_string *dest, type_string *src);

long type_string_prepend(type_string *dest, type_string *src);

type_string *type_string_concat(type_string *str1, type_string *str2);

type_string *type_string_slice(type_string *str, ssize_t from, ssize_t to);

long type_string_equals(type_string *str1, type_string *str2);

ssize_t type_string_index_of(type_string *str, type_string *substr);

long type_string_trim_left(type_string *str);

void type_string_trim_right(type_string *str);

long type_string_trim(type_string *str);
