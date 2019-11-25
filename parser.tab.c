/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y" /* yacc.c:337  */

#include "ast.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

extern "C" int yylex();
extern "C" int yyparse();
extern "C" void yyerror(char *s);
extern "C" int yywrap(void)
{
    return 1;
}

extern union node yylval;
extern class AST_Node * start;

#line 89 "parser.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    DOUBLE = 260,
    BOOL = 261,
    STRING = 262,
    CLASS = 263,
    INTERFACE = 264,
    _NULL = 265,
    THIS = 266,
    EXTENDS = 267,
    IMPLEMENTS = 268,
    FOR = 269,
    WHILE = 270,
    IF = 271,
    ELSE = 272,
    RETURN = 273,
    BREAK = 274,
    NEW = 275,
    NEWARRAY = 276,
    PRINT = 277,
    READINTEGER = 278,
    READLINE = 279,
    _TRUE = 280,
    _FALSE = 281,
    PLUS = 282,
    MINUS = 283,
    MUL = 284,
    DIV = 285,
    MOD = 286,
    LESS = 287,
    LESSEQUAL = 288,
    GREATER = 289,
    GREATEREQUAL = 290,
    EQUALEQUAL = 291,
    EQUAL = 292,
    NOTEQUAL = 293,
    AND = 294,
    OR = 295,
    NOT = 296,
    SEMICOLON = 297,
    COMMA = 298,
    DOT = 299,
    SBO = 300,
    SBC = 301,
    DBO = 302,
    BO = 303,
    BC = 304,
    CBO = 305,
    CBC = 306,
    INT_VALUE = 307,
    DOUBLE_VALUE = 308,
    CHAR_VALUE = 309,
    INVALID_CHAR = 310,
    STRING_VALUE = 311,
    INVALID_STRING = 312,
    IDENTIFIER = 313
  };
#endif

/* Value type.  */

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

