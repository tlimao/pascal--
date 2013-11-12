
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



#include "bison_adaptee.h"
#include "scope_structure.h"

extern int yylex(void);
extern int yyerror(char*);




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

/* "%code requires" blocks.  */


#include "type_check.h"




/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 0,
     T_ID = 1,
     T_INT_CONST = 2,
     T_REAL_CONST = 3,
     T_BOOLEAN_CONST = 4,
     T_PROGRAM = 5,
     T_PROCEDURE = 6,
     T_BEGIN = 7,
     T_END = 8,
     T_IF = 9,
     T_THEN = 10,
     T_ELSE = 11,
     T_WHILE = 12,
     T_DO = 13,
     T_ASSIGN = 14,
     T_PLUS = 15,
     T_MINUS = 16,
     T_TIMES = 17,
     T_DIVIDE = 18,
     T_DIV = 19,
     T_MOD = 20,
     T_PLUS_EQ = 21,
     T_MINUS_EQ = 22,
     T_TIMES_EQ = 23,
     T_AND = 24,
     T_OR = 25,
     T_NOT = 26,
     T_DIVIDE_EQ = 27,
     T_VAR = 28,
     T_INTEGER = 29,
     T_REAL = 30,
     T_BOOLEAN = 31,
     T_COLON = 32,
     T_SEMICOLON = 33,
     T_COMMA = 34,
     T_PERIOD = 35,
     T_DOUBLE_PERIOD = 36,
     T_LBRACKET = 37,
     T_RBRACKET = 38,
     T_CONST = 39,
     T_REPEAT = 40,
     T_UNTIL = 41,
     T_EQ = 42,
     T_DIF = 43,
     T_LT = 44,
     T_LEQ = 45,
     T_GT = 46,
     T_GEQ = 47,
     T_INVALID = 255
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


	char  tk_name[32];
	int   tk_1;
	int   tk_idx;
	int   tk_int;
	int   tk_bool;
	float tk_real;
	struct symbol* record;
	struct expression expr;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     2,     2,
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
       2,     2,     2,     2,     2,    50,     1,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    11,    16,    17,    19,    20,    22,
      23,    26,    29,    31,    34,    39,    44,    49,    52,    54,
      57,    60,    65,    66,    70,    72,    74,    76,    80,    84,
      87,    88,    92,    95,    96,   100,   102,   103,   105,   107,
     109,   111,   113,   117,   120,   121,   125,   128,   129,   133,
     135,   140,   147,   152,   157,   158,   162,   165,   166,   169,
     171,   173,   175,   177,   179,   181,   185,   188,   190,   192,
     193,   197,   199,   201,   203,   206,   207,   211,   213,   215,
     217,   219,   221,   223,   227,   230,   232,   234,   236,   238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,     7,     3,    35,    53,    54,    37,    -1,
      -1,    55,    56,    57,    83,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    67,    57,    -1,    41,    59,    -1,    60,
      -1,    60,    59,    -1,     3,    44,     4,    35,    -1,     3,
      44,     5,    35,    -1,     3,    44,     6,    35,    -1,    30,
      62,    -1,    63,    -1,    63,    62,    -1,    64,    35,    -1,
       3,    65,    34,    66,    -1,    -1,    36,     3,    65,    -1,
      31,    -1,    32,    -1,    33,    -1,    68,    54,    35,    -1,
      69,    70,    35,    -1,     8,     3,    -1,    -1,    39,    71,
      40,    -1,    73,    72,    -1,    -1,    35,    73,    72,    -1,
      64,    -1,    -1,    76,    -1,    81,    -1,    82,    -1,    83,
      -1,    75,    -1,    96,    16,    85,    -1,     3,    77,    -1,
      -1,    39,    78,    40,    -1,    80,    79,    -1,    -1,    36,
      80,    79,    -1,    85,    -1,    11,    85,    12,    74,    -1,
      11,    85,    12,    74,    13,    74,    -1,    14,    85,    15,
      74,    -1,     9,    74,    84,    10,    -1,    -1,    35,    74,
      84,    -1,    88,    86,    -1,    -1,    87,    88,    -1,    46,
      -1,    44,    -1,    48,    -1,    47,    -1,    45,    -1,    49,
      -1,    89,    92,    90,    -1,    92,    90,    -1,    17,    -1,
      18,    -1,    -1,    91,    92,    90,    -1,    17,    -1,    18,
      -1,    27,    -1,    95,    93,    -1,    -1,    94,    95,    93,
      -1,    19,    -1,    21,    -1,    22,    -1,    26,    -1,    20,
      -1,    97,    -1,    39,    85,    40,    -1,    28,    95,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    96,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    96,   101,   104,   105,   108,   109,   112,
     113,   116,   119,   120,   123,   135,   147,   160,   163,   164,
     167,   185,   212,   217,   241,   245,   249,   254,   260,   280,
     294,   299,   308,   351,   362,   405,   410,   411,   412,   413,
     414,   415,   418,   435,   485,   492,   501,   514,   521,   533,
     536,   544,   553,   562,   565,   566,   569,   589,   593,   599,
     600,   601,   602,   603,   604,   607,   625,   644,   645,   649,
     653,   675,   679,   683,   688,   708,   712,   733,   734,   735,
     736,   737,   740,   744,   748,   759,   770,   774,   778,   782
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "T_EOF", "error", "$undefined", "T_ID", "T_INT_CONST", "T_REAL_CONST",
  "T_BOOLEAN_CONST", "T_PROGRAM", "T_PROCEDURE", "T_BEGIN", "T_END",
  "T_IF", "T_THEN", "T_ELSE", "T_WHILE", "T_DO", "T_ASSIGN", "T_PLUS",
  "T_MINUS", "T_TIMES", "T_DIVIDE", "T_DIV", "T_MOD", "T_PLUS_EQ",
  "T_MINUS_EQ", "T_TIMES_EQ", "T_AND", "T_OR", "T_NOT", "T_DIVIDE_EQ",
  "T_VAR", "T_INTEGER", "T_REAL", "T_BOOLEAN", "T_COLON", "T_SEMICOLON",
  "T_COMMA", "T_PERIOD", "T_DOUBLE_PERIOD", "T_LBRACKET", "T_RBRACKET",
  "T_CONST", "T_REPEAT", "T_UNTIL", "T_EQ", "T_DIF", "T_LT", "T_LEQ",
  "T_GT", "T_GEQ", "T_INVALID", "$accept", "input", "force_initialization",
  "block_body", "opt_constant_definition_part",
  "opt_variable_definition_part", "star_procedure_definition",
  "constant_definition_part", "plus_constant_definition",
  "constant_definition", "variable_definition_part",
  "plus_variable_definition", "variable_definition", "variable_group",
  "star_comma_id", "type", "procedure_definition", "procedure_block",
  "init_procedure", "opt_brc_formal_parameter_list_brc",
  "formal_parameter_list", "star_smc_parameter_definition",
  "parameter_definition", "statement", "assignment_statement",
  "procedure_statement", "opt_brc_actual_parameter_list_brc",
  "actual_parameter_list", "star_comma_actual_parameter",
  "actual_parameter", "if_statement", "while_statement",
  "compound_statement", "star_comma_statement", "expression",
  "opt_relational_operator_simple_expression", "relational_operator",
  "simple_expression", "sign_operator", "star_adding_operator_term",
  "adding_operator", "term", "star_multiplying_operator_factor",
  "multiplying_operator", "factor", "variable_access", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     255
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    60,    60,    60,    61,    62,    62,
      63,    64,    65,    65,    66,    66,    66,    67,    68,    69,
      70,    70,    71,    72,    72,    73,    74,    74,    74,    74,
      74,    74,    75,    76,    77,    77,    78,    79,    79,    80,
      81,    81,    82,    83,    84,    84,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    92,    93,    93,    94,    94,    94,
      94,    94,    95,    95,    95,    96,    97,    97,    97,    97
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     4,     0,     1,     0,     1,     0,
       2,     2,     1,     2,     4,     4,     4,     2,     1,     2,
       2,     4,     0,     3,     1,     1,     1,     3,     3,     2,
       0,     3,     2,     0,     3,     1,     0,     1,     1,     1,
       1,     1,     3,     2,     0,     3,     2,     0,     3,     1,
       4,     6,     4,     4,     0,     3,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     1,     0,
       3,     1,     1,     1,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     5,     0,     0,     7,
       6,     0,    11,    12,     2,     0,     9,     8,     0,    13,
      22,    17,    18,     0,     0,     0,     9,     5,    30,     0,
       0,     0,     0,     0,    19,    20,    29,    36,     4,    10,
       0,     0,     0,    14,    15,    16,    22,     0,    44,     0,
       0,    54,    41,    37,    38,    39,    40,     0,    27,    35,
       0,    33,    28,    23,    24,    25,    26,    21,     0,    43,
      85,    86,    87,    88,    67,    68,     0,     0,     0,    57,
       0,    69,    75,    89,    82,     0,    36,     0,     0,    31,
       0,    32,     0,    47,    49,    84,     0,    36,    60,    63,
      59,    62,    61,    64,    56,     0,    69,    71,    72,    73,
      66,     0,    77,    81,    78,    79,    80,    74,     0,    36,
      54,    53,    42,    33,    45,     0,    46,    83,    50,    58,
      65,    69,    75,    52,    55,    34,    47,    36,    70,    76,
      48,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     8,     9,    16,    25,    10,    12,    13,
      17,    21,    22,    23,    33,    67,    26,    27,    28,    42,
      60,    91,    61,    51,    52,    53,    69,    92,   126,    93,
      54,    55,    56,    87,    94,   104,   105,    79,    80,   110,
     111,    81,   117,   118,    82,    83,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int8 yypact[] =
{
       6,    16,    22,   -10,   -96,   -96,   -11,    30,    -2,     8,
     -96,    -4,   -96,    30,   -96,    41,    39,   -96,    64,   -96,
      12,   -96,    41,    23,    50,    65,    39,   -11,    20,    42,
      43,    44,    72,    46,   -96,   -96,   -96,    15,   -96,   -96,
      48,    41,    49,   -96,   -96,   -96,    12,    40,     7,     3,
       3,    51,   -96,   -96,   -96,   -96,   -96,    60,   -96,   -96,
      45,    52,   -96,   -96,   -96,   -96,   -96,   -96,     3,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,    11,     3,    69,    18,
      11,    10,    35,   -96,   -96,    73,    15,    79,     3,   -96,
      41,   -96,    53,    54,   -96,   -96,    55,    15,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,     3,    10,   -96,   -96,   -96,
     -96,    11,   -96,   -96,   -96,   -96,   -96,   -96,    11,    15,
      51,   -96,   -96,    52,   -96,     3,   -96,   -96,    78,   -96,
     -96,    10,    35,   -96,   -96,   -96,    54,    15,   -96,   -96,
     -96,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,    67,   -96,   -96,    66,   -96,    83,   -96,
     -96,    75,   -96,   -39,    56,   -96,   -96,   -96,   -96,   -96,
     -96,   -25,     9,   -85,   -96,   -96,   -96,   -96,   -35,   -22,
     -96,   -96,    80,   -16,   -45,   -96,   -96,     1,   -96,   -95,
     -96,   -70,   -24,   -96,   -73,   -37,   -96
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -86
static const yytype_int16 yytable[] =
{
      57,   120,    59,    95,    78,    85,    70,    71,    72,    73,
     106,   130,   128,     1,    70,    71,    72,    73,    48,     3,
      74,    75,     4,   -85,    37,     5,    49,   107,   108,    50,
       7,    76,    96,    11,   133,    14,   138,   109,    15,    76,
      18,   131,    77,   122,    20,   132,    68,    24,    32,    57,
      77,    59,   141,    36,   112,   113,   114,   115,    35,    41,
      57,   116,    98,    99,   100,   101,   102,   103,    29,    30,
      31,    64,    65,    66,    37,    46,    88,    43,    44,    45,
      47,    97,    57,    58,    62,    89,    86,    90,   119,   121,
     125,   137,    39,   124,    40,   127,    19,    34,   135,   123,
      57,   140,    63,   136,   134,    38,   129,     0,   139
};

static const yytype_int16 yycheck[] =
{
      37,    86,    41,    76,    49,    50,     3,     4,     5,     6,
      80,   106,    97,     7,     3,     4,     5,     6,     3,     3,
      17,    18,     0,    16,     9,    35,    11,    17,    18,    14,
      41,    28,    77,     3,   119,    37,   131,    27,    30,    28,
      44,   111,    39,    88,     3,   118,    39,     8,    36,    86,
      39,    90,   137,     3,    19,    20,    21,    22,    35,    39,
      97,    26,    44,    45,    46,    47,    48,    49,     4,     5,
       6,    31,    32,    33,     9,     3,    16,    35,    35,    35,
      34,    12,   119,    35,    35,    40,    35,    35,    15,    10,
      36,    13,    26,    40,    27,    40,    13,    22,   123,    90,
     137,   136,    46,   125,   120,    25,   105,    -1,   132
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    52,     3,     0,    35,    53,    41,    54,    55,
      58,     3,    59,    60,    37,    30,    56,    61,    44,    59,
       3,    62,    63,    64,     8,    57,    67,    68,    69,     4,
       5,     6,    36,    65,    62,    35,     3,     9,    83,    57,
      54,    39,    70,    35,    35,    35,     3,    34,     3,    11,
      14,    74,    75,    76,    81,    82,    83,    96,    35,    64,
      71,    73,    35,    65,    31,    32,    33,    66,    39,    77,
       3,     4,     5,     6,    17,    18,    28,    39,    85,    88,
      89,    92,    95,    96,    97,    85,    35,    84,    16,    40,
      35,    72,    78,    80,    85,    95,    85,    12,    44,    45,
      46,    47,    48,    49,    86,    87,    92,    17,    18,    27,
      90,    91,    19,    20,    21,    22,    26,    93,    94,    15,
      74,    10,    85,    73,    40,    36,    79,    40,    74,    88,
      90,    92,    95,    74,    84,    72,    80,    13,    90,    93,
      79,    74
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

    {
	printf("FIM\n");
	//clearTypeTables();
;}
    break;

  case 3:

    { 
    createTypeTable();
    initSymTab();
;}
    break;

  case 14:

    {
    YYSTYPE t;
    
    t.tk_int = (yyvsp[(3) - (4)].tk_int);
    
    if ( constDeclare((yyvsp[(1) - (4)].tk_idx), t, T_INT_CONST) == NULL ) 
    {
        printf("ERROR 1: Redefinition of symbol '%s' [Line %d]\n", getToken((yyvsp[(1) - (4)].tk_idx)), getLine());
        YYERROR; 
    }
;}
    break;

  case 15:

    {
    YYSTYPE t;
    
    t.tk_real = (yyvsp[(3) - (4)].tk_real);
    
    if ( constDeclare((yyvsp[(1) - (4)].tk_idx), t, T_REAL_CONST) == NULL ) 
    {
        printf("ERROR 2: Redefinition of symbol '%s' [Line %d]\n", getToken((yyvsp[(1) - (4)].tk_idx)), getLine());
        YYERROR;  
    }
;}
    break;

  case 16:

    {
    YYSTYPE t;
    
    t.tk_bool = (yyvsp[(3) - (4)].tk_bool);
    
    if ( constDeclare((yyvsp[(1) - (4)].tk_idx), t, T_BOOLEAN_CONST) == NULL ) 
    {
        printf("ERROR 3: Redefinition of symbol '%s' [Line %d]\n", getToken((yyvsp[(1) - (4)].tk_idx)), getLine());
        YYERROR;  
    }
;}
    break;

  case 20:

    {
	symbol* lSymbol = (yyvsp[(1) - (2)].record)->param_list->parameter;
	
	while ( lSymbol != NULL )
	{
		lSymbol->spec = VAR;
	
		insertLocal(lSymbol);
		
		lSymbol = lSymbol->next_symbol;
	}
    
    free((yyvsp[(1) - (2)].record)->param_list);
    
    free((yyvsp[(1) - (2)].record));
;}
    break;

  case 21:

    {
    (yyval.record) = (yyvsp[(2) - (4)].record);
    
    if ( ( searchParam2((yyval.record)->param_list, (yyvsp[(1) - (4)].tk_idx)) == 0 ) && ( localSearch((yyvsp[(1) - (4)].tk_idx)) == 0 ) )
    {
        symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
        
        lSymbol->spec = PARAM;
        
        lSymbol->id = (yyvsp[(1) - (4)].tk_idx);
        
        lSymbol->param_list = NULL;
        
        paramListPushBack((yyval.record)->param_list, lSymbol);
        
        setParamType((yyval.record)->param_list, (yyvsp[(4) - (4)].tk_idx));
    }
    
    else
    {
        printf("ERROR 4: Multiple definition of symbol '%s' [Line %d]\n", getToken((yyvsp[(1) - (4)].tk_idx)), getLine());
        YYERROR;
    }
;}
    break;

  case 22:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    
    (yyval.record)->param_list = paramListFactory();
;}
    break;

  case 23:

    {
    (yyval.record) = (yyvsp[(3) - (3)].record);
    
    if ( ( searchParam2((yyval.record)->param_list, (yyvsp[(2) - (3)].tk_idx)) == 0 ) && ( localSearch((yyvsp[(2) - (3)].tk_idx)) == 0 ) )
    {
        symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
        
        lSymbol->spec = PARAM;
        
        lSymbol->id = (yyvsp[(2) - (3)].tk_idx);
        
        lSymbol->param_list = NULL;
        
        paramListPushBack((yyval.record)->param_list, lSymbol);
    }
    
    else
    {
        printf("ERROR 5: Multiple definition of symbol '%s' [Line %d]\n", getToken((yyvsp[(2) - (3)].tk_idx)), getLine());
        YYERROR;
    }
;}
    break;

  case 24:

    {
    (yyval.tk_idx) = T_INTEGER; 
;}
    break;

  case 25:

    {
    (yyval.tk_idx) = T_REAL; 
;}
    break;

  case 26:

    {
    (yyval.tk_idx) = T_BOOLEAN; 
;}
    break;

  case 27:

    {
    clearScope();
    printSymTab();
;}
    break;

  case 28:

    {
	(yyval.record) = globalSearch2((yyvsp[(1) - (3)].record)->id);
	
	symbol* lSymbol = (yyvsp[(2) - (3)].record)->param_list->parameter;

	(yyval.record)->param_list = (yyvsp[(2) - (3)].record)->param_list;
	
	(yyval.record)->param_list->length = (yyvsp[(2) - (3)].record)->param_list->length;

	while ( lSymbol != NULL )
	{	
		insertLocal(lSymbol);
		
        lSymbol = lSymbol->next_symbol;
	}
	
	free((yyvsp[(1) - (3)].record));
;}
    break;

  case 29:

    {
	(yyval.record) = procDeclare((yyvsp[(2) - (2)].tk_idx));
	
	if ( (yyval.record) == NULL )
	{
		printf("Multiple redefinition of Procedure '%s' [Line %d]", getToken((yyvsp[(2) - (2)].tk_idx))->tk_name, getLine());
		YYERROR;
	}
	
	newScope();
;}
    break;

  case 30:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    
	(yyval.record)->param_list = paramListFactory();
;}
    break;

  case 31:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    
	(yyval.record)->param_list = (yyvsp[(2) - (3)].record)->param_list;
	
	free((yyvsp[(2) - (3)].record));
