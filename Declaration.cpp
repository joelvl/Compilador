#include "Declaration.h"

//Declaration
Declaration::Declaration()
{
}
Declaration::Declaration(DeclarationType declarationType, std::string identifier)
{
    this->declarationType = declarationType;
    this->identifier = identifier;
    this->type = nullptr;
}

Type_Node *Declaration::getType()
{
    return this->type;
}
void Declaration::setType(Type_Node *type)
{
    this->type = type;
}
std::string Declaration::getIdentifier(){
    return this->identifier;
}
void Declaration::setScope(unsigned int scopeId){
    this->scopeId = scopeId;
}
unsigned int Declaration::getScope(){
    return this->scopeId;
}

//Variable_Declaration
Variable_Declaration::Variable_Declaration(Type_Node *type, std::string identifier)
    : Declaration(DeclarationType::VARIABLE_DECLARATION, identifier)
{
    this->type = type;
}

//Function_Declaration
Function_Declaration::Function_Declaration(Type_Node *returnType, std::string identifier)
    : Declaration(DeclarationType::FUNCTION_DECLARATION, identifier)
{
    this->type = returnType;
}
void Function_Declaration::addParameter(Type_Node* type)
{
    parameterTypes.push_back(type);
}

//Class_Declaration
Class_Declaration::Class_Declaration(std::string identifier)
    : Declaration(DeclarationType::CLASS_DECLARATION, identifier)
{
    this->extends = nullptr;
}
void Class_Declaration::addFunction(Function_Declaration* function)
{
    functions.push_back(function);
}

bool Class_Declaration::hasFunction(std::string identifier, Type_Node *returnType, std::vector<Type_Node*> parameterTypes)
{
    for (Function_Declaration* function : functions)
    {
        if (function->identifier == identifier && function->type->type == returnType->type && parameterTypes.size() == function->parameterTypes.size())
        {
            for (int i = 0; i < function->parameterTypes.size(); i++)
            {
                if (!parameterTypes[i]->convertible(*function->parameterTypes[i]))
                {
                    return false;
                }
            }
            return true;
        }
    }
}

Type_Node* Class_Declaration::getFunction(std::string identifier, std::vector<Type_Node*> parameterTypes)
{
    Class_Declaration* clazz = this;
    while (clazz){
        for (Function_Declaration* function : clazz->functions)
        {
            if (function->identifier == identifier && parameterTypes.size() == function->parameterTypes.size())
            {   
                bool validParameters = true;
                for (int i = 0; i < function->parameterTypes.size(); i++)
                {
                    if (!parameterTypes[i]->convertible(*function->parameterTypes[i]))
                    {
                        validParameters = false;
                        break;
                    }
                }
                if (validParameters)
                    return function->getType();
                else 
                    return nullptr;
            }
        }
        clazz = clazz->extends;
    }
    return nullptr;
}

void Class_Declaration::addImplement(Interface_Declaration* interface){
    this->implements.push_back(interface);
}


void Class_Declaration::setExtends(Class_Declaration* extendedClass){
    this->extends = extendedClass;
}
Class_Declaration* Class_Declaration::getExtends(){
    return this->extends;
}

//Interface_Declaration
Interface_Declaration::Interface_Declaration(std::string identifier)
    : Declaration(DeclarationType::INTERFACE_DECLARATION, identifier)
{
}
void Interface_Declaration::addProtype(Function_Declaration* prototype)
{
    prototypes.push_back(prototype);
}
bool Interface_Declaration::hasPrototype(std::string identifier, Type_Node *returnType, std::vector<Type_Node*> parameterTypes)
{
    for (Function_Declaration* function : prototypes)
    {
        if (function->identifier == identifier && function->type == returnType && parameterTypes.size() == function->parameterTypes.size())
        {
            for (int i = 0; i < function->parameterTypes.size(); i++)
            {
                if (!parameterTypes[i]->convertible(*function->parameterTypes[i]))
                {
                    return false;
                }
            }
            return true;
        }
    }
}
bool Interface_Declaration::validDerivedClass(std::vector<Function_Declaration*> declaredFunctions)
{
    for (Function_Declaration* prototype : prototypes)
    {
        bool declaraedPrototype = false;
        for (Function_Declaration* function : declaredFunctions)
        {
            if (prototype->identifier == function->identifier)
            {
                if (function->parameterTypes.size() != prototype->parameterTypes.size())
                {
                    return false;
                }
                if (!function->getType()->convertible(*prototype->getType())){
                    return false;
                }
                for (int i = 0; i < function->parameterTypes.size(); i++)
                {
                    if (!function->parameterTypes[i]->convertible(*prototype->parameterTypes[i]))
                    {
                        return false;
                    }
                }
                declaraedPrototype = true;
            }
        }
        if (!declaraedPrototype)
        {
            return false;
        }
    }
    return true;
}