#define YYUNDEFTOK  2
#define YYMAXUTOK   313

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    89,    93,    99,   102,   105,   108,   113,
     117,   123,   129,   138,   141,   146,   150,   156,   164,   168,
     173,   176,   181,   184,   190,   193,   196,   201,   209,   212,
     218,   224,   233,   236,   240,   246,   252,   257,   265,   269,
     273,   277,   281,   285,   291,   294,   297,   300,   303,   306,
     309,   312,   317,   323,   326,   331,   337,   343,   347,   353,
     359,   365,   369,   376,   380,   384,   388,   392,   396,   400,
     404,   408,   412,   416,   420,   424,   428,   432,   436,   440,
     444,   450,   456,   459,   463,   467,   473,   477,   481,   486,
     489,   494,   497,   502,   506,   512,   516,   520,   524,   528,
     532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "DOUBLE", "BOOL",
  "STRING", "CLASS", "INTERFACE", "_NULL", "THIS", "EXTENDS", "IMPLEMENTS",
  "FOR", "WHILE", "IF", "ELSE", "RETURN", "BREAK", "NEW", "NEWARRAY",
  "PRINT", "READINTEGER", "READLINE", "_TRUE", "_FALSE", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "LESS", "LESSEQUAL", "GREATER", "GREATEREQUAL",
  "EQUALEQUAL", "EQUAL", "NOTEQUAL", "AND", "OR", "NOT", "SEMICOLON",
  "COMMA", "DOT", "SBO", "SBC", "DBO", "BO", "BC", "CBO", "CBC",
  "INT_VALUE", "DOUBLE_VALUE", "CHAR_VALUE", "INVALID_CHAR",
  "STRING_VALUE", "INVALID_STRING", "IDENTIFIER", "$accept", "program",
  "decls", "decl", "identifiers", "functionDecl", "optFormals", "formals",
  "classDecl", "optExtends", "optImplements", "fields", "field",
  "interfaceDecl", "prototypes", "prototype", "stmts", "stmtBlock",
  "variableDecl", "variable", "type", "stmt", "ifStmt", "optElse",
  "whileStmt", "forStmt", "returnStmt", "breakStmt", "printStmt",
  "expressionList", "expression", "optActualList", "actualList", "actuals",
  "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -43

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-43)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   -49,   -61,   -61,   -61,   -61,   -27,    -5,   -61,    54,
      21,   -61,   -61,   -61,   -61,   -61,    39,   -44,    34,    76,
      40,   -61,   -61,   -61,   -61,    46,    13,    31,    83,   -61,
      13,    48,    55,   -61,   -43,   -61,    43,    49,    42,    53,
      56,    13,   -61,   -61,    45,   -61,    50,   -61,   -61,    25,
      56,   -61,   -61,   -61,   -61,    29,    59,    61,   -61,   136,
     -61,   -61,   -61,   -61,   -61,    13,    13,   -61,   -61,    63,
      65,    66,   155,    62,    67,    68,    69,    72,    73,   -61,
     -61,   194,   194,   194,   -61,   -61,   -61,   -61,    37,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   338,   -61,
      74,    77,   194,   194,   194,   -61,   -61,   357,   -61,    64,
     194,   194,    78,    79,    47,    41,   226,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   -61,    75,   194,    88,    89,   376,   249,   272,   -61,
      85,   395,   -36,   433,   -61,   -61,   -61,    47,    47,    41,
      41,    41,   509,   509,   509,   509,   196,   452,   196,   490,
     471,    84,   318,   -61,   -61,   194,    56,    56,   -61,    13,
     194,    93,   194,   -61,   -61,   414,   -61,   108,   -41,   433,
     -61,   433,    87,    95,   194,    56,   -61,   -61,   -61,   194,
     295,   -61,   433,    56,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    38,    39,    40,    41,     0,     0,    42,     0,
       2,     3,     6,     7,     8,     5,     0,     0,     0,    19,
       0,     1,     4,    36,    43,    37,    13,     0,    21,    28,
      13,     0,    14,    15,     0,    18,     0,     0,     0,     0,
       0,     0,    37,     9,    20,    22,     0,    27,    29,     0,
       0,    32,    12,    16,    10,     0,     0,     0,    11,     0,
      17,    25,    26,    23,    24,    13,    13,   100,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,    35,    95,    96,    99,    81,    51,
      34,    33,    44,    46,    47,    49,    48,    50,     0,    82,
       0,     0,     0,     0,     0,    58,    81,     0,    59,     0,
       0,     0,     0,     0,    78,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,    61,    83,    84,    88,    71,    72,    73,
      74,    75,    67,    68,    69,    70,    65,    76,    66,    64,
      63,    89,     0,    31,    30,     0,     0,     0,    85,     0,
       0,     0,    92,    80,    79,     0,    55,    53,     0,    62,
      60,    93,     0,    91,     0,     0,    52,    86,    90,     0,
       0,    54,    94,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   129,   -61,    94,     9,   -61,    98,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -48,    -3,   -25,
       0,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -60,   -61,   -61,   -61,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    44,    12,    31,    32,    13,    28,
      37,    55,    63,    14,    38,    48,    59,    52,    15,    16,
      34,    91,    92,   186,    93,    94,    95,    96,    97,   142,
      98,   173,   182,   183,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    33,    58,    24,    24,    33,    24,   170,   187,    18,
      17,    89,   107,   171,    25,    42,    53,     2,     3,     4,
       5,   114,   115,   116,     1,     2,     3,     4,     5,     6,
       7,    19,     1,     2,     3,     4,     5,     6,    49,    39,
      33,    33,   136,   137,   138,    46,     2,     3,     4,     5,
     141,   143,    64,    20,    21,    17,    90,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     8,    24,   162,   100,   101,   119,   120,   121,     8,
      60,    23,    26,    57,   -42,   132,   133,     8,    27,    35,
      29,   132,   133,    47,    30,   -42,    36,    40,    41,    45,
       8,    43,    50,    54,   108,   175,    51,    65,    56,    66,
     179,   102,   181,   103,   104,   109,   110,   111,   176,   177,
     112,   113,   140,   134,   190,   185,   135,   144,   145,   192,
     163,   164,   172,   161,   168,   180,   188,   191,   189,    22,
       2,     3,     4,     5,     0,   194,    67,    68,     0,    61,
      69,    70,    71,    62,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     0,    81,    67,    68,     0,     0,   178,
       0,     0,     0,     0,     0,    74,    75,    82,    77,    78,
      79,    80,     0,    81,    83,     0,    51,    84,    85,    86,
       0,     0,    87,     0,    88,     0,    82,   105,     0,     0,
       0,     0,     0,    83,    67,    68,     0,    85,    86,     0,
       0,    87,     0,   106,    74,    75,     0,    77,    78,    79,
      80,     0,    81,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   -43,     0,   -43,    82,     0,     0,     0,     0,
     132,   133,    83,     0,     0,     0,    85,    86,     0,     0,
      87,     0,   106,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     132,   133,     0,     0,     0,   146,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,   132,   133,     0,     0,     0,   166,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   132,   133,     0,     0,
       0,   167,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,   132,
     133,     0,     0,     0,   193,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   132,   133,   174,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     131,     0,   132,   133,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   139,
       0,   132,   133,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   165,     0,
     132,   133,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,   169,   132,
     133,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,   184,     0,   132,   133,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,   132,   133,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   -43,
     128,   129,   130,     0,     0,     0,   132,   133,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,   128,
     129,     0,     0,     0,     0,   132,   133,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   128,     0,
       0,     0,     0,     0,   132,   133,   117,   118,   119,   120,
     121,   -43,   -43,   -43,   -43,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133
};

