/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "proj.y"


#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int yylex();
void yyerror(char *s);

typedef enum { assignationType, varDecType, funcDecType, whileType,ifType,forType, delayType} stmtEnum;

typedef struct elm{
    int type;
    char* id;
    char* classes;
    char* action;
    char* text;
    struct elm *child;
    struct elm *parent;
    struct elm *neigh_down;
    struct elm *neigh_up;
    struct exp *if_expr;
} element;

typedef struct exp{
    char type;
    char *var_name;
    int int_value;
    struct exp *left_expr;
    struct exp *right_expr;
} expression;

typedef struct _assignation{
    stmtEnum type;
    char* varname;
    struct exp *expression;
}assignation;

typedef struct _delay{
    stmtEnum type;
    struct exp *expression;
}delay;

typedef struct _varDeclarationStruct{
    stmtEnum type;
    char* varname;
    struct exp *expression;
}varDeclarationStruct;

typedef struct _funcDeclarationStruct{
    stmtEnum type;
    char* funcname;
    struct _stmt_node *statements;
}funcDeclarationStruct;

typedef struct _whileDeclaration{
    stmtEnum type;
    struct exp *expression;
    struct _stmt_node *statements;
}whileDeclaration;

typedef struct _ifDeclaration{
    stmtEnum type;
    struct exp *expression;
    struct _stmt_node *statements;
}ifDeclaration;

typedef union _statement{
    stmtEnum type;
    struct _assignation assignation;
    struct _varDeclarationStruct varDeclaration;
    struct _funcDeclarationStruct funcDeclaration;
    struct _whileDeclaration whileDeclaration;
    struct _ifDeclaration ifDeclaration;
    struct _delay delayDeclaration;
}statement;

typedef struct _stmt_node{
    union _statement stmt;
    struct _stmt_node *next;
}stmt_node;

element *generateElement(int type, char *id, char *classes,expression *if_cond, char *action, element *child, char* text);
element *addListToElement(element *existing_element, element *list_head);
expression *generateExpression(char type, expression* left_expr,expression* right_expr);
expression *generateConstant(char *var_name,int int_value);
stmt_node* generateFunction(char* funcname, stmt_node *statements);
stmt_node* generateVar(char* varname, expression* expression);
stmt_node* generateAssignation(char* varname, expression* expression);
stmt_node *addStatementToList(stmt_node *node, stmt_node *head);
void printCodeList(stmt_node *node, int indentation);
char *expressionToString(expression *exp, int size);
void computeRenderingConditions();
void computeVariableDeclaringRendering();
void render(element* html_root, stmt_node *code_root);
stmt_node* generateWhile_If(stmtEnum type,expression* expression, stmt_node *statements);
stmt_node* generateDelay(expression* expression);


void printpre(element *node, int indentation);


#line 173 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    BODY = 258,
    DIV = 259,
    H1 = 260,
    SPAN = 261,
    CLASS = 262,
    DECLARE = 263,
    BUTTON = 264,
    ID = 265,
    CODE_START = 266,
    CODE_END = 267,
    IF = 268,
    ACTION = 269,
    WHILE = 270,
    FOR = 271,
    DELAY = 272,
    VARIABLE = 273,
    BINDING = 274,
    VALUE = 275,
    STRING = 276,
    INTEGER = 277,
    FUNCNAME = 278
  };
#endif
/* Tokens.  */
#define BODY 258
#define DIV 259
#define H1 260
#define SPAN 261
#define CLASS 262
#define DECLARE 263
#define BUTTON 264
#define ID 265
#define CODE_START 266
#define CODE_END 267
#define IF 268
#define ACTION 269
#define WHILE 270
#define FOR 271
#define DELAY 272
#define VARIABLE 273
#define BINDING 274
#define VALUE 275
#define STRING 276
#define INTEGER 277
#define FUNCNAME 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 104 "proj.y"
 
        char* varname;
        char* value;
        char* string;
        int integer;
        char* funcname;
        struct elm *element_pointer;
        struct _cond *cond_pointer;
        struct exp *expr_pointer;
        struct _stmt_node *statement_pointer;
        

