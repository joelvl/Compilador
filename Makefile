FLAGS=-O3 -flto -Wall -std=c++14 `llvm-config --cppflags --ldflags --system-libs --libs core`

parser: scanner.l parser.y 
		bison -d parser.y
		flex scanner.l
		g++ -o parser lex.yy.c parser.tab.c -lfl $(FLAGS) -g -w
.PHONY: clean
clean:
		rm -rf *.o