
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "mycomp.y"

#include "semantic.h"
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
extern int numlin;
int yydebug=1;


/* Line 189 of yacc.c  */
#line 83 "mycomp.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TYPE = 258,
     COMP = 259,
     ID = 260,
     ENTERO = 261,
     REAL = 262,
     STRINGLITERAL = 263,
     WHILE = 264,
     IF = 265,
     ELSE = 266,
     FUNCT = 267,
     MAIN = 268,
     RETURN = 269,
     PRINT = 270,
     UMINUS = 271
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 9 "mycomp.y"
 	
		char type;
		int comp;
		char name[15];
		int entero;
		double real;
		char stringLiteral[120];
		struct ast *ast;
		struct list *list;
		struct funDef *funDef;
		struct returnStatement *returnST;
		struct assign *assign;
		struct listContainer *listContainer;
		struct num *num;



/* Line 214 of yacc.c  */
#line 153 "mycomp.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 165 "mycomp.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   271

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      21,    22,    19,    17,    29,    18,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
       2,    16,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
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
      15,    23
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    13,    14,    15,    16,
      24,    26,    28,    31,    39,    51,    52,    53,    54,    65,
      68,    71,    72,    73,    74,    87,    88,    89,    90,   105,
     107,   108,   111,   112,   117,   118,   123,   124,   129,   130,
     135,   136,   141,   142,   146,   148,   149,   152,   153,   159,
     160,   161,   168,   170,   171,   174,   179,   180,   184,   185,
     188,   189,   194,   195,   203,   204,   205,   211,   213,   214,
     217,   218,   223,   224,   227,   228,   231,   233,   234,   237,
     242,   243,   247,   249,   250,   251,   252,   253,   267,   268,
     274,   276,   277,   278
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    -1,    -1,    -1,    91,    32,    52,    33,
      35,    34,    -1,    -1,    -1,    -1,    13,    36,    24,    37,
      39,    25,    38,    -1,    40,    -1,    41,    -1,    41,    40,
      -1,    10,    21,    69,    22,    24,    39,    25,    -1,    10,
      21,    69,    22,    24,    39,    25,    11,    24,    39,    25,
      -1,    -1,    -1,    -1,     9,    21,    42,    69,    22,    24,
      43,    39,    25,    44,    -1,    54,    26,    -1,    66,    26,
      -1,    -1,    -1,    -1,    12,     3,     5,    21,    46,    82,
      22,    24,    47,    39,    25,    48,    -1,    -1,    -1,    -1,
      12,     3,    27,    28,     5,    21,    49,    82,    22,    24,
      50,    39,    25,    51,    -1,    53,    -1,    -1,    45,    53,
      -1,    -1,    21,    55,    54,    22,    -1,    -1,    54,    17,
      56,    54,    -1,    -1,    54,    18,    57,    54,    -1,    -1,
      54,    19,    58,    54,    -1,    -1,    54,    20,    59,    54,
      -1,    -1,    18,    60,    54,    -1,    79,    -1,    -1,     5,
      61,    -1,    -1,     5,    27,    54,    28,    62,    -1,    -1,
      -1,    15,    21,    63,    54,    22,    64,    -1,    71,    -1,
      -1,     8,    65,    -1,     5,    21,    84,    22,    -1,    -1,
      14,    67,    54,    -1,    -1,    14,    68,    -1,    -1,    54,
       4,    70,    54,    -1,    -1,     5,    27,    54,    28,    16,
      72,    54,    -1,    -1,    -1,     5,    16,    73,    54,    74,
      -1,    76,    -1,    -1,    79,    77,    -1,    -1,    79,    29,
      78,    76,    -1,    -1,     6,    80,    -1,    -1,     7,    81,
      -1,    83,    -1,    -1,     3,     5,    -1,     3,     5,    29,
      83,    -1,    -1,    54,    29,    84,    -1,    54,    -1,    -1,
      -1,    -1,    -1,     3,     5,    27,    86,     6,    28,    16,
      87,    24,    88,    75,    25,    89,    -1,    -1,     3,     5,
      16,    90,    54,    -1,    92,    -1,    -1,    -1,    85,    26,
      93,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    48,    48,    48,    51,    51,    51,    51,
      54,    56,    57,    60,    61,    62,    62,    62,    62,    63,
      64,    67,    67,    67,    67,    68,    68,    68,    68,    71,
      74,    75,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    85,    85,    86,    86,    87,
      87,    87,    88,    89,    89,    90,    93,    93,    94,    94,
      97,    97,   100,   100,   101,   101,   101,   104,   107,   107,
     108,   108,   111,   111,   112,   112,   115,   118,   119,   120,
     123,   124,   125,   128,   128,   128,   128,   128,   129,   129,
     132,   135,   136,   136
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "COMP", "ID", "ENTERO", "REAL",
  "STRINGLITERAL", "WHILE", "IF", "ELSE", "FUNCT", "MAIN", "RETURN",
  "PRINT", "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "UMINUS",
  "'{'", "'}'", "';'", "'['", "']'", "','", "$accept", "program", "$@1",
  "$@2", "$@3", "MainProgram", "$@4", "$@5", "$@6",
  "statementBlockContainer", "statementBlock", "statement", "$@7", "$@8",
  "$@9", "function", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "functionListContainer", "functionList", "exp", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26",
  "returnExp", "$@27", "$@28", "compare", "$@29", "assign", "$@30", "$@31",
  "$@32", "numListContainer", "numList", "$@33", "$@34", "num", "$@35",
  "$@36", "paramListContainer", "paramList", "expList", "declaration",
  "$@37", "$@38", "$@39", "$@40", "$@41", "declarationListContainer",
  "declarationList", "$@42", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    61,    43,    45,    42,
      47,    40,    41,   271,   123,   125,    59,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    32,    33,    34,    31,    36,    37,    38,    35,
      39,    40,    40,    41,    41,    42,    43,    44,    41,    41,
      41,    46,    47,    48,    45,    49,    50,    51,    45,    52,
      53,    53,    55,    54,    56,    54,    57,    54,    58,    54,
      59,    54,    60,    54,    54,    61,    54,    62,    54,    63,
      64,    54,    54,    65,    54,    54,    67,    66,    68,    66,
      70,    69,    72,    71,    73,    74,    71,    75,    77,    76,
      78,    76,    80,    79,    81,    79,    82,    83,    83,    83,
      84,    84,    84,    86,    87,    88,    89,    85,    90,    85,
      91,    92,    93,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     6,     0,     0,     0,     7,
       1,     1,     2,     7,    11,     0,     0,     0,    10,     2,
       2,     0,     0,     0,    12,     0,     0,     0,    14,     1,
       0,     2,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     3,     1,     0,     2,     0,     5,     0,
       0,     6,     1,     0,     2,     4,     0,     3,     0,     2,
       0,     4,     0,     7,     0,     0,     5,     1,     0,     2,
       0,     4,     0,     2,     0,     2,     1,     0,     2,     4,
       0,     3,     1,     0,     0,     0,     0,    13,     0,     5,
       1,     0,     0,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      91,     0,     0,     0,     2,    90,     0,     1,    92,    30,
      88,    83,    91,     0,    30,     3,    29,     0,     0,    93,
       0,    31,     0,    45,    72,    74,    53,     0,    42,    32,
      89,    52,    44,     0,     0,     0,     6,     4,    64,    80,
       0,    46,    73,    75,    54,    49,     0,     0,    34,    36,
      38,    40,     0,    21,     0,     0,     5,     0,    82,     0,
       0,     0,    43,     0,     0,     0,     0,     0,    84,    77,
       0,     7,    65,    80,    55,    47,     0,    33,    35,    37,
      39,    41,     0,     0,     0,    76,    25,     0,    66,    81,
      62,    48,    50,    85,    78,     0,    77,     0,     0,    56,
       0,    10,    11,     0,     0,     0,    51,     0,    77,    22,
       0,    15,     0,     0,    59,     8,    12,    19,    20,    63,
       0,    67,    68,    79,     0,     0,     0,     0,     0,    57,
       9,    86,    70,    69,     0,    26,     0,    60,     0,    87,
       0,    23,     0,     0,     0,     0,    71,    24,     0,    16,
      61,     0,    27,     0,    13,    28,     0,     0,    17,     0,
      18,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    22,    56,    37,    55,    87,   130,   100,
     101,   102,   126,   153,   160,    14,    69,   124,   147,    96,
     142,   155,    15,    16,   103,    47,    64,    65,    66,    67,
      46,    41,    91,    61,   106,    44,   104,   113,   114,   128,
     144,    31,   105,    57,    88,   120,   121,   133,   140,    32,
      42,    43,    84,    85,    59,     3,    18,    82,   107,   139,
      17,     4,     5,    12
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -122
static const yytype_int8 yypact[] =
{
       2,     1,    14,    -6,  -122,  -122,   -14,  -122,  -122,    15,
    -122,  -122,     2,    30,    15,  -122,  -122,    10,    31,  -122,
      -1,  -122,    28,    62,  -122,  -122,  -122,    21,  -122,  -122,
      99,  -122,  -122,    17,    22,    18,  -122,  -122,  -122,    10,
      10,  -122,  -122,  -122,  -122,  -122,    10,    10,  -122,  -122,
    -122,  -122,    47,  -122,    46,    40,  -122,    10,   -10,    43,
      57,    10,  -122,    83,    10,    10,    10,    10,  -122,    65,
      48,  -122,    99,    10,  -122,    55,    93,  -122,    -8,    -8,
    -122,  -122,    56,    67,    59,  -122,  -122,    52,  -122,  -122,
    -122,  -122,  -122,  -122,    50,    58,    65,    63,    66,    60,
      69,  -122,    52,    73,    71,    10,  -122,    29,    65,  -122,
      76,  -122,    10,    10,  -122,  -122,  -122,  -122,  -122,    99,
      79,  -122,    77,  -122,    52,    84,    10,    35,    85,    99,
    -122,  -122,  -122,  -122,    89,  -122,    98,  -122,    97,  -122,
      29,  -122,    52,   100,    10,    52,  -122,  -122,   101,  -122,
      99,   103,  -122,    52,   111,  -122,   104,   106,  -122,    52,
    -122,   107,  -122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -121,
      23,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,   109,   -17,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,     5,
    -122,  -122,  -122,  -122,  -122,  -122,    -7,  -122,  -122,  -106,
    -122,  -122,    38,    27,    64,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,   124,  -122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      30,   122,    10,   134,    34,     1,     6,    48,    49,    50,
      51,    50,    51,    11,     7,    23,    24,    25,    26,    73,
       8,   148,    58,    60,   151,    27,    35,    13,    28,    62,
      63,    29,   156,    20,   122,    24,    25,    33,   161,   137,
      72,    36,    45,    53,    76,    52,    54,    78,    79,    80,
      81,    70,    48,    49,    50,    51,    58,    23,    24,    25,
      26,    97,    98,    68,    71,    74,    99,    27,    83,    86,
      28,    90,    94,    29,    48,    49,    50,    51,    38,   108,
      93,    95,   109,    39,   111,    75,   -58,   112,   119,    40,
      48,    49,    50,    51,   115,   127,   129,   118,   125,   117,
      48,    49,    50,    51,   131,    77,   132,   138,   135,   127,
      48,    49,    50,    51,   141,    92,    48,    49,    50,    51,
     143,   145,   157,    21,   149,   116,   152,   150,   154,   158,
     159,   136,   162,   146,   110,   123,    19,    89
};

