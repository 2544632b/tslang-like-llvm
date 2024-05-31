#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int code;
    const char *description;
} type_error;


#define MALLOC_FAILED_CODE 100001
#define CALLOC_FAILED_CODE 100002
#define REALLOC_FAILED_CODE 100003

#define MALLOC_FAILED_DESC "malloc error"
#define CALLOC_FAILED_DESC "calloc error"
#define REALLOC_FAILED_DESC "realloc error"


#define NULL_ARRAY_PTR_CODE 200001
#define EMPTY_ARRAY_POP_CODE 200002
#define ARRAY_INDEX_GE_SIZE_CODE 200003
#define ARRAY_SLICE_TO_LT_FROM_CODE 200004

#define NULL_ARRAY_PTR_DESC "array pointer is NULL"
#define EMPTY_ARRAY_POP_DESC "can not execute the pop for empty array"
#define ARRAY_INDEX_GE_SIZE_DESC "array out of the index"
#define ARRAY_SLICE_TO_LT_FROM_DESC "source size is smaller than dest while executing the array"


static type_error *type_error_create(int code, const char *description) {
    type_error *error = (type_error *) malloc(sizeof(type_error));
    if (!error) {
        printf("\033[0;31m""[StaticScript Runtime Error]: Create Error Object Failed\n""\033[0m");
        abort();
    }
    error->code = code;
    error->description = description;
    return error;
}

static void type_error_delete(type_error *error) {
    if (error != NULL) {
        free(error);
    }
}

void ss_exit_if_error(type_error *error);

void type_assert(bool condition);