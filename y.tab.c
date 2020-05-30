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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* for symbol table */
    int scope = 0;
    int indexArr[50], lineno[50], scopeArr[50];
    char* name[50], *typeArr[50], *elementType[50];
    int symNum[5];
    int varNum = 0;

    /* for println flag */
    int printflag = 0;

    /* for type */
    char *tmp_type;

    /* for check scope */
    int tmp_scope, i;

    /* for check type */
    int type1, type2;
    int add1, add2;
    char ty1[10],ty2[10];

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol(int, char*, char*, int, char*);
    static int lookup_symbol(char*, int);
    static void dump_symbol(int);

    FILE *file;
    int tmp_id = -1;
    int label = 0;

#line 115 "y.tab.c" /* yacc.c:339  */

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
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    INC = 263,
    DEC = 264,
    GEQ = 265,
    LEQ = 266,
    EQL = 267,
    NEQ = 268,
    ADD_ASSIGN = 269,
    SUB_ASSIGN = 270,
    MUL_ASSIGN = 271,
    QUO_ASSIGN = 272,
    REM_ASSIGN = 273,
    LAND = 274,
    LOR = 275,
    NEWLINE = 276,
    PRINT = 277,
    PRINTLN = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    TRUE = 282,
    FALSE = 283,
    INT_LIT = 284,
    SIGN_INT_LIT = 285,
    FLOAT_LIT = 286,
    SIGN_FLOAT_LIT = 287,
    STRING_LIT = 288,
    ID = 289
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define INC 263
#define DEC 264
#define GEQ 265
#define LEQ 266
#define EQL 267
#define NEQ 268
#define ADD_ASSIGN 269
#define SUB_ASSIGN 270
#define MUL_ASSIGN 271
#define QUO_ASSIGN 272
#define REM_ASSIGN 273
#define LAND 274
#define LOR 275
#define NEWLINE 276
#define PRINT 277
#define PRINTLN 278
#define IF 279
#define ELSE 280
#define FOR 281
#define TRUE 282
#define FALSE 283
#define INT_LIT 284
#define SIGN_INT_LIT 285
#define FLOAT_LIT 286
#define SIGN_FLOAT_LIT 287
#define STRING_LIT 288
#define ID 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    int si_val;
    float f_val;
    float sf_val;
    char *s_val;
    char *id_val;
    /* ... */

