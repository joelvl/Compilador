#ifndef _AST_H
#define _AST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class AST_Node; 
class AST_Program;
class Declaration_Node;
class Variable_Declaration_Node;
class Function_Declaration_Node;
class Statement_Node;
class Statement_Block_Node;
class Expression_Node;
class If_Statement_Node;
class While_Statement_Node;
class For_Statement_Node;
class Break_Statement_Node;
class Print_StateMent_Node;
class Return_Statement_Node;
class Class_Declaration_Node;
class Interface_Declaration_Node;
class Prototype_Node;
class Identifier_Node;
class Type_Node;
class Comparation_Expression_Node;
class Array_Expression_Node;
class Call_Expression_Node;
class Identifier_Expression_Node;
class Int_Constant_Expression_Node;
class Double_Constant_Expression_Node;
class Boolean_Constant_Expression_Node;
class String_Constant_Expression_Node;
class Null_Constant_Expression_Node;
class ReadInteger_Expression_Node;
class ReadLine_Expression_Node;
class New_Expression_Node;
class NewArray_Expression_Node;
class This_Expression_Node;


enum class Datatype
{
    int_type,
    double_type,
    bool_type,
    string_type,
    identifier_type,
    null_type
};

enum class Operator_Type
{
    PLUS,
    MINUS,
    MUL,
    DIV,
    MOD,
    LESS,
    LESSEQUAL,
    GREATER,
    GREATEREQUAL,
    EQUALEQUAL,
    EQUAL,
    NOTEQUAL,
    AND,
    OR,
    NOT
};

union node{
    AST_Program * program;
    Declaration_Node * decl;
    Function_Declaration_Node * functionDecl;
    Class_Declaration_Node * classDecl;
    Interface_Declaration_Node * interfaceDecl;
    Variable_Declaration_Node * variableDecl;
    Identifier_Node * optExtends;
    Declaration_Node * field;
    Prototype_Node * prototype;
    Statement_Block_Node * stmtBlock;
    Variable_Declaration_Node * variable;
    Type_Node * type;
    Statement_Node * stmt;
    If_Statement_Node * ifStmt;
    Statement_Block_Node * optElse;
    While_Statement_Node * whileStmt;
    For_Statement_Node * forStmt;
    Return_Statement_Node * returnStmt;
    Break_Statement_Node * breakStmt;
    Print_StateMent_Node * printStmt;
    Expression_Node * expression;
    Expression_Node * constant;
    
    std::vector<Variable_Declaration_Node*> * optFormals;
    std::vector<Expression_Node*> * expressionList;
    std::vector<Expression_Node*> * optActualList;
    std::vector<Expression_Node*> * actualList;
    std::vector<Expression_Node*> * actuals;
    std::vector<Prototype_Node*> * prototypes;
    std::vector<Statement_Node*> stmts;
    std::vector<Identifier_Node*> * optImplements;
    std::vector<Declaration_Node*> * fields;
    std::vector<Declaration_Node*> * decls;
    std::vector<Identifier_Node*> * identifiers;
    std::vector<Variable_Declaration_Node*> * formals;

    int ival;
    double dval;
    char cval;
    char* sval;
};


typedef union node YYSTYPE;
#define YYSTYPE_IS_DECLARED 1

class AST_Node {
public:
    AST_Node() {}
    ~AST_Node() {}
};

class AST_Program: public AST_Node
{
public:
    std::vector<Declaration_Node* > * declarations;
    AST_Program(std::vector<Declaration_Node* > * declarations) {
        this->declarations = declarations;
    }
};

class Declaration_Node: public AST_Node
{
public:
    Identifier_Node* identifier;
    Declaration_Node(Identifier_Node* identifier){
        this->identifier = identifier;
    }
};

class Variable_Declaration_Node: public Declaration_Node
{
public:
    Type_Node * type_node;

    Variable_Declaration_Node(Type_Node * type_node, Identifier_Node* identifier) : Declaration_Node(identifier){
        this->type_node = type_node;
    }

};

class Function_Declaration_Node: public Declaration_Node
{
public:
    Type_Node * type_node;
    std::vector<Variable_Declaration_Node* >* parameters;
    Statement_Block_Node* statement_Block;
    Function_Declaration_Node(Type_Node * type_node, Identifier_Node* identifier, 
        std::vector<Variable_Declaration_Node*>* parameters, Statement_Block_Node* statement_Block) 
            : Declaration_Node(identifier){
        this->type_node = type_node;
        this->parameters = parameters;
        this->statement_Block = statement_Block;
    }

};

class Statement_Node : public AST_Node
{
public:
    Statement_Node(){}
};

class Statement_Block_Node : public AST_Node
{
public:
    std::vector<Statement_Node* >* statements;
    Statement_Block_Node(std::vector<Statement_Node* >* statements){
        this->statements = statements;
    }
};

class Field_Node : public AST_Node
{
public:
    std::vector<Declaration_Node*>* declarations;
    Field_Node(std::vector<Declaration_Node*>* declarations){
        this->declarations = declarations;
    }
};

class If_Statement_Node : public Statement_Node
{
public:
    Expression_Node* expression;
    Statement_Block_Node* if_block;
    Statement_Block_Node* else_block;
    If_Statement_Node(Expression_Node* expression, Statement_Block_Node* if_block, Statement_Block_Node* else_block){
        this->expression = expression;
        this->if_block = if_block;
        this->else_block = else_block;
    }
};

class While_Statement_Node : public Statement_Node
{
public:
    Expression_Node* expression;
    Statement_Block_Node* block;
    While_Statement_Node(Expression_Node* expression, Statement_Block_Node* block){
        this->expression = expression;
        this->block = block;
    }
};