static const yytype_int16 yycheck[] =
{
       0,    26,    50,    47,    47,    30,    47,    43,    49,    58,
      10,    59,    72,    49,    58,    58,    41,     4,     5,     6,
       7,    81,    82,    83,     3,     4,     5,     6,     7,     8,
       9,    58,     3,     4,     5,     6,     7,     8,    38,    30,
      65,    66,   102,   103,   104,     3,     4,     5,     6,     7,
     110,   111,    55,    58,     0,    55,    59,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    58,    47,   133,    65,    66,    29,    30,    31,    58,
      51,    42,    48,    58,    47,    44,    45,    58,    12,    58,
      50,    44,    45,    51,    48,    58,    13,    49,    43,    50,
      58,    58,    49,    58,    42,   165,    50,    48,    58,    48,
     170,    48,   172,    48,    48,    48,    48,    48,   166,   167,
      48,    48,    58,    49,   184,    17,    49,    49,    49,   189,
      42,    42,    48,    58,    49,    42,    49,   185,    43,    10,
       4,     5,     6,     7,    -1,   193,    10,    11,    -1,    55,
      14,    15,    16,    55,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    10,    11,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    20,    21,    41,    23,    24,
      25,    26,    -1,    28,    48,    -1,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    58,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    10,    11,    -1,    52,    53,    -1,
      -1,    56,    -1,    58,    20,    21,    -1,    23,    24,    25,
      26,    -1,    28,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    41,    -1,    -1,    -1,    -1,
      44,    45,    48,    -1,    -1,    -1,    52,    53,    -1,    -1,
      56,    -1,    58,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    49,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    49,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    49,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    49,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    45,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    45,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    44,    45,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    45,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    43,    44,
      45,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    45,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    44,    45,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    45,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    45,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    58,    60,
      61,    62,    64,    67,    72,    77,    78,    79,    58,    58,
      58,     0,    62,    42,    47,    58,    48,    12,    68,    50,
      48,    65,    66,    78,    79,    58,    13,    69,    73,    65,
      49,    43,    58,    58,    63,    50,     3,    51,    74,    79,
      49,    50,    76,    78,    58,    70,    58,    58,    76,    75,
      51,    64,    67,    71,    77,    48,    48,    10,    11,    14,
      15,    16,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    28,    41,    48,    51,    52,    53,    56,    58,    76,
      77,    80,    81,    83,    84,    85,    86,    87,    89,    93,
      65,    65,    48,    48,    48,    42,    58,    89,    42,    48,
      48,    48,    48,    48,    89,    89,    89,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    42,    44,    45,    49,    49,    89,    89,    89,    42,
      58,    89,    88,    89,    49,    49,    49,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    58,    89,    42,    42,    42,    49,    49,    49,    43,
      43,    49,    48,    90,    46,    89,    76,    76,    79,    89,
      42,    89,    91,    92,    42,    17,    82,    49,    49,    43,
      89,    76,    89,    49,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    75,    76,    77,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    82,    82,    83,    84,    85,    85,    86,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    93,    93,    93,
      93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     6,     6,     0,     1,     1,     3,     7,     2,     0,
       2,     0,     0,     2,     1,     1,     1,     5,     0,     2,
       6,     6,     0,     2,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     6,     0,     2,     5,     9,     3,     2,     2,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       4,     1,     1,     3,     3,     4,     6,     1,     3,     0,
       3,     1,     0,     1,     3,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 81 "parser.y" /* yacc.c:1652  */
    {
        (yyval.program) = new AST_Program((yyvsp[0].decls));
        start = (yyval.program);
        if (start)
            start->checkSemantic();
    }
#line 1603 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 89 "parser.y" /* yacc.c:1652  */
    {
        (yyval.decls) = new std::vector<Declaration_Node*>();
        (yyval.decls)->push_back((yyvsp[0].decl));
    }
#line 1612 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 93 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-1].decls)->push_back((yyvsp[0].decl));
        (yyval.decls) = (yyvsp[-1].decls);
    }
