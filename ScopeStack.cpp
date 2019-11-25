#include <iostream>
#include <string>
#include <vector>

template <typename T> 
struct HashNode {
    std::string key;
    T* value;

    HashNode<T>* next;

    HashNode(std::string key, T* value){
        this->key = key;
        this->value = value;
    }
};

template <typename T>
class HashMap {
    HashNode<T>* first;

public:
    HashMap(){
        
    }

    void put(std::string key, T* value){
        if(!first){
            first = new HashNode<T>(key, value);
            return;
        }
        HashNode<T>* hashNode = first;
        while(hashNode){
            if(hashNode->key == key){
                hashNode->value = value;
                return;
            }
            if(!hashNode->next){
                break;
            }
            hashNode = hashNode->next;
        }
        hashNode->next = new HashNode<T>(key, value);
    }

    T* get(std::string key){
        HashNode<T>* hashNode = first;
        while(hashNode){
            if(hashNode->key == key)
                return hashNode->value;
            hashNode = hashNode->next;
        }
        return nullptr;
    }

    void print(){
        HashNode<T>* node = first;
        while(node){
            std::cout << "  " << node->key << std::endl;
            node = node->next;
        }
    }
};


template <typename T>
class Scope {
    unsigned int id;
    Scope<T>* parent;
    HashMap<T>* symbolTable;

public:
    Scope(int id){
        this->id = id;
        this->symbolTable = new HashMap<T>();
    }
    
    Scope(int id, Scope<T>* parent){
        this->id = id;
        this->parent = parent;
        this->symbolTable = new HashMap<T>();
    }

    unsigned int getId(){
        return id;
    }

    Scope<T>* getParent(){
        return parent;
    }

    bool isDeclared(T identifier){
        return symbolTable->get(identifier) == nullptr ? false : true;
    }

    T* getType(std::string identifier){
        return symbolTable->get(identifier);
    }

    void declare(std::string identifier, T* type){
        symbolTable->put(identifier, type);
    }

    void print(){
        symbolTable->print();
    }
};

template <typename T>
class ScopeStack{
    unsigned int scopeCount;
    std::vector<Scope<T>*> scopes = std::vector<Scope<T>*>();
    Scope<T>* mainScope;
    Scope<T>* currentScope;
    std::vector<Scope<T>*> stashedScopes;

    T* getDeclaration(std::string identifier, Scope<T>* searchingScope){
        T* type;
        while (searchingScope){
            type = searchingScope->getType(identifier);
            if(type) {
                return type;
            } else {
                searchingScope = searchingScope->getParent();
            }
        }
        return nullptr;
    }

    unsigned int getScopeIdForDeclaration(std::string identifier, Scope<T>* searchingScope){
        T* type;
        while (searchingScope){
            type = searchingScope->getType(identifier);
            if(type) {
                return searchingScope->getId();
            } else {
                searchingScope = searchingScope->getParent();
            }
        }
        return 0;
    }

public:
    ScopeStack(){
        this->scopeCount = 0;
        addScope();
    }

    unsigned int getCurrentScopeId(){
        return currentScope->getId();
    }

    void addScope(){
        currentScope = new Scope<T>(scopeCount++, currentScope);
        scopes.push_back(currentScope);
        if(!mainScope)
            mainScope = currentScope;
    }

    void stashScope(){
        stashedScopes.push_back(currentScope);
    }

    void popScope(){
        if (!stashedScopes.empty()){
            currentScope = stashedScopes.back();
            stashedScopes.pop_back();
        }
    }

    void addScope(unsigned int parentId){
        Scope<T>* parentScope = getScope(parentId);
        if (!parentScope) 
            return;
        Scope<T>* newScope = new Scope<T>(scopeCount++, parentScope);
        scopes.push_back(newScope);
        if(!mainScope)
            mainScope = newScope;
            currentScope = newScope;
    }

    void backScope(){
        if(currentScope->getParent())
            currentScope = currentScope->getParent();
    }

    void gotoScope(unsigned int id){
        for (Scope<T>* scope : scopes){
            if (scope->getId() == id){
                currentScope = scope;
                return;
            }
        }
    }

    Scope<T>* getScope(unsigned int id){
        for (Scope<T>* scope : scopes){
            if (scope->getId() == id){
                return scope;
            }
        }
    }

    unsigned int getScopeIdForDeclaration(std::string identifier){
        unsigned int scopeId = getScopeIdForDeclaration(identifier, currentScope);
        std::cout << scopeId << std::endl;
        return scopeId;
    }
    
    bool addDeclaration(std::string identifier, T* type){
        if (isDeclaredOnCurrentScope(identifier)) return false;
        currentScope->declare(identifier, type);
        return true;
    }

    bool isDeclaredOnCurrentScope(std::string identifier){
        return currentScope->getType(identifier) == nullptr ? false : true;
    }

    bool isDeclaredOnScope(std::string identifier, unsigned int scopeId){
        Scope<T>* scope = getScope(scopeId);
        if (scope)
            return scope->getType(identifier) == nullptr ? false : true;
        else
            return false;
    }

    T* getDeclaration(std::string identifier){
        return getDeclaration(identifier, currentScope);
    }

    T* getDeclaration(std::string identifier, unsigned int id){
        for(Scope<T>* scope : scopes){
            if(scope->getId() == id){
                return getDeclaration(identifier, scope);
            }
        }
    }

    bool isDeclared(std::string identifier){
        return getDeclaration(identifier) == nullptr ? false : true;
    }

    bool isDeclared(std::string identifier, unsigned int id){
        return getDeclaration(identifier, id) == nullptr ? false : true;
    }

    void printScopeStack(){
        for(Scope<T>* scope : scopes){
            int nestingLevel = getScopeNestingLevel(scope);
            while(nestingLevel){
                std::cout << "  ";
                nestingLevel--;
            }
            std::cout << scope->getId() << std::endl;
        }
    }

    int getScopeNestingLevel(Scope<T>* scope){
        if(!scope)
            return 0;
        return getScopeNestingLevel(scope->getParent()) + 1;
    }

    void printScopes(){
        for (Scope<T>* scope : scopes){
            if (scope->getParent())
                std::cout << "ID: " << scope->getId()  << " P: " << scope->getParent()->getId() << std::endl;
            else
                std::cout << "ID: " << scope->getId()  << std::endl;
            scope->print();
        }
    }
};


/*
int test(){
    ScopeStack<Declaration>* ss = new ScopeStack<std::string>();

    ss->addDeclaration("hola", "int");
    ss->addScope();
    ss->addScope();
    ss->backScope();
    ss->backScope();
    ss->addScope();
    ss->addScope();
    ss->addDeclaration("test", "double");

    std::cout << *ss->getDeclaration("hola") << std::endl;
    ss->backScope();
    std::cout << *ss->getDeclaration("hola") << std::endl;

    ss->printScopeStack();
}
*/