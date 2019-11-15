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

//Variable_Declaration_Node
Variable_Declaration_Node::Variable_Declaration_Node(Type_Node *type_node, Identifier_Node *identifier)
    : Declaration_Node(identifier)
{
    this->type_node = type_node;
}
void Variable_Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Variable Name: " << identifier->identifier << std::endl;
    type_node->print(depth + 1);
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
    std::cout << "Function Name: " << identifier->identifier << std::endl;
    type_node->print(depth + 1);
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
    std::cout << "Name: " << identifier->identifier ;
    if(implements->size() > 0){
        std::cout << " Implements: ";
        for (Identifier_Node *identifier : *implements){
            std::cout << identifier->identifier << " ";
        }
    }
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

//Statement_Node
Statement_Node::Statement_Node()
{
}
Statement_Block_Node::Statement_Block_Node(std::vector<AST_Node *> *statements)
{
    this->statements = statements;
}
void Statement_Block_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Block Declaration" << std::endl;
    for (AST_Node *statement : *statements){
        statement->print(depth + 1);
    }
}

//If_Statement_Node
If_Statement_Node::If_Statement_Node(Expression_Node *expression, Statement_Block_Node *if_block, Statement_Block_Node *else_block)
{
    this->expression = expression;
    this->if_block = if_block;
    this->else_block = else_block;
}
void If_Statement_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "If Statement" << std::endl;
    expression->print(depth + 1);
    std::cout << "If Block" << std::endl;
    if_block->print(depth + 1);
    std::cout << "Else Block" << std::endl;
    else_block->print(depth + 1);
}

//While_Statement_Node
While_Statement_Node::While_Statement_Node(Expression_Node *expression, Statement_Block_Node *block)
{
    this->expression = expression;
    this->block = block;
}
void While_Statement_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "While Statement" << std::endl;
    expression->print(depth + 1);
    std::cout << "Block" << std::endl;
    block->print(depth + 1);
}

//For_Statement_Node
For_Statement_Node::For_Statement_Node(Expression_Node *expressionA, Expression_Node *expressionB, Expression_Node *expressionC, Statement_Block_Node *block)
{
    this->expressionA = expressionA;
    this->expressionB = expressionB;
    this->expressionC = expressionC;
    this->block = block;
}
void For_Statement_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "For Statement" << std::endl;
    expressionA->print(depth + 1);
    expressionB->print(depth + 1);
    expressionC->print(depth + 1);
    block->print(depth + 1);
}

//Break_Statement_Node
Break_Statement_Node::Break_Statement_Node()
{
}
void Break_Statement_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Break Statement" << std::endl;
}

//Print_Statement_Node
Print_Statement_Node::Print_Statement_Node(std::vector<Expression_Node *> *expressions)
{
    this->expressions = expressions;
}
void Print_Statement_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Print Statement" << std::endl;
    for (Expression_Node *expression : *expressions){
        expression->print(depth + 1);
    }
}

//Return_Statement_Node
Return_Statement_Node::Return_Statement_Node(Expression_Node *expression)
{
    this->expression = expression;
}
void Return_Statement_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Return Statement" << std::endl;
    expression->print(depth + 1);
}

//Identifier_Statement_Node
Identifier_Node::Identifier_Node(std::string identifier)
{
    this->identifier = identifier;
}
void Identifier_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Identifier: " << identifier << std::endl;
}

//Type_Node
Type_Node::Type_Node(Datatype type)
{
    this->type = type;
}
Type_Node::Type_Node(Datatype type, Identifier_Node *identifier)
{
    this->type = type;
    this->identifier = identifier;
}
void Type_Node::print(int depth){
    std::cout << depthSpacing(depth) << "Type: ";
    switch (type)
    {
    case Datatype::int_type:
        std::cout << "INT" << std::endl;
        break;
    case Datatype::bool_type:
        std::cout << "BOOL" << std::endl;
        break;
    case Datatype::double_type :
        std::cout << "DOUBLE" << std::endl;
        break;
    case Datatype::string_type:
        std::cout << "STRING" << std::endl;
        break;
    case Datatype::null_type:
        std::cout << "VOID" << std::endl;
        break;
    case Datatype::identifier_type :
        std::cout << "IDENTIFIER TYPE" << std::endl;
        identifier->print(depth + 1);
        break;
    default:
        break;
    }
}

//Expression_Node
Expression_Node::Expression_Node()
{
}

