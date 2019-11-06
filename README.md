# Compilador de Decaf

**Estructura del Proyecto**

- scanner.l - Contiene el escáner del compilador decaf que se encarga de reconocer los tokens usando expresiones regulares.
- parser.y - Contiene el analizador del compilador decaf. Comprueba la macro-sintaxis del lenguaje.
- ast.h - Contiene declaraciones de todas las clases utilizadas en la construcción de AST.
- ast.cpp: contiene todas las funciones de las clases, excepto las declaraciones, clases relacionadas con los métodos necesarias para AST.
- main.cpp: inicia el proceso de análisis del programa.

**Pasos para ejecutar**
- Para compilar el código, use el comando 'make'.
- Para ejecutar el compilador en el archivo use el comando ` ./parser input.dcf`


- Ejemplo:
	- make
	- ./parser *archivo*

**Descripción del proyecto**


# Escáner

- Scanner `flex` para escanear tokens.
- Detecta tokens usando expresiones regulares.

# Parser

- Parser `bison` para generar AST
- Se implemento usando gramaticas libres de contexto

# AST

- Genera AST
