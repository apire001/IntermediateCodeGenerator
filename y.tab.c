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
#line 11 "mini_l.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
using namespace std;
 
void yyerror(const char *msg);
extern int yylineno;
extern int line_num;
extern int col_num;
extern FILE * yyin;
int yylex(void);

//function declarations
void opFunction(string);
void spaceAllocate(int);
int findLastSpace();
int findLastContinue();
bool vectorSearch(string input, vector<string> target);
void fillTerminalSymbolTable();
void outputErrors();
 
//Counters to help calculate tags for labels, temps and continues
int tempCount = 0;
int labelCount = 0;
int continueCount = 0;

//Tables used for code generation
vector<string> symbol_table;
vector<string> equation_table;
vector<string> cond_table;
vector<string> function_table;
vector<string> variable_table;
vector<string> array_table;
vector<string> terminal_symbol_table;
  
//Stack for program
vector<string> program_stack;
 
//Stack of generated code
vector<string> generated_code;
 
//temporary vector for intermediate storage
vector<string> temp_vector;

//vector to store error string messages
vector<string> error_messages;

//Flag to check if in loop
bool loopFlag = false;


#line 124 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    MULT = 258,
    DIV = 259,
    ADD = 260,
    SUB = 261,
    MOD = 262,
    EQUAL = 263,
    L_PAREN = 264,
    R_PAREN = 265,
    END = 266,
    PROGRAM = 267,
    BEGIN_PROGRAM = 268,
    END_PROGRAM = 269,
    ELSEIF = 270,
    FUNCTION = 271,
    BEGINPARAM = 272,
    ENDPARAM = 273,
    BEGINLOCALS = 274,
    ENDLOCALS = 275,
    BEGINBODY = 276,
    ENDBODY = 277,
    INTEGER = 278,
    ARRAY = 279,
    OF = 280,
    IF = 281,
    THEN = 282,
    ENDIF = 283,
    ELSE = 284,
    WHILE = 285,
    DO = 286,
    IN = 287,
    BEGINLOOP = 288,
    ENDLOOP = 289,
    CONTINUE = 290,
    READ = 291,
    WRITE = 292,
    AND = 293,
    OR = 294,
    NOT = 295,
    TRUE = 296,
    FALSE = 297,
    RETURN = 298,
    EQ = 299,
    NEQ = 300,
    LT = 301,
    GT = 302,
    LTE = 303,
    GTE = 304,
    SEMICOLON = 305,
    COLON = 306,
    COMMA = 307,
    L_BRACKET = 308,
    R_BRACKET = 309,
    ASSIGN = 310,
    NUMBER = 311,
    IDENTIFIER = 312,
    USUB = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 69 "mini_l.y" /* yacc.c:355  */

  int ival;
  char* s;

#line 228 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

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
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   109,   114,   114,   126,   126,   141,   145,
     151,   172,   184,   189,   196,   215,   236,   240,   246,   252,
     257,   263,   285,   296,   296,   313,   318,   322,   313,   345,
     345,   368,   376,   392,   403,   411,   411,   420,   424,   430,
     436,   452,   456,   460,   465,   469,   473,   477,   483,   487,
     492,   496,   508,   529,   533,   533,   559,   559,   583,   587,
     591,   595,   599,   603,   609,   613,   619,   623,   629,   633,
     638,   648,   658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MULT", "DIV", "ADD", "SUB", "MOD",
  "EQUAL", "L_PAREN", "R_PAREN", "END", "PROGRAM", "BEGIN_PROGRAM",
  "END_PROGRAM", "ELSEIF", "FUNCTION", "BEGINPARAM", "ENDPARAM",
  "BEGINLOCALS", "ENDLOCALS", "BEGINBODY", "ENDBODY", "INTEGER", "ARRAY",
  "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "IN", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "RETURN", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON",
  "COLON", "COMMA", "L_BRACKET", "R_BRACKET", "ASSIGN", "NUMBER",
  "IDENTIFIER", "USUB", "$accept", "input", "funcs", "$@1", "func", "$@2",
  "decs", "dec", "param_decs", "param_dec", "idents", "ident", "stats",
  "stat", "$@3", "$@4", "$@5", "$@6", "$@7", "if_stat", "$@8", "vars",
  "var", "expr", "mult_expr", "exprs", "term", "$@9", "$@10", "comp",
  "bool_expr", "rel_and_exp", "rel_expr", YY_NULLPTR
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

