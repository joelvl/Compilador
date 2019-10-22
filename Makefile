default: 
		flex -l scanner.l
		bison -dv parser.y
		g++ -o parser parser.tab.c lex.yy.c Nodo.cpp

