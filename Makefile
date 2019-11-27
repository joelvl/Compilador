
dcc: parser.y scanner.l ast.h ast.cpp Declaration.cpp Declaration.h main.cpp ScopeStack.cpp
		clear
		bison -d parser.y
		flex scanner.l
		g++ -o dcc main.cpp ast.cpp Declaration.cpp lex.yy.c parser.tab.c -lfl -g -w

clean:
		rm -rf *.o