#line 1621 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 99 "parser.y" /* yacc.c:1652  */
    {
        (yyval.decl) = (yyvsp[0].variableDecl);
    }
#line 1629 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 102 "parser.y" /* yacc.c:1652  */
    {
        (yyval.decl) = (yyvsp[0].functionDecl);
    }
#line 1637 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 105 "parser.y" /* yacc.c:1652  */
    {
        (yyval.decl) = (yyvsp[0].classDecl);
    }
#line 1645 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 108 "parser.y" /* yacc.c:1652  */
    {
        (yyval.decl) = (yyvsp[0].interfaceDecl);
    }
#line 1653 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 113 "parser.y" /* yacc.c:1652  */
    {
        (yyval.identifiers) = new std::vector<Identifier_Node*> ();
        (yyval.identifiers)->push_back(new Identifier_Node(std::string((yyvsp[0].sval))));
    }
#line 1662 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 117 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-1].identifiers)->push_back(new Identifier_Node(std::string((yyvsp[0].sval))));
        (yyval.identifiers) = (yyvsp[-1].identifiers);
    }
#line 1671 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 123 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-4].sval)));
        identifier->setPos((yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.functionDecl) = new Function_Declaration_Node((yyvsp[-5].type), identifier, (yyvsp[-2].optFormals), (yyvsp[0].stmtBlock));
        (yyval.functionDecl)->setPos((yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 1682 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 129 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-4].sval)));
        Type_Node* type = new Type_Node(Datatype::null_type, nullptr);
        type->setPos((yylsp[-5]).first_line, (yylsp[-5]).first_column);
        identifier->setPos((yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.functionDecl) = new Function_Declaration_Node(type, identifier, (yyvsp[-2].optFormals), (yyvsp[0].stmtBlock));
    }
#line 1694 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 138 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optFormals) = nullptr;
    }
#line 1702 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 141 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optFormals) = (yyvsp[0].formals);
    }
#line 1710 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 146 "parser.y" /* yacc.c:1652  */
    {
        (yyval.formals) = new std::vector<Variable_Declaration_Node*>();
        (yyval.formals)->push_back((yyvsp[0].variable));
    }
#line 1719 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 150 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-2].formals)->push_back((yyvsp[0].variable));
        (yyval.formals) = (yyvsp[-2].formals);
    }
