set(BUILTIN_LIB_SOURCES type_error.c type_string.c type_array.c type_io.c type_math.c type_input.cpp type_map.cpp)
set(BUILTIN_LIB_BITCODES type_error.bc type_string.bc type_array.bc type_io.bc type_math.bc type_input.bc type_map.bc)

add_custom_command(
        OUTPUT ${BUILTIN_LIB_BITCODES}
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/type_error.c -std=c99 -O2 -o type_error.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/type_string.c -std=c99 -O2 -o type_string.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/type_array.c -std=c99 -O2 -o type_array.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/type_io.c -std=c99 -O2 -o type_io.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/type_math.c -std=c11 -O2 -o type_math.bc
        COMMAND clang++ -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/type_input.cpp -std=c++17 -O2 -o type_input.bc
        COMMAND clang++ -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/type_map.cpp -std=c++17 -O2 -o type_map.bc
        DEPENDS ${BUILTIN_LIB_SOURCES}
)

add_custom_target(
        lib
        DEPENDS ${BUILTIN_LIB_BITCODES}
)