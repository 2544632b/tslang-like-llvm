#include <utility>
#include "AST/DeclNode.h"
#include "Sema/ASTVisitor.h"

VarDeclNode::VarDeclNode() : modifier(VarModifier::Let) {}

VarDeclNode::VarDeclNode(
        VarModifier modifier,
        const SharedPtr<Type> &type
) : modifier(modifier), type(type) {}

VarDeclNode::VarDeclNode(
        VarModifier modifier,
        String name,
        const SharedPtr<Type> &type
) : modifier(modifier), name(std::move(name)), type(type) {}

// MultiType begin
/*
VarDeclNode::VarDeclNode(
        VarModifier modifier,
        String name,
        const std::vector<SharedPtr<Type>> &multiType
) : modifier(modifier), name(std::move(name)), multiType(multiType) {}
*/
// MultiType end

VarDeclNode::VarDeclNode(VarModifier modifier,
                         String name,
                         const SharedPtr<Type> &type,
                         const SharedPtr<ExprNode> &initVal
) : modifier(modifier), name(std::move(name)), type(type), initVal(initVal) {}

void VarDeclNode::accept(const SharedPtr<ASTVisitor> &visitor) {
    visitor->visit(staticPtrCast<VarDeclNode>(shared_from_this()));
}

void VarDeclNode::bindChildrenInversely() {
    auto self = shared_from_this();
    if (initVal) {
        initVal->parent = self;
    }
}

bool VarDeclNode::isConstant() const {
    return modifier == VarModifier::Const;
}

ParmVarDeclNode::ParmVarDeclNode(
        const SharedPtr<Type> &type
) : VarDeclNode(VarModifier::Param, type) {}

ParmVarDeclNode::ParmVarDeclNode(
        const String &name,
        const SharedPtr<Type> &type
) : VarDeclNode(VarModifier::Param, name, type) {}

void ParmVarDeclNode::accept(const SharedPtr<ASTVisitor> &visitor) {
    visitor->visit(staticPtrCast<ParmVarDeclNode>(shared_from_this()));
}

SharedPtrMap<String, FunctionDeclNode> FunctionDeclNode::getBuiltinFunctions() {
    SharedPtr<ArrayType> arrayType = makeShared<ArrayType>();
    
    SharedPtrMap<String, FunctionDeclNode> functions;
    SharedPtr<ParmVarDeclNode> booleanArg = makeShared<ParmVarDeclNode>(BasicType::BOOLEAN_TYPE);
    SharedPtr<ParmVarDeclNode> integerArg = makeShared<ParmVarDeclNode>(BasicType::INTEGER_TYPE);
    SharedPtr<ParmVarDeclNode> floatArg = makeShared<ParmVarDeclNode>(BasicType::FLOAT_TYPE);
    SharedPtr<ParmVarDeclNode> strArg = makeShared<ParmVarDeclNode>(BasicType::STRING_TYPE);
    SharedPtr<ParmVarDeclNode> arrArg = makeShared<ParmVarDeclNode>(arrayType);

    SharedPtrVector<ParmVarDeclNode> booleanArgs{booleanArg};
    SharedPtrVector<ParmVarDeclNode> integerArgs{integerArg};
    SharedPtrVector<ParmVarDeclNode> floatArgs{floatArg};
    SharedPtrVector<ParmVarDeclNode> strArgs{strArg};
    SharedPtrVector<ParmVarDeclNode> arrArgs{arrArg};
    SharedPtrVector<ParmVarDeclNode> dFloatArgs{floatArg, floatArg};
    SharedPtrVector<ParmVarDeclNode> arrStrArgs{arrArg, strArg};

    functions["integer2string"] = makeShared<FunctionDeclNode>("integer2string", integerArgs, BasicType::STRING_TYPE);
    functions["integer2ascii"] = makeShared<FunctionDeclNode>("integer2ascii", integerArgs, BasicType::STRING_TYPE);
    functions["string2integer"] = makeShared<FunctionDeclNode>("string2integer", strArgs, BasicType::INTEGER_TYPE);
    functions["float2string"] = makeShared<FunctionDeclNode>("float2string", floatArgs, BasicType::STRING_TYPE);
    functions["string2float"] = makeShared<FunctionDeclNode>("string2float", strArgs, BasicType::FLOAT_TYPE);
    functions["print_number"] = makeShared<FunctionDeclNode>("print_number", integerArgs);
    functions["print_number_ln"] = makeShared<FunctionDeclNode>("print_number_ln", integerArgs);
    functions["print_float"] = makeShared<FunctionDeclNode>("print_float", floatArgs);
    functions["print_float_ln"] = makeShared<FunctionDeclNode>("print_float_ln", floatArgs);
    functions["print_string"] = makeShared<FunctionDeclNode>("print_string", strArgs);
    functions["print_string_ln"] = makeShared<FunctionDeclNode>("print_string_ln", strArgs);
    functions["print_ln"] = makeShared<FunctionDeclNode>("print_ln");
    functions["get_string"] = makeShared<FunctionDeclNode>("get_string", BasicType::STRING_TYPE);
    functions["type_assert"] = makeShared<FunctionDeclNode>("type_assert", booleanArgs);

    functions["type_log"] = makeShared<FunctionDeclNode>("type_log", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_log10"] = makeShared<FunctionDeclNode>("type_log10", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_pow"] = makeShared<FunctionDeclNode>("type_pow", dFloatArgs, BasicType::FLOAT_TYPE);
    functions["type_sqrt"] = makeShared<FunctionDeclNode>("type_sqrt", dFloatArgs, BasicType::FLOAT_TYPE);
    functions["type_sin"] = makeShared<FunctionDeclNode>("type_sin", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_cos"] = makeShared<FunctionDeclNode>("type_cos", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_tan"] = makeShared<FunctionDeclNode>("type_tan", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_ceil"] = makeShared<FunctionDeclNode>("type_ceil", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_floor"] = makeShared<FunctionDeclNode>("type_floor", floatArgs, BasicType::FLOAT_TYPE);
    
    functions["string_size"] = makeShared<FunctionDeclNode>("string_size", strArgs, BasicType::INTEGER_TYPE);
    functions["string_to_array"] = makeShared<FunctionDeclNode>("string_to_array", strArgs, arrayType);
    functions["array_length"] = makeShared<FunctionDeclNode>("array_length", arrArgs, BasicType::INTEGER_TYPE);
    functions["push_back_string"] = makeShared<FunctionDeclNode>("push_back_string", arrStrArgs);

    return functions;
}

FunctionDeclNode::FunctionDeclNode(
    String name
) : name(std::move(name)) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtrVector<ParmVarDeclNode> &params
) : name(std::move(name)),
    params(params) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtr<Type> &returnType
) : name(std::move(name)),
    returnType(returnType) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtrVector<ParmVarDeclNode> &params,
        const SharedPtr<Type> &returnType
) : name(std::move(name)),
    params(params),
    returnType(returnType) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtrVector<ParmVarDeclNode> &params,
        const SharedPtr<Type> &returnType,
        const SharedPtr<CompoundStmtNode> &body
) : name(std::move(name)),
    params(params),
    returnType(returnType),
    body(body) {}

void FunctionDeclNode::accept(const SharedPtr<ASTVisitor> &visitor) {
    visitor->visit(staticPtrCast<FunctionDeclNode>(shared_from_this()));
}

void FunctionDeclNode::bindChildrenInversely() {
    auto self = shared_from_this();
    for (const SharedPtr<ParmVarDeclNode> &param: params) {
        param->parent = self;
    }
    body->parent = self;
}