#define YYPACT_NINF -70

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-70)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,   -49,    18,   -70,   -70,   -70,   -27,   -70,    -6,   -70,
     -70,     8,   -49,    22,   -16,    -7,     2,    29,   -49,    35,
     -49,   -49,   -70,   -70,    21,   -70,    32,    11,    30,    52,
      92,   -49,    74,    60,   106,   -70,   -70,    62,    93,    23,
     -70,   -70,   -70,   -49,   -49,     0,    64,   107,    80,    71,
      73,    75,   110,     0,    23,    23,   -70,   -70,   -70,    -4,
     -70,    78,    89,   -70,    96,   109,   -70,    23,   105,    98,
     -70,    98,     0,   100,     0,   -70,   106,   -70,   -70,     0,
      90,   -70,   -70,    41,    -8,   -70,   135,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,    23,
     121,    23,    96,   106,   -49,    31,    16,   -70,   106,   100,
     126,   -70,   -70,     0,   142,    89,    89,   100,   -70,   -70,
     -70,   109,   106,   -70,   120,   104,   -70,   -70,   127,   133,
      10,   147,   -70,   108,   -70,   106,   -70,   -70,     0,   -70,
     106,   106,   125,   -70,   -70,   111,   130,   106,    23,   128,
      96,   -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     4,    18,     0,     1,     3,     6,
       5,     0,    12,     0,     0,     0,    16,     0,    12,     0,
       0,     8,    13,    14,     0,    17,     0,     0,     0,     0,
       0,     8,     0,     0,    19,     9,    10,     0,     0,     0,
      25,    29,    33,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    51,    39,
      52,     0,    41,    44,    35,    64,    66,     0,     0,    31,
      37,    32,     0,    34,     0,     7,    19,    22,    23,     0,
       0,    15,    50,     0,     0,    68,    54,     0,     0,    58,
      59,    60,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,    20,    19,    21,
       0,    53,    72,     0,     0,    42,    43,    69,    45,    46,
      47,    65,     0,    67,     0,     0,    38,    40,     0,     0,
      48,     0,    57,     0,    27,    19,    24,    11,     0,    55,
      19,     0,     0,    49,    36,     0,     0,    19,     0,     0,
      30,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   156,   -70,   -70,   -70,   134,   -70,   148,   -70,
       7,    -1,   -69,   -21,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   123,   -31,   -19,    24,    33,   -29,   -70,   -70,   -70,
     -53,    69,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     4,    11,    26,    27,    13,    14,
      15,    59,    47,    48,   108,    67,   124,   141,    68,    49,
     100,    69,    60,    61,    62,   131,    63,   113,   114,    95,
      64,    65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    84,   112,    50,    85,    86,    53,   107,     5,    72,
       1,    16,    70,    70,   102,    87,    88,    16,     7,    16,
      16,    87,    88,     9,    82,    12,    73,    25,    28,    53,
      16,    99,    54,    46,    18,    83,    87,    88,    28,   128,
      17,   111,    46,    46,    19,    50,    87,    88,    21,    74,
     123,   111,    30,   105,    20,   106,    58,     5,    23,    24,
     109,    31,   138,    55,    56,    57,   142,   118,   119,   120,
     127,   144,    50,   126,    29,    46,   117,    50,   149,    58,
       5,    32,   125,    87,    88,    89,    90,    91,    92,    93,
      94,    50,    96,    97,   130,   150,    98,    36,    37,    77,
      78,   133,    46,    46,    50,    87,    88,    46,    33,    50,
      50,   115,   116,    34,    38,    51,    50,    74,    52,   130,
     145,    46,    89,    90,    91,    92,    93,    94,    79,    75,
      76,    80,    39,    81,    46,    99,    40,    41,   103,    46,
      46,    42,    43,    44,   110,   -56,    46,   101,   122,    45,
     104,   129,   132,   134,   135,   136,   137,   139,   140,   146,
     148,   147,   151,     5,    10,    35,    22,    71,   121,     0,
       0,   143
};

