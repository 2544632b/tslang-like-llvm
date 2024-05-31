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

VarDeclNode::VarDeclNode(VarModifier modifier,
                         String name,
                         const SharedPtr<Type> &type,
                         const SharedPtr<ExprNode> &initVal
) : modifier(modifier),
    name(std::move(name)),
    type(type),
    initVal(initVal) {}

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
    SharedPtrMap<String, FunctionDeclNode> functions;
    SharedPtr<ParmVarDeclNode> booleanArg = makeShared<ParmVarDeclNode>(BasicType::BOOLEAN_TYPE);
    SharedPtr<ParmVarDeclNode> integerArg = makeShared<ParmVarDeclNode>(BasicType::INTEGER_TYPE);
    SharedPtr<ParmVarDeclNode> floatArg = makeShared<ParmVarDeclNode>(BasicType::FLOAT_TYPE);
    SharedPtr<ParmVarDeclNode> strArg = makeShared<ParmVarDeclNode>(BasicType::STRING_TYPE);
    SharedPtrVector<ParmVarDeclNode> booleanArgs{booleanArg};
    SharedPtrVector<ParmVarDeclNode> integerArgs{integerArg};
    SharedPtrVector<ParmVarDeclNode> floatArgs{floatArg};
    SharedPtrVector<ParmVarDeclNode> dFloatArgs{floatArg, floatArg};
    SharedPtrVector<ParmVarDeclNode> strArgs{strArg};
    functions["integer2string"] = makeShared<FunctionDeclNode>("integer2string", integerArgs, BasicType::STRING_TYPE);
    functions["string2integer"] = makeShared<FunctionDeclNode>("string2integer", strArgs, BasicType::INTEGER_TYPE);
    functions["float2string"] = makeShared<FunctionDeclNode>("float2string", floatArgs, BasicType::STRING_TYPE);
    functions["string2float"] = makeShared<FunctionDeclNode>("string2float", strArgs, BasicType::FLOAT_TYPE);
    functions["print_number"] = makeShared<FunctionDeclNode>("print_number", integerArgs);
    functions["print_number_ln"] = makeShared<FunctionDeclNode>("print_number_ln", integerArgs);
    functions["print_float"] = makeShared<FunctionDeclNode>("print_float", floatArgs);
    functions["print_double_ln"] = makeShared<FunctionDeclNode>("print_double_ln", floatArgs);
    functions["print_string"] = makeShared<FunctionDeclNode>("print_string", strArgs);
    functions["print_string_ln"] = makeShared<FunctionDeclNode>("print_string_ln", strArgs);
    functions["type_assert"] = makeShared<FunctionDeclNode>("type_assert", booleanArgs);

    functions["type_log"] = makeShared<FunctionDeclNode>("type_log", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_log10"] = makeShared<FunctionDeclNode>("type_log10", floatArgs, BasicType::FLOAT_TYPE);
    functions["type_pow"] = makeShared<FunctionDeclNode>("type_pow", dFloatArgs, BasicType::FLOAT_TYPE);
    functions["type_sqrt"] = makeShared<FunctionDeclNode>("type_sqrt", dFloatArgs, BasicType::FLOAT_TYPE);
    return functions;
}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtrVector<ParmVarDeclNode> &params
) : name(std::move(name)),
    params(params) {}

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
