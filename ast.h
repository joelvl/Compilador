#ifndef _AST_H
#define _AST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "ScopeStack.cpp"
#include "Declaration.h"

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
class Print_Statement_Node;
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

class Declaration;
class Variable_Declaration;
class Function_Declaration;
class Class_Declaration;
class Interface_Declaration;

extern ScopeStack<Declaration> scopes;

enum class Datatype
{
    int_type,
    double_type,
    bool_type,
    string_type,
    null_type,
    identifier_type
};

std::string typeToString(Type_Node type);

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

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

union node {
    Datatype dataType;
    Operator_Type operator_type;
    AST_Program *program;
    Declaration_Node *decl;
    Function_Declaration_Node *functionDecl;
    Class_Declaration_Node *classDecl;
    Interface_Declaration_Node *interfaceDecl;
    Variable_Declaration_Node *variableDecl;
    Identifier_Node *optExtends;
    Declaration_Node *field;
    Prototype_Node *prototype;
    Statement_Block_Node *stmtBlock;
    Variable_Declaration_Node *variable;
    Type_Node *type;
    Statement_Node *stmt;
    If_Statement_Node *ifStmt;
    Statement_Block_Node *optElse;
    While_Statement_Node *whileStmt;
    For_Statement_Node *forStmt;
    Return_Statement_Node *returnStmt;
    Break_Statement_Node *breakStmt;
    Print_Statement_Node *printStmt;
    Expression_Node *expression;
    Expression_Node *constant;

    std::vector<Variable_Declaration_Node *> *optFormals;
    std::vector<Expression_Node *> *expressionList;
    std::vector<Expression_Node *> *optActualList;
    std::vector<Expression_Node *> *actualList;
    std::vector<Expression_Node *> *actuals;
    std::vector<Prototype_Node *> *prototypes;
    std::vector<AST_Node *> *stmts;
    std::vector<Identifier_Node *> *optImplements;
    std::vector<Declaration_Node *> *fields;
    std::vector<Declaration_Node *> *decls;
    std::vector<Identifier_Node *> *identifiers;
    std::vector<Variable_Declaration_Node *> *formals;

    int ival;
    double dval;
    char cval;
    char *sval;
};
typedef union node YYSTYPE;
#define YYSTYPE_IS_DECLARED 1

class AST_Node
{
    int line, column;
    int scope;
    Class_Declaration* parentClass;
    Interface_Declaration* parentInterface;
    Function_Declaration* parentFunction;
public:
    std::string depthSpacing(int depth);
    AST_Node();
    ~AST_Node();
    int getScope();
    void setScope(int scope);
    void setPos(int line, int column);
    void printPos();
    virtual void checkSemantic();
    virtual void print(int depth);
    void setParentClass(Class_Declaration* parent);
    Class_Declaration* getParentClass();
    void setParentInterface(Interface_Declaration* parent);
    Interface_Declaration* getParentInterface();
    void setParentFunction(Function_Declaration* parent);
    Function_Declaration* getParentFunction();
};

class AST_Program : public AST_Node
{
public:
    std::vector<Declaration_Node *> *declarations;
    AST_Program(std::vector<Declaration_Node *> *declarations);
    virtual void checkSemantic();
    virtual void print(int depth);
};

class Declaration_Node : public AST_Node
{
public:
    Identifier_Node *identifier;
    Declaration_Node(Identifier_Node *identifier);
};

class Variable_Declaration_Node : public Declaration_Node
{
public:
    Type_Node *type_node;
    bool classAtribute;
    Variable_Declaration_Node(Type_Node *type_node, Identifier_Node *identifier);
    virtual void checkSemantic();
    virtual void print(int depth);
    void setAsClassAtribute();
};

class Function_Declaration_Node : public Declaration_Node
{
public:
    Type_Node *return_type;
    std::vector<Variable_Declaration_Node *> *parameters;
    Statement_Block_Node *statement_Block;
    Function_Declaration_Node(Type_Node *type_node, Identifier_Node *identifier, std::vector<Variable_Declaration_Node *> *parameters, Statement_Block_Node *statement_Block);
    virtual void checkSemantic();
    virtual void print(int depth);
};

class Class_Declaration_Node : public Declaration_Node
{
public:
    Identifier_Node *extends;
    std::vector<Identifier_Node *> *implements;

    std::vector<Declaration_Node *> *field;
    Class_Declaration_Node(Identifier_Node *identifier, Identifier_Node *extends, std::vector<Identifier_Node *> *implements, std::vector<Declaration_Node *> *field);
    virtual void checkSemantic();
    virtual void print(int depth);
};

class Interface_Declaration_Node : public Declaration_Node //TODO
{
public:
    std::vector<Prototype_Node *> *prototypes;
    Interface_Declaration_Node(Identifier_Node *identifier, std::vector<Prototype_Node *> *prototypes);
    virtual void print(int depth);
    virtual void checkSemantic();
};

class Prototype_Node : public Declaration_Node //TODO
{
public:
    Type_Node *return_type;
    std::vector<Variable_Declaration_Node *> *parameters;
    Prototype_Node(Type_Node *return_type, Identifier_Node *identifier, std::vector<Variable_Declaration_Node *> *parameters);
    virtual void print(int depth);
    virtual void checkSemantic();
};

class Statement_Node : public AST_Node
{
public:
    Statement_Node();
};