static const yytype_int16 yycheck[] =
{
       1,    54,    10,    34,    55,     9,     6,    76,    57,     9,
      16,    12,    43,    44,    67,     5,     6,    18,     0,    20,
      21,     5,     6,    50,    53,    17,    45,    20,    21,     6,
      31,    39,     9,    34,    50,    54,     5,     6,    31,   108,
      18,    10,    43,    44,    51,    76,     5,     6,    19,    53,
     101,    10,    20,    72,    52,    74,    56,    57,    23,    24,
      79,    50,    52,    40,    41,    42,   135,    96,    97,    98,
      54,   140,   103,   104,    53,    76,    95,   108,   147,    56,
      57,    51,   103,     5,     6,    44,    45,    46,    47,    48,
      49,   122,     3,     4,   113,   148,     7,    23,    24,    28,
      29,   122,   103,   104,   135,     5,     6,   108,    56,   140,
     141,    87,    88,    21,    54,    53,   147,    53,    25,   138,
     141,   122,    44,    45,    46,    47,    48,    49,    55,    22,
      50,    56,    26,    23,   135,    39,    30,    31,    33,   140,
     141,    35,    36,    37,    54,    10,   147,    38,    27,    43,
      52,    25,    10,    33,    50,    28,    23,    10,    50,    34,
      30,    50,    34,    57,     8,    31,    18,    44,    99,    -1,
      -1,   138
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    60,    61,    63,    57,    70,     0,    62,    50,
      61,    64,    17,    67,    68,    69,    70,    18,    50,    51,
      52,    19,    67,    23,    24,    69,    65,    66,    69,    53,
      20,    50,    51,    56,    21,    65,    23,    24,    54,    26,
      30,    31,    35,    36,    37,    43,    70,    71,    72,    78,
      81,    53,    25,     6,     9,    40,    41,    42,    56,    70,
      81,    82,    83,    85,    89,    90,    91,    74,    77,    80,
      81,    80,     9,    82,    53,    22,    50,    28,    29,    55,
      56,    23,    85,    82,    89,    91,     9,     5,     6,    44,
      45,    46,    47,    48,    49,    88,     3,     4,     7,    39,
      79,    38,    89,    33,    52,    82,    82,    71,    73,    82,
      54,    10,    10,    86,    87,    83,    83,    82,    85,    85,
      85,    90,    27,    91,    75,    72,    81,    54,    71,    25,
      82,    84,    10,    72,    33,    50,    28,    23,    52,    10,
      50,    76,    71,    84,    71,    72,    34,    50,    30,    71,
      89,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    62,    61,    64,    63,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    71,
      71,    72,    72,    73,    72,    74,    75,    76,    72,    77,
      72,    72,    72,    72,    72,    79,    78,    80,    80,    81,
      81,    82,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    85,    85,    85,    86,    85,    87,    85,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     0,     3,     0,    13,     0,     3,
       3,     8,     0,     3,     3,     8,     1,     3,     1,     0,
       3,     3,     2,     0,     5,     0,     0,     0,    10,     0,
       9,     2,     2,     1,     2,     0,     7,     1,     3,     1,
       4,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       2,     1,     1,     3,     0,     5,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     2,     3,
       1,     1,     3
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
#line 99 "mini_l.y" /* yacc.c:1646  */
    {
        if (vectorSearch("main", function_table) != true) {
            //error 3
            yyerror("Not defining a main function.");
        }
        outputErrors();
        //cout << terminal_symbol_table.at(0) << endl;
    }
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "mini_l.y" /* yacc.c:1646  */
    {
        //funcs -> epsilon
        //do nothing
    }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 114 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered funcs\n";
        variable_table.clear(); 
        array_table.clear();
        //rest handled in func
    }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 120 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by next funcs call
    }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 126 "mini_l.y" /* yacc.c:1646  */
    { 
        //cout << "Entered func\n";
        function_table.push_back(symbol_table.back());
        cout << "func " << symbol_table.back() << endl; 
        symbol_table.pop_back();
    }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "mini_l.y" /* yacc.c:1646  */
    {
        for(int i = 0; i < generated_code.size(); i++){
            cout << generated_code.at(i) << endl;
        }
        generated_code.clear();
        cout << "endfunc\n\n";
    }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 141 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing
    }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing
    }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 151 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered dec\n";
        for( int i = 0; i < symbol_table.size(); i++){
          	if (vectorSearch(symbol_table.at(i), variable_table) == false) {
          		if (vectorSearch(symbol_table.at(i), terminal_symbol_table) == false) {
          			cout << ". " << symbol_table.at(i) << endl;
					variable_table.push_back(symbol_table.at(i));
          		}
          		else {
          		    //error 5
          			yyerror("Trying to name a variable with the same name as a reserved keyword.");
          		}
          	}
          	else {
          	    //error 4
          		yyerror("Defining a variable more than once.");
          	}
        }
        symbol_table.clear();
    }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 172 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered dec pt2\n";
        cout << ".[] " << symbol_table.back() << ", " << (yyvsp[-3].ival) << endl;
		variable_table.push_back(symbol_table.back());
		array_table.push_back(symbol_table.back());
        symbol_table.pop_back();
        //for(int i = 0; i < symbol_table.size(); ++i){
        //    cout << symbol_table.at(i);
        //}
    }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "mini_l.y" /* yacc.c:1646  */
    {
        //param_decs -> epsilon
        //do nothing
    }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 189 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered param_decs\n";
        //handled in param_dec
    }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 196 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered param_dec\n";
        if (vectorSearch(symbol_table.back(), variable_table) == false) {
     		if (vectorSearch(symbol_table.back(), terminal_symbol_table) == false) {
      			cout << ". " << symbol_table.back() << endl;
      			cout << "= " << symbol_table.back() << ", $0" << endl; 
      			//cout << "$0 is: " << $0 << "\n";
      			variable_table.push_back(symbol_table.back());
      			symbol_table.pop_back();
      		}
      		else {
      			yyerror("Trying to name a variable with the same name as a reserved keyword");
      			}
    		}
    	else {
    		yyerror("Defining a variable more than once");
    	}
    }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 215 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered param_dec bottom\n";
        if ((yyvsp[-3].ival) <= 0) {
        	yyerror("Declaring an array of size <= 0");
        }
        else {
            if ((yyvsp[-3].ival) <= 0) {
                yyerror("Declaring an array of size <= 0");
        	}
            else {
                cout << ".[] " << symbol_table.back() << ", " << (yyvsp[-3].ival) << endl;
    			array_table.push_back(symbol_table.back());
    			//cout << "$num is: " << $num << "\n";
    			variable_table.push_back(symbol_table.back());
            	symbol_table.pop_back();
            }
        }
    }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 236 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by ident
    }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 240 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by ident
    }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "mini_l.y" /* yacc.c:1646  */
    {
        //add identifier to symbol table
        symbol_table.push_back((yyvsp[0].s));
    }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 252 "mini_l.y" /* yacc.c:1646  */
    {
        //stats -> epsilon
        //do nothing
    }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 257 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by stat
    }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 263 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat1\n";
        if(symbol_table.back() == "[]"){ 
            symbol_table.pop_back();
            string temp2 = temp_vector.back();
            temp_vector.pop_back();
            //cout << "temp2 is: " << temp2 << "\n";
            string temp1 = temp_vector.back();
            temp_vector.pop_back();
            //cout << "temp1 is: " << temp1 << "\n";
            generated_code.push_back("[]= " + symbol_table.back() + ", " + temp1 + ", " + temp2);
            symbol_table.pop_back();
        }
        else {
            generated_code.push_back("= " + symbol_table.back() + ", " + temp_vector.back());
            //cout << "symbol_table.back is: " << symbol_table.back() << "\n";
            //cout << "temp_vector.back is: " << temp_vector.back() << "\n";
            symbol_table.pop_back();
            temp_vector.pop_back();
        }
    }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 285 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat2\n";
        //cout << "labelCount is: " << labelCount << "\n";
        generated_code.push_back(": __label__" + to_string(labelCount+1));
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
        generated_code.at(findLastSpace()) = ":= __label__" + to_string(labelCount+1);
        generated_code.at(findLastSpace()) = "?:= __label__" + to_string(labelCount) + ", " + cond_table.back();
        labelCount+=2;
        cond_table.pop_back();                    
    }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 296 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat3\n";
        spaceAllocate(2);
    }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 300 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat3 pt2\n";
        //cout << "labelCount is: " << labelCount << "\n";
        generated_code.push_back(": __label__" + to_string(labelCount+2));
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount+1); 
        generated_code.at(findLastSpace()) = ":=  __label__" + to_string(labelCount+2);
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
        generated_code.at(findLastSpace()) = ":= __label__" + to_string(labelCount+1);
        generated_code.at(findLastSpace()) = "?:= __label__" + to_string(labelCount) + ", " + cond_table.back();
        labelCount+=3;
        cond_table.pop_back();
    }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 313 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat4\n";
        loopFlag = true; 
        generated_code.push_back("_ALLOCATED_SPACE_");
    }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 318 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat4 pt2\n";
        spaceAllocate(3);
    }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 322 "mini_l.y" /* yacc.c:1646  */
    {
        loopFlag = true;
    }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 325 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat4 pt3\n";
        if(continueCount){
            generated_code.push_back(": __label__" + to_string(labelCount+3));
            generated_code.at(findLastContinue()) = ":= __label__" + to_string(labelCount+3);
        } 
        generated_code.push_back(":= __label__" + to_string(labelCount+2));
        generated_code.push_back(": __label__" + to_string(labelCount+1));
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
      	generated_code.at(findLastSpace()) = ":= __label__" + to_string(labelCount+1);
      	generated_code.at(findLastSpace()) = "?:= __label__" + to_string(labelCount) + ", " + cond_table.back();
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount+2);
      	labelCount+=3;
        if(continueCount){
            labelCount++;
            continueCount--;
        }
        cond_table.pop_back();
    }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 345 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat5\n";
        generated_code.push_back("_ALLOCATED_SPACE_");
        loopFlag = true;
        
    }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 351 "mini_l.y" /* yacc.c:1646  */
    { 
        //cout << "Entered stat5 pt2\n";
        if(continueCount){
            generated_code.push_back(": __label__" + to_string(labelCount+1));
            generated_code.at(findLastContinue()) = ":= __label__" + to_string(labelCount+1);
        }                      
        generated_code.push_back("?:= __label__" + to_string(labelCount) + ", " + temp_vector.back());  
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
        labelCount++;
        if(continueCount){
            labelCount++;
            continueCount--;
        }
		loopFlag = false; 
        temp_vector.pop_back();                  
    }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 368 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat6\n";
        for(int i = 0; i < symbol_table.size(); i++){
            generated_code.push_back(".< " + symbol_table.at(i));
        }
        symbol_table.clear();
    }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 376 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat7\n";
        if(symbol_table.back() == "[]") {
            symbol_table.pop_back();
            generated_code.push_back(".[]> " + symbol_table.back() + ", " + temp_vector.back());
            temp_vector.pop_back();
            symbol_table.pop_back();
        }
        else { 
            for(int i = 0; i < symbol_table.size(); i++){
                generated_code.push_back(".> " + symbol_table.at(i));
            }
            symbol_table.clear();
        }
    }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 392 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat8\n";
        if(loopFlag == false){
            yyerror("Using continue statement outside a loop");
        }
        else{
            generated_code.push_back("_ALLOCATED_CONTINUE_");
            continueCount++;
        }
    }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 403 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered stat9\n";
        generated_code.push_back("ret " + temp_vector.back());
        temp_vector.pop_back();
    }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 411 "mini_l.y" /* yacc.c:1646  */
    {
        spaceAllocate(3);
    }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 414 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by stat
    }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by var
    }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 424 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by var
    }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 430 "mini_l.y" /* yacc.c:1646  */
    {
        if (vectorSearch(symbol_table.back(), variable_table) != true)  {
			yyerror("Using a variable without having first declared it");
		}
	}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 436 "mini_l.y" /* yacc.c:1646  */
    {
        if (vectorSearch(symbol_table.back(), variable_table) != true)  {
		    yyerror("Using a variable without having first declared it");
		}
		else {
		    if (vectorSearch(symbol_table.back(), array_table) == true) {
                symbol_table.push_back("[]");
		    }
			else {
				yyerror("Specifying an array index when using a regular integer variable");
			}
		}
    }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 452 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by mult_expr
    }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 456 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction("+ ");
    }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 460 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction("- ");
    }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 465 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by term
    }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 469 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction("* ");
    }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 473 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction("/ ");
    }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 477 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction("% ");
    }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 483 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by expr
    }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 487 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by expr
    }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 492 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by other cases
    }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 496 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered term NUMBER\n";
        string temp = "__temp__" + to_string(tempCount);
        ostringstream oss;
        oss << (yyvsp[0].ival);
        generated_code.push_back(". " + temp);
        generated_code.push_back("= " + temp + ", " + oss.str());
        temp_vector.push_back(temp);
        //cout << temp_vector.back() << endl;
        ++tempCount;
    }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 508 "mini_l.y" /* yacc.c:1646  */
    {
        //cout << "Entered term var\n";
        string temp = "__temp__" + to_string(tempCount);
        generated_code.push_back(". " + temp);
        //cout << generated_code.back() << endl;
        if(symbol_table.back() == "[]"){
            symbol_table.pop_back();
            generated_code.push_back("=[] " + temp + ", " + symbol_table.back() + ", " + temp_vector.back());
            //cout << generated_code.back() << endl;
            temp_vector.pop_back();                      
        }
        else {
            generated_code.push_back("= " + temp + ", " + symbol_table.back());
            //cout << generated_code.back() << endl;
        }
        symbol_table.pop_back();
        temp_vector.push_back(temp);
        //cout << temp_vector.back() << endl;
        ++tempCount;
    }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 529 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by expr
    }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 533 "mini_l.y" /* yacc.c:1646  */
    {
        //push identifier to program stack
        program_stack.push_back((yyvsp[-1].s));
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 537 "mini_l.y" /* yacc.c:1646  */
    {
        string s = program_stack.back();
        s = s.substr(0,s.size()-2);
        if (vectorSearch(s, function_table) == true) {
            generated_code.push_back("param " + temp_vector.back());
            //cout << generated_code.back() << endl;
          	temp_vector.pop_back();
          	string temp = "__temp__" + to_string(tempCount);
          	generated_code.push_back(". " + temp);
          	//cout << generated_code.back() << endl;
          	generated_code.push_back("call " + s + ", " + temp);
          	//cout << generated_code.back() << endl;
          	temp_vector.push_back(temp);
          	program_stack.pop_back();
          	symbol_table.pop_back();
          	tempCount++;
        }
        else {
          	yyerror("Calling a function which has not been defined");
        }
    }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 559 "mini_l.y" /* yacc.c:1646  */
    {
        program_stack.push_back((yyvsp[-1].s));
    }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 562 "mini_l.y" /* yacc.c:1646  */
    {
        string s = program_stack.back();
        s = s.substr(0,s.size()-2);
        if (vectorSearch(s, function_table) == true) {
            string temp = "__temp__" + to_string(tempCount);
          	generated_code.push_back(". " + temp);
          	//cout << generated_code.back() << endl;
          	generated_code.push_back("call " + s + ", " + temp);
          	//cout << generated_code.back() << endl;
          	temp_vector.push_back(temp);
          	program_stack.pop_back();
          	symbol_table.pop_back();
          	tempCount++;
        }
        else {
          	yyerror("Calling a function which has not been defined");
        }
    }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 583 "mini_l.y" /* yacc.c:1646  */
    {
        equation_table.push_back("== ");
    }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 587 "mini_l.y" /* yacc.c:1646  */
    {
        equation_table.push_back("!= ");
    }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 591 "mini_l.y" /* yacc.c:1646  */
    {
        equation_table.push_back("< ");
    }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 595 "mini_l.y" /* yacc.c:1646  */
    {
        equation_table.push_back("> ");
    }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 599 "mini_l.y" /* yacc.c:1646  */
    {
        equation_table.push_back("<= ");
    }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 603 "mini_l.y" /* yacc.c:1646  */
    {
        equation_table.push_back(">= ");
    }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 609 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by rel_and_expr
    }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 613 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction("|| ");
    }
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 619 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by rel_expr
    }
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 623 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction("&& ");
    }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 629 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by other cases
    }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 633 "mini_l.y" /* yacc.c:1646  */
    {
        opFunction(equation_table.back());
        equation_table.pop_back();
    }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 638 "mini_l.y" /* yacc.c:1646  */
    { 
        string temp = "__temp__" + to_string(tempCount);
        generated_code.push_back(". " + temp);
        //cout << generated_code.back() << endl;
        generated_code.push_back("= " + temp + ", 1");
        //cout << generated_code.back() << endl;
        temp_vector.push_back(temp);
        ++tempCount;
    }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 648 "mini_l.y" /* yacc.c:1646  */
    { 
        string temp = "__temp__" + to_string(tempCount);
        generated_code.push_back(". " + temp);
        //cout << generated_code.back() << endl;
        generated_code.push_back("= " + temp + ", 0");
        //cout << generated_code.back() << endl;
        temp_vector.push_back(temp);
        ++tempCount;
    }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 658 "mini_l.y" /* yacc.c:1646  */
    {
        //do nothing, handled by bool_expr
    }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2257 "y.tab.c" /* yacc.c:1646  */
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
#line 663 "mini_l.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
   fillTerminalSymbolTable();
   yyparse();
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", yylineno, col_num, msg);
}

