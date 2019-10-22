/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <vector>

#include "Nodo.h"

int yylex();
int yyerror(char *s);
static void insertNodo(Nodo *pNodo);
static void readVector();


#line 79 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
    BO = 302,
    BC = 303,
    CBO = 304,
    CBC = 305,
    INT_VALUE = 306,
    DOUBLE_VALUE = 307,
    CHAR_VALUE = 308,
    INVALID_CHAR = 309,
    STRING_VALUE = 310,
    INVALID_STRING = 311,
    IDENTIFIER = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:355  */

    int ival;
    double dval;
    char cval;
    char* sval;

#line 184 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "parser.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    39,    39,    42,    43,    46,    47,    48,    49,    52,
      53,    56,    57,    60,    61,    62,    65,    68,    69,    72,
      73,    76,    77,    80,    81,    84,    87,    88,    89,    92,
      93,    94,    97,   100,   103,   106,   107,   108,   109,   110,
     111,   114,   115,   116,   117,   118,   119,   120,   121,   124,
     127,   128,   131,   134,   137,   140,   143,   146,   147,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   179,   180,   183,   184,   187,
     188,   191,   192,   193,   194,   195,   196
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
  "COMMA", "DOT", "SBO", "SBC", "BO", "BC", "CBO", "CBC", "INT_VALUE",
  "DOUBLE_VALUE", "CHAR_VALUE", "INVALID_CHAR", "STRING_VALUE",
  "INVALID_STRING", "IDENTIFIER", "$accept", "program", "decls", "decl",
  "identifiers", "functionDecl", "formals", "classDecl", "optExtends",
  "optImplements", "fields", "field", "interfaceDecl", "prototype",
  "stmts", "stmtBlock", "variableDecl", "variable", "type", "stmt",
  "ifStmt", "optElse", "whileStmt", "forStmt", "returnStmt", "breakStmt",
  "printStmt", "expressionList", "expression", "optActualList",
  "actualList", "actuals", "constant", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-40)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,   -48,   -59,   -59,   -59,   -59,   -43,   -16,   -59,    45,
      27,   -59,   -59,   -59,   -59,   -59,    36,   -44,    32,    69,
      37,   -59,   -59,   -59,    41,    42,    33,    38,    80,    17,
     -59,    33,    -1,    46,    33,   -30,   -59,    39,    50,    40,
      52,     1,    53,   -59,    54,   -59,   -59,   -59,    43,   -59,
      59,   -59,    61,    54,   134,   -59,   -59,    48,    33,    33,
     -59,   -59,   -59,    64,    66,    81,   177,    62,    86,    87,
      88,    89,    90,   -59,   -59,   177,   177,   177,   -59,   -59,
     -59,    35,    77,   -59,   134,   134,   -59,   -59,   -59,   -59,
     -59,   -59,   316,   -59,   -59,   -59,   -59,   -59,    84,    94,
     177,   177,   177,   -59,   335,   -59,   104,   177,   177,    98,
      99,   178,   430,   208,   -59,   -59,   -59,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   -59,   106,   177,   122,   123,   354,   230,   252,   -59,
     118,   373,   -36,   411,   -59,   -59,   -59,   178,   178,    85,
      85,    85,   444,   444,   444,   444,   444,   444,   444,   430,
     430,   120,   296,   -59,   -59,   177,    54,    54,   -59,    -1,
     177,   126,   177,   -59,   -59,   392,   -59,   153,   -20,   411,
     -59,   411,   124,   128,   177,    54,   -59,   -59,   -59,   177,
     274,   -59,   411,    54,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    35,    36,    37,    38,     0,     0,    39,     0,
       2,     3,     6,     7,     8,     5,     0,     0,     0,    18,
       0,     1,     4,    33,     0,    34,    13,     0,    20,    26,
      40,    13,     0,     0,    13,     0,    17,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    34,     9,    19,    21,
       0,    25,     0,     0,    29,    12,    10,     0,    13,    13,
      11,    96,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,     0,    91,    92,
      95,    77,     0,    48,    29,    29,    41,    43,    44,    46,
      45,    47,     0,    78,    16,    24,    22,    23,     0,     0,
       0,     0,     0,    77,     0,    55,     0,     0,     0,     0,
       0,    74,    73,     0,    32,    31,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,    57,    79,    80,    84,    67,    68,    69,
      70,    71,    63,    64,    65,    66,    61,    72,    62,    60,
      59,    85,     0,    28,    27,     0,     0,     0,    81,     0,
       0,     0,    88,    76,    75,     0,    52,    50,     0,    58,
      56,    89,     0,    87,     0,     0,    49,    82,    86,     0,
       0,    51,    90,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -59,   163,   -59,   117,    57,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -37,   -42,    16,    51,     0,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -58,   -59,
     -59,   -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    48,    12,    33,    13,    28,    38,
      57,    96,    14,    40,    82,    83,    84,    16,    35,    85,
      86,   186,    87,    88,    89,    90,    91,   142,    92,   173,
     182,   183,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    24,    55,     2,     3,     4,     5,   170,   104,    18,
      17,    60,   171,    25,    19,    24,    15,   111,   112,   113,
      39,     2,     3,     4,     5,    24,    15,    46,   187,    41,
       1,     2,     3,     4,     5,     6,     7,     2,     3,     4,
       5,    20,   136,   137,   138,    21,    24,   115,   116,   141,
     143,     1,     2,     3,     4,     5,     8,    17,    52,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    97,     8,   162,    32,    34,    23,    26,
     -39,    27,    34,    43,     8,    34,    29,    30,    42,    31,
       8,    45,   -39,    37,    44,    36,    47,    50,    94,    49,
      56,    53,    51,    54,   105,     8,    58,   175,    59,    34,
      34,   100,   179,   101,   181,    98,    99,   122,   123,   124,
     125,   126,   127,   128,   176,   177,   190,   114,   102,   132,
     133,   192,   134,   106,   107,   108,   109,   110,     2,     3,
       4,     5,   135,   191,    61,    62,   144,   145,    63,    64,
      65,   194,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   140,    75,   161,   163,   164,   168,   172,   180,   178,
     185,   189,   188,    22,    95,    76,     0,     0,     0,     0,
       0,    77,     0,    54,     0,    78,    79,    61,    62,    80,
       0,    81,     0,     0,     0,     0,     0,    68,    69,     0,
      71,    72,    73,    74,     0,    75,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     0,    76,     0,
       0,     0,   132,   133,    77,     0,     0,     0,    78,    79,
       0,     0,    80,     0,   103,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   132,   133,     0,     0,   146,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,   132,   133,     0,     0,   166,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   132,   133,     0,     0,
     167,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   132,   133,
       0,     0,   193,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     132,   133,   174,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   131,     0,
     132,   133,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,   139,     0,   132,
     133,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,   165,     0,   132,   133,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,   169,   132,   133,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   184,     0,   132,   133,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,   132,   133,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,     0,
       0,     0,     0,     0,   132,   133,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,     0,     0,     0,     0,     0,   -40,   -40
};