#line 1728 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 156 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-5].sval)));
        identifier->setPos((yylsp[-5]).first_line, (yylsp[-5]).first_column);
        (yyval.classDecl) = new Class_Declaration_Node(identifier, (yyvsp[-4].optExtends), (yyvsp[-3].optImplements), (yyvsp[-1].fields));
        (yyval.classDecl)->setPos((yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 1739 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 164 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optExtends) = new Identifier_Node(std::string((yyvsp[0].sval)));
        (yyval.optExtends)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1748 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 168 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optExtends) = nullptr;
    }
#line 1756 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 173 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optImplements) = (yyvsp[0].identifiers);
    }
#line 1764 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 176 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optImplements) = nullptr;
    }
#line 1772 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 181 "parser.y" /* yacc.c:1652  */
    {
        (yyval.fields) = new std::vector<Declaration_Node*>();
    }
#line 1780 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 184 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-1].fields)->push_back((yyvsp[0].field));
        (yyval.fields) = (yyvsp[-1].fields);
    }
#line 1789 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 190 "parser.y" /* yacc.c:1652  */
    {
        (yyval.field) = (yyvsp[0].variableDecl);
    }
#line 1797 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 193 "parser.y" /* yacc.c:1652  */
    {
        (yyval.field) = (yyvsp[0].functionDecl);
    }
#line 1805 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 196 "parser.y" /* yacc.c:1652  */
    {
        (yyval.field) = (yyvsp[0].classDecl);
    }
#line 1813 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 201 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-3].sval)));
        identifier->setPos((yylsp[-3]).first_line, (yylsp[-3]).first_column);
        (yyval.interfaceDecl) = new Interface_Declaration_Node(identifier, (yyvsp[-1].prototypes));
        (yyval.interfaceDecl)->setPos((yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 1824 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 209 "parser.y" /* yacc.c:1652  */
    {
        (yyval.prototypes) = new std::vector<Prototype_Node*>();
    }
#line 1832 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 212 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-1].prototypes)->push_back((yyvsp[0].prototype));
        (yyval.prototypes) = (yyvsp[-1].prototypes);
    }
#line 1841 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 218 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-4].sval)));
        identifier->setPos((yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.prototype) = new Prototype_Node((yyvsp[-5].type), identifier, (yyvsp[-2].optFormals));
        (yyval.prototype)->setPos((yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 1852 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 224 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-4].sval)));
        identifier->setPos((yylsp[-4]).first_line, (yylsp[-4]).first_column);
        Type_Node* type = new Type_Node(Datatype::null_type);
        (yyval.prototype) = new Prototype_Node(type, identifier, (yyvsp[-2].optFormals));
        (yyval.prototype)->setPos((yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 1864 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 233 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmts) = new std::vector<AST_Node*>();
    }
#line 1872 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 236 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-1].stmts)->push_back((yyvsp[0].stmt));
        (yyval.stmts) = (yyvsp[-1].stmts);
    }
#line 1881 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 240 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-1].stmts)->push_back((yyvsp[0].variableDecl));
        (yyval.stmts) = (yyvsp[-1].stmts);
    }
#line 1890 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 246 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmtBlock) = new Statement_Block_Node((yyvsp[-1].stmts));
        (yyval.stmtBlock)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 1899 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 252 "parser.y" /* yacc.c:1652  */
    {
            (yyval.variableDecl) = (yyvsp[-1].variable);
        }
