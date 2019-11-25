FLAGS=-O3 -flto -Wall -std=c++14

parser: parser.y scanner.l ast.h ast.cpp Declaration.cpp Declaration.h main.cpp ScopeStack.cpp
		clear
		bison -d parser.y
		flex scanner.l
		g++ -o parser main.cpp ast.cpp Declaration.cpp lex.yy.c parser.tab.c -lfl $(FLAGS) -g -w

clean:
		rm -rf *.o