;}
    break;

  case 32:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    
    (yyval.record)->id = -1;
    
    (yyval.record)->spec = PARAMLIST;
    
    (yyval.record)->type = 0;
    
    (yyvsp[(2) - (2)].record)->param_list = invertParamList((yyvsp[(2) - (2)].record)->param_list);
    
    symbol* lSymbol = (yyvsp[(2) - (2)].record)->param_list->parameter;

	int r = 1;
	
	while( lSymbol != NULL  )
    {
    	if ( searchParam2((yyvsp[(1) - (2)].record)->param_list, lSymbol->id) != 0 )
    	{
    		r = 0;
    		
    		printf("ERROR 6: Definition of multiple parameters with the same identifier '%s' [Line %d]\n", getToken(lSymbol->id), getLine());
    		
    		break;
    	}
    	
    	paramListPushFront((yyvsp[(1) - (2)].record)->param_list, lSymbol);
    	
    	lSymbol = lSymbol->next_symbol;	
    }
    
    (yyval.record)->param_list = (yyvsp[(1) - (2)].record)->param_list;
    
    free((yyvsp[(2) - (2)].record)->param_list);
	
	if ( r == 0 )
	{
		YYERROR;
	}
;}
    break;

  case 33:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    
    (yyval.record)->id = -1;
    
    (yyval.record)->spec = PARAMLIST;
    
    (yyval.record)->type = 0; 
    
    (yyval.record)->param_list = paramListFactory();