#line 233 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 250 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   408

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  283

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    43,     2,     2,    36,     2,     2,
      47,    48,    45,    35,     2,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      51,    40,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,    98,    99,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   116,   117,   121,   126,
     130,   136,   142,   142,   146,   154,   156,   154,   157,   159,
     157,   160,   160,   161,   161,   165,   169,   169,   170,   170,
     171,   171,   172,   175,   172,   177,   180,   177,   184,   184,
     185,   185,   189,   190,   191,   192,   193,   194,   198,   198,
     209,   217,   233,   238,   243,   248,   253,   258,   275,   279,
     286,   293,   300,   307,   315,   349,   350,   354,   354,   358,
     362,   366,   370,   373,   373,   387,   388,   392,   396,   400,
     404,   408,   414,   418,   424,   428,   434,   447,   460,   470,
     480,   490,   500,   513,   513,   541,   541,   563,   572,   581,
     590,   591,   592,   593,   594,   595,   596,   600,   604,   613,
     622,   623,   627,   631,   638,   638,   642,   646,   653,   667,
     668,   669,   670,   671,   675,   680,   685,   696,   706,   706,
     720,   747,   753,   759,   764
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "FLOAT", "BOOL", "STRING",
  "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR", "NEWLINE",
  "PRINT", "PRINTLN", "IF", "ELSE", "FOR", "TRUE", "FALSE", "INT_LIT",
  "SIGN_INT_LIT", "FLOAT_LIT", "SIGN_FLOAT_LIT", "STRING_LIT", "ID", "'+'",
  "'%'", "'{'", "'}'", "';'", "'='", "'['", "']'", "'\"'", "'-'", "'*'",
  "'/'", "'('", "')'", "'!'", "'>'", "'<'", "$accept", "Program", "stmts",
  "stmt", "const", "const_add", "$@1", "forloop", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "forexpr", "ifelse", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "error_assign", "$@15", "$@16", "assign",
  "setVal", "$@17", "var", "assignVal", "ident", "value_initial", "block",
  "$@18", "Def", "$@19", "typee", "BOOL_initial", "FLOAT_initial",
  "INT_initial", "STR_initial", "cal", "print", "$@20", "$@21", "expr",
  "preexpr", "andor", "bool", "$@22", "compare", "term", "$@23", YY_NULLPTR
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
     285,   286,   287,   288,   289,    43,    37,   123,   125,    59,
      61,    91,    93,    34,    45,    42,    47,    40,    41,    33,
      62,    60
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -139

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     354,   -25,   -72,   -72,   -72,     2,   -23,    84,   -72,   101,
     -20,   357,    29,    60,   354,   -72,   -72,   -72,   -72,   -72,
     210,   -72,   -72,   -72,   -72,     6,    51,    59,    85,    96,
     142,   142,   -72,   -72,   -72,   -72,   117,   -72,    11,   144,
     142,    48,    43,   107,   142,   -72,   114,   142,   -72,   155,
      86,    82,    55,   145,   170,   183,   334,   199,   172,   163,
     191,   124,   198,   124,    33,   100,   174,   208,   214,   218,
     229,   -72,   -72,   -72,   354,   -72,   -72,   174,   174,   174,
     174,   174,   221,    -5,     3,    19,    21,   215,   142,   142,
     150,   116,   -72,   224,   323,   323,   230,   231,   228,   232,
     203,   -72,   142,   142,   142,   142,    34,    34,   -72,    34,
     142,   142,   142,    34,    34,   323,   220,   354,   243,   244,
     -72,   -72,   -72,   235,   -72,   142,   -72,   -72,   142,   -72,
     -72,   -72,   -72,   142,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -13,    53,    56,    89,   -16,   247,   260,   323,   -72,
     -72,   -72,   -72,   354,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   253,   -72,   -72,   252,   -72,   -72,   140,   -72,
     -72,   248,   -72,   -72,   249,   266,   242,   -72,   246,   250,
     259,   -72,   -72,   142,   -72,   153,   142,   323,   323,   323,
     323,   142,   107,   -72,   107,   354,   107,   323,   323,   323,
     107,   107,   -72,   254,   -72,   -72,   354,   261,   354,   323,
     323,   323,   265,   -72,   267,   258,   292,   294,   298,   304,
     297,   289,   -72,   -72,   -72,   -72,   -72,   -72,   354,   354,
     276,   323,   293,   300,   354,   -72,   354,   354,   301,     7,
     302,   105,   305,   321,   -72,   -72,   -72,   -72,   310,   236,
     316,   318,   -72,   -72,   -72,   322,   330,   331,   -72,   326,
     -72,   142,   -72,   -72,   351,   -72,   -72,   360,   -72,   -72,
     -72,   -72,   -72,   350,   311,   -72,   -72,   151,   237,   -72,
     -72,   352,   353
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     7,   105,   103,   117,     0,   117,    22,    48,
      50,    74,     0,     0,     5,    15,    14,    13,    12,    11,
       0,    10,     6,     8,     9,     0,     0,     0,     0,     0,
     117,   117,   126,   127,   134,   136,   135,   137,   140,     0,
     117,     0,     0,   110,   117,   115,   111,   117,    40,   127,
     134,   135,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,    77,     1,     2,     5,    96,    97,   117,   117,   117,
     117,   117,     0,     0,     0,     0,     0,     0,   117,   117,
       0,     0,   135,   140,   122,   123,     0,     0,     0,     0,
       0,   124,   117,   117,   117,   117,     0,     0,    36,     0,
     117,   117,   117,     0,     0,   113,     0,     5,     0,     0,
      25,    28,    33,     0,    31,   117,    21,    18,   117,    54,
      55,    56,    57,   117,    49,    19,    51,    24,    98,    20,
     102,   126,   127,   134,   135,   140,     0,     0,    68,    58,
      99,   100,   101,     5,     4,    69,    70,    71,    72,    73,
      60,    93,     0,    79,    91,     0,    81,    89,     0,    82,
      95,     0,    80,    83,     0,     0,     0,    74,     0,     0,
       0,    46,    43,   117,   116,   114,   117,   130,   131,   132,
     133,   117,   107,   121,   109,     5,   108,   128,   129,   112,
     118,   119,    38,     0,    26,    29,     5,     0,     5,    23,
      53,    52,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   104,   142,   141,   144,   143,     5,     5,
       0,   125,     0,     0,     5,    41,     5,     5,     0,     0,
       0,   116,    76,     0,    92,    90,    87,    88,     0,     0,
       0,     0,   139,   120,    37,     0,     0,     0,    34,     0,
      32,   117,    59,    78,     0,    85,    86,     0,    47,    44,
      39,    27,    30,     0,     0,    94,    84,    74,     0,    35,
      75,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -71,   389,   -72,   383,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   332,   -72,   -72,   327,
     338,    -7,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   123,   -72,   -72,   -72,    -3,    42,   -72,   358,
     -72,   161,   257,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    73,    74,    53,    15,    58,    16,   204,   236,
     205,   237,   208,   206,    55,    17,   195,   234,   117,    97,
     229,    96,   228,    18,    61,    63,   134,    19,   214,   147,
      82,    20,   262,    21,   153,    22,   221,   267,   169,   166,
     163,   172,    23,    24,    27,    26,   148,    43,    44,    45,
     186,   112,    46,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    47,    42,   154,    57,   -67,    28,    29,   -65,    25,
      83,    84,    85,    86,    48,    62,   161,   102,   103,   104,
     105,    30,    31,   -67,   164,  -138,   -65,    94,    95,    32,
      33,    34,    35,    36,    37,   162,    38,   100,    28,    29,
     167,   115,   170,   165,   116,    39,   203,    87,   -42,    40,
      71,    41,  -138,   102,   103,   104,   105,   110,   111,   168,
      72,   171,   137,    34,    35,    92,    37,   138,    93,   -74,
     -74,   -74,   -74,   -74,   -66,    32,    33,   -62,   106,   107,
     108,   191,   215,   178,   180,   174,   175,   109,    28,    29,
     118,   119,   -66,   110,   111,   -62,  -138,    41,    88,   187,
     188,   189,   190,    30,    31,    59,    89,   197,   198,   199,
     -63,    32,    49,    50,    35,    51,    37,    62,    52,   -17,
      59,    60,   209,   -16,   233,   210,   -64,    39,   -63,   139,
     211,    40,    90,    41,   140,   238,    60,   240,   128,   129,
     130,   131,   132,    91,   -64,   179,    28,    29,   192,   194,
     177,   196,   113,   114,   -45,   200,   201,   250,   251,  -121,
    -121,    30,    31,   255,   133,   256,   257,   218,   219,    32,
      33,    34,    35,    92,    37,   -22,    93,    99,    28,    29,
     230,   176,   120,   231,   177,    39,   281,   282,   232,    40,
     126,    41,   125,    30,    31,    68,    69,    70,  -120,  -120,
     239,   141,   142,   143,    35,   144,    37,   121,   145,   102,
     103,   104,   105,   102,   103,   104,   105,   146,    75,    76,
     122,    40,   127,    41,    77,    78,    79,    80,    81,   135,
     102,   103,   104,   105,   106,   107,   124,   149,   106,   107,
     265,   266,   160,   109,   173,    75,    76,   109,   150,   110,
     111,   185,   151,   110,   111,   106,   107,   202,   274,   102,
     103,   104,   105,   152,   109,  -138,   278,   181,   182,   183,
     110,   111,   137,   139,   207,   184,   102,   103,   104,   105,
     212,   213,   216,   217,   106,   107,   102,   103,   104,   105,
     224,   220,   235,   109,   225,   177,   243,   222,   226,   110,
     111,   106,   107,   102,   103,   104,   105,   227,   241,   242,
     109,   106,   107,   244,   223,   245,   110,   111,   252,   246,
     109,   102,   103,   104,   105,   247,   110,   111,   106,   107,
     248,   249,   280,   102,   103,   104,   105,   109,   254,   258,
     260,   253,   263,   110,   111,   261,   106,   107,    77,    78,
      79,    80,    81,   264,   268,   109,   269,     1,   106,   107,
     270,   110,   111,   193,   193,   273,   193,   109,   271,   272,
     193,   193,   275,   110,   111,     2,     3,     4,     5,     6,
       7,   276,     8,     9,   277,    10,   138,   140,    11,    14,
      54,    12,    64,    65,   123,   136,   279,    66,    67,   101,
     259,    68,    69,    70,   155,   156,   157,   158,   159
};

