#include "ast.h"
void AST_Node::print(int depth)
{
}
AST_Node::AST_Node()
{
}
AST_Node::~AST_Node()
{
}
std::string AST_Node::depthSpacing(int depth)
{
    std::string spacing = "╰╴";
    for (; depth > 0; depth--)
        spacing = "  " + spacing;
    return spacing;
}

//AST_PROGRAM
AST_Program::AST_Program(std::vector<Declaration_Node *> *declarations)
{
    this->declarations = declarations;
}

void AST_Program::print(int depth)
{
    std::cout << "Program" << std::endl;
    for (Declaration_Node *declaration : *declarations)
    {
        declaration->print(depth + 1);
    }
}


//Declaration_Node
Declaration_Node::Declaration_Node(Identifier_Node *identifier)
{
    this->identifier = identifier;
}
void Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Declaration" << std::endl;
}

//Variable_Declaration_Node
Variable_Declaration_Node::Variable_Declaration_Node(Type_Node *type_node, Identifier_Node *identifier)
    : Declaration_Node(identifier)
{
    this->type_node = type_node;
}
void Variable_Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Variable Declaration" << std::endl;
}

//Function_Declaration_Node
Function_Declaration_Node::Function_Declaration_Node(Type_Node *type_node, Identifier_Node *identifier, std::vector<Variable_Declaration_Node *> *parameters, Statement_Block_Node *statement_Block)
    : Declaration_Node(identifier)
{
    this->type_node = type_node;
    this->parameters = parameters;
    this->statement_Block = statement_Block;
}
void Function_Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Function Name: " << identifier->identifier << " Type:" << type_node->identifier << std::endl;
    if(parameters)
    for (Variable_Declaration_Node *variable_Declaration_Node : *parameters){
        variable_Declaration_Node->print(depth + 1);
    }
    statement_Block->print(depth + 1);
}

//Class_Declaration_Node
Class_Declaration_Node::Class_Declaration_Node(Identifier_Node *identifier, Identifier_Node *extends, std::vector<Identifier_Node *> *implements, std::vector<Declaration_Node *> *field)
    : Declaration_Node(identifier)
{
    this->extends = extends;
    this->implements = implements;
    this->field = field;
}
void Class_Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Class Declaration ";
    std::cout << "Name: " << identifier->identifier;
/*
    if(implements->size() > 0){
        std::cout << "Implements: ";
        for (Identifier_Node *identifier : *implements){
            std::cout << identifier->identifier << " ";
        }
    }
*/
    std::cout << std::endl;
    for (Declaration_Node *declaration : *field){
        declaration->print(depth + 1);
    }
}

//Interface_Declaration_Node
Interface_Declaration_Node::Interface_Declaration_Node(Identifier_Node *identifier, std::vector<Prototype_Node *> *prototypes)
    : Declaration_Node(identifier)
{
    this->prototypes = prototypes;
}
void Interface_Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Interface Declaration" << std::endl;
}

//Prototype_Node
Prototype_Node::Prototype_Node(Type_Node *type_node, Identifier_Node *identifier, std::vector<Variable_Declaration_Node *> *parameters)
    : Declaration_Node(identifier)
{
    this->type_node = type_node;
    this->parameters = parameters;
}
void Prototype_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Prototype Declaration" << std::endl;
}

Statement_Node::Statement_Node()
{
}
Statement_Block_Node::Statement_Block_Node(std::vector<AST_Node *> *statements)
{
    this->statements = statements;
}
If_Statement_Node::If_Statement_Node(Expression_Node *expression, Statement_Block_Node *if_block, Statement_Block_Node *else_block)
{
    this->expression = expression;
    this->if_block = if_block;
    this->else_block = else_block;
}
While_Statement_Node::While_Statement_Node(Expression_Node *expression, Statement_Block_Node *block)
{
    this->expression = expression;
    this->block = block;
}
For_Statement_Node::For_Statement_Node(Expression_Node *expressiA, Expression_Node *expressiB, Expression_Node *expressionC, Statement_Block_Node *block)
{
    this->expressionA = expressionA;
    this->expressionB = expressionB;
    this->expressionC = expressionC;
    this->block = block;
}
Break_Statement_Node::Break_Statement_Node()
{
}
Print_Statement_Node::Print_Statement_Node(std::vector<Expression_Node *> *expressions)
{
    this->expressions = expressions;
}
Return_Statement_Node::Return_Statement_Node(Expression_Node *expression)
{
    this->expression = expression;
}

Identifier_Node::Identifier_Node(std::string identifier)
{
    this->identifier = identifier;
}
Type_Node::Type_Node(Datatype type)
{
    this->type = type;
}
Type_Node::Type_Node(Datatype type, Identifier_Node *identifier)
{
    this->type = type;
    this->identifier = identifier;
}
Expression_Node::Expression_Node()
{
}
Comparation_Expression_Node::Comparation_Expression_Node(Expression_Node *leftExpression, Expression_Node *rightExpression, Operator_Type operator_Type)
{
    this->leftExpression = leftExpression;
    this->rightExpression = rightExpression;
    this->operator_Type = operator_Type;
}
Array_Expression_Node::Array_Expression_Node(Expression_Node *leftExpression, Expression_Node *rightExpression)
{
    this->leftExpression = leftExpression;
    this->rightExpression = rightExpression;
}
Call_Expression_Node::Call_Expression_Node(Expression_Node *expression, Identifier_Node *identifier, std::vector<Expression_Node *> *actuals)
{
    this->expression = expression;
    this->identifier = identifier;
    this->actuals = actuals;
}
Identifier_Expression_Node::Identifier_Expression_Node(Identifier_Node *identifier)
{
    this->identifier = identifier;
}
Int_Constant_Expression_Node::Int_Constant_Expression_Node(int value)
{
    this->value = value;
}
Double_Constant_Expression_Node::Double_Constant_Expression_Node(double value)
{
    this->value = value;
}
Boolean_Constant_Expression_Node::Boolean_Constant_Expression_Node(bool value)
{
    this->value = value;
}
String_Constant_Expression_Node::String_Constant_Expression_Node(std::string value)
{
    this->value = value;
}
Null_Constant_Expression_Node::Null_Constant_Expression_Node()
{
}
ReadInteger_Expression_Node::ReadInteger_Expression_Node()
{
}
ReadLine_Expression_Node::ReadLine_Expression_Node()
{
}
New_Expression_Node::New_Expression_Node(Identifier_Node *identfier)
{
    this->identifier = identifier;
}
NewArray_Expression_Node::NewArray_Expression_Node(Expression_Node *identfier, Type_Node *type)
{
    this->expression = expression;
    this->type = type;
}
This_Expression_Node::This_Expression_Node()
{
}
#undef LZZ_INLINE
