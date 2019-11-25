#include "ast.h"

std::string typeToString(Type_Node type_)
{
    std::string str = "";
    switch (type_.type)
    {
    case Datatype::int_type:
        str = "int";
        break;
    case Datatype::double_type:
        str = "double";
        break;
    case Datatype::bool_type:
        str = "bool";
        break;
    case Datatype::string_type:
        str = "string";
        break;
    case Datatype::identifier_type:
        if (type_.identifier)
        {
            str = type_.identifier->identifier;
        }
        else
        {
            str = "<LOST IDENTIFIER>";
        }
        break;
    case Datatype::null_type:
        return "null";
    default:
        return "null";
    }

    if (type_.isArray())
    {
        str += "[]";
    }

    return str;
}

//AST_Node
void AST_Node::print(int depth) {}
AST_Node::AST_Node()
{
    this->parentClass = nullptr;
    this->parentFunction = nullptr;
}
AST_Node::~AST_Node() {}
int AST_Node::getScope()
{
    return this->scope;
}

void AST_Node::checkSemantic() {}

void AST_Node::setScope(int scope)
{
    this->scope = scope;
}

void AST_Node::setPos(int line, int column)
{
    this->line = line;
    this->column = column;
}

void AST_Node::printPos()
{
    std::cout << "At Line: " << line << " Column: " << column << ":" << std::endl
              << "    ";
}

std::string AST_Node::depthSpacing(int depth)
{
    std::string spacing = "╰╴";
    for (; depth > 0; depth--)
        spacing = "  " + spacing;
    return spacing;
}

void AST_Node::setParentClass(Class_Declaration *parent)
{
    this->parentClass = parent;
}

Class_Declaration *AST_Node::getParentClass()
{
    return this->parentClass;
}

void AST_Node::setParentInterface(Interface_Declaration *parent)
{
    this->parentInterface = parent;
}

Interface_Declaration *AST_Node::getParentInterface()
{
    return this->parentInterface;
}

void AST_Node::setParentFunction(Function_Declaration *parent)
{
    this->parentFunction = parent;
}

Function_Declaration *AST_Node::getParentFunction()
{
    return this->parentFunction;
}

//AST_PROGRAM
AST_Program::AST_Program(std::vector<Declaration_Node *> *declarations) : AST_Node()
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

void AST_Program::checkSemantic()
{
    this->setScope(scopes.getCurrentScopeId());
    for (Declaration_Node *declaration : *declarations)
    {
        declaration->checkSemantic();
    }
}

//Declaration_Node
Declaration_Node::Declaration_Node(Identifier_Node *identifier) : AST_Node()
{
    this->identifier = identifier;
}

//Variable_Declaration_Node
Variable_Declaration_Node::Variable_Declaration_Node(Type_Node *type_node, Identifier_Node *identifier)
    : Declaration_Node(identifier)
{
    this->type_node = type_node;
    this->classAtribute = false;
}
void Variable_Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Variable Name: " << identifier->identifier << std::endl;
    type_node->print(depth + 1);
}

void Variable_Declaration_Node::checkSemantic()
{
    Type_Node *type;
    if (type_node->type == Datatype::null_type)
    {
        printPos();
        std::cout << "Las variables pueden ser declaradas de cualquier tipo distinto a ​ void​." << std::endl;
        return;
    }
    else if (type_node->type == Datatype::identifier_type)
    {
        Declaration *class_Declaration = scopes.getDeclaration(type_node->identifier->identifier);
        if (!class_Declaration)
        {
            printPos();
            std::cout << "La clase " << type_node->identifier->identifier << " no está declarada." << std::endl;
            return;
        }
        else
        {
            if (class_Declaration->declarationType == DeclarationType::INTERFACE_DECLARATION)
            {
                printPos();
                std::cout << "Las interfaces no pueden ser declaradas." << std::endl;
                return;
            }
            type = class_Declaration->getType();
        }
    }
    else
    {
        type = type_node;
    }

    Variable_Declaration *variable = new Variable_Declaration(type, identifier->identifier);
    if (!scopes.addDeclaration(identifier->identifier, variable))
    {
        printPos();
        std::cout << "Redifinición. Los identificadores dentro de un alcance deben ser únicos." << std::endl;
    }
    else
    {
        if (classAtribute)
        {
            getParentClass()->addVariable(variable);
        }
    }
}
void Variable_Declaration_Node::setAsClassAtribute()
{
    this->classAtribute = true;
}