#line 284 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    36,    34,     2,    35,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    27,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   132,   132,   134,   136,   138,   139,   140,   141,   142,
     143,   145,   146,   149,   150,   153,   154,   157,   158,   161,
     162,   165,   166,   168,   170,   172,   174,   176,   177,   179,
     180,   181,   182,   183,   184,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BODY", "DIV", "H1", "SPAN", "CLASS",
  "DECLARE", "BUTTON", "ID", "CODE_START", "CODE_END", "IF", "ACTION",
  "WHILE", "FOR", "DELAY", "VARIABLE", "BINDING", "VALUE", "STRING",
  "INTEGER", "FUNCNAME", "'<'", "'>'", "'/'", "'='", "'['", "']'", "'{'",
  "'}'", "'('", "')'", "'+'", "'-'", "'*'", "$accept", "page",
  "code_section", "html", "html_element", "html_list", "class_node",
  "action_node", "id_node", "if_node", "var_declaration",
  "func_declaration", "while_stmt", "if_stmt", "delay_stmt", "stmt_list",
  "stmt", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    60,    62,    47,    61,    91,    93,
     123,   125,    40,    41,    43,    45,    42
};
# endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,    19,    34,     8,    14,   -31,   -31,   -31,   -31,    91,
     -13,    15,   -31,    18,    22,    31,    42,    43,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,    12,   -31,    50,   -15,
     -15,   -15,   -15,   -31,    77,    77,    77,    77,    80,   -15,
     -31,   -31,    92,    96,   109,   128,    -3,    66,    82,    82,
      82,    82,    72,   128,     5,    30,   -15,    60,    71,   -15,
     -15,   -15,    83,   -31,   -31,   -31,    95,    87,    87,    87,
      87,   -31,   -15,   128,   -15,   128,   128,   -15,   -31,   128,
     128,   128,   -31,   -31,    97,    98,    98,    98,    98,   128,
     128,   128,    28,    47,   113,   130,   149,   150,   151,   152,
     -31,   -31,   -15,   -31,   -31,   -31,   -31,   -31,   122,    16,
      37,    74,    86,   -31,    62,    70,    76,    85,   174,   175,
     173,   172,   157,   158,   159,   160,   -31,   -31,   -31,   -31
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,    28,     2,    12,     0,
       0,     0,     3,     0,     0,     0,     0,     0,    30,    31,
      32,    33,    34,    27,    10,     9,     0,    11,    22,     0,
       0,     0,     0,    28,    14,    14,    14,    14,     0,     0,
      36,    35,     0,     0,     0,    29,     0,     0,    18,    18,
      18,    18,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    23,    13,     0,    20,    20,    20,
      20,     4,     0,    41,     0,    42,    40,     0,    28,    37,
      38,    39,    28,    17,     0,    16,    16,    16,    16,    44,
      45,    43,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    24,     0,    15,    12,    12,    12,    12,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     5,     7,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   -31,   -31,    33,   124,    79,   119,   103,
     -31,   -31,   -31,   -31,   -31,   -29,   -31,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     3,    27,    10,    48,    96,    67,    85,
      18,    19,    20,    21,    22,     9,    23,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    44,    45,    40,    46,    11,    24,    41,    25,    53,
      13,    26,    14,     1,    15,    16,    34,    35,    36,     6,
      17,    37,     4,    40,    73,    75,    76,    41,    64,    79,
      80,    81,    72,    28,     5,    24,    11,    25,    38,     8,
     114,    13,    89,    14,    90,    15,    16,    91,    40,    92,
      29,    17,    41,    93,    30,    11,    24,    74,    25,   100,
      13,   115,    14,    31,    15,    16,    34,    35,    36,    32,
      17,    37,   108,    33,    34,    35,    36,    39,   101,    37,
      34,    35,    36,    52,    47,    37,    65,    77,   118,    34,
      35,    36,    66,    24,    37,    25,   119,    71,   116,    11,
      84,    78,   120,    12,    13,    24,    14,    25,    15,    16,
     117,   121,    95,    82,    17,    83,    54,    55,    56,    57,
      54,    55,    56,    57,    94,    58,    59,    60,    61,    62,
      59,    60,    61,    54,    55,    56,    57,   109,   110,   111,
     112,   102,    63,    59,    60,    61,    54,    55,    56,    57,
     103,   113,    54,    55,    56,    57,    59,    60,    61,    49,
      50,    51,    59,    60,    61,    97,    98,    99,    68,    69,
      70,    86,    87,    88,   104,   105,   106,   107,   122,   124,
     123,   125,   126,   127,   128,   129
};

