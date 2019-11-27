# Compilador de Decaf

**Estructura del Proyecto**

- scanner.l - Contiene el escáner del compilador decaf que se encarga de reconocer los tokens usando expresiones regulares.
- parser.y - Contiene el analizador del compilador decaf. Comprueba la macro-sintaxis del lenguaje.
- ast.h / ast.cpp - Contiene la implementación del AST (Árbol de análisis sintáctico). Incluye revisión semántica.
- Declaration.h / Declaration.cpp - Estructura que almacena infomación para cada Variable, Clase, Interface o Función declarada. Esta estructura se almacena en el ScopeStack.
- ScopeStack.cpp - Implementación de la pila para manejar los alcances del programa.
- main.cpp: inicia el proceso de análisis del programa.


**Pasos para ejecutar**
- Para compilar el código, use el comando 'make'.
- Para ejecutar el compilador en el archivo use el comando ` ./dcc < input.dcf` o ` ./dcc input.dcf`


- Ejemplo:
	- make
	- ./dcc < *archivo* o ./dcc *archivo*

**Descripción del proyecto**

# Escáner

- Scanner `flex` para escanear tokens.
- Detecta tokens usando expresiones regulares.

# Parser

- Parser `bison` para generar AST.
- Se implemento usando gramaticas libres de contexto.

# AST

- Árbol de análisis sintáctico que genera el parser.
- Imprime el árbol.
- Chequea la semántica del programa.

# Declaration

- Guarda los datos de cada variable, clase, interface o función.
- Incluye jerarquías para las clases.


