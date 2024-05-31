#include "CodeGen/Builtin.h"

void Builtin::initialize(LLVMModule &module, LLVMContext &context, const llvm::Twine &libDirArg) {
    llvm::SmallString<256> libPath;
    if (!libDirArg.str().empty()) {
        libDirArg.toVector(libPath);
        if (!llvm::sys::path::is_absolute(libPath)) {
            if (llvm::sys::fs::make_absolute(libPath)) {
                reportLinkError("Parse the specified library directory failed");
            }
        }
        if (!llvm::sys::fs::exists(libPath)) {
            reportLinkError("The specified library directory does not exist");
        }
        if (!llvm::sys::fs::is_directory(libPath)) {
            reportLinkError("The specified library directory is not a directory");
        }
        libDir = libPath.str();
    } else {
        // 在当前执行目录下搜索lib目录
        llvm::sys::fs::current_path(libPath);
        llvm::sys::path::append(libPath, "lib");
        if (llvm::sys::fs::exists(libPath) && llvm::sys::fs::is_directory(libPath)) {
            libDir = libPath.str();
        }
    }

    if (!llvm::sys::fs::exists(libDir)) {
        reportLinkError("The library directory '" + libDir + "'does not exist");
    }

    BuiltinError::linkModule(module, context);
    BuiltinString::linkModule(module, context);
    BuiltinArray::linkModule(module, context);
    BuiltinIO::linkModule(module, context);
    BuiltinMath::linkModule(module, context);

    BuiltinError::getTypeAndFunction(module);
    BuiltinString::getTypeAndFunction(module);
    BuiltinArray::getTypeAndFunction(module);
    BuiltinIO::getTypeAndFunction(module);
    BuiltinMath::getTypeAndFunction(module);
}

#define BUILTIN_LINK_MODULE(moduleName) \
    llvm::SMDiagnostic error; \
    String bitcodeFilename = Builtin::libDir + "/type_"#moduleName".bc"; \
    bool bitcodeExist = llvm::sys::fs::exists(bitcodeFilename); \
    reportOnLinkError(!bitcodeExist, "Not found " + bitcodeFilename); \
    std::unique_ptr<LLVMModule> bitcodeModule = llvm::parseIRFile(bitcodeFilename, error, context); \
    reportOnLinkError(!bitcodeModule, "Parse bitcode file of the "#moduleName" module failed"); \
    bool linkFailed = llvm::Linker::linkModules(module, std::move(bitcodeModule)); \
    reportOnLinkError(linkFailed, "Link "#moduleName" module failed");

void BuiltinError::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(error)
}

void BuiltinError::getTypeAndFunction(LLVMModule &module) {
    llvm::StructType *errStructType = llvm::StructType::getTypeByName(module.getContext(), "struct.type_error");
    type = errStructType->getPointerTo();
    exitIfErrorFunc = module.getFunction("ss_exit_if_error");
    assertFunc = module.getFunction("type_assert");
}

void BuiltinString::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(string)
}

void BuiltinString::getTypeAndFunction(LLVMModule &module) {
    llvm::StructType *strStructType = llvm::StructType::getTypeByName(module.getContext(), "struct.type_string");
    type = strStructType->getPointerTo();
    createFunc = module.getFunction("type_string_create");
    deleteFunc = module.getFunction("type_string_delete");
    getSizeFunc = module.getFunction("type_string_get_size");
    concatFunc = module.getFunction("type_string_concat");
    appendFunc = module.getFunction("type_string_append");
    prependFunc = module.getFunction("type_string_prepend");
    sliceFunc = module.getFunction("type_string_slice");
    equalsFunc = module.getFunction("type_string_equals");
    indexOfFunc = module.getFunction("type_string_index_of");
    trimLeftFunc = module.getFunction("type_string_trim_left");
    trimRightFunc = module.getFunction("type_string_trim_right");
    trimFunc = module.getFunction("type_string_trim");
}