;}
    break;

  case 34:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    
    (yyval.record)->id = -1;
    
    (yyval.record)->spec = PARAMLIST;
    
    (yyval.record)->type = 0;
    
    symbol* lSymbol = (yyvsp[(3) - (3)].record)->param_list->parameter;

	int r = 1;
	
	while( lSymbol != NULL )
    {
    	if ( searchParam2((yyvsp[(2) - (3)].record)->param_list, lSymbol->id) != 0 )
    	{
    		r = 0;
    		
    		break;
    	}
    	
    	paramListPushBack((yyvsp[(2) - (3)].record)->param_list, lSymbol);
    	
    	lSymbol = lSymbol->next_symbol;
    }
    
    (yyval.record)->param_list = (yyvsp[(2) - (3)].record)->param_list;
	
	if ( r == 0 )
	{
		printf("ERROR 7: Definition of multiple parameters with the same identifier [Line %d]\n", getLine());
	}
	
	free((yyvsp[(3) - (3)].record)->param_list);
	
	if ( r == 0 )
	{
		YYERROR;
	}
;}
    break;

  case 35:

    {
	(yyval.record) = (yyvsp[(1) - (1)].record);
;}
    break;

  case 42:

    {
	symbol* lSymbol = globalSearch2((yyvsp[(1) - (3)].tk_idx));
	
	if ( ( lSymbol->spec != VAR ) && ( lSymbol->spec != PARAM ) )
	{
		printf("\nERROR: Assignment to non-lvalue '%s' [Line %d]\n", getToken((yyvsp[(1) - (3)].tk_idx)), getLine());
        YYERROR;
	}
	
	if ( checkCompatibility(lSymbol->type, (yyvsp[(3) - (3)].tk_idx)) == 0 )
	{
		printf("\nERROR: Cannot coerce expression into variable '%s' [Line %d]\n", getToken((yyvsp[(1) - (3)].tk_idx)), getLine());
        YYERROR;
	}
;}
    break;

  case 43:

    {
	symbol* procSymbol = globalSearch2((yyvsp[(1) - (2)].tk_idx));
	
	printf("CALL: %s, nP: %d\n", getToken((yyvsp[(1) - (2)].tk_idx))->tk_name, procSymbol->param_list->length);
	
	printParamList(procSymbol->param_list);
	
    if ( procSymbol == NULL || procSymbol->spec != PROCEDURE )
    {
        printf("\nERROR 8: Undefined procedure '%s' [Line %d]\n", getToken((yyvsp[(1) - (2)].tk_idx)), getLine());
        YYERROR;
    }

    if ( procSymbol->param_list->length == 0 )
    {
        if ( (yyvsp[(2) - (2)].record)->param_list->length != 0 )
        {
            printf("\nERROR 9: Procedure '%s' has void signature, but is being passed parameters [Line %d]\n", getToken((yyvsp[(1) - (2)].tk_idx)), getLine());
            YYERROR;
        }
    }
    
    else
    {
        if ( (yyvsp[(2) - (2)].record)->param_list->length == 0 )
        {
            printf("\nERROR 10: Procedure '%s' does not have void signature, but is being passed no parameters [Line %d]\n", getToken((yyvsp[(1) - (2)].tk_idx)), getLine());
            YYERROR;
        }
        
        if ( (yyvsp[(2) - (2)].record)->param_list->length != procSymbol->param_list->length )
        {
            printf("\nERROR 11: Procedure call for '%s' is not passing the right amount of parameters, expected '%d', got '%d' [Line %d]\n", getToken((yyvsp[(1) - (2)].tk_idx)), procSymbol->param_list->length, (yyvsp[(2) - (2)].record)->param_list->length, getLine());
            YYERROR;
        }
        
        symbol* aux = compareParamList((yyvsp[(2) - (2)].record)->param_list, procSymbol->param_list);
        int diff = compareParamList2((yyvsp[(2) - (2)].record)->param_list, procSymbol->param_list);
        
    	if ( aux != NULL )
    	{
    		//printf("ERROR 12: Cannot coerce expression into parameter '%s' [Line %d]\n", getToken(aux->id), getLine());
    		printf("ERROR 12: Cannot coerce expression into %d%c parameter [Line %d]\n", diff, (char) 248, getLine());
    		YYERROR;
    	}
    }
;}
    break;

  case 44:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    (yyval.record)->id = -1;
    (yyval.record)->spec = PARAMLIST;
    (yyval.record)->next_symbol = NULL;
    (yyval.record)->param_list = paramListFactory();  