#line 1907 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 257 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[0].sval)));
        identifier->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.variable) = new Variable_Declaration_Node((yyvsp[-1].type),identifier);
        (yyval.variable)->setPos((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1918 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 265 "parser.y" /* yacc.c:1652  */
    {
        (yyval.type) = new Type_Node(Datatype::int_type, nullptr);
        (yyval.type)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1927 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 269 "parser.y" /* yacc.c:1652  */
    {
        (yyval.type) = new Type_Node(Datatype::double_type, nullptr);
        (yyval.type)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1936 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 273 "parser.y" /* yacc.c:1652  */
    {
        (yyval.type) = new Type_Node(Datatype::bool_type, nullptr);
        (yyval.type)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1945 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 277 "parser.y" /* yacc.c:1652  */
    {
        (yyval.type) = new Type_Node(Datatype::string_type, nullptr);
        (yyval.type)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1954 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 281 "parser.y" /* yacc.c:1652  */
    {
        (yyval.type) = new Type_Node(Datatype::identifier_type, new Identifier_Node(std::string((yyvsp[0].sval))));
        (yyval.type)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1963 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 285 "parser.y" /* yacc.c:1652  */
    {
        (yyval.type) = (yyvsp[-1].type);
        (yyval.type)->setAsArray();
    }
#line 1972 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 291 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[0].ifStmt);
    }
#line 1980 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 294 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[-1].expression);
    }
#line 1988 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 297 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[0].whileStmt);
    }
#line 1996 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 300 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[0].forStmt);
    }
#line 2004 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 303 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[0].breakStmt);
    }
#line 2012 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 306 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[0].returnStmt);
    }
#line 2020 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 309 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[0].printStmt);
    }
#line 2028 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 312 "parser.y" /* yacc.c:1652  */
    {
        (yyval.stmt) = (yyvsp[0].stmtBlock);
    }
#line 2036 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 317 "parser.y" /* yacc.c:1652  */
    {
        (yyval.ifStmt) = new If_Statement_Node((yyvsp[-3].expression), (yyvsp[-1].stmtBlock), (yyvsp[0].optElse));
        (yyval.ifStmt)->setPos((yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 2045 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 323 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optElse) = nullptr;
    }
#line 2053 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 326 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optElse) = (yyvsp[0].stmtBlock);
    }
