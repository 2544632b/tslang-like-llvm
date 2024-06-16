#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "type_string.h"
#include "type_error.h"

#define TYPE_ARRAY_INIT_CAPACITY 8

enum ElementType {
    BooleanType = 1,
    IntegerType = 3,
    FloatType = 5,
    StringType = 7,
    ArrayType = 9
};

typedef struct {
    void *buffer;
    size_t size;
    size_t capacity;
    size_t element_size;
    enum ElementType element_type;
} type_array;

static size_t type_array_get_capacity_with_size(size_t size) {
    return 1u << (size_t) ceil(log2(size));
}

static void type_array_grow(type_array *arr, type_error **error) {
    size_t new_capacity = arr->capacity * 2;
    void *new_buffer = realloc(arr->buffer, arr->element_size * new_capacity);
    if (!new_buffer) {
        *error = type_error_create(REALLOC_FAILED_CODE, REALLOC_FAILED_DESC);
        return;
    }
    arr->buffer = new_buffer;
    arr->capacity = new_capacity;
}

static type_array *type_array_create(size_t capacity, size_t element_size, enum ElementType element_type, type_error **error) {
    type_array *arr = (type_array *) malloc(sizeof(type_array));
    if (!arr) {
        *error = type_error_create(MALLOC_FAILED_CODE, MALLOC_FAILED_DESC);
        return NULL;
    }
    arr->buffer = calloc(capacity, element_size);
    if (!arr->buffer) {
        *error = type_error_create(CALLOC_FAILED_CODE, CALLOC_FAILED_DESC);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = capacity;
    arr->element_size = element_size;
    arr->element_type = element_type;
    return arr;
}

type_array *type_array_create_integer_array(type_error **error);

type_array *type_array_create_float_array(type_error **error);

type_array *type_array_create_boolean_array(type_error **error);

type_array *type_array_create_string_array(type_error **error);

type_array *type_array_create_array_array(type_error **error);

#define type_array_create_array_with_literal(type, element_type) \
    size_t capacity = type_array_get_capacity_with_size(size); \
    type_array *arr = type_array_create(capacity, sizeof(type), element_type, error); \
    if (!arr) { \
        return NULL; \
    } \
    memcpy(arr->buffer, literal_list, arr->element_size * size); \
    arr->size = size; \
    return arr;

type_array *type_array_create_integer_array_with_literal(long literal_list[], size_t size, type_error **error);

type_array *type_array_create_float_array_with_literal(double literal_list[], size_t size, type_error **error);

type_array *type_array_create_boolean_array_with_literal(bool literal_list[], size_t size, type_error **error);

type_array *type_array_create_string_array_with_literal(type_string *literal_list[], size_t size, type_error **error);

type_array *type_array_create_array_array_with_literal(type_array *literal_list[], size_t size, type_error **error);

void type_array_delete(type_array *arr);

size_t type_array_get_size(type_array *arr, type_error **error);

bool type_array_is_nd_array(type_array *arr, type_error **error);

bool type_array_is_float_array(type_array *arr, type_error **error);

#define type_array_push_detect() \
    if (arr->size + 1 >= arr->capacity) { \
        type_array_grow(arr, error); \
        if (*error != NULL) { \
            return; \
        } \
    }

#define type_array_push(type) \
    type *buffer = (type *) arr->buffer; \
    buffer[arr->size++] = new_element; \


void type_array_push_integer(type_array *arr, long new_element, type_error **error);

void type_array_push_float(type_array *arr, double new_element, type_error **error);

void type_array_push_boolean(type_array *arr, bool new_element, type_error **error);

void type_array_push_string(type_array *arr, type_string *new_element, type_error **error);

void type_array_push_array(type_array *arr, type_array *new_element, type_error **error);

#define type_array_pop_detect(zero_value) \
    if (arr->size == 0) { \
        *error = type_error_create(EMPTY_ARRAY_POP_CODE, EMPTY_ARRAY_POP_DESC); \
        return zero_value; \
    }

#define type_array_pop(type) \
    type *buffer = (type *) arr->buffer; \
    return buffer[--arr->size];

long type_array_pop_integer(type_array *arr, type_error **error);

double type_array_pop_float(type_array *arr, type_error **error);

bool type_array_pop_boolean(type_array *arr, type_error **error);

type_string *type_array_pop_string(type_array *arr, type_error **error);

type_array *type_array_pop_array(type_array *arr, type_error **error);

#define type_array_get_detect(zero_value) \
    if (index >= arr->size) {           \
        *error = type_error_create(ARRAY_INDEX_GE_SIZE_CODE, ARRAY_INDEX_GE_SIZE_DESC); \
        return zero_value; \
    }

#define type_array_get(type) \
    type *buffer = (type *) arr->buffer; \
    return buffer[index];

long type_array_get_integer(type_array *arr, size_t index, type_error **error);

double type_array_get_float(type_array *arr, size_t index, type_error **error);

bool type_array_get_boolean(type_array *arr, size_t index, type_error **error);

type_string *type_array_get_string(type_array *arr, size_t index, type_error **error);

type_array *type_array_get_array(type_array *arr, size_t index, type_error **error);

#define type_array_set_detect() \
    if (index >= arr->size) { \
        *error = type_error_create(ARRAY_INDEX_GE_SIZE_CODE, ARRAY_INDEX_GE_SIZE_DESC); \
        return; \
    }

#define type_array_set(type) \
    type *buffer = (type *)arr->buffer; \
    buffer[index] = element;

void type_array_set_integer(type_array *arr, size_t index, long element, type_error **error);

void type_array_set_float(type_array *arr, size_t index, double element, type_error **error);

void type_array_set_boolean(type_array *arr, size_t index, bool element, type_error **error);

void type_array_set_string(type_array *arr, size_t index, type_string *element, type_error **error);

void type_array_set_array(type_array *arr, size_t index, type_array *element, type_error **error);

type_array *type_array_slice(type_array *arr, ssize_t from, ssize_t to, type_error **error);

long array_length(type_array *arr);

type_array *string_to_array(type_string *str);

void push_back_string(type_array *arr, type_string *new_element);