static const yytype_int8 yycheck[] =
{
      30,    31,    32,    18,    33,     8,    19,    22,    21,    39,
      13,    24,    15,    24,    17,    18,     4,     5,     6,    11,
      23,     9,     3,    18,    54,    55,    56,    22,    31,    59,
      60,    61,    27,    18,     0,    19,     8,    21,    26,    25,
      24,    13,    72,    15,    74,    17,    18,    77,    18,    78,
      32,    23,    22,    82,    32,     8,    19,    27,    21,    31,
      13,    24,    15,    32,    17,    18,     4,     5,     6,    27,
      23,     9,   102,    30,     4,     5,     6,    27,    31,     9,
       4,     5,     6,     3,     7,     9,    20,    27,    26,     4,
       5,     6,    10,    19,     9,    21,    26,    25,    24,     8,
      13,    30,    26,    12,    13,    19,    15,    21,    17,    18,
      24,    26,    14,    30,    23,    20,    24,    25,    26,    27,
      24,    25,    26,    27,    27,    33,    34,    35,    36,    33,
      34,    35,    36,    24,    25,    26,    27,   104,   105,   106,
     107,    28,    33,    34,    35,    36,    24,    25,    26,    27,
      20,    29,    24,    25,    26,    27,    34,    35,    36,    35,
      36,    37,    34,    35,    36,    86,    87,    88,    49,    50,
      51,    68,    69,    70,    25,    25,    25,    25,     4,     6,
       5,     9,    25,    25,    25,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    38,    40,     3,     0,    11,    39,    25,    52,
      42,     8,    12,    13,    15,    17,    18,    23,    47,    48,
      49,    50,    51,    53,    19,    21,    24,    41,    18,    32,
      32,    32,    27,    30,     4,     5,     6,     9,    26,    27,
      18,    22,    54,    54,    54,    54,    52,     7,    43,    43,
      43,    43,     3,    54,    24,    25,    26,    27,    33,    34,
      35,    36,    33,    33,    31,    20,    10,    45,    45,    45,
      45,    25,    27,    54,    27,    54,    54,    27,    30,    54,
      54,    54,    30,    20,    13,    46,    46,    46,    46,    54,
      54,    54,    52,    52,    27,    14,    44,    44,    44,    44,
      31,    31,    28,    20,    25,    25,    25,    25,    54,    42,
      42,    42,    42,    29,    24,    24,    24,    24,    26,    26,
      26,    26,     4,     5,     6,     9,    25,    25,    25,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    40,    41,    41,    41,    41,    41,
      41,    42,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    47,    48,    49,    50,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     8,    12,    12,    12,    12,     1,
       1,     2,     0,     2,     0,     2,     0,     2,     0,     5,
       0,     4,     2,     4,     7,     7,     4,     2,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     4,     4,     4
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 132 "proj.y"
                         { render((yyvsp[-1].element_pointer),(yyvsp[0].statement_pointer)); }
#line 1544 "y.tab.c"
    break;

  case 3:
#line 134 "proj.y"
                                             {printf("<!--A parsat ok codul-->\n"); (yyval.statement_pointer) = (yyvsp[-1].statement_pointer);}
#line 1550 "y.tab.c"
    break;

  case 4:
#line 136 "proj.y"
                                               {printf("<!--A parsat ok html-ul-->\n"); (yyval.element_pointer) = (yyvsp[-4].element_pointer);}
#line 1556 "y.tab.c"
    break;

  case 5:
#line 138 "proj.y"
                                                                                          {(yyval.element_pointer) = generateElement(H1, (yyvsp[-8].value), (yyvsp[-9].value),(yyvsp[-7].expr_pointer),(yyvsp[-6].value), (yyvsp[-4].element_pointer), NULL);}
#line 1562 "y.tab.c"
    break;

  case 6:
#line 139 "proj.y"
                                                                                            {(yyval.element_pointer) = generateElement(DIV, (yyvsp[-8].value), (yyvsp[-9].value),(yyvsp[-7].expr_pointer),(yyvsp[-6].value), (yyvsp[-4].element_pointer), NULL);}
#line 1568 "y.tab.c"
    break;

  case 7:
#line 140 "proj.y"
                                                                                              {(yyval.element_pointer) = generateElement(SPAN, (yyvsp[-8].value), (yyvsp[-9].value),(yyvsp[-7].expr_pointer),(yyvsp[-6].value), (yyvsp[-4].element_pointer), NULL);}
#line 1574 "y.tab.c"
    break;

  case 8:
#line 141 "proj.y"
                                                                                                  {(yyval.element_pointer) = generateElement(BUTTON, (yyvsp[-8].value), (yyvsp[-9].value),(yyvsp[-7].expr_pointer),(yyvsp[-6].value), (yyvsp[-4].element_pointer), NULL);}
#line 1580 "y.tab.c"
    break;

  case 9:
#line 142 "proj.y"
                      {(yyval.element_pointer) = generateElement(STRING, NULL, NULL,NULL, NULL, NULL, (yyvsp[0].string));}
#line 1586 "y.tab.c"
    break;

  case 10:
#line 143 "proj.y"
                       {(yyval.element_pointer) = generateElement(BINDING, NULL, NULL,NULL, NULL, NULL, (yyvsp[0].varname)+1);}
#line 1592 "y.tab.c"
    break;

  case 11:
#line 145 "proj.y"
                                   {(yyval.element_pointer) = addListToElement((yyvsp[0].element_pointer), (yyvsp[-1].element_pointer));}
#line 1598 "y.tab.c"
    break;

  case 12:
#line 146 "proj.y"
            {(yyval.element_pointer) = NULL;}
#line 1604 "y.tab.c"
    break;

  case 13:
#line 149 "proj.y"
                         {(yyval.value) = (yyvsp[0].value)+1;}
#line 1610 "y.tab.c"
    break;

  case 14:
#line 150 "proj.y"
             {(yyval.value) = NULL;}
#line 1616 "y.tab.c"
    break;

  case 15:
#line 153 "proj.y"
                           {(yyval.value) = (yyvsp[0].value)+1;}
#line 1622 "y.tab.c"
    break;

  case 16:
#line 154 "proj.y"
              {(yyval.value) = NULL;}
#line 1628 "y.tab.c"
    break;

  case 17:
#line 157 "proj.y"
                   {(yyval.value) = (yyvsp[0].value)+1;}
#line 1634 "y.tab.c"
    break;

  case 18:
#line 158 "proj.y"
          {(yyval.value) = NULL;}
#line 1640 "y.tab.c"
    break;

  case 19:
#line 161 "proj.y"
                              {(yyval.expr_pointer) = (yyvsp[-1].expr_pointer);}
#line 1646 "y.tab.c"
    break;

  case 20:
#line 162 "proj.y"
          {(yyval.expr_pointer) = NULL;}
#line 1652 "y.tab.c"
    break;

  case 21:
#line 165 "proj.y"
                                            {(yyval.statement_pointer) = generateVar((yyvsp[-2].varname),(yyvsp[0].expr_pointer));}
#line 1658 "y.tab.c"
    break;

  case 22:
#line 166 "proj.y"
                                   {(yyval.statement_pointer) = generateVar((yyvsp[0].varname),NULL);}
#line 1664 "y.tab.c"
    break;

  case 23:
#line 168 "proj.y"
                                              {(yyval.statement_pointer) = generateFunction((yyvsp[-3].funcname), (yyvsp[-1].statement_pointer));}
#line 1670 "y.tab.c"
    break;

  case 24:
#line 170 "proj.y"
                                                  {(yyval.statement_pointer) = generateWhile_If(whileType, (yyvsp[-4].expr_pointer), (yyvsp[-1].statement_pointer));}
#line 1676 "y.tab.c"
    break;

  case 25:
#line 172 "proj.y"
                                            {(yyval.statement_pointer) = generateWhile_If(ifType, (yyvsp[-4].expr_pointer), (yyvsp[-1].statement_pointer));}
#line 1682 "y.tab.c"
    break;

  case 26:
#line 174 "proj.y"
                                {(yyval.statement_pointer) = generateDelay((yyvsp[-1].expr_pointer));}
#line 1688 "y.tab.c"
    break;

  case 27:
#line 176 "proj.y"
                           {(yyval.statement_pointer) = addStatementToList((yyvsp[0].statement_pointer), (yyvsp[-1].statement_pointer));}
#line 1694 "y.tab.c"
    break;

  case 28:
#line 177 "proj.y"
            {(yyval.statement_pointer) = NULL;}
#line 1700 "y.tab.c"
    break;

  case 29:
#line 179 "proj.y"
                         {(yyval.statement_pointer) = generateAssignation((yyvsp[-2].varname), (yyvsp[0].expr_pointer));}
#line 1706 "y.tab.c"
    break;

  case 30:
#line 180 "proj.y"
                       {(yyval.statement_pointer) = (yyvsp[0].statement_pointer);}
#line 1712 "y.tab.c"
    break;

  case 31:
#line 181 "proj.y"
                        {(yyval.statement_pointer) = (yyvsp[0].statement_pointer);}
#line 1718 "y.tab.c"
    break;

  case 32:
#line 182 "proj.y"
                  {(yyval.statement_pointer) = (yyvsp[0].statement_pointer);}
#line 1724 "y.tab.c"
    break;

  case 33:
#line 183 "proj.y"
               {(yyval.statement_pointer) = (yyvsp[0].statement_pointer);}
#line 1730 "y.tab.c"
    break;

  case 34:
#line 184 "proj.y"
                  {(yyval.statement_pointer) = (yyvsp[0].statement_pointer);}
#line 1736 "y.tab.c"
    break;

  case 35:
#line 186 "proj.y"
                              { (yyval.expr_pointer) = generateConstant(NULL, (yyvsp[0].integer)); }
#line 1742 "y.tab.c"
    break;

  case 36:
#line 187 "proj.y"
                              { (yyval.expr_pointer) = generateConstant((yyvsp[0].varname), 0);}
#line 1748 "y.tab.c"
    break;

  case 37:
#line 188 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('+', (yyvsp[-2].expr_pointer), (yyvsp[0].expr_pointer));}
#line 1754 "y.tab.c"
    break;

  case 38:
#line 189 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('-', (yyvsp[-2].expr_pointer), (yyvsp[0].expr_pointer));}
#line 1760 "y.tab.c"
    break;

  case 39:
#line 190 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('*', (yyvsp[-2].expr_pointer), (yyvsp[0].expr_pointer));}
#line 1766 "y.tab.c"
    break;

  case 40:
#line 191 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('/', (yyvsp[-2].expr_pointer), (yyvsp[0].expr_pointer)); }
#line 1772 "y.tab.c"
    break;

  case 41:
#line 192 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('<', (yyvsp[-2].expr_pointer), (yyvsp[0].expr_pointer)); }
#line 1778 "y.tab.c"
    break;

  case 42:
#line 193 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('>', (yyvsp[-2].expr_pointer), (yyvsp[0].expr_pointer)); }
#line 1784 "y.tab.c"
    break;

  case 43:
#line 194 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('e', (yyvsp[-3].expr_pointer), (yyvsp[0].expr_pointer)); }
#line 1790 "y.tab.c"
    break;

  case 44:
#line 195 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('l', (yyvsp[-3].expr_pointer), (yyvsp[0].expr_pointer)); }
#line 1796 "y.tab.c"
    break;

  case 45:
#line 196 "proj.y"
                              { (yyval.expr_pointer) = generateExpression('g', (yyvsp[-3].expr_pointer), (yyvsp[0].expr_pointer)); }
#line 1802 "y.tab.c"
    break;


#line 1806 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 199 "proj.y"


int conditionCount = 0;
expression *conditions[100];

int varCounts = 0;
stmt_node *variables[100];

void main(){
    yyparse();
}


void yyerror(char *s)
{
    printf("\n%s\n",s);
}


stmt_node *addStatementToList(stmt_node *node, stmt_node *head){
    if(head == NULL){
        return node;
    }
    stmt_node *tail = head;
    while(tail->next){
        tail = tail->next;
    };
    tail->next = node;
    return head;
}

char *getTabs(int count){
    char *tabs = (char*) calloc(50,1);
    strcpy(tabs," ");
    for(int i=0;i<count;i++){
        strcat(tabs,"\t");
    }
    return tabs;
}

stmt_node* generateAssignation(char* varname, expression* expression){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = assignationType;
    p->stmt.assignation.varname = varname;
    p->stmt.assignation.expression = expression;
    p->next = NULL;
    return p;
}

stmt_node* generateVar(char* varname, expression* expression){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = varDecType;
    p->stmt.varDeclaration.varname = varname;
    p->stmt.varDeclaration.expression = expression;
    p->next = NULL;

    variables[varCounts++] = p;
    return p;
}

stmt_node* generateFunction(char* funcname, stmt_node *statements){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = funcDecType;
    p->stmt.funcDeclaration.funcname = funcname;
    p->stmt.funcDeclaration.statements = statements;
    p->next = NULL;
    return p;
}

stmt_node* generateWhile_If(stmtEnum type,expression* expression, stmt_node *statements){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = type;
    p->stmt.whileDeclaration.expression = expression;
    p->stmt.whileDeclaration.statements = statements;
    p->next = NULL;
    return p;
}

stmt_node* generateDelay(expression* expression){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = delayType;
    p->stmt.delayDeclaration.expression = expression;
    p->next = NULL;
    return p;
}

expression *generateConstant(char *var_name,int int_value){
    expression *p = (expression*)malloc(sizeof(expression));

    p->type = var_name != NULL ? 'v' : 'i';
    p->int_value = int_value;
    p->var_name = var_name;
    p->left_expr=NULL;
    p->right_expr =NULL;

    return p;
}

expression *generateExpression(char type, expression* left_expr,expression* right_expr){
    expression *p = (expression*)malloc(sizeof(expression));
    p->type= type;
    p->left_expr=left_expr;
    p->right_expr = right_expr;

    return p;
}

element *addListToElement(element *existing_element, element *list_head){
    if(list_head == NULL){
        return existing_element;
    }
    element *tail = list_head;
    while(tail->neigh_down){
        tail = tail->neigh_down;
    };
    existing_element->neigh_up = tail;
    tail->neigh_down = existing_element;
    return list_head;
}


element *generateElement(int type, char *id, char *classes,expression *if_cond, char *action, element *child, char* text){
    element *p = (element*)malloc(sizeof(element));
    p->type= type;
    p->id=id;
    p->classes = classes;
    p->action = action;
    p->child = child;
    p->neigh_down = NULL;
    p->neigh_up = NULL;
    p->text = text;
    p->if_expr = if_cond;

    if(child != NULL){
        child->parent = p;
    }
    return p;
}

char *expressionToString(expression *exp, int size){
    char* expstr = (char*) calloc(size,1);

    if(exp->type == 'i'){
        sprintf(expstr, "%d", exp->int_value);
        return expstr;
    }
    else if(exp->type == 'v'){
        sprintf(expstr, "getVar('%s')", exp->var_name);
        return expstr;
    }
    else if(exp->type == 'e'){
        sprintf(expstr, "%s == %s", expressionToString(exp->left_expr, size/2), expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    else if(exp->type == 'l'){
        sprintf(expstr, "%s <= %s", expressionToString(exp->left_expr, size/2), expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    else if(exp->type == 'g'){
        sprintf(expstr, "%s >= %s", expressionToString(exp->left_expr, size/2), expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    else{
        sprintf(expstr, "%s %c %s", expressionToString(exp->left_expr, size/2),exp->type, expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    return expstr;
}

void computeVariableDeclaringRendering(){

    char *render = (char*) calloc(5000,1);

    sprintf(render,"const variables = {\n");

    for(int i=0;i<varCounts;i++){
        
            /* p->stmt.type = varDecType;
    p->stmt.varDeclaration.varname = varname;
    p->stmt.varDeclaration.expression = expression;
    p->next = NULL; */

        varDeclarationStruct varNode = variables[i]->stmt.varDeclaration;

        char *json = (char*) calloc(350,1);
        sprintf(json, 
        "'%s' : {\n"
        "    value: %s,\n"
        "    elements: document.querySelectorAll('.%s-binding')\n"
        "},\n"
        ,varNode.varname, expressionToString(varNode.expression,200), varNode.varname);
        strcat(render,json);
    }
    strcat(render,"}\n");
    printf("%s",render);
}

void computeRenderingConditions(){

    char *renderingConditions = (char*) calloc(5000,1);

    sprintf(renderingConditions,"const conditions = [\n");

    for(int i=0;i<conditionCount;i++){
        char *condstr = expressionToString(conditions[i],200);
        char *json = (char*) calloc(350,1);
        sprintf(json, 
        "{\n"
        "   condition: () => %s,\n"
        "   element: document.querySelector(\".cond-with-id%d\")\n"
        "},\n"
        ,condstr,i);
        strcat(renderingConditions,json);
    }
    strcat(renderingConditions,"]\n");
    printf("%s",renderingConditions);
}

void printCodeList(stmt_node *node, int indentation){
    if(node != NULL){
        char *tabs = getTabs(indentation);
        if(node->stmt.type == varDecType){
            //printf("var declaration\n");
        }
        else if(node->stmt.type == funcDecType){
            printf("%sconst %s = async () => {\n",tabs,node->stmt.funcDeclaration.funcname);
            printCodeList(node->stmt.funcDeclaration.statements,indentation+1);
            printf("%s}\n",tabs);
        }
        else if(node->stmt.type == whileType){
            printf("%swhile(%s){\n",tabs,expressionToString(node->stmt.whileDeclaration.expression,200));
            printCodeList(node->stmt.whileDeclaration.statements,indentation+1);
            printf("%s}\n",tabs);
        }
        else if(node->stmt.type == ifType){
            printf("%sif(%s){\n",tabs,expressionToString(node->stmt.ifDeclaration.expression,200));
            printCodeList(node->stmt.ifDeclaration.statements,indentation+1);
            printf("%s}\n",tabs);
        }
        else if(node->stmt.type == assignationType){
            printf("%supdateVar('%s',%s)\n",tabs,node->stmt.assignation.varname, expressionToString(node->stmt.assignation.expression,200));
        }
        else if(node->stmt.type == delayType){
            printf("%sawait delay(%s)\n",tabs,expressionToString(node->stmt.delayDeclaration.expression,200));
        }
        printCodeList(node->next, indentation);
    }
}

void printpre(element *node, int indentation){
    if(node != NULL){
        char *tabs = getTabs(indentation);
        int hasClasses = node->classes != NULL;
        int hasAction = node->action != NULL;
        int hasId = node->id != NULL;
        int hasCondition = node->if_expr != NULL;


        char *action_s = (char*)calloc(50,1);
        char *class_s = (char*)calloc(100,1);
        char *id_s = (char*)calloc(50,1);

        if(hasCondition){
            conditions[conditionCount] = node->if_expr;
            char *all_classes = (char*) calloc(120,1);
            if(hasClasses){
                sscanf(node->classes,"\"%[^\"]",all_classes);
            }
            sprintf(all_classes, "%s cond-with-id%d",all_classes,conditionCount);
            node->classes = all_classes;
            hasClasses = 1;
            conditionCount++;
        }
        if(hasClasses){
            sscanf(node->classes,"\"%[^\"]",node->classes);
            sprintf(class_s, " class=\"%s\"",node->classes);
        }
        if(hasId){
            sscanf(node->id,"\"%[^\"]",node->id);
            sprintf(id_s, " id=\"%s\"",node->id);
        }

        if(hasAction){
            sscanf(node->action,"\"%[^\"]",node->action);
            sprintf(action_s, " onclick=\"%s()\"",node->action);
        }

        if(node->type == H1){
            printf("%s<h1%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</h1>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == DIV){
            printf("%s<div%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</div>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == BUTTON){
            printf("%s<button%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</button>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == SPAN){
            printf("%s<span%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</span>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == BINDING){
            printf("%s<span class=\"%s-binding\"></span>\n",tabs,node->text);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == STRING){
            char *s = (char*)calloc(100,1);
            sscanf(node->text,"<text>%[^<]",s);
            printf("%s%s\n",tabs,s);
            printpre(node->neigh_down,indentation);
        }
    }
}

void render(element* html_root, stmt_node *code_root){

    printf("<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<head>"
            "    <meta charset=\"UTF-8\">\n"
            "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n"
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
            "    <title>Framework example</title>\n"
            "</head>\n"
            "<body>\n\n");

    printpre(html_root,0);
    printf("</body>\n\n<script>\n\n");

    computeRenderingConditions();
    computeVariableDeclaringRendering();

    printf("\nconst updateUI = (varName, newValue) => {\n"
           "    variables[varName].elements.forEach(element=>element.innerHTML = newValue);\n"
           "    conditions.forEach((cond, i)=>{\n"
           "        if(cond.condition()){\n"
           "            cond.element.style.display = '';\n"
           "        }\n"
           "        else{\n"
           "            cond.element.style.display = 'none';\n"
           "        }\n"
           "    });\n"
           "}\n"
           "const delay = (delayInms) => {\n"
           "     return new Promise(resolve => setTimeout(resolve, delayInms))\n"
           "     }\n"
           "const updateVar = (varName, value) => {\n"
           "    variables[varName].value = value;\n"
           "    updateUI(varName, value);\n"
           "}\n"
           "const getVar = (varName) => {\n"
           "    return variables[varName].value;\n"
           "}\n\n");

    printCodeList(code_root,0); 
    printf("\n\n</script>\n</html>\n");
}

     