#line 2061 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 331 "parser.y" /* yacc.c:1652  */
    {
        (yyval.whileStmt) = new While_Statement_Node((yyvsp[-2].expression), (yyvsp[0].stmtBlock));
        (yyval.whileStmt)->setPos((yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2070 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 337 "parser.y" /* yacc.c:1652  */
    {
        (yyval.forStmt) = new For_Statement_Node((yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].stmtBlock));
        (yyval.forStmt)->setPos((yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 2079 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 343 "parser.y" /* yacc.c:1652  */
    {
        (yyval.returnStmt) = new Return_Statement_Node((yyvsp[-1].expression));
        (yyval.returnStmt)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2088 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 347 "parser.y" /* yacc.c:1652  */
    {
        (yyval.returnStmt) = new Return_Statement_Node(new Null_Constant_Expression_Node());
        (yyval.returnStmt)->setPos((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2097 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 353 "parser.y" /* yacc.c:1652  */
    {
        (yyval.breakStmt) = new Break_Statement_Node();
        (yyval.breakStmt)->setPos((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2106 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 359 "parser.y" /* yacc.c:1652  */
    {
        (yyval.printStmt) = new Print_Statement_Node((yyvsp[-2].expressionList));
        (yyval.printStmt)->setPos((yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2115 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 365 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expressionList) = new std::vector<Expression_Node*>();
        (yyval.expressionList)->push_back((yyvsp[0].expression));
    }
#line 2124 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 369 "parser.y" /* yacc.c:1652  */
    { 
        (yyvsp[-2].expressionList)->push_back((yyvsp[0].expression)); 
        (yyval.expressionList) = (yyvsp[-2].expressionList);
    }
#line 2133 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 376 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::OR);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2142 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 380 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::AND);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2151 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 384 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::EQUALEQUAL);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2160 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 388 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::NOTEQUAL);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2169 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 392 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::LESS);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2178 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 396 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::LESSEQUAL);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2187 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 400 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::GREATER);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2196 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 404 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::GREATEREQUAL);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2205 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 408 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::PLUS);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2214 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 412 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::MINUS);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2223 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 416 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::MUL);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2232 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 420 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::DIV);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2241 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 424 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::MOD);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2250 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 428 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[-2].expression), (yyvsp[0].expression), Operator_Type::EQUAL);
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2259 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 432 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[0].expression), nullptr, Operator_Type::NOT);
        (yyval.expression)->setPos((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2268 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 436 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Comparation_Expression_Node((yyvsp[0].expression), nullptr, Operator_Type::MINUS);
        (yyval.expression)->setPos((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2277 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 440 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new Array_Expression_Node((yyvsp[-3].expression), (yyvsp[-1].expression));
        (yyval.expression)->setPos((yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2286 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 444 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-1].sval)));
        identifier->setPos((yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.expression) = new Call_Expression_Node((yyvsp[-3].expression), identifier, (yyvsp[0].optActualList));
        (yyval.expression)->setPos((yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2297 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 450 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[0].sval)));
        identifier->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.expression) = new Identifier_Expression_Node(identifier);
        (yyval.expression)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2308 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 456 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = (yyvsp[0].constant);
    }
#line 2316 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 459 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new ReadInteger_Expression_Node();
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2325 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 463 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new ReadLine_Expression_Node();
        (yyval.expression)->setPos((yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2334 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 467 "parser.y" /* yacc.c:1652  */
    {
        Identifier_Node* identifier = new Identifier_Node(std::string((yyvsp[-1].sval)));
        identifier->setPos((yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.expression) = new New_Expression_Node(identifier);
        (yyval.expression)->setPos((yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2345 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 473 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new NewArray_Expression_Node((yyvsp[-3].expression), (yyvsp[-1].type));
        (yyval.expression)->setPos((yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 2354 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 477 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = new This_Expression_Node(); 
        (yyval.expression)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2363 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 481 "parser.y" /* yacc.c:1652  */
    {
        (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2371 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 486 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optActualList) = nullptr;
    }
#line 2379 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 489 "parser.y" /* yacc.c:1652  */
    {
        (yyval.optActualList) = (yyvsp[-1].actualList);
    }
#line 2387 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 494 "parser.y" /* yacc.c:1652  */
    {
        (yyval.actualList) = (yyvsp[0].actuals);
    }
#line 2395 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 497 "parser.y" /* yacc.c:1652  */
    {
        (yyval.actualList) = new std::vector<Expression_Node*>();
    }
#line 2403 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 502 "parser.y" /* yacc.c:1652  */
    {
        (yyval.actuals) = new std::vector<Expression_Node*>();
        (yyval.actuals)->push_back((yyvsp[0].expression));
    }
#line 2412 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 506 "parser.y" /* yacc.c:1652  */
    {
        (yyvsp[-2].actuals)->push_back((yyvsp[0].expression));
        (yyval.actuals) = (yyvsp[-2].actuals);
    }
#line 2421 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 512 "parser.y" /* yacc.c:1652  */
    {
        (yyval.constant) = new Int_Constant_Expression_Node((yyvsp[0].ival));
        (yyval.constant)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2430 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 516 "parser.y" /* yacc.c:1652  */
    {
        (yyval.constant) = new Double_Constant_Expression_Node((yyvsp[0].dval));
        (yyval.constant)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2439 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 520 "parser.y" /* yacc.c:1652  */
    {
        (yyval.constant) = new Boolean_Constant_Expression_Node(true);
        (yyval.constant)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2448 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 524 "parser.y" /* yacc.c:1652  */
    {
        (yyval.constant) = new Boolean_Constant_Expression_Node(false);
        (yyval.constant)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2457 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 528 "parser.y" /* yacc.c:1652  */
    {
        (yyval.constant) = new String_Constant_Expression_Node(std::string((yyvsp[0].sval)));
        (yyval.constant)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2466 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 532 "parser.y" /* yacc.c:1652  */
    {
        (yyval.constant) = new Null_Constant_Expression_Node();
        (yyval.constant)->setPos((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2475 "parser.tab.c" /* yacc.c:1652  */
    break;


#line 2479 "parser.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 537 "parser.y" /* yacc.c:1918  */


void yyerror(char *s)
{
	fprintf(stderr, "\tError: %s\n", s);
}
