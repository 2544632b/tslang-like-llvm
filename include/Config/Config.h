#define PROJECT_BINARY_DIR "/Users/chan/Desktop/tslang-llvm"
#define CMAKE_HOST_APPLE 1
#define CMAKE_HOST_UNIX 1
/* #undef CMAKE_HOST_WIN32 */

#if defined(CMAKE_HOST_UNIX) && !defined(CMAKE_HOST_APPLE)
    #define CMAKE_HOST_LINUX true
#endif

/* #undef PROJECT_VERSION_MAJOR */
#define PROJECT_VERSION_MINOR 3
#define PROJECT_VERSION_PATCH 4
#define PROJECT_VERSION "0.3.4"

/* #undef DEBUG_MODE */

#define STATICSCRIPT_INSTALL_DIR "/usr/local/staticscript"
#define STATICSCRIPT_BIN_DIR STATICSCRIPT_INSTALL_DIR"/bin"
#define STATICSCRIPT_LIB_DIR STATICSCRIPT_INSTALL_DIR"/lib"