//returns true if vector contains string, othwerwise false
bool vectorSearch(string input, vector<string> target) {
	for (unsigned i = 0; i < target.size(); ++i) {
		if (target.at(i) == input) {
			   return true;
		}
	}
	return false;
}

//allocates space for embedded calls
void spaceAllocate(int spaces) {
    //cout << "Called spaceAllocate for " << spaces << " spaces" << endl;
    generated_code.push_back("_ALLOCATED_SPACE_");
    generated_code.push_back("_ALLOCATED_SPACE_");
    if(spaces == 3) {
        generated_code.push_back("_ALLOCATED_SPACE_"); 
        cond_table.push_back(temp_vector.back());
        temp_vector.pop_back();
    }
}

//fills terminal symbol table with names of terminal symbols to check against
void fillTerminalSymbolTable(){
    //cout << "Called fillTerminalSymbolTable" << endl;
    terminal_symbol_table.push_back("*"); 
    terminal_symbol_table.push_back("/");  
    terminal_symbol_table.push_back("+"); 
    terminal_symbol_table.push_back("-");  
    terminal_symbol_table.push_back("%");  
    terminal_symbol_table.push_back("=");  
    terminal_symbol_table.push_back("(");  
    terminal_symbol_table.push_back(")"); 
    terminal_symbol_table.push_back("end"); 
    terminal_symbol_table.push_back("beginprogram");  
    terminal_symbol_table.push_back("endprogram");  
    terminal_symbol_table.push_back("elseif"); 
    terminal_symbol_table.push_back("function"); 
    terminal_symbol_table.push_back("beginparams"); 
    terminal_symbol_table.push_back("endparams"); 
    terminal_symbol_table.push_back("beginlocals"); 
    terminal_symbol_table.push_back("endlocals"); 
    terminal_symbol_table.push_back("beginbody"); 
    terminal_symbol_table.push_back("endbody"); 
    terminal_symbol_table.push_back("integer"); 
    terminal_symbol_table.push_back("array"); 
    terminal_symbol_table.push_back("["); 
    terminal_symbol_table.push_back("]"); 
    terminal_symbol_table.push_back("[]"); 
    terminal_symbol_table.push_back("of"); 
    terminal_symbol_table.push_back("if"); 
    terminal_symbol_table.push_back("then"); 
    terminal_symbol_table.push_back("endif"); 
    terminal_symbol_table.push_back("else"); 
    terminal_symbol_table.push_back("while"); 
    terminal_symbol_table.push_back("do"); 
    terminal_symbol_table.push_back("in"); 
    terminal_symbol_table.push_back("beginloop"); 
    terminal_symbol_table.push_back("endloop"); 
    terminal_symbol_table.push_back("continue"); 
    terminal_symbol_table.push_back("read"); 
    terminal_symbol_table.push_back("write"); 
    terminal_symbol_table.push_back("&&");
    terminal_symbol_table.push_back("and"); 
    terminal_symbol_table.push_back("or");
    terminal_symbol_table.push_back("||");
    terminal_symbol_table.push_back("true"); 
    terminal_symbol_table.push_back("false"); 
    terminal_symbol_table.push_back("return"); 
    terminal_symbol_table.push_back("=="); 
    terminal_symbol_table.push_back("!="); 
    terminal_symbol_table.push_back("<"); 
    terminal_symbol_table.push_back(">"); 
    terminal_symbol_table.push_back(">="); 
    terminal_symbol_table.push_back("<="); 
    terminal_symbol_table.push_back(";"); 
    terminal_symbol_table.push_back(":"); 
    terminal_symbol_table.push_back(",");
    return;
}