;}
    break;

  case 45:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    (yyval.record)->id = -1;
    (yyval.record)->spec = PARAMLIST;
    (yyval.record)->next_symbol = NULL;
    (yyval.record)->param_list = (yyvsp[(2) - (3)].record)->param_list;
;}
    break;

  case 46:

    {
    (yyval.record) = (yyvsp[(2) - (2)].record);
    symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
    lSymbol->id = -1;
    lSymbol->spec = PARAM;
    lSymbol->type = (yyvsp[(1) - (2)].tk_idx);
    lSymbol->next_symbol = NULL;
    lSymbol->param_list = NULL;
    paramListPushBack((yyval.record)->param_list, lSymbol);
;}
    break;

  case 47:

    {
    (yyval.record) = (symbol*) malloc(sizeof(symbol));
    (yyval.record)->id = -1;
    (yyval.record)->spec = PARAMLIST;
    (yyval.record)->next_symbol = NULL;
    (yyval.record)->param_list = paramListFactory();
;}
    break;

  case 48:

    {
    (yyval.record) = (yyvsp[(3) - (3)].record);
    symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
    lSymbol->id = -1;
    lSymbol->spec = PARAM;
    lSymbol->type = (yyvsp[(2) - (3)].tk_idx);
    lSymbol->next_symbol = NULL;
    lSymbol->param_list = NULL;
    paramListPushBack((yyval.record)->param_list, lSymbol);
;}
    break;

  case 49:

    { (yyval.tk_idx) = (yyvsp[(1) - (1)].tk_idx); ;}
    break;

  case 50:

    {
	if ( (yyvsp[(2) - (4)].tk_idx) != T_BOOLEAN )
	{
		printf("ERROR: Expression does not have boolean type [Line %d]\n", getLine());
		YYERROR;
	}
;}
    break;

  case 51:

    {
	if ( (yyvsp[(2) - (6)].tk_idx) != T_BOOLEAN )
	{
		printf("ERROR: Expression does not have boolean type [Line %d]\n", getLine());
		YYERROR;
	}
;}
    break;

  case 52:

    {
	if ( (yyvsp[(2) - (4)].tk_idx) != T_BOOLEAN )
	{
		printf("ERROR: Expression does not have boolean type [Line %d]\n", getLine());
		YYERROR;
	}
;}
    break;

  case 56:

    {
	if ( (yyvsp[(2) - (2)].expr).operation != T_INVALID )
	{
		(yyval.tk_idx) = getExpressionReturnType((yyvsp[(1) - (2)].tk_idx), (yyvsp[(2) - (2)].expr).type, (yyvsp[(2) - (2)].expr).operation);
		
		if ( (yyval.tk_idx) == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		(yyval.tk_idx) = (yyvsp[(1) - (2)].tk_idx);
	}
;}
    break;

  case 57:

    {
	(yyval.expr).operation = T_INVALID;
	(yyval.expr).type = T_INVALID;
;}
    break;

  case 58:

    {
	(yyval.expr).operation = (yyvsp[(1) - (2)].tk_idx);
	(yyval.expr).type = (yyvsp[(2) - (2)].tk_idx);
;}
    break;

  case 59:

    { (yyval.tk_idx) = T_LT;  ;}
    break;

  case 60:

    { (yyval.tk_idx) = T_EQ;  ;}
    break;

  case 61:

    { (yyval.tk_idx) = T_GT;  ;}
    break;

  case 62:

    { (yyval.tk_idx) = T_LEQ; ;}
    break;

  case 63:

    { (yyval.tk_idx) = T_DIF; ;}
    break;

  case 64:

    { (yyval.tk_idx) = T_GEQ; ;}
    break;

  case 65:

    {
	if ( ( (yyvsp[(3) - (3)].expr).operation != T_INVALID ) && ( (yyvsp[(3) - (3)].expr).type != T_INVALID ) )
	{
		(yyval.tk_idx) = getExpressionReturnType((yyvsp[(2) - (3)].tk_idx), (yyvsp[(3) - (3)].expr).type, (yyvsp[(3) - (3)].expr).operation);
		
		if ( (yyval.tk_idx) == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		(yyval.tk_idx) = (yyvsp[(2) - (3)].tk_idx);
	}
;}
    break;

  case 66:

    {
	if ( ( (yyvsp[(2) - (2)].expr).operation != T_INVALID ) && ( (yyvsp[(2) - (2)].expr).type != T_INVALID ) )
	{
		(yyval.tk_idx) = getExpressionReturnType((yyvsp[(1) - (2)].tk_idx), (yyvsp[(2) - (2)].expr).type, (yyvsp[(2) - (2)].expr).operation);
		
		if ( (yyval.tk_idx) == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		(yyval.tk_idx) = (yyvsp[(1) - (2)].tk_idx);
	}
;}
    break;

  case 69:

    {
	(yyval.expr).operation = T_INVALID;
	(yyval.expr).type = T_INVALID;
;}
    break;

  case 70:

    {
	(yyval.expr).operation = (yyvsp[(1) - (3)].tk_idx);
	
	if ( ( (yyvsp[(3) - (3)].expr).operation != T_INVALID ) && ( (yyvsp[(3) - (3)].expr).type != T_INVALID ) )
	{
		(yyval.expr).type = getExpressionReturnType((yyvsp[(2) - (3)].tk_idx), (yyvsp[(3) - (3)].expr).type, (yyvsp[(3) - (3)].expr).operation);
		
		if ( (yyval.expr).type == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		(yyval.expr).operation = (yyvsp[(1) - (3)].tk_idx);
		(yyval.expr).type = (yyvsp[(2) - (3)].tk_idx);
	}
;}
    break;

  case 71:

    {
	(yyval.tk_idx) = T_PLUS;
;}
    break;

  case 72:

    {
	(yyval.tk_idx) = T_MINUS;
;}
    break;

  case 73:

    {
	(yyval.tk_idx) = T_OR;
;}
    break;

  case 74:

    {
	if ( ( (yyvsp[(2) - (2)].expr).operation != T_INVALID ) && ( (yyvsp[(2) - (2)].expr).type != T_INVALID ) )
	{
		(yyval.tk_idx) = getExpressionReturnType((yyvsp[(1) - (2)].tk_idx), (yyvsp[(2) - (2)].expr).type, (yyvsp[(2) - (2)].expr).operation);
		
		if ( (yyval.tk_idx) == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		(yyval.tk_idx) = (yyvsp[(1) - (2)].tk_idx);
	}
;}
    break;

  case 75:

    {		
	(yyval.expr).operation = T_INVALID;
	(yyval.expr).type = T_INVALID;
;}
    break;

  case 76:

    {
	(yyval.expr).operation = (yyvsp[(1) - (3)].tk_idx);
	
	if ( ( (yyvsp[(3) - (3)].expr).operation != T_INVALID ) && ( (yyvsp[(3) - (3)].expr).type != T_INVALID ) )
	{
		(yyval.expr).type = getExpressionReturnType((yyvsp[(2) - (3)].tk_idx), (yyvsp[(3) - (3)].expr).type, (yyvsp[(3) - (3)].expr).operation);
		
		if ( (yyval.expr).type == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		(yyval.expr).type = (yyvsp[(2) - (3)].tk_idx);
	}
;}
    break;

  case 77:

    { (yyval.tk_idx) = T_TIMES;  ;}
    break;

  case 78:

    { (yyval.tk_idx) = T_DIV;    ;}
    break;

  case 79:

    { (yyval.tk_idx) = T_MOD;    ;}
    break;

  case 80:

    { (yyval.tk_idx) = T_AND;    ;}
    break;

  case 81:

    { (yyval.tk_idx) = T_DIVIDE; ;}
    break;

  case 82:

    {
	(yyval.tk_idx) = (yyvsp[(1) - (1)].tk_idx);
;}
    break;

  case 83:

    {
	(yyval.tk_idx) = (yyvsp[(2) - (3)].tk_idx);
;}
    break;

  case 84:

    {
	(yyval.tk_idx) = getExpressionReturnType(T_INVALID, (yyvsp[(2) - (2)].tk_idx) , T_NOT);

	if ( (yyval.tk_idx) == T_INVALID )
	{
		printf("ERROR 34: Invalid Operation in [Line %d]\n", getLine());
		YYERROR;
	}
;}
    break;

  case 85:

    {
	(yyval.tk_idx) = (yyvsp[(1) - (1)].tk_idx); 
	
    if ( globalSearch((yyvsp[(1) - (1)].tk_idx)) == 0 )
    {
        printf("\nERROR 12: Use of undeclared identifier '%s', [Line %d] ", getToken((yyvsp[(1) - (1)].tk_idx)), getLine());
        YYERROR;
    }
;}
    break;

  case 86:

    {
	(yyval.tk_idx) = T_INTEGER;
;}
    break;

  case 87:

    {
	(yyval.tk_idx) = T_REAL;
;}
    break;

  case 88:

    {
	(yyval.tk_idx) = T_BOOLEAN;
;}
    break;

  case 89:

    {
	symbol* lSymbol = globalSearch2((yyvsp[(1) - (1)].tk_idx));
	
	(yyval.tk_idx) = lSymbol->type;
;}
    break;



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




