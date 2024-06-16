#include "type_string.h"

type_string *type_string_create(const char *literal) {
    size_t size = strlen(literal);
    size_t capacity = type_string_get_capacity_with_size(size);
    type_string *str = type_string_create_with_capacity(capacity);
    if (!str) {
        return NULL;
    }
    memcpy(str->buffer, literal, size);
    str->size = size;
    return str;
}

void type_string_delete(type_string *str) {
    free(str->buffer);
    free(str);
}

size_t type_string_get_size(type_string *str) {
    return str->size;
}

long type_string_append(type_string *dest, type_string *src) {
    size_t needed_size = dest->size + src->size;
    size_t needed_capacity = type_string_get_capacity_with_size(needed_size);
    if (dest->capacity < needed_capacity) {
        if (type_string_grow_with_capacity(dest, needed_capacity) == -1) {
            return -1;
        }
    }
    strncat(dest->buffer, src->buffer, src->size);
    dest->size = needed_size;
    return 0;
}

long type_string_prepend(type_string *dest, type_string *src) {
    size_t needed_size = dest->size + src->size;
    size_t needed_capacity = type_string_get_capacity_with_size(needed_size);
    if (dest->capacity < needed_capacity) {
        if (type_string_grow_with_capacity(dest, needed_capacity) == -1) {
            return -1;
        }
    }
    memmove(dest->buffer + src->size, dest->buffer, src->size + 1);
    memcpy(dest->buffer, src->buffer, src->size);
    dest->size = needed_size;
    return 0;
}

type_string *type_string_concat(type_string *str1, type_string *str2) {
    size_t size = str1->size + str2->size;
    size_t capacity = type_string_get_capacity_with_size(size);
    type_string *str = type_string_create_with_capacity(capacity);
    memcpy(str->buffer, str1->buffer, str1->size);
    memcpy(str->buffer + str1->size, str2->buffer, str2->size);
    str->size = size;
    return str;
}

type_string *type_string_slice(type_string *str, ssize_t from, ssize_t to) {
    if (from < 0) {
        from = str->size + from;
    }
    if (to < 0) {
        to = str->size + to;
    }
    if (to < from) {
        return NULL;
    }
    size_t slice_size = to - from;
    size_t new_capacity = type_string_get_capacity_with_size(slice_size);
    type_string *new_str = type_string_create_with_capacity(new_capacity);
    memcpy(new_str->buffer, str->buffer + from, slice_size);
    new_str->size = slice_size;
    return new_str;
}

long type_string_equals(type_string *str1, type_string *str2) {
    if (str1->size != str2->size) {
        return -1;
    }
    return strncmp(str1->buffer, str2->buffer, str1->size);
}

ssize_t type_string_index_of(type_string *str, type_string *substr) {
    char *sub = strstr(str->buffer, substr->buffer);
    if (!sub) {
        return -1;
    }
    return sub - str->buffer;
}

long type_string_trim_left(type_string *str) {
    size_t i = 0;
    while (isspace(str->buffer[i])) {
        i += 1;
    }
    char *new_buffer = (char *) calloc(str->capacity, 1);
    if (!new_buffer) {
        return -1;
    }
    memset(new_buffer, 0, str->capacity);
    memcpy(new_buffer, str->buffer + i, str->size - i);
    free(str->buffer);
    str->buffer = new_buffer;
    str->size -= i;
    return 0;
}

void type_string_trim_right(type_string *str) {
    ssize_t i = str->size - 1;
    while (i >= 0 && isspace(str->buffer[i])) {
        str->buffer[i] = 0;
        i -= 1;
    }
    str->size = i + 1;
}

long type_string_trim(type_string *str) {
    type_string_trim_right(str);
    return type_string_trim_left(str);
}

long string_size(type_string *str) {
    return type_string_get_size(str);
}