class For_Statement_Node : public Statement_Node
{
public:
    Expression_Node* expressionA;
    Expression_Node* expressionB;
    Expression_Node* expressionC;
    Statement_Block_Node* block;
    For_Statement_Node(Expression_Node* expressiA, Expression_Node* expressiB, Expression_Node* expressionC, Statement_Block_Node* block){
        this->expressionA = expressionA;
        this->expressionB = expressionB;
        this->expressionC = expressionC;
        this->block = block;
    }
};

class Break_Statement_Node : public Statement_Node
{
public:
    Break_Statement_Node();
};

class Print_StateMent_Node : public Statement_Node
{
public:
    std::vector<Expression_Node*> * expressions;
    Print_StateMent_Node(std::vector<Expression_Node*> * expressions){
        this->expressions = expressions;
    }
};

class Return_Statement_Node : public Statement_Node
{
public:
    Expression_Node * expression;
    Return_Statement_Node(Expression_Node * expression){
        this->expression = expression;
    }
};

class Class_Declaration_Node : public Declaration_Node
{
public:
    Identifier_Node * extends;
    std::vector<Identifier_Node*> * implements;
    Statement_Block_Node * statementBlock;
    Class_Declaration_Node(Identifier_Node* identifier, Identifier_Node* extends, 
                std::vector<Identifier_Node*>* implements, Statement_Block_Node* statementBlock) : Declaration_Node(identifier){
        this->extends = extends;
        this->implements = implements;
        this->statementBlock = statementBlock;
    }
};

class Interface_Declaration_Node : public Declaration_Node
{
public:
    std::vector<Identifier_Node*> * prototypes;
    Interface_Declaration_Node(Identifier_Node* identifier, std::vector<Identifier_Node*> * prototypes) : Declaration_Node(identifier){
        this->prototypes = prototypes;
    }
};

class Prototype_Node: public Declaration_Node
{
public:
    Type_Node * type_node;
    std::vector<Variable_Declaration_Node* >* parameters;
    Prototype_Node(Type_Node * type_node, Identifier_Node* identifier, std::vector<Variable_Declaration_Node*>* parameters) : Declaration_Node(identifier){
        this->type_node = type_node;
        this->parameters = parameters;
    }

};

class Identifier_Node : AST_Node
{
public:
    Identifier_Node* identifier;
    Identifier_Node(Identifier_Node* identifier){
        this->identifier = identifier;
    }
};

class Type_Node : public AST_Node
{
public:
    Datatype type;
    Identifier_Node* identifier;
    Type_Node(Datatype type){
        this->type = type;
    }
    Type_Node(Datatype type, Identifier_Node* identifier){
        this->type = type;
        this->identifier = identifier;
    }
};

class Expression_Node : public Statement_Node
{
public:
    Expression_Node(){}
};

class Comparation_Expression_Node : public Expression_Node
{
public:
    Expression_Node* leftExpression;
    Expression_Node* rightExpression;
    Operator_Type operator_Type;
    Comparation_Expression_Node(Expression_Node* leftExpression, Expression_Node* rightExpression, Operator_Type operator_Type){
        this->leftExpression = leftExpression;
        this->rightExpression = rightExpression;
        this->operator_Type = operator_Type;
    }
};

class Array_Expression_Node : public Expression_Node
{
public:
    Expression_Node* leftExpression;
    Expression_Node* rightExpression;
    Array_Expression_Node(Expression_Node* leftExpression, Expression_Node* rightExpression){
        this->leftExpression = leftExpression;
        this->rightExpression = rightExpression;
    }
};

class Call_Expression_Node : public Expression_Node
{
public:
    Expression_Node* expression;
    Identifier_Node* identifier;
    std::vector<Expression_Node*>* actuals;
    Call_Expression_Node(Expression_Node* expression, Identifier_Node* identifier, std::vector<Expression_Node*>* actuals){
        this->expression = expression;
        this->identifier = identifier;
        this->actuals = actuals;
    }
};

class Identifier_Expression_Node : public Expression_Node
{
public:
    Identifier_Node* identifier;
    Identifier_Expression_Node(Identifier_Node* identifier){
        this->identifier = identifier;
    }
};

class Int_Constant_Expression_Node : public Expression_Node
{
public:
    int value;
    Int_Constant_Expression_Node(int value){
        this->value = value;
    }
};

class Double_Constant_Expression_Node : public Expression_Node
{
public:
    double value;
    Double_Constant_Expression_Node(double value){
        this->value = value;
    }
};

class Boolean_Constant_Expression_Node : public Expression_Node
{
public:
    bool value;
    Boolean_Constant_Expression_Node(bool value){
        this->value = value;
    }
};

class String_Constant_Expression_Node : public Expression_Node
{
public:
    std::string value;
    String_Constant_Expression_Node(std::string value){
        this->value = value;
    }
};

class Null_Constant_Expression_Node : public Expression_Node
{
public:
    Null_Constant_Expression_Node(){}
};

class ReadInteger_Expression_Node : public Expression_Node
{
public:
    ReadInteger_Expression_Node(){}
};

class ReadLine_Expression_Node : public Expression_Node
{
public:
    ReadLine_Expression_Node(){}
};

class New_Expression_Node : public Expression_Node
{
public:
    Identifier_Node* identifier;
    New_Expression_Node(Identifier_Node* identfier){
        this->identifier = identifier;
    }
};

class NewArray_Expression_Node : public Expression_Node
{
public:
    Expression_Node* expression;
    Type_Node* type;
    NewArray_Expression_Node(Expression_Node* identfier, Type_Node* type){
        this->expression = expression;
        this->type = type;
    }
};

class This_Expression_Node : public Expression_Node
{
public:
    This_Expression_Node(){}
};

#endif