//Function_Declaration_Node
Function_Declaration_Node::Function_Declaration_Node(Type_Node *return_type, Identifier_Node *identifier, std::vector<Variable_Declaration_Node *> *parameters, Statement_Block_Node *statement_Block)
    : Declaration_Node(identifier)
{
    this->return_type = return_type;
    this->parameters = parameters;
    this->statement_Block = statement_Block;
}
void Function_Declaration_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Function Name: " << identifier->identifier << std::endl;
    return_type->print(depth + 1);
    if (parameters)
        for (Variable_Declaration_Node *variable_Declaration_Node : *parameters)
        {
            variable_Declaration_Node->print(depth + 1);
        }
    statement_Block->print(depth + 1);
}
void Function_Declaration_Node::checkSemantic()
{

    Function_Declaration *function = new Function_Declaration(return_type, identifier->identifier);

    //Parámetros únicos
    std::vector<Variable_Declaration_Node *> validParameters;

    if (parameters)
    {
        for (Variable_Declaration_Node *variable : *parameters)
        {
            //No Nulos
            if (variable->type_node->type == Datatype::null_type)
            {
                printPos();
                std::cout << "Los parámetros pueden ser de cualquier tipo, excepto ​ void." << std::endl;
                continue;
            }

            bool repetedVariable = false;
            for (Variable_Declaration_Node *validVariable : validParameters)
            {
                if (variable->identifier->identifier == validVariable->identifier->identifier)
                {
                    printPos();
                    std::cout << "Los identificadores usados en la declaración de parámetros deben ser distintos." << std::endl;
                    repetedVariable = true;
                    break;
                }
            }

            if (!repetedVariable)
            {
                validParameters.push_back(variable);
                function->addParameter(variable->type_node);
            }
        }
    }

    if (!scopes.addDeclaration(identifier->identifier, function))
    {
        printPos();
        std::cout << "Redifinición. Los identificadores dentro de un alcance deben ser únicos." << std::endl;
        return;
    }
    else
    {
        if (getParentClass() && getParentClass()->declarationType == DeclarationType::CLASS_DECLARATION)
        {
            Class_Declaration *parent = getParentClass();
            parent->addFunction(function);
        }
    }

    //Scope para los parámetros de la funcion
    scopes.addScope();

    for (Variable_Declaration_Node *validVariable : validParameters)
    {
        scopes.addDeclaration(validVariable->identifier->identifier,
                              new Variable_Declaration(validVariable->type_node, validVariable->identifier->identifier));
    }

    //Scope para el bloque de la función
    scopes.addScope();

    std::vector<AST_Node *> *statements = statement_Block->statements;

    for (AST_Node *statement : *statements)
    {
        statement->setParentClass(getParentClass());
        statement->setParentFunction(function);
        statement->checkSemantic();
    }

    if (!function->getValidReturn() && function->getType()->type != Datatype::null_type)
    {
        printPos();
        std::cout << "La función no tiene un return válido." << std::endl;
        return;
    }

    //Cierre scope para el bloque de la función
    scopes.backScope();
    //Cierre scope para los parámetros de la funcion
    scopes.backScope();
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
    if (implements)
    {
        std::cout << " Implements: ";
        for (Identifier_Node *identifier : *implements)
        {
            std::cout << identifier->identifier << " ";
        }
    }
    std::cout << std::endl;
    for (Declaration_Node *declaration : *field)
    {
        declaration->print(depth + 1);
    }
}
void Class_Declaration_Node::checkSemantic()
{
    Class_Declaration *clazz = new Class_Declaration(identifier->identifier);
    Declaration *extendedClass;
    Type_Node *type = new Type_Node(Datatype::identifier_type, this->identifier);
    bool extending = false;
    if (extends)
    {
        extendedClass = scopes.getDeclaration(extends->identifier);
        if (extendedClass)
        {
            if (extendedClass->declarationType != DeclarationType::CLASS_DECLARATION)
            {
                printPos();
                std::cout << "Las clases pueden heredar únicamente de otras clases." << std::endl;
                return;
            }
            else
            {
                extending = true;
                clazz->setExtends((Class_Declaration *)extendedClass);
                type->setDerived(extendedClass->getType());
                for (Type_Node *implementedInterface : extendedClass->getType()->implemented)
                {
                    if (!implements)
                    {
                        implements = new std::vector<Identifier_Node *>();
                    }
                    implements->push_back(implementedInterface->identifier);
                }
            }
        }
        else
        {
            printPos();
            std::cout << "La clase base " << extends->identifier << " no esta declarada." << std::endl;
            return;
        }
    }

    if (implements)
        for (Identifier_Node *identifier : *implements)
        {
            Declaration *interface_declaration = scopes.getDeclaration(identifier->identifier);
            if (interface_declaration->declarationType != DeclarationType::INTERFACE_DECLARATION)
            {
                printPos();
                std::cout << identifier->identifier << " no es una interface." << std::endl;
                continue;
            }
            else
            {
                type->implement(interface_declaration->getType());
            }
        }

    clazz->setType(type);

    if (!scopes.addDeclaration(identifier->identifier, clazz))
    {
        printPos();
        std::cout << "Redifinición. No se puede redifinir una clase." << std::endl;
        return;
    }

    if (extending)
    {
        scopes.stashScope();
        scopes.addScope(extendedClass->getScope());
    }

    //Declaración de miembros
    //Se crea el scope para la clase
    scopes.addScope();

    clazz->setScope(scopes.getCurrentScopeId());

    for (Declaration_Node *declaration : *field)
    {
        Class_Declaration *tempParentClass = (Class_Declaration *)extendedClass;
        if (extending)
        {
            if (instanceof <Function_Declaration_Node>(declaration))
            {
                while (tempParentClass)
                {
                    if (scopes.isDeclaredOnScope(declaration->identifier->identifier, tempParentClass->getScope()))
                    {
                        printPos();
                        std::cout << "No se puede sobre-escribir métodos de la clase base." << std::endl;
                        break;
                    }
                    tempParentClass = tempParentClass->getExtends();
                }
            }
            else if (instanceof <Variable_Declaration_Node>(declaration))
            {
                while (tempParentClass)
                {
                    if (scopes.isDeclaredOnScope(declaration->identifier->identifier, tempParentClass->getScope()))
                    {
                        printPos();
                        std::cout << "No se puede re-declarar atributos de la clase base." << std::endl;
                        break;
                    }
                    tempParentClass = tempParentClass->getExtends();
                }
            }
        }
        if (instanceof <Variable_Declaration_Node>(declaration)){
            ((Variable_Declaration_Node*) declaration)->setAsClassAtribute();
        }
        declaration->setParentClass(clazz);
        declaration->checkSemantic();
    }

    //Cierre de scope de clase
    scopes.backScope();

    if (extending)
    {
        scopes.popScope();
    }

    if (implements)
        for (Identifier_Node *identifier : *implements)
        {
            Declaration *interface_declaration = scopes.getDeclaration(identifier->identifier);
            if (interface_declaration->declarationType == DeclarationType::INTERFACE_DECLARATION)
            {
                if (!((Interface_Declaration *)interface_declaration)->validDerivedClass(clazz->functions))
                {
                    printPos();
                    std::cout << "La clase no define todos los métodos de la interface implementada." << std::endl;
                    return;
                }
            }
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
void Interface_Declaration_Node::checkSemantic()
{
    Interface_Declaration *interface = new Interface_Declaration(identifier->identifier);
    Type_Node *type = new Type_Node(Datatype::identifier_type, this->identifier);

    interface->setType(type);

    if (!scopes.addDeclaration(identifier->identifier, interface))
    {
        printPos();
        std::cout << "Redifinición. No se puede redifinir una interface." << std::endl;
        return;
    }

    //Declaración de miembros
    //Se crea el scope para la clase
    scopes.addScope();

    for (Prototype_Node *prototype : *prototypes)
    {
        prototype->setParentInterface(interface);
        prototype->checkSemantic();
    }

    //Cierre de scope de clase
    scopes.backScope();
}

//Prototype_Node
Prototype_Node::Prototype_Node(Type_Node *return_type, Identifier_Node *identifier, std::vector<Variable_Declaration_Node *> *parameters)
    : Declaration_Node(identifier)
{
    this->return_type = return_type;
    this->parameters = parameters;
}
void Prototype_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "Prototype Declaration" << std::endl;
    //TODO
}

void Prototype_Node::checkSemantic()
{
    Function_Declaration *function = new Function_Declaration(return_type, identifier->identifier);
    //Parámetros únicos
    std::vector<Variable_Declaration_Node *> validParameters;

    if (parameters)
    {
        for (Variable_Declaration_Node *variable : *parameters)
        {
            //No Nulos
            if (variable->type_node->type == Datatype::null_type)
            {
                printPos();
                std::cout << "Los parámetros pueden ser de cualquier tipo, excepto ​ void." << std::endl;
                continue;
            }

            bool repetedVariable = false;
            for (Variable_Declaration_Node *validVariable : validParameters)
            {
                if (variable->identifier->identifier == validVariable->identifier->identifier)
                {
                    printPos();
                    std::cout << "Los identificadores usados en la declaración de parámetros deben ser distintos." << std::endl;
                    repetedVariable = true;
                    break;
                }
            }

            if (!repetedVariable)
            {
                validParameters.push_back(variable);
                function->addParameter(variable->type_node);
            }
        }
    }

    if (!scopes.addDeclaration(identifier->identifier, function))
    {
        printPos();
        std::cout << "Redifinición. Los identificadores dentro de un alcance deben ser únicos." << std::endl;
        return;
    }
    else
    {
        if (getParentInterface() && getParentInterface()->declarationType == DeclarationType::INTERFACE_DECLARATION)
        {
            Interface_Declaration *parent = (Interface_Declaration *)getParentInterface();
            parent->addProtype(function);
        }
    }
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
    for (AST_Node *statement : *statements)
    {
        statement->print(depth + 1);
    }
}
void Statement_Block_Node::checkSemantic()
{
    for (AST_Node *statement : *statements)
    {
        statement->setParentClass(getParentClass());
        statement->setParentFunction(getParentFunction());
        statement->checkSemantic();
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

    std::cout << depthSpacing(depth + 1);
    std::cout << "If Block" << std::endl;

    if_block->print(depth + 2);
    if (else_block)
    {
        std::cout << depthSpacing(depth + 1);
        std::cout << "Else Block" << std::endl;
        else_block->print(depth + 2);
    }
}
void If_Statement_Node::checkSemantic()
{
    expression->setParentClass(getParentClass());
    expression->setParentFunction(getParentFunction());
    if (expression->getType().type != Datatype::bool_type)
    {
        expression->printPos();
        std::cout << "La expresión en la sección de condición booleana de un if debe ser de tipo boolean." << std::endl;
        return;
    }

    //Bloque IF
    scopes.addScope();
    if_block->setParentClass(getParentClass());
    if_block->setParentFunction(getParentFunction());
    if_block->checkSemantic();
    scopes.backScope();
    //Bloque ELSE
    if (else_block)
    {
        scopes.addScope();
        else_block->setParentClass(getParentClass());
        else_block->setParentFunction(getParentFunction());
        else_block->checkSemantic();
        scopes.backScope();
    }
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
    block->print(depth + 1);
}
void While_Statement_Node::checkSemantic()
{
    expression->setParentClass(getParentClass());
    expression->setParentFunction(getParentFunction());

    if (expression->getType().type != Datatype::bool_type)
    {
        expression->printPos();
        std::cout << "La expresión en la sección de condición booleana de un while debe ser de tipo boolean." << std::endl;
        return;
    }

    //Bloque
    scopes.addScope();
    block->setParentClass(getParentClass());
    block->setParentFunction(getParentFunction());
    block->checkSemantic();
    scopes.backScope();
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
    std::cout << depthSpacing(depth + 1);
    block->print(depth + 1);
}
void For_Statement_Node::checkSemantic()
{
    expressionA->setParentClass(getParentClass());
    expressionA->setParentFunction(getParentFunction());
    expressionB->setParentClass(getParentClass());
    expressionB->setParentFunction(getParentFunction());
    expressionC->setParentClass(getParentClass());
    expressionC->setParentFunction(getParentFunction());

    if (expressionB->getType().type != Datatype::bool_type)
    {
        expressionB->printPos();
        std::cout << "La expresión en la sección de condición booleana de un for debe ser de tipo boolean." << std::endl;
        return;
    }
    //Bloque
    scopes.addScope();
    block->setParentClass(getParentClass());
    block->setParentFunction(getParentFunction());
    block->checkSemantic();
    scopes.backScope();
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
    for (Expression_Node *expression : *expressions)
    {
        expression->print(depth + 1);
    }
}

void Print_Statement_Node::checkSemantic()
{
    for (Expression_Node *expression : *expressions)
    {
        expression->setParentClass(getParentClass());
        expression->setParentFunction(getParentFunction());

        if (expression->getType().type != Datatype::bool_type &&
            expression->getType().type != Datatype::int_type &&
            expression->getType().type != Datatype::string_type)
        {
            printPos();
            std::cout << "Las invocaciones a la función Print unicamente pueden ser int, bool o string." << std::endl;
            return;
        }
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
void Return_Statement_Node::checkSemantic()
{
    if (getParentFunction())
    {
        expression->setParentClass(getParentClass());
        expression->setParentFunction(getParentFunction());
        Type_Node expressionType = expression->getType();
        if (!expressionType.convertible(*getParentFunction()->type))
        {
            printPos();
            std::cout << "El return de tipo " << typeToString(expressionType)
                      << " no es compatible con " << typeToString(*getParentFunction()->type) << "." << std::endl;
            return;
        }
        else
        {
            getParentFunction()->setValidReturn();
        }
    }
    else
    {
        printPos();
        std::cout << "Los return pueden estar únicamente dentro de funciones." << std::endl;
        return;
    }
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
    this->array = false;
    this->identifier = nullptr;
}
Type_Node::Type_Node(Datatype type, Identifier_Node *identifier)
{
    this->type = type;
    this->identifier = identifier;
    this->array = false;
}
void Type_Node::setAsArray()
{
    this->array = true;
}

bool Type_Node::isArray()
{
    return this->array;
}

void Type_Node::print(int depth)
{
    std::cout << depthSpacing(depth) << "Type: ";
    switch (type)
    {
    case Datatype::int_type:
        std::cout << "INT" << std::endl;
        break;
    case Datatype::bool_type:
        std::cout << "BOOL" << std::endl;
        break;
    case Datatype::double_type:
        std::cout << "DOUBLE" << std::endl;
        break;
    case Datatype::string_type:
        std::cout << "STRING" << std::endl;
        break;
    case Datatype::null_type:
        std::cout << "VOID" << std::endl;
        break;
    case Datatype::identifier_type:
        std::cout << "IDENTIFIER TYPE" << std::endl;
        identifier->print(depth + 1);
        break;
    default:
        break;
    }
}
void Type_Node::setDerived(Type_Node *derives)
{
    this->derived = derives;
}

void Type_Node::implement(Type_Node *implements)
{
    this->implemented.push_back(implements);
}

bool Type_Node::convertible(Type_Node ntype)
{
    Type_Node *atype = this;
    Type_Node *btype = &ntype;

    if (atype->type == btype->type && atype->isArray() == btype->isArray())
    {
        if (atype->type == Datatype::identifier_type)
        {
            while (atype)
            {
                if (atype->identifier->identifier == btype->identifier->identifier)
                {
                    return true;
                }
                atype = atype->derived;
            }

            atype = this;
            for (Type_Node *type : atype->implemented)
            {
                std::cout << btype->identifier << std::endl;
                if (btype->identifier->identifier == type->identifier->identifier)
                {
                    return true;
                }
            }
        }
        else
        {
            return true;
        }
    }
    else if (atype->type == Datatype::identifier_type && btype->type == Datatype::null_type)
    {
        return true;
    }
    return false;
}

//Expression_Node
Expression_Node::Expression_Node()
{
}
Type_Node Expression_Node::getType()
{
    return Type_Node(Datatype::null_type);
}
void Expression_Node::checkSemantic()
{
    this->getType();
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
    if (leftExpression)
        leftExpression->print(depth + 1);
    if (rightExpression)
        rightExpression->print(depth + 1);
}
Type_Node Comparation_Expression_Node::getType()
{
    if (leftExpression)
    {
        leftExpression->setParentClass(getParentClass());
        leftExpression->setParentFunction(getParentFunction());
    }
    if (rightExpression)
    {
        rightExpression->setParentClass(getParentClass());
        rightExpression->setParentFunction(getParentFunction());
    }
    // +, -, *, /, %
    if (operator_Type == Operator_Type::PLUS ||
        operator_Type == Operator_Type::MINUS ||
        operator_Type == Operator_Type::MUL ||
        operator_Type == Operator_Type::DIV ||
        operator_Type == Operator_Type::MOD)
    {
        if ((rightExpression->getType().type == Datatype::int_type ||
             rightExpression->getType().type == Datatype::double_type) &&
            (!leftExpression ||
             leftExpression->getType().type == rightExpression->getType().type))
        {
            return rightExpression->getType();
        }
        else
        {
            printPos();
            std::cout << "Los dos operandos de operaciones aritméticas (+, -, *, /, %) deben ser ambos int, o ambos double." << std::endl;
            return Datatype::null_type;
        }
    }

    // >, >=, <, <=
    else if (operator_Type == Operator_Type::GREATER ||
             operator_Type == Operator_Type::GREATEREQUAL ||
             operator_Type == Operator_Type::LESS ||
             operator_Type == Operator_Type::LESSEQUAL)
    {
        if ((rightExpression->getType().type == Datatype::int_type ||
             rightExpression->getType().type == Datatype::double_type) &&
            (!leftExpression ||
             leftExpression->getType().type == rightExpression->getType().type))
        {
            return Type_Node(Datatype::bool_type);
        }
        else
        {
            printPos();
            std::cout << "Los dos operandos de operadores relacionales (<, >, <=, >=) deben ser ambos int, o ambos double." << std::endl;
            return Type_Node(Datatype::null_type);
        }
    }

    // ==, !=
    else if (operator_Type == Operator_Type::EQUALEQUAL || operator_Type == Operator_Type::NOTEQUAL)
    {
        if (leftExpression->getType().type == Datatype::null_type)
        {
            if (rightExpression->getType().type == Datatype::identifier_type)
            {
                Type_Node(Datatype::bool_type);
            }
            else
            {
                printPos();
                std::cout << "Los dos operandos de operadores de equidad pueden ser dos objetos o un objeto y la constante null." << std::endl;
            }
        }
        else if (rightExpression->getType().type == Datatype::null_type)
        {
            if (leftExpression->getType().type == Datatype::identifier_type)
            {
                Type_Node(Datatype::bool_type);
            }
            else
            {
                printPos();
                std::cout << "Los dos operandos de operadores de equidad pueden ser dos objetos o un objeto y la constante null." << std::endl;
            }
        }
        else if (leftExpression->getType().type != rightExpression->getType().type)
        {
            printPos();
            std::cout << "Los dos operandos de operadores de equidad deben ser de tipos equivalentes (dos enteros, dos doubles, dos arreglos de doubles, etc)." << std::endl;
            return Type_Node(Datatype::null_type);
        }
        else
        {
            return Type_Node(Datatype::bool_type);
        }
    }

    // &&, ||
    else if (operator_Type == Operator_Type::AND || operator_Type == Operator_Type::OR)
    {
        if (leftExpression->getType().type != rightExpression->getType().type || leftExpression->getType().type != Datatype::bool_type)
        {
            printPos();
            std::cout << "Los operandos de los operadores binarios y unarios (&&, || y !) deben ser de tipo bool." << std::endl;
            return Type_Node(Datatype::null_type);
        }
        else
        {
            return Type_Node(Datatype::bool_type);
        }
    }
    // =
    else if (operator_Type == Operator_Type::EQUAL)
    {
        Type_Node leftExpressionType = leftExpression->getType();
        Type_Node rightExpressionType = rightExpression->getType();
        if (!rightExpressionType.convertible(leftExpressionType))
        {
            printPos();
            std::cout << "La variable " << typeToString(rightExpressionType)
                      << " no es convertible a " << typeToString(leftExpressionType) << std::endl;
        }

        return Type_Node(Datatype::null_type);
    }
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
Type_Node Array_Expression_Node::getType()
{
    if (leftExpression)
    {
        leftExpression->setParentClass(getParentClass());
        leftExpression->setParentFunction(getParentFunction());
    }
    if (rightExpression)
    {
        rightExpression->setParentClass(getParentClass());
        rightExpression->setParentFunction(getParentFunction());
    }
    if (!leftExpression->getType().isArray())
    {
        printPos();
        std::cout << "La indexación de arreglos puede ser aplicada solamente a variables de tipo arreglo." << std::endl;
        return Type_Node(Datatype::null_type);
    }
    if (rightExpression->getType().type != Datatype::int_type)
    {
        printPos();
        std::cout << "Los índices de los arreglos deben ser enteros." << std::endl;
        return Type_Node(Datatype::null_type);
    }
    if (instanceof <Int_Constant_Expression_Node>(rightExpression))
    {
        if (((Int_Constant_Expression_Node *)rightExpression)->value < 0)
        {
            printPos();
            std::cout << "Los índices de los arreglos deben ser positivos." << std::endl;
            return Type_Node(Datatype::null_type);
        }
    }
    return Type_Node(leftExpression->getType().type);
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
    if (actuals)
        std::cout << "Parameters: ";
    for (Expression_Node *expression : *actuals)
    {
        expression->print(depth + 1);
    }
}
Type_Node Call_Expression_Node::getType()
{
    if (expression)
    {
        expression->setParentClass(getParentClass());
        expression->setParentFunction(getParentFunction());
    }
    Expression_Node *expression = this->expression;

    if (!expression)
    { // identifier(...);
        Declaration *declaration = scopes.getDeclaration(identifier->identifier);
        //variable
        if (declaration->declarationType == DeclarationType::VARIABLE_DECLARATION)
        {
            if (actuals)
            {
                printPos();
                std::cout << "Llamada de función a una variable." << std::endl;
                return Type_Node(Datatype::null_type);
            }
        }
        else if (declaration->declarationType == DeclarationType::FUNCTION_DECLARATION)
        {
            std::vector<Type_Node *> parameters;
            for (Expression_Node *expression : *actuals)
            {
                Type_Node tn = expression->getType();
                parameters.push_back(&tn);
            }
            if (!((Function_Declaration *)declaration)->checkParameters(parameters))
            {
                printPos();
                std::cout << " no tiene una función llamada " << identifier->identifier << std::endl;
                return Type_Node(Datatype::null_type);
            }
            else
            {
                return *((Function_Declaration *)declaration)->getType();
            }
        }
    }
    else
    { // expression.identifier(...) / expression.identifier;
        Type_Node type = expression->getType();
        if (type.type == Datatype::null_type)
        {
            printPos();
            std::cout << "No se pueden realizar llamadas a un tipo nulo." << std::endl;
            return Type_Node(Datatype::null_type);
        }
        else if (actuals)
        {                                                             // Si es una función tiene actuals aunque esté vacio
            if (identifier->identifier == "length" && type.isArray()) //función length para arrays
            {
                return Type_Node(Datatype::int_type);
            }
            else if (type.type == Datatype::identifier_type)
            {
                Declaration *declaration = scopes.getDeclaration(type.identifier->identifier);
                if (!declaration)
                {
                    printPos();
                    std::cout << "La variable " << typeToString(type) << " no está declarada." << std::endl; //?
                    return Type_Node(Datatype::null_type);
                }
                else if (declaration->declarationType == CLASS_DECLARATION)
                {
                    std::vector<Type_Node *> parameters;
                    for (Expression_Node *expression : *actuals)
                    {
                        Type_Node tn = expression->getType();
                        parameters.push_back(&tn);
                    }
                    Type_Node *returnType = ((Class_Declaration *)declaration)->getFunction(identifier->identifier, parameters);
                    if (!returnType)
                    {
                        printPos();
                        std::cout << type.identifier->identifier << " no tiene una función llamada " << identifier->identifier << "." << std::endl; //?
                        return Type_Node(Datatype::null_type);
                    }
                    else
                    {
                        return *returnType;
                    }
                }
                else
                {
                    printPos();
                    std::cout << type.identifier->identifier << " no es una clase." << std::endl; //?
                    return Type_Node(Datatype::null_type);
                }
            }
            else
            {
                printPos();
                std::cout << "El tipo " << typeToString(type) << " no tiene un método llamado " << identifier->identifier << "." << std::endl;
                return Type_Node(Datatype::null_type);
            }
        }
        else
        {
            Declaration *declaration = scopes.getDeclaration(type.identifier->identifier);
            if (!declaration)
            {
                printPos();
                std::cout << "La variable " << typeToString(type) << " no está declarada." << std::endl; //?
                return Type_Node(Datatype::null_type);
            }
            else if (declaration->declarationType == CLASS_DECLARATION)
            {
                Class_Declaration* clazz = ((Class_Declaration *) declaration);
                Type_Node *returnType = clazz->getVariable(identifier->identifier);
                if (!returnType)
                {
                    printPos();
                    std::cout << type.identifier->identifier << " no tiene un atributo llamado " << identifier->identifier << "." << std::endl; //?
                    return Type_Node(Datatype::null_type);
                }
                else if (getParentClass() && getParentClass()->type->convertible(*clazz->getType()))
                {
                    return *returnType;
                }
                else
                {
                    printPos();
                    std::cout << "No se puede acceder a un atributo privado." << std::endl; //?
                    return Type_Node(Datatype::null_type);
                }
            }
            else
            {
                printPos();
                std::cout << type.identifier->identifier << " no es una clase." << std::endl; //?
                return Type_Node(Datatype::null_type);
            }
            return Type_Node(Datatype::null_type);
        }
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
Type_Node Identifier_Expression_Node::getType()
{
    Declaration *declaration = scopes.getDeclaration(identifier->identifier);
    if (!declaration)
    {
        printPos();
        std::cout << "Uso de identificador no declarado: " << identifier->identifier << std::endl;
        return Type_Node(Datatype::null_type);
    }
    else
    {
        return *declaration->getType();
    }
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
Type_Node Int_Constant_Expression_Node::getType()
{
    return Type_Node(Datatype::int_type);
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
Type_Node Double_Constant_Expression_Node::getType()
{
    return Type_Node(Datatype::double_type);
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
Type_Node Boolean_Constant_Expression_Node::getType()
{
    return Type_Node(Datatype::bool_type);
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
Type_Node String_Constant_Expression_Node::getType()
{
    return Type_Node(Datatype::string_type);
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
Type_Node Null_Constant_Expression_Node::getType()
{
    return Type_Node(Datatype::null_type);
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
Type_Node ReadInteger_Expression_Node::getType()
{
    return Type_Node(Datatype::int_type);
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
Type_Node ReadLine_Expression_Node::getType()
{
    return Type_Node(Datatype::string_type);
}

//New_Expression_Node
New_Expression_Node::New_Expression_Node(Identifier_Node *identifier)
{
    this->identifier = identifier;
}
void New_Expression_Node::print(int depth)
{
    std::cout << depthSpacing(depth);
    std::cout << "New" << std::endl;
    identifier->print(depth + 1);
}
Type_Node New_Expression_Node::getType()
{
    Declaration *clazz = scopes.getDeclaration(this->identifier->identifier);
    if (!clazz)
    {
        printPos();
        std::cout << "No se puede instanciar una clase no declarada." << std::endl;
        return Type_Node(Datatype::null_type);
    }
    else if (clazz->declarationType != DeclarationType::CLASS_DECLARATION)
    {
        printPos();
        std::cout << "Solo se pueden instanciar clases." << std::endl;
        return Type_Node(Datatype::null_type);
    }
    else
    {
        return *clazz->getType();
    }
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
Type_Node NewArray_Expression_Node::getType()
{
    if (expression)
    {
        expression->setParentClass(getParentClass());
        expression->setParentFunction(getParentFunction());
    }
    if (expression->getType().type != Datatype::int_type)
    {
        printPos();
        std::cout << "Uso incorrecto de NewArray. Se espera un entero." << std::endl;
        return Type_Node(Datatype::null_type);
    }
    if (type->type == Datatype::null_type)
    {
        printPos();
        std::cout << "Uso incorrecto de NewArray. No se puede crear un array de nulos." << std::endl;
        return Type_Node(Datatype::null_type);
    }
    else
    {
        Type_Node array_type = *type;
        array_type.setAsArray();
        return array_type;
    }
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
Type_Node This_Expression_Node::getType()
{
    if (getParentClass())
    {
        return *getParentClass()->getType();
    }
    else
    {
        printPos();
        std::cout << "Uso incorrecto de This. Solo se puede usar dentro de alguna clase." << std::endl;
        return Type_Node(Datatype::null_type);
    }
}