//Comparation_Expression_Node
Comparation_Expression_Node::Comparation_Expression_Node(Expression_Node *leftExpression, Expression_Node *rightExpression, Operator_Type operator_Type)
{
    this->leftExpression = leftExpression;
    this->rightExpression = rightExpression;
    this->operator_Type = operator_Type;
}
void Comparation_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    switch (operator_Type)
    {
    case Operator_Type::PLUS:
        std::cout << "+";
        break;
    case Operator_Type::MINUS:
        std::cout << "+";
        break;
    case Operator_Type::MUL:
        std::cout << "*";
        break;
    case Operator_Type::DIV:
        std::cout << "/";
        break;
    case Operator_Type::MOD:
        std::cout << "%";
        break;
    case Operator_Type::LESS:
        std::cout << "<";
        break;
    case Operator_Type::LESSEQUAL:
        std::cout << "<=";
        break;
    case Operator_Type::GREATER:
        std::cout << ">";
        break;
    case Operator_Type::GREATEREQUAL:
        std::cout << ">=";
        break;
    case Operator_Type::EQUALEQUAL:
        std::cout << "==";
        break;
    case Operator_Type::EQUAL:
        std::cout << "=";
        break;
    case Operator_Type::NOTEQUAL:
        std::cout << "!=";
        break;
    case Operator_Type::AND:
        std::cout << "&&";
        break;
    case Operator_Type::OR:
        std::cout << "||";
        break;
    case Operator_Type::NOT:
        std::cout << "!";
        break;
    default:
        break;
    }
    std::cout << std::endl;
    if(leftExpression)
        leftExpression->print(depth + 1);
    if(rightExpression)
        rightExpression->print(depth + 1);
}

//Array_Expression_Node
Array_Expression_Node::Array_Expression_Node(Expression_Node *leftExpression, Expression_Node *rightExpression)
{
    this->leftExpression = leftExpression;
    this->rightExpression = rightExpression;
}
void Array_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Array Expression" << std::endl;
    leftExpression->print(depth + 1);
    rightExpression->print(depth + 1);
}

//Call_Expression_Node
Call_Expression_Node::Call_Expression_Node(Expression_Node *expression, Identifier_Node *identifier, std::vector<Expression_Node *> *actuals)
{
    this->expression = expression;
    this->identifier = identifier;
    this->actuals = actuals;
}
void Call_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Call Expression" << std::endl;
    expression->print(depth + 1);
    identifier->print(depth + 1);
    if(actuals)
        std::cout << "Parameters: ";
    for (Expression_Node *expression : *actuals){
        expression->print(depth + 1);
    }
}

//Identifier_Expression_Node
Identifier_Expression_Node::Identifier_Expression_Node(Identifier_Node *identifier)
{
    this->identifier = identifier;
}
void Identifier_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Identifier" << std::endl;
    identifier->print(depth + 1);
}

//Int_Constant_Expression_Node
Int_Constant_Expression_Node::Int_Constant_Expression_Node(int value)
{
    this->value = value;
}
void Int_Constant_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Int Constant: " << value << std::endl;
}

//Double_Constant_Expression_Node
Double_Constant_Expression_Node::Double_Constant_Expression_Node(double value)
{
    this->value = value;
}
void Double_Constant_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Double Constant: " << value << std::endl;
}

//Boolean_Constant_Expression_Node
Boolean_Constant_Expression_Node::Boolean_Constant_Expression_Node(bool value)
{
    this->value = value;
}
void Boolean_Constant_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Boolean Constant: " << (value ? "True" : "False") << std::endl;
}

//String_Constant_Expression_Node
String_Constant_Expression_Node::String_Constant_Expression_Node(std::string value)
{
    this->value = value;
}
void String_Constant_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "String Constant: " << value << std::endl;
}

//Null_Expression_Node
Null_Constant_Expression_Node::Null_Constant_Expression_Node()
{
}
void Null_Constant_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Null Constant" << std::endl;
}

//ReadInteger_Expression_Node
ReadInteger_Expression_Node::ReadInteger_Expression_Node()
{
}
void ReadInteger_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "ReadInteger" << std::endl;
}

//ReadLine_Expression_Node
ReadLine_Expression_Node::ReadLine_Expression_Node()
{
}
void ReadLine_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "ReadLine" << std::endl;
}

//New_Expression_Node
New_Expression_Node::New_Expression_Node(Identifier_Node *identfier)
{
    this->identifier = identifier;
}
void New_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "New" << std::endl;
    identifier->print(depth + 1);
}

//NewArray_Expression_Node
NewArray_Expression_Node::NewArray_Expression_Node(Expression_Node *expression, Type_Node *type)
{
    this->expression = expression;
    this->type = type;
}
void NewArray_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "New Array" << std::endl;
    expression->print(depth + 1);
    type->print(depth + 1);
}

//This_Expression_Node
This_Expression_Node::This_Expression_Node()
{
}
void This_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "This" << std::endl;
}
