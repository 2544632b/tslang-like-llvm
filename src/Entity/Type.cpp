#include "Entity/Type.h"

bool Type::equals(const SharedPtr<Type> &rhs) const {
    // 如果rhs为nullptr, 直接返回false
    if (!rhs) {
        return false;
    }
    // 如果比较的两类型不属于同类, 直接返回false
    if (isBasic() && rhs->isArray() || isArray() && rhs->isBasic()) {
        return false;
    }
    /*
    if (isUnion() && rhs->isNumber() && isNumber()) {
        return true;
    }
    if (isUnion() && rhs->isString() && isString()) {
        return true;
    }
    if (isUnion() && rhs->isBoolean() && isBoolean()) {
        return true;
    }
    */

    if (SharedPtr<BasicType> basicType = dynPtrCast<BasicType>(rhs)) {
        const auto *type = dynamic_cast<const BasicType *>(this);
        return type->equals(basicType);
    } else {
        SharedPtr<ArrayType> arrayType = dynPtrCast<ArrayType>(rhs);
        const auto *type = dynamic_cast<const ArrayType *>(this);
        return type->equals(arrayType);
    }

    return false;
}

// 相同类型
// 1. 相等的类型是相同类型
// 2. 基础整型和基础浮点型是相同类型
// 3. 数组与空数组是相同类型
bool Type::sameAs(const SharedPtr<Type> &rhs) const {
    // 右值为空直接返回false
    if (!rhs) {
        return false;
    }
    // 相等的类型是兼容的
    if (equals(rhs)) {
        return true;
    }
    // 整数和浮点数是同类的
    if (isNumber() && rhs->isNumber()) {
        return true;
    }

    if (isArray() && rhs->isUnknown()) {
        // 1. 左值为数组, 右值为unknown基础类型, 左值兼容右值(反之不成立)
        // 2. 左右值都是数组, 且右值为空数组, 左值深度不小于右值深度, 左值兼容右值(反之不成立)
        if (rhs->isBasic() || rhs->isArray() || rhs->isNumberArray() && asArray()->getDepth() >= rhs->asArray()->getDepth()) {
            return true;
        }
    }

    // 如果左边是一个Array，右边是个接受自Array的函数，则允许成立
    if(isArray() && (rhs->isArray())) {
        SharedPtr<ArrayType> tempArray = staticPtrCast<ArrayType>(rhs);
        if(tempArray->getElementType()->isString()) {
            return true;
        }

        return false;
    }

    return false;
}

// 左值: 形式上的类型(左值的类型(变量声明类型), 函数形参类型)
// 右值: 实际的类型(右值的类型(变量赋值类型), 函数实参类型)
// 兼容是有方向的, 左值兼容右值并不一定代表右值兼容左值
bool Type::compatibleWith(const SharedPtr<Type> &rhs) const {
    // 右值为空直接返回false
    if (!rhs) {
        return false;
    }
    // 同类的类型是兼容的
    if (equals(rhs) || sameAs(rhs)) {
        return true;
    }
    if (isNumberArray() && rhs->isNumberArray()) {
        if (asArray()->getDepth() == rhs->asArray()->getDepth()) {
            return true;
        }
    }
    return false;
}

BasicType::BasicType(BasicTypeKind kind) : kind(kind) {}

bool BasicType::isBasic() const {
    return true;
}

bool BasicType::isBoolean() const {
    return kind == BasicTypeKind::Boolean;
}

bool BasicType::isInteger() const {
    return kind == BasicTypeKind::Integer;
}

bool BasicType::isFloat() const {
    return kind == BasicTypeKind::Float;
}

bool BasicType::isNumber() const {
    return kind == BasicTypeKind::Integer || kind == BasicTypeKind::Float;
}

bool BasicType::isString() const {
    return kind == BasicTypeKind::String;
}

bool BasicType::isUnknown() const {
    return kind == BasicTypeKind::Unknown;
}

bool BasicType::isArray() const {
    return false;
}