//finds last open space in generated code
int findLastSpace() {
    //cout << "Called findLastSpace" << endl;
    for(int i = generated_code.size()-1; i >= 0; i--){
        if(generated_code.at(i) == "_ALLOCATED_SPACE_") {
            //cout << "findLastSpace i is " << i << endl;
            return i;
        }
    }
    //cout << "findLastSpace did not find allocated space" << endl;
    return -1;
}

//finds last occurrence of continue in generated code
int findLastContinue() {
    //cout << "Called findLastContinue" << endl;
    for(int i = generated_code.size()-1; i >= 0; i--){
        if(generated_code.at(i) == "_ALLOCATED_CONTINUE_") {
            //cout << "findLastContinue i is " << i << endl;
            return i;
        }
    }
    //cout << "findLastContinue did not find allocated continue" << endl;
    return -1;
}

//handles operation statements
void opFunction(string op) {
    //cout << "Called opFunction" << endl;
    string temp = "__temp__" + to_string(tempCount);
    string src2 = temp_vector.back();
    temp_vector.pop_back();
    string src1 = temp_vector.back();
    temp_vector.pop_back();
    generated_code.push_back(". " + temp);
    //cout << generated_code.back() << endl;
    generated_code.push_back(op + temp + ", " + src1 + ", " + src2);
    //cout << generated_code.back() << endl;
    temp_vector.push_back(temp);
    tempCount++;
    return;
}

void outputErrors(){
    return;
}