void BuiltinArray::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(array)
}

void BuiltinArray::getTypeAndFunction(LLVMModule &module) {
    llvm::StructType *arrStructType = llvm::StructType::getTypeByName(module.getContext(), "struct.type_array");
    type = arrStructType->getPointerTo();
    createIntegerArrayFunc = module.getFunction("type_array_create_integer_array");
    createFloatArrayFunc = module.getFunction("type_array_create_float_array");
    createBooleanArrayFunc = module.getFunction("type_array_create_boolean_array");
    createStringArrayFunc = module.getFunction("type_array_create_string_array");
    createArrayArrayFunc = module.getFunction("type_array_create_array_array");
    createIntegerArrayWithLiteralFunc = module.getFunction("type_array_create_integer_array_with_literal");
    createFloatArrayWithLiteralFunc = module.getFunction("type_array_create_float_array_with_literal");
    createBooleanArrayWithLiteralFunc = module.getFunction("type_array_create_boolean_array_with_literal");
    createStringArrayWithLiteralFunc = module.getFunction("type_array_create_string_array_with_literal");
    createArrayArrayWithLiteralFunc = module.getFunction("type_array_create_array_array_with_literal");
    deleteFunc = module.getFunction("type_array_delete");
    getSizeFunc = module.getFunction("type_array_get_size");
    isNDArrayFunc = module.getFunction("type_array_is_nd_array");
    isFloatArrayFunc = module.getFunction("type_array_is_float_array");
    pushIntegerFunc = module.getFunction("type_array_push_integer");
    pushFloatFunc = module.getFunction("type_array_push_float");
    pushBooleanFunc = module.getFunction("type_array_push_boolean");
    pushStringFunc = module.getFunction("type_array_push_string");
    pushArrayFunc = module.getFunction("type_array_push_array");
    popIntegerFunc = module.getFunction("type_array_pop_integer");
    popFloatFunc = module.getFunction("type_array_pop_float");
    popBooleanFunc = module.getFunction("type_array_pop_boolean");
    popStringFunc = module.getFunction("type_array_pop_string");
    popArrayFunc = module.getFunction("type_array_pop_array");
    getIntegerFunc = module.getFunction("type_array_get_integer");
    getFloatFunc = module.getFunction("type_array_get_float");
    getBooleanFunc = module.getFunction("type_array_get_boolean");
    getStringFunc = module.getFunction("type_array_get_string");
    getArrayFunc = module.getFunction("type_array_get_array");
    setIntegerFunc = module.getFunction("type_array_set_integer");
    setFloatFunc = module.getFunction("type_array_set_float");
    setBooleanFunc = module.getFunction("type_array_set_boolean");
    setStringFunc = module.getFunction("type_array_set_string");
    setArrayFunc = module.getFunction("type_array_set_array");
    sliceFunc = module.getFunction("type_array_slice");
}

void BuiltinIO::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(io)
}

void BuiltinIO::getTypeAndFunction(LLVMModule &module) {
    integer2stringFunc = module.getFunction("integer2string");
    string2integerFunc = module.getFunction("string2integer");
    float2stringFunc = module.getFunction("float2string");
    string2floatFunc = module.getFunction("string2float");
    printIntegerFunc = module.getFunction("print_number");
    printlnIntegerFunc = module.getFunction("print_number_ln");
    printFloatFunc = module.getFunction("print_float");
    printlnFloatFunc = module.getFunction("print_float_ln");
    printStringFunc = module.getFunction("print_string");
    printlnStringFunc = module.getFunction("print_string_ln");
}

void BuiltinMath::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(math)
}

void BuiltinMath::getTypeAndFunction(LLVMModule &module) {
    logFunc = module.getFunction("type_log");
    log10Func = module.getFunction("type_log10");
    powFunc = module.getFunction("type_pow");
    sqrtFunc = module.getFunction("type_sqrt");
}