bool BasicType::isUnion() const {
    return false;
}

SharedPtr<ArrayType> BasicType::asArray() const {
    return nullptr;
}

BasicTypeKind BasicType::getKind() const {
    return kind;
}

bool BasicType::equals(const SharedPtr<BasicType> &rhs) const {
    return kind == rhs->kind;
}

bool BasicType::isNumberArray() const {
    return false;
}


SharedPtr<ArrayType> ArrayType::createNDArrayType(const SharedPtr<BasicType> &basicType, size_t depth) {
    SharedPtr<Type> type = basicType;
    for (size_t i = 0; i < depth; ++i) {
        type = makeShared<ArrayType>(type);
    }
    return staticPtrCast<ArrayType>(type);
}

ArrayType::ArrayType(const SharedPtr<Type> &elementType) : elementType(elementType) {
    if (elementType->isArray()) {
        depth = elementType->asArray()->depth + 1;
    }
}

bool ArrayType::isBasic() const {
    return false;
}

bool ArrayType::isBoolean() const {
    return false;
}

bool ArrayType::isInteger() const {
    return false;
}

bool ArrayType::isFloat() const {
    return false;
}

bool ArrayType::isNumber() const {
    return false;
}

bool ArrayType::isString() const {
    return false;
}

bool ArrayType::isUnknown() const {
    return getBasicElementType()->isUnknown();
}

bool ArrayType::isArray() const {
    return true;
}

bool ArrayType::isUnion() const {
    return false;
}

SharedPtr<ArrayType> ArrayType::asArray() const {
    return constPtrCast<ArrayType>(staticPtrCast<const ArrayType>(shared_from_this()));
}

const SharedPtr<Type> &ArrayType::getElementType() const {
    return elementType;
}

SharedPtr<Type> ArrayType::getBasicElementType() const {
    if (elementType->isBasic()) {
        return elementType;
    }
    SharedPtr<Type> iterType = elementType;
    while (iterType->isArray()) {
        iterType = iterType->asArray()->elementType;
    }
    return iterType;
}

bool ArrayType::equals(const SharedPtr<ArrayType> &rhs) const {
    return elementType->equals(rhs->elementType);
}

size_t ArrayType::getDepth() const {
    return depth;
}

bool ArrayType::isNumberArray() const {
    if (getBasicElementType()->isNumber()) {
        return true;
    }
    return false;
}


void UnionType::createUnionType(std::vector<SharedPtr<BasicType>> typeList, size_t depth) {
    // this->typeList = typeList;
    this->typeList.assign(typeList.begin(), typeList.end());
    /*
    for(int i = 0; i < depth; ++i) {
        this->typeList.push_back(typeList[i]);
    }
    */
    this->depth = depth;
}

bool UnionType::isBasic() const {
    return true;
}

bool UnionType::isBoolean() const {
    for(int i = 0; i < depth; ++i) {
        if(typeList[i]->isBoolean()) {
            return true;
        }
    }

    return false;
}

bool UnionType::isInteger() const {
    for(int i = 0; i < depth; ++i) {
        if(typeList[i]->isInteger()) {
            return true;
        }
    }

    return false;
}

bool UnionType::isFloat() const {
    for(int i = 0; i < depth; ++i) {
        if(typeList[i]->isFloat()) {
            return true;
        }
    }

    return false;
}

bool UnionType::isNumber() const {
    for(int i = 0; i < depth; ++i) {
        if(typeList[i]->isNumber()) {
            return true;
        }
    }

    return false;
}

bool UnionType::isString() const {
    for(int i = 0; i < depth; ++i) {
        if(typeList[i]->isString()) {
            return true;
        }
    }

    return false;
}

bool UnionType::isUnknown() const {
    return false;
}

bool UnionType::isArray() const {
    return false;
}

bool UnionType::isNumberArray() const {
    return false;
}

bool UnionType::isUnion() const {
    return true;
}

SharedPtr<ArrayType> UnionType::asArray() const {
    return nullptr;
}