static const yytype_uint16 yycheck[] =
{
       7,    24,     5,    74,     7,    21,     4,     5,    21,    34,
       4,     5,     6,     7,    37,    35,    21,    10,    11,    12,
      13,    19,    20,    39,    21,    41,    39,    30,    31,    27,
      28,    29,    30,    31,    32,    40,    34,    40,     4,     5,
      21,    44,    21,    40,    47,    43,   117,    41,    37,    47,
      21,    49,    41,    10,    11,    12,    13,    50,    51,    40,
       0,    40,    29,    29,    30,    31,    32,    34,    34,    14,
      15,    16,    17,    18,    21,    27,    28,    21,    35,    36,
      37,    47,   153,    90,    91,    88,    89,    44,     4,     5,
      35,    36,    39,    50,    51,    39,    41,    49,    47,   102,
     103,   104,   105,    19,    20,    19,    47,   110,   111,   112,
      21,    27,    28,    29,    30,    31,    32,    35,    34,    37,
      19,    35,   125,    37,   195,   128,    21,    43,    39,    29,
     133,    47,    47,    49,    34,   206,    35,   208,    14,    15,
      16,    17,    18,    47,    39,    29,     4,     5,   106,   107,
      34,   109,    45,    46,    37,   113,   114,   228,   229,    45,
      46,    19,    20,   234,    40,   236,   237,    27,    28,    27,
      28,    29,    30,    31,    32,    20,    34,    33,     4,     5,
     183,    31,    37,   186,    34,    43,    35,    36,   191,    47,
      27,    49,    20,    19,    20,    44,    45,    46,    45,    46,
     207,    27,    28,    29,    30,    31,    32,    37,    34,    10,
      11,    12,    13,    10,    11,    12,    13,    43,     8,     9,
      37,    47,    31,    49,    14,    15,    16,    17,    18,    31,
      10,    11,    12,    13,    35,    36,    37,    29,    35,    36,
       4,     5,    21,    44,    29,     8,     9,    44,    34,    50,
      51,    48,    34,    50,    51,    35,    36,    37,   261,    10,
      11,    12,    13,    34,    44,    41,   273,    37,    37,    41,
      50,    51,    29,    29,    39,    43,    10,    11,    12,    13,
      33,    21,    29,    31,    35,    36,    10,    11,    12,    13,
      48,    43,    38,    44,    48,    34,    38,    48,    48,    50,
      51,    35,    36,    10,    11,    12,    13,    48,    43,    42,
      44,    35,    36,    21,    48,    21,    50,    51,    42,    21,
      44,    10,    11,    12,    13,    21,    50,    51,    35,    36,
      33,    42,    21,    10,    11,    12,    13,    44,    38,    38,
      38,    48,    21,    50,    51,    40,    35,    36,    14,    15,
      16,    17,    18,    43,    38,    44,    38,     3,    35,    36,
      38,    50,    51,   106,   107,    39,   109,    44,    38,    38,
     113,   114,    21,    50,    51,    21,    22,    23,    24,    25,
      26,    21,    28,    29,    34,    31,    34,    34,    34,     0,
       7,    37,    35,    36,    56,    63,   273,    40,    41,    41,
     239,    44,    45,    46,    77,    78,    79,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    21,    22,    23,    24,    25,    26,    28,    29,
      31,    34,    37,    53,    55,    57,    59,    67,    75,    79,
      83,    85,    87,    94,    95,    34,    97,    96,     4,     5,
      19,    20,    27,    28,    29,    30,    31,    32,    34,    43,
      47,    49,    98,    99,   100,   101,   104,    24,    37,    28,
      29,    31,    34,    56,    57,    66,    83,    98,    58,    19,
      35,    76,    35,    77,    35,    36,    40,    41,    44,    45,
      46,    21,     0,    54,    55,     8,     9,    14,    15,    16,
      17,    18,    82,     4,     5,     6,     7,    41,    47,    47,
      47,    47,    31,    34,    98,    98,    73,    71,   105,    33,
      98,   101,    10,    11,    12,    13,    35,    36,    37,    44,
      50,    51,   103,    45,    46,    98,    98,    70,    35,    36,
      37,    37,    37,    82,    37,    20,    27,    31,    14,    15,
      16,    17,    18,    40,    78,    31,    78,    29,    34,    29,
      34,    27,    28,    29,    31,    34,    43,    81,    98,    29,
      34,    34,    34,    86,    54,    81,    81,    81,    81,    81,
      21,    21,    40,    92,    21,    40,    91,    21,    40,    90,
      21,    40,    93,    29,    98,    98,    31,    34,    83,    29,
      83,    37,    37,    41,    43,    48,   102,    98,    98,    98,
      98,    47,    99,   104,    99,    68,    99,    98,    98,    98,
      99,    99,    37,    54,    60,    62,    65,    39,    64,    98,
      98,    98,    33,    21,    80,    54,    29,    31,    27,    28,
      43,    88,    48,    48,    48,    48,    48,    48,    74,    72,
      98,    98,    98,    54,    69,    38,    61,    63,    54,    83,
      54,    43,    42,    38,    21,    21,    21,    21,    33,    42,
      54,    54,    42,    48,    38,    54,    54,    54,    38,   103,
      38,    40,    84,    21,    43,     4,     5,    89,    38,    38,
      38,    38,    38,    39,    98,    21,    21,    34,    83,    94,
      21,    35,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      57,    57,    58,    57,    57,    60,    61,    59,    62,    63,
      59,    64,    59,    65,    59,    66,    68,    67,    69,    67,
      70,    67,    71,    72,    67,    73,    74,    67,    76,    75,
      77,    75,    78,    78,    78,    78,    78,    78,    80,    79,
      79,    79,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    83,    84,    84,    86,    85,    87,
      87,    87,    87,    88,    87,    89,    89,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    96,    95,    97,    95,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,   100,   100,   102,   101,   101,   101,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   104,   105,   104,
     104,   104,   104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     0,     4,     3,     0,     0,     7,     0,     0,
       7,     0,     6,     0,     6,     7,     0,     6,     0,     7,
       0,     5,     0,     0,     7,     0,     0,     7,     0,     3,
       0,     3,     2,     2,     1,     1,     1,     1,     0,     6,
       3,     4,     1,     1,     3,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     1,     3,     0,     0,     6,     4,
       4,     4,     4,     0,     8,     1,     1,     3,     3,     1,
       3,     1,     3,     1,     5,     1,     2,     2,     3,     3,
       3,     3,     3,     0,     5,     0,     5,     3,     3,     3,
       1,     1,     3,     2,     3,     1,     3,     0,     3,     3,
       3,     1,     2,     2,     0,     4,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     0,     5,
       1,     4,     4,     4,     4
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
#line 93 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope); }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\nFLOAT_LIT %f\n", (yyvsp[-2].i_val), (yyvsp[0].f_val));
        printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno+1);
        printf("ADD\n");
    }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 126 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FLOAT_LIT %f\nFLOAT_LIT %f\n", (yyvsp[-2].f_val), (yyvsp[0].f_val));
        printf("ADD\n");
    }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 130 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
        printf("REM\n");
    }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\n", (yyvsp[-2].i_val));
        printf("TRUE\n");
        printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno+1);
        printf("LAND\n");
    }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("FALSE\n");}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("error:%d: invalid operation: (operator LOR not defined on int32)\n", yylineno);
        printf("LOR\n");
    }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        printf("ADD\n");
    }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 154 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("error:%d: non-bool (type float32) used as for condition\n", yylineno+1);
    }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 156 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 156 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1);
    }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 160 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 160 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 169 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 169 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 170 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 170 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 171 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 171 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 172 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
        printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, "int32");
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 175 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 175 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 177 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, "float32");
    }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 180 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 180 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 184 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 185 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("ASSIGN\n"); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 190 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("error:%d: cannot assign to int32\nADD_ASSIGN\n", yylineno); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("SUB_ASSIGN\n"); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 192 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("MUL_ASSIGN\n"); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 193 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("QUO_ASSIGN\n"); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 194 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("REM_ASSIGN\n"); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        fprintf(file, "aload %d\n", lookup_symbol((yyvsp[-2].id_val), scope));
        printf("IDENT (name=%s, address=%d)\nINT_LIT %d\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope), (yyvsp[0].i_val));
        fprintf(file, "ldc %d\n", (yyvsp[0].i_val));
    }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 202 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "iastore\n");
        else if(printflag == 2)
            fprintf(file, "fastore\n");
    }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(printflag == 0 || printflag == 1)
            fprintf(file, "istore %d\n", tmp_scope);
        else if(printflag == 2)
            fprintf(file, "fstore %d\n", tmp_scope);
        else if(printflag == 3)
            fprintf(file, "astore %d\n", tmp_scope);
    }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 217 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(type2 != type1) {
            printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, typeArr[add1], typeArr[add2]);
        }
        printf("ASSIGN\n"); 

        if(printflag == 0 || printflag == 1)
            fprintf(file, "istore %d\n", lookup_symbol((yyvsp[-3].id_val), scope));
        else if(printflag == 2)
            fprintf(file, "fstore %d\n", lookup_symbol((yyvsp[-3].id_val), scope));
        else if(printflag == 3)
            fprintf(file, "astore %d\n", lookup_symbol((yyvsp[-3].id_val), scope));
    }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 233 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        type2 = 0;
        fprintf(file, "ldc %d\n", (yyvsp[0].i_val));
    }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 238 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val)); 
        type2 = 2;
        fprintf(file, "ldc %f\n", (yyvsp[0].f_val));
    }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 243 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("STRING_LIT %s\n", (yyvsp[-1].s_val)); 
        type2 = 3;
        fprintf(file, "ldc \"%s\"\n", (yyvsp[-1].s_val));
    }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 248 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("TRUE\n"); 
        type2 = 1;
        fprintf(file, "ldc 1\n");
    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 253 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FALSE\n"); 
        type2 = 1;
        fprintf(file, "iconst_0\n");
    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 258 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
        type2 = 0;
        if( strcmp(typeArr[lookup_symbol((yyvsp[0].id_val), scope)],"bool") == 0 ) {
            printflag = 1;
            type2 = 1;
        }
        else if( strcmp(typeArr[lookup_symbol((yyvsp[0].id_val), scope)],"float32") == 0 ) {
            printflag = 2;
            type2 = 2;
        }
        else if( strcmp(typeArr[lookup_symbol((yyvsp[0].id_val), scope)],"string") == 0 ) {
            printflag = 3;
            type2 = 3;
        }
        add2 = lookup_symbol((yyvsp[0].id_val), scope);
    }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 279 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("ADD_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "iadd\n");
        else if(printflag == 2)
            fprintf(file, "fadd\n");
    }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 286 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("SUB_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "isub\n");
        else if(printflag == 2)
            fprintf(file, "fsub\n");
    }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 293 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("MUL_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "imul\n");
        else if(printflag == 2)
            fprintf(file, "fmul\n");
    }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 300 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("QUO_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "idiv\n");
        else if(printflag == 2)
            fprintf(file, "fdiv\n");
    }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 307 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("REM_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "irem\n");
    }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 315 "compiler_hw3.y" /* yacc.c:1646  */
    { tmp_scope = -1;
        type1 = 0;
        for(i=0; i<=scope; i++) {
            if(lookup_symbol((yyvsp[0].id_val), i) != -1) tmp_scope = lookup_symbol((yyvsp[0].id_val), i);
        }
        add1 = tmp_scope;
        if( tmp_scope == -1 ) {
            printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].id_val));
        }
        else {
            printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), tmp_scope); 
            if( strcmp(typeArr[tmp_scope],"bool") == 0 ) {
                printflag = 1;
                type1 = 1;
            }
            else if( strcmp(typeArr[tmp_scope],"float32") == 0 ) {
                printflag = 2;
                type1 = 2;
                fprintf(file, "fload %d\n", tmp_scope);
                tmp_id = tmp_scope;
            }
            else if( strcmp(typeArr[tmp_scope],"string") == 0 ) {
                printflag = 3;
                type1 = 3;
            }
            else {
                fprintf(file, "iload %d\n", tmp_scope);
                tmp_id = tmp_scope;
            }
        }
    }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 354 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 354 "compiler_hw3.y" /* yacc.c:1646  */
    { scope--; }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 358 "compiler_hw3.y" /* yacc.c:1646  */
    {
        insert_symbol( scope, (yyvsp[-2].id_val), "int32", yylineno, "-"); 
        fprintf(file, "istore %d\n", lookup_symbol((yyvsp[-2].id_val), scope));
    }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 362 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope, (yyvsp[-2].id_val), "string", yylineno, "-"); 
        fprintf(file, "astore %d\n", lookup_symbol((yyvsp[-2].id_val), scope));
    }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 366 "compiler_hw3.y" /* yacc.c:1646  */
    {
        insert_symbol( scope, (yyvsp[-2].id_val), "float32", yylineno, "-");
        fprintf(file, "fstore %d\n", lookup_symbol((yyvsp[-2].id_val), scope));
    }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope, (yyvsp[-2].id_val), "bool", yylineno, "-"); 
    }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 373 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        fprintf(file, "ldc %d\n", (yyvsp[0].i_val));
        }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 376 "compiler_hw3.y" /* yacc.c:1646  */
    { 
            insert_symbol( scope, (yyvsp[-6].id_val), "array", yylineno, tmp_type); 
            if(strcmp(tmp_type, "int32") == 0)
                fprintf(file, "newarray int\n");
            else 
                fprintf(file, "newarray float\n");
            fprintf(file, "astore %d\n", lookup_symbol((yyvsp[-6].id_val), scope));
    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 387 "compiler_hw3.y" /* yacc.c:1646  */
    { tmp_type = "int32"; }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 388 "compiler_hw3.y" /* yacc.c:1646  */
    { tmp_type = "float32"; }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 392 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("TRUE\n");
        fprintf(file, "ldc 1\n");
    }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 396 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FALSE\n");
        fprintf(file, "ldc 0\n");
    }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 404 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FLOAT_LIT %f\n", (yyvsp[-1].f_val));
        fprintf(file, "ldc %f\n", (yyvsp[-1].f_val));
    }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 408 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "ldc 0.0\n");
    }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 414 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\n", (yyvsp[-1].i_val));
        fprintf(file, "ldc %d\n", (yyvsp[-1].i_val));
    }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 418 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "ldc 0\n");
    }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 424 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("STRING_LIT %s\n", (yyvsp[-2].s_val));
        fprintf(file, "ldc \"%s\"\n", (yyvsp[-2].s_val));
    }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 428 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "ldc \"\"\n");
    }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 434 "compiler_hw3.y" /* yacc.c:1646  */
    {
                        printf("INC\n");
                        if(strcmp(typeArr[tmp_id], "int32") == 0) {
                            fprintf(file, "ldc 1\n");
                            fprintf(file, "iadd\n");
                            fprintf(file, "istore %d\n", tmp_id);
                        }
                        else if(strcmp(typeArr[tmp_id], "float32") == 0) {
                            fprintf(file, "ldc 1.0\n");
                            fprintf(file, "fadd\n");
                            fprintf(file, "fstore %d\n", tmp_id);
                        }
                      }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 447 "compiler_hw3.y" /* yacc.c:1646  */
    {
                        printf("DEC\n");
                        if(strcmp(typeArr[tmp_id], "int32") == 0) {
                            fprintf(file, "ldc 1\n");
                            fprintf(file, "isub\n");
                            fprintf(file, "istore %d\n", tmp_id);
                        }
                        else if(strcmp(typeArr[tmp_id], "float32") == 0) {
                            fprintf(file, "ldc 1.0\n");
                            fprintf(file, "fsub\n");
                            fprintf(file, "fstore %d\n", tmp_id);
                        }
                      }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 460 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        strcpy(ty1, typeArr[lookup_symbol((yyvsp[-2].id_val), scope)]);
                        strcpy(ty2, typeArr[lookup_symbol((yyvsp[0].id_val), scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("ADD\n"); 
                      }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        strcpy(ty1, typeArr[lookup_symbol((yyvsp[-2].id_val), scope)]);
                        strcpy(ty2, typeArr[lookup_symbol((yyvsp[0].id_val), scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("SUB\n"); 
                      }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 480 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        strcpy(ty1, typeArr[lookup_symbol((yyvsp[-2].id_val), scope)]);
                        strcpy(ty2, typeArr[lookup_symbol((yyvsp[0].id_val), scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("MUL\n"); 
                      }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        strcpy(ty1, typeArr[lookup_symbol((yyvsp[-2].id_val), scope)]);
                        strcpy(ty2, typeArr[lookup_symbol((yyvsp[0].id_val), scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("QUO\n"); 
                      }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 500 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        strcpy(ty1, typeArr[lookup_symbol((yyvsp[-2].id_val), scope)]);
                        strcpy(ty2, typeArr[lookup_symbol((yyvsp[0].id_val), scope)]);
                        if( strcmp("float32",ty2) == 0 ) {
                            printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
                        }
                        printf("REM\n"); 
                      }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 513 "compiler_hw3.y" /* yacc.c:1646  */
    { printflag = 0; }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 513 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(printflag == 0) {
            printf("PRINTLN int32\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(I)V\n");
        }
        else if(printflag == 1) {
            printf("PRINTLN bool\n");

            fprintf(file, "ifne label%d\nldc \"false\"\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\nldc \"true\"\n", label);

            fprintf(file, "label%d:\n", label+1);
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
            label = label + 2;
        }
        else if(printflag == 2) {
            printf("PRINTLN float32\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(F)V\n");
        }
        else {
            printf("PRINTLN string\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        }
    }
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 541 "compiler_hw3.y" /* yacc.c:1646  */
    { printflag = 0; }
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 541 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(printflag == 0)
            printf("PRINT int32\n");
        else if(printflag == 1) {
            printf("PRINT bool\n");

            fprintf(file, "ifne label%d\nldc \"false\"\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\nldc \"true\"\n", label);

            fprintf(file, "label%d:\n", label+1);
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
            label = label + 2;
        }
        else if(printflag == 2) 
            printf("PRINT float32\n");
        else
            printf("PRINT string\n");
    }
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 563 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("ADD\n");
        if(printflag == 0) {
            fprintf(file, "iadd\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fadd\n");
        }
    }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 572 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("SUB\n");
        if(printflag == 0) {
            fprintf(file, "isub\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fsub\n");
        }
    }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 581 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("REM\n");
        if(printflag == 0) {
            fprintf(file, "irem\n");
        }
        else if(printflag == 2) {
            fprintf(file, "frem\n");
        }
    }
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 592 "compiler_hw3.y" /* yacc.c:1646  */
    { printflag = 1; }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 595 "compiler_hw3.y" /* yacc.c:1646  */
    { printflag = 1; }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 596 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("STRING_LIT %s\n", (yyvsp[-1].s_val)); 
        printflag = 3; 
    }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 604 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("MUL\n");
        if(printflag == 0) {
            fprintf(file, "imul\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fmul\n");
        }
    }
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 613 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("QUO\n");
        if(printflag == 0) {
            fprintf(file, "idiv\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fdiv\n");
        }
    }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 627 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("LAND\n"); 
        fprintf(file, "iand\n");
    }
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 631 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("LOR\n"); 
        fprintf(file, "ior\n");
    }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 638 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("NOT\n"); 
        fprintf(file, "iconst_1\nixor\n");
    }
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 642 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("TRUE\n"); 
        fprintf(file, "iconst_1\n");
    }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 646 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("FALSE\n"); 
        fprintf(file, "iconst_0\n");
    }
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 653 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("GTR\n");
        if(printflag == 0) {
            fprintf(file, "isub\n");
            fprintf(file, "ifgt label%d\niconst_0\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\niconst_1\nlabel%d:\n", label, label+1);
        }
        else if(printflag == 2) {
            fprintf(file, "fcmpl\n");
            fprintf(file, "ifgt label%d\niconst_0\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\niconst_1\nlabel%d:\n", label, label+1);
        }
        label = label + 2;
    }
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 667 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LSS\n"); }
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 668 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("GEQ\n"); }
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 669 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LEQ\n"); }
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 670 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("EQL\n"); }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 671 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("NEQ\n"); }
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 675 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        fprintf(file, "ldc %d\n", (yyvsp[0].i_val));
        printflag = 0;
    }
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 680 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val)); 
        printflag = 2;
        fprintf(file, "ldc %f\n", (yyvsp[0].f_val));
    }
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 685 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                                printf("INT_LIT %d\n", abs((yyvsp[0].si_val))); 
                                fprintf(file, "ldc %d\n", abs((yyvsp[0].si_val)));
                                if( abs((yyvsp[0].si_val)) == (yyvsp[0].si_val)) {
                                    printf("POS\n");
                                }
                                else {
                                    printf("NEG\n");
                                    fprintf(file, "ineg\n");
                                }
                            }
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 696 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FLOAT_LIT %f\n", fabs((yyvsp[0].sf_val))); 
                                fprintf(file, "ldc %f\n", fabs((yyvsp[0].sf_val)));
                                if( abs((yyvsp[0].sf_val)) == (yyvsp[0].sf_val)) {
                                    printf("POS\n");
                                }
                                else {
                                    printf("NEG\n");
                                    fprintf(file, "fneg\n");
                                }
                            }
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 706 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope)); 
        fprintf(file, "aload %d\n", lookup_symbol((yyvsp[0].id_val), scope));
    }
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 710 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                if( strcmp(elementType[lookup_symbol((yyvsp[-4].id_val), scope)],"float32") == 0 ) {
                    printflag = 2;
                    fprintf(file, "faload\n");
                }
                else if( strcmp(elementType[lookup_symbol((yyvsp[-4].id_val), scope)],"string") == 0 )
                    printflag = 3; 
                else if(strcmp(elementType[lookup_symbol((yyvsp[-4].id_val), scope)],"int32") == 0) 
                    fprintf(file, "iaload\n");
            }
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 720 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                tmp_scope = -1;
                for(i=0; i<=scope; i++) {
                    if( lookup_symbol((yyvsp[0].id_val), i) != -1) tmp_scope = lookup_symbol((yyvsp[0].id_val), i);
                }

                if( tmp_scope == -1 ) {
                    printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].id_val));
                }
                else {
                    printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), tmp_scope); 
                    if( strcmp(typeArr[tmp_scope],"float32") == 0 ) {
                        printflag = 2;
                        fprintf(file, "fload %d\n", tmp_scope);
                    }
                    else if( strcmp(typeArr[tmp_scope],"string") == 0 ) {
                        printflag = 3;
                        fprintf(file, "aload %d\n", tmp_scope);
                    }
                    else if( strcmp(typeArr[tmp_scope],"bool") == 0 ) {
                        printflag = 1;
                    }
                    else {
                        fprintf(file, "iload %d\n", tmp_scope);
                    }
                }
            }
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 747 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("F to I\n"); 
        type1 = 0;
        fprintf(file, "f2i\n");
        printflag = 0;
    }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 753 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("FLOAT_LIT %f\nF to I\n",(yyvsp[-1].f_val)); 
        fprintf(file, "ldc %f\n", (yyvsp[-1].f_val));
        fprintf(file, "f2i\n");
        printflag = 0;
    }
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 759 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("I to F\n"); 
        fprintf(file, "i2f\n");
        printflag = 2;
    }
