#ifndef Declaration_h
#define Declaration_h

#include <vector>
#include <string>
#include "ast.h"

class Type_Node;

class Declaration;
class Variable_Declaration;
class Function_Declaration;
class Interface_Declaration;

enum DeclarationType
{
    FUNCTION_DECLARATION,
    VARIABLE_DECLARATION,
    CLASS_DECLARATION,
    INTERFACE_DECLARATION
};

class Declaration
{
public:
    DeclarationType declarationType;
    Type_Node *type;
    std::string identifier;
    unsigned int scopeId;
    Declaration();
    Declaration(DeclarationType declarationType, std::string identifier);

    Type_Node* getType();
    void setType(Type_Node* type);
    std::string getIdentifier();
    void setScope(unsigned int scopeId);
    unsigned int getScope();
};
class Variable_Declaration : public Declaration
{
public:
    Variable_Declaration(Type_Node *type, std::string identifier);
};
class Function_Declaration : public Declaration
{
public:
    std::vector<Type_Node*> parameterTypes;
    Function_Declaration(Type_Node *returnType, std::string identifier);
    void addParameter(Type_Node* type);
};
class Class_Declaration : public Declaration
{
public:
    std::vector<Function_Declaration*> functions;
    std::vector<Interface_Declaration*> implements;
    Class_Declaration* extends;
    Class_Declaration(std::string identifier);
    virtual void addFunction(Function_Declaration* function);
    bool hasFunction(std::string identifier, Type_Node *returnType, std::vector<Type_Node*> parameterTypes);
    Type_Node* getFunction(std::string identifier, std::vector<Type_Node*> parameterTypes);
    void addImplement(Interface_Declaration* interface);
    void setExtends(Class_Declaration* extendedClass);
    Class_Declaration* getExtends();
};
class Interface_Declaration : public Declaration
{
public:
    std::vector<Function_Declaration*> prototypes;
    Interface_Declaration(std::string identifier);
    virtual void addProtype(Function_Declaration* prototype);
    bool hasPrototype(std::string identifier, Type_Node* returnType, std::vector<Type_Node*> parameterTypes);
    bool validDerivedClass(std::vector<Function_Declaration*> declaredFunctions);
};
#endif