static const yytype_uint8 yycheck[] =
{
      17,   107,    16,   124,     5,     3,     5,    17,    18,    19,
      20,    19,    20,    27,     0,     5,     6,     7,     8,    29,
      26,   142,    39,    40,   145,    15,    27,    12,    18,    46,
      47,    21,   153,     3,   140,     6,     7,     6,   159,     4,
      57,    13,    21,    21,    61,    28,    28,    64,    65,    66,
      67,     5,    17,    18,    19,    20,    73,     5,     6,     7,
       8,     9,    10,    16,    24,    22,    14,    15,     3,    21,
      18,    16,     5,    21,    17,    18,    19,    20,    16,    29,
      24,    22,    24,    21,    21,    28,    26,    21,   105,    27,
      17,    18,    19,    20,    25,   112,   113,    26,    22,    26,
      17,    18,    19,    20,    25,    22,    29,    22,    24,   126,
      17,    18,    19,    20,    25,    22,    17,    18,    19,    20,
      22,    24,    11,    14,    24,   102,    25,   144,    25,    25,
      24,   126,    25,   140,    96,   108,    12,    73
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    85,    91,    92,     5,     0,    26,    32,
      16,    27,    93,    12,    45,    52,    53,    90,    86,    92,
       3,    53,    33,     5,     6,     7,     8,    15,    18,    21,
      54,    71,    79,     6,     5,    27,    13,    35,    16,    21,
      27,    61,    80,    81,    65,    21,    60,    55,    17,    18,
      19,    20,    28,    21,    28,    36,    34,    73,    54,    84,
      54,    63,    54,    54,    56,    57,    58,    59,    16,    46,
       5,    24,    54,    29,    22,    28,    54,    22,    54,    54,
      54,    54,    87,     3,    82,    83,    21,    37,    74,    84,
      16,    62,    22,    24,     5,    22,    49,     9,    10,    14,
      39,    40,    41,    54,    66,    72,    64,    88,    29,    24,
      82,    21,    21,    67,    68,    25,    40,    26,    26,    54,
      75,    76,    79,    83,    47,    22,    42,    54,    69,    54,
      38,    25,    29,    77,    39,    24,    69,     4,    22,    89,
      78,    25,    50,    22,    70,    24,    76,    48,    39,    24,
      54,    39,    25,    43,    25,    51,    39,    11,    25,    24,
      44,    39,    25
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 48 "mycomp.y"
    {printf("Fin declaraciones------------------\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 48 "mycomp.y"
    {printf("Fin funciones------------------\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 48 "mycomp.y"
    {printf("Final programa\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 48 "mycomp.y"
    { (yyval.ast) = eval((yyvsp[(1) - (6)].listContainer), (yyvsp[(3) - (6)].listContainer), (yyvsp[(5) - (6)].listContainer)); printf("parse done.\n"); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 51 "mycomp.y"
    { printf("Main"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 51 "mycomp.y"
    { printf("[ corchetes\n"); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 51 "mycomp.y"
    { printf("}\n"); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 51 "mycomp.y"
    { (yyval.listContainer) = (yyvsp[(5) - (7)].listContainer) ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 54 "mycomp.y"
    { (yyval.listContainer) = newListContainer( 'S', (yyvsp[(1) - (1)].list)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 56 "mycomp.y"
    { (yyval.list) = newList( (yyvsp[(1) - (1)].ast), NULL); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 57 "mycomp.y"
    { (yyval.list) = newList ((yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].list)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 60 "mycomp.y"
    { (yyval.ast) = (struct ast*)newBranch('I', (yyvsp[(3) - (7)].ast), (struct ast*)(yyvsp[(6) - (7)].listContainer), NULL); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 61 "mycomp.y"
    { (yyval.ast) = newBranch('I', (yyvsp[(3) - (11)].ast), (struct ast*)(yyvsp[(6) - (11)].listContainer), (struct ast*)(yyvsp[(10) - (11)].listContainer)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 62 "mycomp.y"
    { printf("while["); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 62 "mycomp.y"
    { printf("]  [\n"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 62 "mycomp.y"
    { printf("}\n"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 62 "mycomp.y"
    { (yyval.ast) = newBranch('W', (yyvsp[(4) - (10)].ast), (struct ast*)(yyvsp[(8) - (10)].listContainer), NULL); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 63 "mycomp.y"
    { printf(";\n"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 64 "mycomp.y"
    { printf(";\n"); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 67 "mycomp.y"
    { printf("funct %c %s[", (yyvsp[(2) - (4)].type), (yyvsp[(3) - (4)].name)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 67 "mycomp.y"
    { printf("] [\n"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 67 "mycomp.y"
    { printf("]\n"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 67 "mycomp.y"
    { (yyval.ast) = newFunDef((yyvsp[(2) - (12)].type), false, (yyvsp[(3) - (12)].name), (struct ast*)(yyvsp[(6) - (12)].listContainer), (struct ast*)(yyvsp[(10) - (12)].listContainer)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 68 "mycomp.y"
    { printf("funct %c[] %s[", (yyvsp[(2) - (6)].type), (yyvsp[(5) - (6)].name)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 68 "mycomp.y"
    { printf("] [\n"); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 68 "mycomp.y"
    { printf("]\n"); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 68 "mycomp.y"
    { (yyval.ast) = newFunDef((yyvsp[(2) - (14)].type), true, (yyvsp[(5) - (14)].name), (struct ast*)(yyvsp[(8) - (14)].listContainer), (struct ast*)(yyvsp[(12) - (14)].listContainer)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 71 "mycomp.y"
    { (yyval.listContainer) = newListContainer('F', (yyvsp[(1) - (1)].list)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 74 "mycomp.y"
    { (yyval.list) =  NULL; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 75 "mycomp.y"
    { (yyval.list) = newList((yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].list)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 78 "mycomp.y"
    { printf("["); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 78 "mycomp.y"
    { printf("]"); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 79 "mycomp.y"
    { printf("+"); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 79 "mycomp.y"
    { (yyval.ast) = newAst('+', (yyvsp[(1) - (4)].ast), (yyvsp[(4) - (4)].ast)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 80 "mycomp.y"
    { printf("-"); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 80 "mycomp.y"
    { (yyval.ast) = newAst('-', (yyvsp[(1) - (4)].ast), (yyvsp[(4) - (4)].ast)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 81 "mycomp.y"
    { printf("*"); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 81 "mycomp.y"
    { (yyval.ast) = newAst('*', (yyvsp[(1) - (4)].ast), (yyvsp[(4) - (4)].ast)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 82 "mycomp.y"
    { printf("/"); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 82 "mycomp.y"
    { (yyval.ast) = newAst('/', (yyvsp[(1) - (4)].ast), (yyvsp[(4) - (4)].ast)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 83 "mycomp.y"
    { printf("-"); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 83 "mycomp.y"
    { (yyval.ast) = newAst('M', (yyvsp[(3) - (3)].ast), NULL); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 84 "mycomp.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 85 "mycomp.y"
    { printf("%s", (yyvsp[(1) - (1)].name)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 85 "mycomp.y"
    { (yyval.ast) = newRef((yyvsp[(1) - (2)].name)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 86 "mycomp.y"
    { printf("]"); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 86 "mycomp.y"
    { (yyval.ast) = newVecRef((yyvsp[(1) - (5)].name), (yyvsp[(3) - (5)].ast)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 87 "mycomp.y"
    { printf("PRINT ["); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 87 "mycomp.y"
    { printf("]"); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 87 "mycomp.y"
    { (yyval.ast) = newPrint((yyvsp[(4) - (6)].ast));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 88 "mycomp.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 89 "mycomp.y"
    { printf("\"%s\"",(yyvsp[(1) - (1)].stringLiteral)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 89 "mycomp.y"
    { (yyval.ast) = newStringLiteral((yyvsp[(1) - (2)].stringLiteral)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 90 "mycomp.y"
    { (yyval.ast) = newFunCall((yyvsp[(1) - (4)].name), (struct ast*)(yyvsp[(3) - (4)].list)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 93 "mycomp.y"
    { printf("return "); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 93 "mycomp.y"
    { (yyval.ast) = newReturn((yyvsp[(3) - (3)].ast)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 94 "mycomp.y"
    { printf("return "); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 94 "mycomp.y"
    { (yyval.ast) = newReturn(NULL); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 97 "mycomp.y"
    { printf("%d",(yyvsp[(2) - (2)].comp)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 97 "mycomp.y"
    { (yyval.ast) = newAst((yyvsp[(2) - (4)].comp), (yyvsp[(1) - (4)].ast), (yyvsp[(4) - (4)].ast)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 100 "mycomp.y"
    { printf("] = "); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 100 "mycomp.y"
    { (yyval.ast) = (struct ast*)newVecItemAssign((yyvsp[(1) - (7)].name), (yyvsp[(3) - (7)].ast), (yyvsp[(7) - (7)].ast)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 101 "mycomp.y"
    { printf("%s = ", (yyvsp[(1) - (2)].name)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 101 "mycomp.y"
    { printf("   Asignacion"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 101 "mycomp.y"
    { (yyval.ast) = (struct ast*)newAssign((yyvsp[(1) - (5)].name), (yyvsp[(4) - (5)].ast)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 104 "mycomp.y"
    { (yyval.listContainer) = newListContainer('N', (yyvsp[(1) - (1)].list)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 107 "mycomp.y"
    { printf("] = "); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 107 "mycomp.y"
    { (yyval.list) = newList((yyvsp[(1) - (2)].ast), NULL); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 108 "mycomp.y"
    { printf(","); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 108 "mycomp.y"
    { (yyval.list) = newList((yyvsp[(1) - (4)].ast), (yyvsp[(4) - (4)].list)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 111 "mycomp.y"
    { printf("%d ", (yyvsp[(1) - (1)].entero)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 111 "mycomp.y"
    { (yyval.ast) = newNum((yyvsp[(1) - (2)].entero)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 112 "mycomp.y"
    { printf("%f", (yyvsp[(1) - (1)].real)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 112 "mycomp.y"
    { (yyval.ast) = newNum((yyvsp[(1) - (2)].real)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 115 "mycomp.y"
    { (yyval.listContainer) = newListContainer('P', (yyvsp[(1) - (1)].list)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 118 "mycomp.y"
    { (yyval.list) = NULL ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 119 "mycomp.y"
    { (yyval.list) = newList((struct ast*)newSymbol((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].name), false, 0), NULL); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 120 "mycomp.y"
    { (yyval.list) = newList((struct ast*)newSymbol((yyvsp[(1) - (4)].type), (yyvsp[(2) - (4)].name), false, 0), (yyvsp[(4) - (4)].list)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 123 "mycomp.y"
    { (yyval.list) = NULL ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 124 "mycomp.y"
    { (yyval.list) = newList((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].list)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 125 "mycomp.y"
    { (yyval.list) = newList((yyvsp[(1) - (1)].ast), NULL); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 128 "mycomp.y"
    { printf("%c %s[",(yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].name)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 128 "mycomp.y"
    { printf("] = "); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 128 "mycomp.y"
    { printf("corc"); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 128 "mycomp.y"
    { printf("corc"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 128 "mycomp.y"
    { (yyval.ast) = newVecDef((yyvsp[(1) - (13)].type), (yyvsp[(5) - (13)].entero), (yyvsp[(2) - (13)].name), (struct ast*)(yyvsp[(11) - (13)].listContainer)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 129 "mycomp.y"
    { printf("%c %s = ",(yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].name)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 129 "mycomp.y"
    { (yyval.ast) = newDef((yyvsp[(1) - (5)].type), (yyvsp[(2) - (5)].name), (yyvsp[(5) - (5)].ast)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 132 "mycomp.y"
    { (yyval.listContainer) = newListContainer('D', (yyvsp[(1) - (1)].list)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 135 "mycomp.y"
    { (yyval.list) =  NULL; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 136 "mycomp.y"
    { printf(";     Declaracion\n"); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 136 "mycomp.y"
    { (yyval.list) = newList((yyvsp[(1) - (4)].ast), (yyvsp[(4) - (4)].list)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2152 "mycomp.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 138 "mycomp.y"

int main(int argc, char** argv) {
if (argc>1) yyin=fopen(argv[1],"r");
yyparse();
}
void yyerror(char* mens) {
printf("Error en linea %i: %s ",numlin,mens);
}