#line 2692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 764 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("INT_LIT %d\nI to F\n",(yyvsp[-1].i_val)); 
        type1 = 0;
        fprintf(file, "ldc %d\n", (yyvsp[-1].i_val));
        fprintf(file, "i2f\n");
        printflag = 2;
    }
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2708 "y.tab.c" /* yacc.c:1646  */
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
#line 773 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    file = fopen("hw3.j", "wb");
    fprintf(file, ".source hw3.j\n");
    fprintf(file, ".class public Main\n");
    fprintf(file, ".super java/lang/Object\n");
    fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
    fprintf(file, ".limit stack 100\n");
    fprintf(file, ".limit locals 100\n");

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    fprintf(file, "return\n.end method\n");
    fclose(file);
    return 0;
}

static void create_symbol() {
    /* initialize the symbol table */
    for(int i=0; i<50; i++) {
        indexArr[i] = 0;
        lineno[i] = 0;
        scopeArr[i] = -1;
        name[i] = NULL;
        typeArr[i] = NULL;
        elementType[i] = NULL;
    }
    for(int i=0; i<5; i++) {
        symNum[i] = 0;
    }
}

static void insert_symbol(int level, char *id, char *type, int linenum, char *element) {
    for(int i=0; i<varNum; i++) {
        if(strcmp(name[i],id) == 0 && scopeArr[i] == level) {
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", linenum, id, lineno[i]);
            return;
        }
    }
    
    printf("> Insert {%s} into symbol table (scope level: %d)\n", id, level);
    
    int i = varNum;
    indexArr[i] = symNum[level];
    name[i] = id;
    typeArr[i] = type;
    lineno[i] = linenum;
    elementType[i] = element;
    scopeArr[i] = level;

    symNum[level]++;
    varNum++;
}

static int lookup_symbol(char *id, int level) {
    for(int i=0; i<varNum; i++) {
        if( strcmp(id,name[i]) == 0 && level == scopeArr[i] ) {
            return i;
        }
    }
    return -1;
}

static void dump_symbol(int level) {
    printf("> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i=0; i<varNum; i++) {
        if(scopeArr[i] == level) {
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            indexArr[i], name[i], typeArr[i], i, lineno[i], elementType[i]);

            scopeArr[i] = -1;
            strcpy(name[i], "");
        }
    }

    symNum[level] = 0;
}