class Statement_Block_Node : public Statement_Node
{
public:
    unsigned int scopeid;
    std::vector<AST_Node *> *statements;
    Statement_Block_Node(std::vector<AST_Node *> *statements);
    virtual void checkSemantic();
    virtual void print(int depth);
};

class If_Statement_Node : public Statement_Node
{
public:
    Expression_Node *expression;
    Statement_Block_Node *if_block;
    Statement_Block_Node *else_block;
    If_Statement_Node(Expression_Node *expression, Statement_Block_Node *if_block, Statement_Block_Node *else_block);
    virtual void checkSemantic();
    virtual void print(int depth);
};

class While_Statement_Node : public Statement_Node
{
public:
    Expression_Node *expression;
    Statement_Block_Node *block;
    While_Statement_Node(Expression_Node *expression, Statement_Block_Node *block);
    virtual void checkSemantic();
    virtual void print(int depth);
};

class For_Statement_Node : public Statement_Node
{
public:
    Expression_Node *expressionA;
    Expression_Node *expressionB;
    Expression_Node *expressionC;
    Statement_Block_Node *block;
    For_Statement_Node(Expression_Node *expressiA, Expression_Node *expressiB, Expression_Node *expressionC, Statement_Block_Node *block);
    virtual void checkSemantic();
    virtual void print(int depth);
};

class Break_Statement_Node : public Statement_Node
{
public:
    Break_Statement_Node();
    virtual void print(int depth);
};

class Print_Statement_Node : public Statement_Node
{
public:
    std::vector<Expression_Node *> *expressions;
    Print_Statement_Node(std::vector<Expression_Node *> *expressions);
    virtual void print(int depth);
    virtual void checkSemantic();
};

class Return_Statement_Node : public Statement_Node
{
public:
    Expression_Node *expression;
    Return_Statement_Node(Expression_Node *expression);
    virtual void print(int depth);
    virtual void checkSemantic();
};

class Identifier_Node : public AST_Node
{
public:
    std::string identifier;
    Identifier_Node(std::string identifier);
    virtual void print(int depth);
};

class Type_Node : public AST_Node
{
public:
    Datatype type;
    Identifier_Node *identifier;
    Type_Node* derived;
    std::vector<Type_Node*> implemented;
    bool array;
    bool isArray();
    Type_Node(Datatype type);
    Type_Node(Datatype type, Identifier_Node *identifier);
    void setAsArray();
    virtual void print(int depth);
    void setDerived(Type_Node* type_Node);
    void implement(Type_Node* type_Node);
    bool convertible(Type_Node type_node);
};

class Expression_Node : public Statement_Node
{
public:
    Expression_Node();
    virtual Type_Node getType();
    virtual void checkSemantic();
};

class Comparation_Expression_Node : public Expression_Node
{
public:
    Expression_Node *leftExpression;
    Expression_Node *rightExpression;
    Operator_Type operator_Type;
    Comparation_Expression_Node(Expression_Node *leftExpression, Expression_Node *rightExpression, Operator_Type operator_Type);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class Array_Expression_Node : public Expression_Node
{
public:
    Expression_Node *leftExpression;
    Expression_Node *rightExpression;
    Array_Expression_Node(Expression_Node *leftExpression, Expression_Node *rightExpression);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class Call_Expression_Node : public Expression_Node
{
public:
    Expression_Node *expression;
    Identifier_Node *identifier;
    std::vector<Expression_Node *> *actuals;
    Call_Expression_Node(Expression_Node *expression, Identifier_Node *identifier, std::vector<Expression_Node *> *actuals);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class Identifier_Expression_Node : public Expression_Node
{
public:
    Identifier_Node *identifier;
    Identifier_Expression_Node(Identifier_Node *identifier);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class Int_Constant_Expression_Node : public Expression_Node
{
public:
    int value;
    Int_Constant_Expression_Node(int value);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class Double_Constant_Expression_Node : public Expression_Node
{
public:
    double value;
    Double_Constant_Expression_Node(double value);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class Boolean_Constant_Expression_Node : public Expression_Node
{
public:
    bool value;
    Boolean_Constant_Expression_Node(bool value);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class String_Constant_Expression_Node : public Expression_Node
{
public:
    std::string value;
    String_Constant_Expression_Node(std::string value);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class Null_Constant_Expression_Node : public Expression_Node
{
public:
    Null_Constant_Expression_Node();
    virtual void print(int depth);
    virtual Type_Node getType();
};

class ReadInteger_Expression_Node : public Expression_Node
{
public:
    ReadInteger_Expression_Node();
    virtual void print(int depth);
    virtual Type_Node getType();
};

class ReadLine_Expression_Node : public Expression_Node
{
public:
    ReadLine_Expression_Node();
    virtual void print(int depth);
    virtual Type_Node getType();
};

class New_Expression_Node : public Expression_Node
{
public:
    Identifier_Node *identifier;
    New_Expression_Node(Identifier_Node *identifier);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class NewArray_Expression_Node : public Expression_Node
{
public:
    Expression_Node *expression;
    Type_Node *type;
    NewArray_Expression_Node(Expression_Node *identfier, Type_Node *type);
    virtual void print(int depth);
    virtual Type_Node getType();
};

class This_Expression_Node : public Expression_Node
{
public:
    This_Expression_Node();
    virtual void print(int depth);
    virtual Type_Node getType();
};

#endif