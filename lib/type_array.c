#include "type_array.h"

type_array *type_array_create_integer_array(type_error **error) {
    return type_array_create(TYPE_ARRAY_INIT_CAPACITY, sizeof(long), IntegerType, error);
}

type_array *type_array_create_float_array(type_error **error) {
    return type_array_create(TYPE_ARRAY_INIT_CAPACITY, sizeof(double), FloatType, error);
}

type_array *type_array_create_boolean_array(type_error **error) {
    return type_array_create(TYPE_ARRAY_INIT_CAPACITY, sizeof(bool), BooleanType, error);
}

type_array *type_array_create_string_array(type_error **error) {
    return type_array_create(TYPE_ARRAY_INIT_CAPACITY, sizeof(type_string *), StringType, error);
}

type_array *type_array_create_array_array(type_error **error) {
    type_array *arr = type_array_create(TYPE_ARRAY_INIT_CAPACITY, sizeof(type_array *), ArrayType, error);
    if (!arr) {
        return NULL;
    }
    return arr;
}

type_array *type_array_create_integer_array_with_literal(long literal_list[], size_t size, type_error **error) {
    type_array_create_array_with_literal(long, IntegerType)
}

type_array *type_array_create_float_array_with_literal(double literal_list[], size_t size, type_error **error) {
    type_array_create_array_with_literal(double, FloatType)
}

type_array *type_array_create_boolean_array_with_literal(bool literal_list[], size_t size, type_error **error) {
    type_array_create_array_with_literal(bool, BooleanType)
}

type_array *type_array_create_string_array_with_literal(type_string *literal_list[], size_t size, type_error **error) {
    type_array_create_array_with_literal(type_string *, StringType)
}

type_array *type_array_create_array_array_with_literal(type_array *literal_list[], size_t size, type_error **error) {
    type_array_create_array_with_literal(type_array *, ArrayType)
}

void type_array_delete(type_array *arr) {
    if (arr != NULL) {
        if (arr->buffer != NULL) {
            free(arr->buffer);
        }
        free(arr);
    }
}

size_t type_array_get_size(type_array *arr, type_error **error) {
    if (!arr) {
        *error = type_error_create(NULL_ARRAY_PTR_CODE, NULL_ARRAY_PTR_DESC);
        return 0;
    }
    return arr->size;
}

bool type_array_is_nd_array(type_array *arr, type_error **error) {
    if (!arr) {
        *error = type_error_create(NULL_ARRAY_PTR_CODE, NULL_ARRAY_PTR_DESC);
        return false;
    }
    return arr->element_type == ArrayType;
}

bool type_array_is_float_array(type_array *arr, type_error **error) {
    if (!arr) {
        *error = type_error_create(NULL_ARRAY_PTR_CODE, NULL_ARRAY_PTR_DESC);
        return false;
    }
    return arr->element_type == FloatType;
}

void type_array_push_integer(type_array *arr, long new_element, type_error **error) {
    type_array_push_detect()
    type_array_push(long)
}

void type_array_push_float(type_array *arr, double new_element, type_error **error) {
    type_array_push_detect()
    type_array_push(double)
}

void type_array_push_boolean(type_array *arr, bool new_element, type_error **error) {
    type_array_push_detect()
    type_array_push(bool)
}

void type_array_push_string(type_array *arr, type_string *new_element, type_error **error) {
    type_array_push_detect()
    type_array_push(type_string *)
}

void type_array_push_array(type_array *arr, type_array *new_element, type_error **error) {
    type_array_push_detect()
    type_array_push(type_array *)
}

long type_array_pop_integer(type_array *arr, type_error **error) {
    type_array_pop_detect(0)
    type_array_pop(long)
}

double type_array_pop_float(type_array *arr, type_error **error) {
    type_array_pop_detect(0)
    type_array_pop(double)
}

bool type_array_pop_boolean(type_array *arr, type_error **error) {
    type_array_pop_detect(false)
    type_array_pop(bool)
}

type_string *type_array_pop_string(type_array *arr, type_error **error) {
    type_array_pop_detect(NULL)
    type_array_pop(type_string *)
}

type_array *type_array_pop_array(type_array *arr, type_error **error) {
    type_array_pop_detect(NULL)
    type_array_pop(type_array *)
}

long type_array_get_integer(type_array *arr, size_t index, type_error **error) {
    type_array_get_detect(0)
    type_array_get(long)
}

double type_array_get_float(type_array *arr, size_t index, type_error **error) {
    type_array_get_detect(0)
    type_array_get(double)
}

bool type_array_get_boolean(type_array *arr, size_t index, type_error **error) {
    type_array_get_detect(false)
    type_array_get(bool)
}

type_string *type_array_get_string(type_array *arr, size_t index, type_error **error) {
    type_array_get_detect(NULL)
    type_array_get(type_string *)
}

type_array *type_array_get_array(type_array *arr, size_t index, type_error **error) {
    type_array_get_detect(NULL)
    type_array_get(type_array *)
}

void type_array_set_integer(type_array *arr, size_t index, long element, type_error **error) {
    type_array_set_detect()
    type_array_set(long)
}

void type_array_set_float(type_array *arr, size_t index, double element, type_error **error) {
    type_array_set_detect()
    type_array_set(double)
}

void type_array_set_boolean(type_array *arr, size_t index, bool element, type_error **error) {
    type_array_set_detect()
    type_array_set(bool)
}

void type_array_set_string(type_array *arr, size_t index, type_string *element, type_error **error) {
    type_array_set_detect()
    type_array_set(type_string *)
}

void type_array_set_array(type_array *arr, size_t index, type_array *element, type_error **error) {
    type_array_set_detect()
    type_array_set(type_array *)
}


type_array *type_array_slice(type_array *arr, ssize_t from, ssize_t to, type_error **error) {
    if (from < 0) {
        from = arr->size + from;
    }
    if (to < 0) {
        to = arr->size + to;
    }
    if (to < from) {
        *error = type_error_create(ARRAY_SLICE_TO_LT_FROM_CODE, ARRAY_SLICE_TO_LT_FROM_DESC);
        return NULL;
    }
    size_t slice_size = to - from;
    size_t new_capacity = type_array_get_capacity_with_size(slice_size);
    type_array *new_arr = type_array_create(new_capacity, arr->element_size, arr->element_type, error);
    if (!new_arr) {
        return NULL;
    }
    memcpy(new_arr->buffer, arr->buffer + from * arr->element_size, slice_size * arr->element_size);
    new_arr->size = slice_size;
    return new_arr;
}