static const yytype_int16 yycheck[] =
{
       0,    45,    44,     4,     5,     6,     7,    43,    66,    57,
      10,    53,    48,    57,    57,    45,     0,    75,    76,    77,
       3,     4,     5,     6,     7,    45,    10,    57,    48,    29,
       3,     4,     5,     6,     7,     8,     9,     4,     5,     6,
       7,    57,   100,   101,   102,     0,    45,    84,    85,   107,
     108,     3,     4,     5,     6,     7,    57,    57,    57,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    57,    57,   133,    43,    26,    42,    47,
      45,    12,    31,    32,    57,    34,    49,    46,    31,    47,
      57,    34,    57,    13,    48,    57,    57,    57,    50,    49,
      57,    48,    50,    49,    42,    57,    47,   165,    47,    58,
      59,    47,   170,    47,   172,    58,    59,    32,    33,    34,
      35,    36,    37,    38,   166,   167,   184,    50,    47,    44,
      45,   189,    48,    47,    47,    47,    47,    47,     4,     5,
       6,     7,    48,   185,    10,    11,    48,    48,    14,    15,
      16,   193,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    57,    28,    57,    42,    42,    48,    47,    42,   169,
      17,    43,    48,    10,    57,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    -1,    51,    52,    10,    11,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      23,    24,    25,    26,    -1,    28,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    41,    -1,
      -1,    -1,    44,    45,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    -1,    57,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    45,    -1,    -1,    48,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,
      48,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    45,
      -1,    -1,    48,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      44,    45,    46,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    45,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      45,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    45,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    43,    44,    45,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    45,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    45,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    57,    59,
      60,    61,    63,    65,    70,    74,    75,    76,    57,    57,
      57,     0,    61,    42,    45,    57,    47,    12,    66,    49,
      46,    47,    43,    64,    75,    76,    57,    13,    67,     3,
      71,    76,    64,    75,    48,    64,    57,    57,    62,    49,
      57,    50,    57,    48,    49,    73,    57,    68,    47,    47,
      73,    10,    11,    14,    15,    16,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    28,    41,    47,    51,    52,
      55,    57,    72,    73,    74,    77,    78,    80,    81,    82,
      83,    84,    86,    90,    50,    63,    69,    74,    64,    64,
      47,    47,    47,    57,    86,    42,    47,    47,    47,    47,
      47,    86,    86,    86,    50,    72,    72,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    42,    44,    45,    48,    48,    86,    86,    86,    42,
      57,    86,    85,    86,    48,    48,    48,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    57,    86,    42,    42,    42,    48,    48,    48,    43,
      43,    48,    47,    87,    46,    86,    73,    73,    76,    86,
      42,    86,    88,    89,    42,    17,    79,    48,    48,    43,
      86,    73,    86,    48,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    71,    71,    72,
      72,    72,    73,    74,    75,    76,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    79,    80,    81,    82,    83,    84,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     6,     6,     0,     2,     2,     7,     2,     0,     2,
       0,     0,     2,     1,     1,     5,     0,     6,     6,     0,
       2,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     6,
       0,     2,     5,     9,     3,     2,     5,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     4,     1,     1,     3,
       3,     4,     6,     1,     3,     0,     3,     1,     0,     1,
       3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 39 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("program"," ")); printf("OK\n"); readVector();}
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 42 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("declas","  "));}
#line 1482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 43 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("declas","  "));}
#line 1488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 46 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("decla","  "));}
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 47 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("decla","  "));}
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 48 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("decla","  "));}
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 49 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("decla","  "));}
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 52 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("identifiers","  "));}
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 53 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("identifiers","  "));}
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 56 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("functionDecl","  "));}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 57 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("functionDecl","  "));}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 61 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("formals","  "));}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 62 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("formals","  "));}
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 65 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("classDecl","  "));}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("optExtends","  "));}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 72 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("optImplements","  "));}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("fields","  "));}
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("field","  "));}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("field","  "));}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 84 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("interfaceDecl","  "));}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("prototype","  "));}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 89 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("prototype","  "));}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmts","  "));}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 94 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmts","  "));}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 97 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmtBlock","  "));}
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("variableDecl","  "));}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 103 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("variable","  "));}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 106 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("type","  "));}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 107 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("type","  "));}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 108 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("type","  "));}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 109 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("type","  "));}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 110 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("type","  "));}
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("type","  "));}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 114 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 115 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 116 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 117 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 118 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 119 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 120 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 121 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("stmt","  "));}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 124 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("Program","  "));}
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 128 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("optElse","  "));}
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 131 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("whileStmt","  "));}
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 134 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("forStmt","  "));}
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 137 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("returnStmt","  "));}
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 140 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("breakStmt","  "));}
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 143 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("printStmt","  "));}
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 146 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expressionList","  "));}
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 147 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expressionList","  "));}
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 151 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 152 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 153 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 154 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 155 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 156 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 157 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 158 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 159 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 160 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 161 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 162 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 163 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 164 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1854 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 165 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1860 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 166 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 167 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 168 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 169 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 170 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 171 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 172 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 173 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 174 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 175 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 176 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("expression","  "));}
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 180 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("optActualList","  "));}
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 183 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("actualList","  "));}
#line 1938 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 187 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("actuals","  "));}
#line 1944 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 188 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("actuals","  "));}
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 191 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("constant","  "));}
#line 1956 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 192 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("constant","  "));}
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 193 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("constant","  "));}
#line 1968 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 194 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("constant","  "));}
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 195 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("constant","  "));}
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 196 "parser.y" /* yacc.c:1646  */
    {insertNodo(new Nodo("constant","  "));}
#line 1986 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1990 "parser.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 199 "parser.y" /* yacc.c:1906  */


int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}

static vector<Nodo*> stack;

static void insertNodo(Nodo *pNodo){
    stack.push_back(pNodo);
}

static void readVector(){
      for(int i =stack.size()-1; i>=0; i--){       
            printf("%s","  ombre: ");
            printf("%s\n",stack[i]->name.c_str());
      }
}

