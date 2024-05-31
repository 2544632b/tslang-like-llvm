#include "type_error.h"

void ss_exit_if_error(type_error *error) {
    if (error) {
        printf("\033[0;31m""[StaticScript Runtime Error]:\n\tcode: %d\n\tdescription: %s\n""\033[0m", error->code, error->description);
        type_error_delete(error);
        abort();
    } else {
        type_error_delete(error);
    }
}

void type_assert(bool condition) {
    if (!condition) {
        printf("\033[0;31m""assert failed\n""\033[0m");
        abort();
    }
}