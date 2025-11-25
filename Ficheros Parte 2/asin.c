/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "src/asin.y"

#include <stdio.h>
#include "header.h" // Fichero de cabeceras del proyecto
#include "libtds.h"

void yyerror(const char *s);
extern int yylex();
extern int yylineno;
extern char *yytext;

int ref;    // referencia para arrays
int tipoRetornoActual; //guardar el tipo de retorno de las funciones, se hace así????


#line 86 "asin.c"

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

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_ = 3,                       /* INT_  */
  YYSYMBOL_BOOL_ = 4,                      /* BOOL_  */
  YYSYMBOL_TRUE_ = 5,                      /* TRUE_  */
  YYSYMBOL_FALSE_ = 6,                     /* FALSE_  */
  YYSYMBOL_RETURN_ = 7,                    /* RETURN_  */
  YYSYMBOL_READ_ = 8,                      /* READ_  */
  YYSYMBOL_PRINT_ = 9,                     /* PRINT_  */
  YYSYMBOL_IF_ = 10,                       /* IF_  */
  YYSYMBOL_ELSE_ = 11,                     /* ELSE_  */
  YYSYMBOL_FOR_ = 12,                      /* FOR_  */
  YYSYMBOL_ID_ = 13,                       /* ID_  */
  YYSYMBOL_CTE_ = 14,                      /* CTE_  */
  YYSYMBOL_MAS_ = 15,                      /* MAS_  */
  YYSYMBOL_MENOS_ = 16,                    /* MENOS_  */
  YYSYMBOL_POR_ = 17,                      /* POR_  */
  YYSYMBOL_DIV_ = 18,                      /* DIV_  */
  YYSYMBOL_NOT_ = 19,                      /* NOT_  */
  YYSYMBOL_AND_ = 20,                      /* AND_  */
  YYSYMBOL_OR_ = 21,                       /* OR_  */
  YYSYMBOL_ASIG_ = 22,                     /* ASIG_  */
  YYSYMBOL_IGUAL_ = 23,                    /* IGUAL_  */
  YYSYMBOL_DISTINTO_ = 24,                 /* DISTINTO_  */
  YYSYMBOL_MAYOR_ = 25,                    /* MAYOR_  */
  YYSYMBOL_MENOR_ = 26,                    /* MENOR_  */
  YYSYMBOL_MAYORIGUAL_ = 27,               /* MAYORIGUAL_  */
  YYSYMBOL_MENORIGUAL_ = 28,               /* MENORIGUAL_  */
  YYSYMBOL_PARA_ = 29,                     /* PARA_  */
  YYSYMBOL_PARC_ = 30,                     /* PARC_  */
  YYSYMBOL_CORA_ = 31,                     /* CORA_  */
  YYSYMBOL_CORC_ = 32,                     /* CORC_  */
  YYSYMBOL_LLAVEA_ = 33,                   /* LLAVEA_  */
  YYSYMBOL_LLAVEC_ = 34,                   /* LLAVEC_  */
  YYSYMBOL_PUNTOCOMA_ = 35,                /* PUNTOCOMA_  */
  YYSYMBOL_COMA_ = 36,                     /* COMA_  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_listDecla = 40,                 /* listDecla  */
  YYSYMBOL_decla = 41,                     /* decla  */
  YYSYMBOL_declaVar = 42,                  /* declaVar  */
  YYSYMBOL_const = 43,                     /* const  */
  YYSYMBOL_tipoSimp = 44,                  /* tipoSimp  */
  YYSYMBOL_declaFunc = 45,                 /* declaFunc  */
  YYSYMBOL_46_2 = 46,                      /* @2  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_paramForm = 48,                 /* paramForm  */
  YYSYMBOL_listParamForm = 49,             /* listParamForm  */
  YYSYMBOL_bloque = 50,                    /* bloque  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_declaVarLocal = 52,             /* declaVarLocal  */
  YYSYMBOL_listInst = 53,                  /* listInst  */
  YYSYMBOL_inst = 54,                      /* inst  */
  YYSYMBOL_instExpre = 55,                 /* instExpre  */
  YYSYMBOL_instEntSal = 56,                /* instEntSal  */
  YYSYMBOL_instSelec = 57,                 /* instSelec  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_instIter = 59,                  /* instIter  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_expreOP = 61,                   /* expreOP  */
  YYSYMBOL_expre = 62,                     /* expre  */
  YYSYMBOL_expreLogic = 63,                /* expreLogic  */
  YYSYMBOL_expreIgual = 64,                /* expreIgual  */
  YYSYMBOL_expreRel = 65,                  /* expreRel  */
  YYSYMBOL_expreAd = 66,                   /* expreAd  */
  YYSYMBOL_expreMul = 67,                  /* expreMul  */
  YYSYMBOL_expreUna = 68,                  /* expreUna  */
  YYSYMBOL_expreSufi = 69,                 /* expreSufi  */
  YYSYMBOL_paramAct = 70,                  /* paramAct  */
  YYSYMBOL_listParamAct = 71,              /* listParamAct  */
  YYSYMBOL_opLogic = 72,                   /* opLogic  */
  YYSYMBOL_opIgual = 73,                   /* opIgual  */
  YYSYMBOL_opRel = 74,                     /* opRel  */
  YYSYMBOL_opAd = 75,                      /* opAd  */
  YYSYMBOL_opMul = 76,                     /* opMul  */
  YYSYMBOL_opUna = 77                      /* opUna  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    63,    73,    74,    77,    78,    81,    92,
     107,   132,   133,   134,   137,   138,   142,   157,   141,   175,
     179,   184,   195,   208,   207,   217,   218,   221,   222,   225,
     226,   227,   228,   229,   232,   233,   236,   246,   254,   254,
     263,   262,   278,   278,   280,   281,   307,   336,   337,   348,
     349,   361,   362,   373,   374,   385,   386,   397,   398,   416,
     417,   418,   429,   446,   471,   472,   475,   476,   479,   480,
     483,   484,   487,   488,   489,   490,   493,   494,   497,   498,
     501,   502,   503
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_", "BOOL_",
  "TRUE_", "FALSE_", "RETURN_", "READ_", "PRINT_", "IF_", "ELSE_", "FOR_",
  "ID_", "CTE_", "MAS_", "MENOS_", "POR_", "DIV_", "NOT_", "AND_", "OR_",
  "ASIG_", "IGUAL_", "DISTINTO_", "MAYOR_", "MENOR_", "MAYORIGUAL_",
  "MENORIGUAL_", "PARA_", "PARC_", "CORA_", "CORC_", "LLAVEA_", "LLAVEC_",
  "PUNTOCOMA_", "COMA_", "$accept", "programa", "$@1", "listDecla",
  "decla", "declaVar", "const", "tipoSimp", "declaFunc", "@2", "$@3",
  "paramForm", "listParamForm", "bloque", "$@4", "declaVarLocal",
  "listInst", "inst", "instExpre", "instEntSal", "instSelec", "$@5",
  "instIter", "$@6", "expreOP", "expre", "expreLogic", "expreIgual",
  "expreRel", "expreAd", "expreMul", "expreUna", "expreSufi", "paramAct",
  "listParamAct", "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -60,     7,    24,   -60,   -60,   -60,    24,   -60,   -60,    10,
     -60,   -60,    57,    -4,    23,   -60,    15,   -60,   -60,   -60,
      13,    35,    24,   -60,    48,    60,    68,   -60,   -60,    51,
     -60,    24,    74,   -60,   -60,   -60,    24,   -60,    95,     6,
      57,    80,    86,    88,    90,    91,    -5,   -60,   -60,   -60,
      80,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,    89,
      56,    66,   -22,    85,    87,   -60,   -60,    97,    92,   108,
      80,    80,    80,    80,    80,    80,    93,    37,   -60,   -60,
     -60,    97,   -60,   -60,    97,   -60,   -60,   -60,   -60,    97,
     -60,   -60,    97,   -60,   -60,    97,     9,   -60,   -60,    98,
      99,   -60,    96,   -60,   -60,    94,   102,   -60,   101,   -60,
     -60,    66,   -22,    85,    87,   -60,    80,   100,   103,   104,
     105,    80,    80,   -60,   114,   109,   -60,   -60,   -60,    49,
     -60,   -60,    80,   -60,   111,   107,   -60,    49,    80,   -60,
     110,    49,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    14,    15,     3,     4,     6,     0,
       7,     5,    16,     0,     0,     8,     0,    12,    13,    11,
       0,     0,    19,     9,     0,     0,     0,    20,    10,    21,
      17,     0,     0,    22,    25,    18,    27,    26,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    80,    81,    82,
       0,    27,    35,    59,    28,    30,    31,    32,    33,     0,
      44,    47,    49,    51,    53,    55,    57,     0,     0,     0,
       0,     0,    42,     0,    64,     0,     0,     0,    34,    68,
      69,     0,    70,    71,     0,    72,    73,    74,    75,     0,
      76,    77,     0,    78,    79,     0,    61,    58,    23,     0,
       0,    38,     0,    43,    45,    66,     0,    65,     0,    60,
      29,    48,    50,    52,    54,    56,     0,     0,     0,     0,
       0,     0,     0,    63,    62,     0,    24,    36,    37,     0,
      40,    67,     0,    62,     0,     0,    46,     0,    42,    39,
       0,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -60,   119,   112,   124,    38,   -60,   -60,
     -60,   -60,   113,   -60,   -60,   -60,   106,   -23,   -60,   -60,
     -60,   -60,   -60,   -60,     5,   -41,   -60,    64,    62,    58,
      59,   -59,   -60,   -60,    27,   -60,   -60,   -60,   -60,   -60,
     -60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    53,     9,    10,    16,
      32,    26,    27,    35,   117,    36,    39,    54,    55,    56,
      57,   120,    58,   135,   102,    59,    60,    61,    62,    63,
      64,    65,    66,   106,   107,    81,    84,    89,    92,    95,
      67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    17,    18,    85,    86,    87,    88,     3,    97,    76,
      19,    17,    18,    41,    42,    43,    44,    73,    45,    46,
      19,    47,    48,    12,    74,    49,    75,     4,     5,   100,
     101,   103,   104,   105,   108,    50,   115,    21,    74,    51,
     116,    52,    17,    18,    22,    42,    43,    44,    23,    45,
      46,    19,    47,    48,    17,    18,    49,    42,    43,    44,
      25,    45,    46,    19,    47,    48,    50,    24,    49,    25,
      51,   110,    52,    29,    38,   125,    79,    80,    50,    13,
     130,   105,    51,    28,    52,    17,    18,    31,    14,    82,
      83,   136,    15,    46,    19,    47,    48,   103,    30,    49,
      90,    91,    17,    18,    93,    94,   134,    34,    40,    50,
      96,    19,    47,    48,   139,    69,    49,    70,   142,    71,
      72,    99,   137,   109,    78,    11,    50,    98,   118,   119,
     122,   121,   123,   124,   126,   129,   132,    20,   127,   128,
     141,   133,   138,   140,    33,   111,   112,   113,    37,   131,
       0,   114,     0,     0,     0,     0,     0,    77
};

static const yytype_int16 yycheck[] =
{
      41,     5,     6,    25,    26,    27,    28,     0,    67,    50,
      14,     5,     6,     7,     8,     9,    10,    22,    12,    13,
      14,    15,    16,    13,    29,    19,    31,     3,     4,    70,
      71,    72,    73,    74,    75,    29,    95,    14,    29,    33,
      31,    35,     5,     6,    29,     8,     9,    10,    35,    12,
      13,    14,    15,    16,     5,     6,    19,     8,     9,    10,
      22,    12,    13,    14,    15,    16,    29,    32,    19,    31,
      33,    34,    35,    13,    36,   116,    20,    21,    29,    22,
     121,   122,    33,    35,    35,     5,     6,    36,    31,    23,
      24,   132,    35,    13,    14,    15,    16,   138,    30,    19,
      15,    16,     5,     6,    17,    18,   129,    33,    13,    29,
      13,    14,    15,    16,   137,    29,    19,    29,   141,    29,
      29,    13,    11,    30,    35,     6,    29,    35,    30,    30,
      36,    35,    30,    32,    34,    30,    22,    13,    35,    35,
      30,    32,    35,   138,    31,    81,    84,    89,    36,   122,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,     4,    40,    41,    42,    44,
      45,    41,    13,    22,    31,    35,    46,     5,     6,    14,
      43,    14,    29,    35,    32,    44,    48,    49,    35,    13,
      30,    36,    47,    49,    33,    50,    52,    42,    44,    53,
      13,     7,     8,     9,    10,    12,    13,    15,    16,    19,
      29,    33,    35,    43,    54,    55,    56,    57,    59,    62,
      63,    64,    65,    66,    67,    68,    69,    77,    62,    29,
      29,    29,    29,    22,    29,    31,    62,    53,    35,    20,
      21,    72,    23,    24,    73,    25,    26,    27,    28,    74,
      15,    16,    75,    17,    18,    76,    13,    68,    35,    13,
      62,    62,    61,    62,    62,    62,    70,    71,    62,    30,
      34,    64,    65,    66,    67,    68,    31,    51,    30,    30,
      58,    35,    36,    30,    32,    62,    34,    35,    35,    30,
      62,    71,    22,    32,    54,    60,    62,    11,    35,    54,
      61,    30,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      42,    43,    43,    43,    44,    44,    46,    47,    45,    48,
      48,    49,    49,    51,    50,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    58,    57,
      60,    59,    61,    61,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     1,     1,     1,     0,     0,     8,     0,
       1,     2,     4,     0,     8,     0,     2,     0,     2,     3,
       1,     1,     1,     1,     2,     1,     5,     5,     0,     8,
       0,    10,     0,     1,     1,     3,     6,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       3,     1,     4,     4,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* $@1: %empty  */
#line 63 "src/asin.y"
         {niv = 0; cargaContexto(niv); dvar = 0;/*doy valor a niv y dvar inicial para cuando lo usemos*/}
#line 1524 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 63 "src/asin.y"
                                                                                                                   {
                
                SIMB sim_main = obtTdS("main");
                if (sim_main.t == T_ERROR || sim_main.t != T_ENTERO) {
                    yyerror("Debe existir una función 'main'");
                }
                mostrarTdS();   
        }
#line 1537 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp ID_ PUNTOCOMA_  */
#line 82 "src/asin.y"
        {
                int tipo = (yyvsp[-2].cent);
                int talla = 1;//como es un tipo simple = 1
                if (! insTdS((yyvsp[-1].ident), VARIABLE, tipo, niv, dvar, -1)){
                        yyerror("Identificador repetido");
                } else{
                        dvar += talla;
                }
                
        }
#line 1552 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp ID_ ASIG_ const PUNTOCOMA_  */
#line 93 "src/asin.y"
        {
            // declaVar: tipoSimp ID_ ASIG_ const PUNTOCOMA_ (Variable Simple Inicializada)
            int tipo = (yyvsp[-4].cent);
            int talla = 1;

            if (tipo != (yyvsp[-1].attr).tipo) {
                yyerror("Incompatibilidad de tipos en la inicialización de variable");
            }
             if (! insTdS((yyvsp[-3].ident), VARIABLE, tipo, niv, dvar, -1)){
                yyerror("Identificador de variable repetido");
            } else{
                dvar += talla;
            }
        }
#line 1571 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp ID_ CORA_ CTE_ CORC_ PUNTOCOMA_  */
#line 108 "src/asin.y"
        {
            int tipo_elem = (yyvsp[-5].cent);
            int numelem = (yyvsp[-2].cent);//numero de elementos del array

            if (numelem <= 0) {
                yyerror("Talla inapropiada del array (debe ser positiva)");
                numelem = 0;
                //por si acaso
                ref = -1;
            }
            
            if (numelem > 0) {
                 ref = insTdA(tipo_elem, numelem); // Guarda info del array en TdA
            }
            
            if ( ! insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, ref)) { 
                yyerror ("Identificador repetido");
            } else{
                dvar += numelem;
            }
            
        }
#line 1598 "asin.c"
    break;

  case 11: /* const: CTE_  */
#line 132 "src/asin.y"
               {(yyval.attr).tipo = T_ENTERO; (yyval.attr).cent = (yyvsp[0].cent);}
#line 1604 "asin.c"
    break;

  case 12: /* const: TRUE_  */
#line 133 "src/asin.y"
                {(yyval.attr).tipo = T_LOGICO; (yyval.attr).cent = 1;}
#line 1610 "asin.c"
    break;

  case 13: /* const: FALSE_  */
#line 134 "src/asin.y"
                 {(yyval.attr).tipo = T_LOGICO; (yyval.attr).cent = 0;}
#line 1616 "asin.c"
    break;

  case 14: /* tipoSimp: INT_  */
#line 137 "src/asin.y"
                {(yyval.cent) = T_ENTERO;}
#line 1622 "asin.c"
    break;

  case 15: /* tipoSimp: BOOL_  */
#line 138 "src/asin.y"
                 {(yyval.cent) = T_LOGICO;}
#line 1628 "asin.c"
    break;

  case 16: /* @2: %empty  */
#line 142 "src/asin.y"
    {
        //comprobamos si la función ya existe
        if (obtTdS((yyvsp[0].ident)).t != T_ERROR) {
            yyerror("Identificación de función repetido");
        }
        tipoRetornoActual = (yyvsp[-1].cent);
        (yyval.stf).tipoRetorno = (yyvsp[-1].cent);//guardamos el tipo de retorno ??

        (yyval.stf).despAnterior = dvar; // Usamos para guardar el dvar actual 
        niv++;     
        dvar = 0;  
        cargaContexto(niv); 

    }
#line 1647 "asin.c"
    break;

  case 17: /* $@3: %empty  */
#line 157 "src/asin.y"
    {
        //insertamos la función en el ámbito padre
        //dolar5 viene de paramForm, es la referencia a la TdD
        //printf("Entró en insertarfunción \n");
        if (!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv - 1, -1, (yyvsp[-1].cent))) {
            yyerror("Error al insertar función en TDS");
        }
    }
#line 1660 "asin.c"
    break;

  case 18: /* declaFunc: tipoSimp ID_ @2 PARA_ paramForm PARC_ $@3 bloque  */
#line 166 "src/asin.y"
    {
        descargaContexto(niv);
        niv--;
        /* Restauramos el dvar global */
        dvar = (yyvsp[-5].stf).despAnterior; 
    }
#line 1671 "asin.c"
    break;

  case 19: /* paramForm: %empty  */
#line 175 "src/asin.y"
    { 
        /* Si no hay parámetros, creamos entrada vacía en TdD */
        (yyval.cent) = insTdD(-1, T_VACIO); 
    }
#line 1680 "asin.c"
    break;

  case 20: /* paramForm: listParamForm  */
#line 180 "src/asin.y"
    { 
        (yyval.cent) = (yyvsp[0].cent); 
    }
#line 1688 "asin.c"
    break;

  case 21: /* listParamForm: tipoSimp ID_  */
#line 185 "src/asin.y"
    {
        /* b04.c: Identificador de parametro repetido (en TDS local) */
        if (!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, dvar, -1)) {
            yyerror("Identificador de parámetro repetido");
        } else {
            dvar += TALLA_TIPO_SIMPLE;
        }
        /* Crear nueva entrada en TdD (final de la lista) */
        (yyval.cent) = insTdD(-1, (yyvsp[-1].cent));
    }
#line 1703 "asin.c"
    break;

  case 22: /* listParamForm: tipoSimp ID_ COMA_ listParamForm  */
#line 196 "src/asin.y"
    {
        if (!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, dvar, -1)) {
            yyerror("Identificador de parámetro repetido");
        } else {
            dvar += TALLA_TIPO_SIMPLE;
        }
        /* Insertar al principio de la lista existente */
        (yyval.cent) = insTdD((yyvsp[0].cent), (yyvsp[-3].cent));
    }
#line 1717 "asin.c"
    break;

  case 23: /* $@4: %empty  */
#line 208 "src/asin.y"
    {
        /* b04.c: Error de tipos en el "return" */
        if ((yyvsp[-1].cent) != T_ERROR) {
            if ((yyvsp[-1].cent) != tipoRetornoActual) {
                yyerror("Error de tipos en el 'return'");
            }
        }
    }
#line 1730 "asin.c"
    break;

  case 36: /* instEntSal: READ_ PARA_ ID_ PARC_ PUNTOCOMA_  */
#line 237 "src/asin.y"
    {
        /* b03.c: El argumento del "read" debe ser "entero" */
        SIMB sim = obtTdS((yyvsp[-2].ident));
        if (sim.t == T_ERROR) {
            yyerror("Objeto no declarado");
        } else if (sim.t != T_ENTERO) {
            yyerror("El argumento del \"read\" debe ser \"entero\"");
        }
    }
#line 1744 "asin.c"
    break;

  case 37: /* instEntSal: PRINT_ PARA_ expre PARC_ PUNTOCOMA_  */
#line 247 "src/asin.y"
    {
        /* b03.c: La expresion del "print" debe ser "entera" */
        if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[-2].cent) != T_ENTERO) {
            yyerror("La expresion del \"print\" debe ser \"entera\"");
        }
    }
#line 1755 "asin.c"
    break;

  case 38: /* $@5: %empty  */
#line 254 "src/asin.y"
                           {
        /* b04.c: La expresion del `if' debe ser 'logico' */
        if ((yyvsp[0].cent) != T_ERROR && (yyvsp[0].cent) != T_LOGICO) {
            yyerror("La expresion del \"if\" debe ser \"logica\"");
        }
    }
#line 1766 "asin.c"
    break;

  case 40: /* $@6: %empty  */
#line 263 "src/asin.y"
    {
        /* b03.c: La expresion del "for" debe ser "logica" (la del medio $5) */
        if ((yyvsp[0].cent) != T_ERROR && (yyvsp[0].cent) != T_LOGICO) {
            yyerror("La expresion del \"for\" debe ser \"logica\"");
        }
    }
#line 1777 "asin.c"
    break;

  case 41: /* instIter: FOR_ PARA_ expreOP PUNTOCOMA_ expre $@6 PUNTOCOMA_ expreOP PARC_ inst  */
#line 269 "src/asin.y"
    {
        /* b02.c: La `expreOp' del `for' debe ser de tipo simple */
        if ((yyvsp[-7].cent) == T_ARRAY || (yyvsp[-2].cent) == T_ARRAY || (yyvsp[-7].cent) == T_ERROR || (yyvsp[-2].cent) == T_ERROR) {
                yyerror("La `expreOp' del `for' debe ser de tipo simple");
        }
    
    }
#line 1789 "asin.c"
    break;

  case 42: /* expreOP: %empty  */
#line 278 "src/asin.y"
                       { (yyval.cent) = T_VACIO; }
#line 1795 "asin.c"
    break;

  case 45: /* expre: ID_ ASIG_ expre  */
#line 282 "src/asin.y"
     {
         SIMB sim = obtTdS((yyvsp[-2].ident));
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             (yyval.cent) = T_ERROR;
         } else if (sim.t == T_ARRAY || sim.ref >= 0) { 
             /* b03.c: i = x (x es array) -> Error variable debe ser simple */
             /* Usamos sim.ref >= 0 para detectar funciones y arrays */
             yyerror("La variable debe ser de tipo simple"); 
             (yyval.cent) = T_ERROR;
         } else if ((yyvsp[0].cent) != T_ERROR) {
             if ((yyvsp[0].cent) == T_ARRAY) {
                 /* b03.c: "El variable debe ser de tipo simple" para RHS array */
                 yyerror("La variable debe ser de tipo simple");
                 (yyval.cent) = T_ERROR;
             } else if (sim.t != (yyvsp[0].cent)) {
                 yyerror("Error de tipos en la \"asignacion\"");
                 (yyval.cent) = T_ERROR;
             } else {
                 (yyval.cent) = sim.t;
             }
         } else {
             (yyval.cent) = T_ERROR;
         }
     }
#line 1825 "asin.c"
    break;

  case 46: /* expre: ID_ CORA_ expre CORC_ ASIG_ expre  */
#line 308 "src/asin.y"
     {
         SIMB sim = obtTdS((yyvsp[-5].ident));
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             (yyval.cent) = T_ERROR;
         } else {
             if (sim.t != T_ARRAY) {
                 /* b01.c error 17 */
                 yyerror("La variable debe ser de tipo \"array\"");
                 (yyval.cent) = T_ERROR;
             } else {
                 if ((yyvsp[-3].cent) != T_ENTERO && (yyvsp[-3].cent) != T_ERROR) {
                     yyerror("El indice del \"array\" debe ser entero");
                 }
                 
                 DIM dim = obtTdA(sim.ref);
                 if ((yyvsp[0].cent) != T_ERROR && dim.telem != (yyvsp[0].cent)) {
                     /* b01.c error 14 y 17 */
                     yyerror("Error de tipos en la asignacion a un `array'");
                     (yyval.cent) = T_ERROR;
                 } else {
                     (yyval.cent) = dim.telem;
                 }
             }
         }
     }
#line 1856 "asin.c"
    break;

  case 48: /* expreLogic: expreLogic opLogic expreIgual  */
#line 338 "src/asin.y"
          {
              if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
                  if ((yyvsp[-2].cent) != T_LOGICO || (yyvsp[0].cent) != T_LOGICO) {
                      yyerror("Error en \"expresion logica\"");
                      (yyval.cent) = T_ERROR;
                  } else (yyval.cent) = T_LOGICO;
              } else (yyval.cent) = T_ERROR;
          }
#line 1869 "asin.c"
    break;

  case 50: /* expreIgual: expreIgual opIgual expreRel  */
#line 350 "src/asin.y"
          {
              if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
                  if ((yyvsp[-2].cent) != (yyvsp[0].cent)) {
                    //printf("Entro en operando igual \n");
                      yyerror("Error en \"expresion de igualdad\"");
                      (yyval.cent) = T_ERROR;
                  } else (yyval.cent) = T_LOGICO;
              } else (yyval.cent) = T_ERROR;
          }
#line 1883 "asin.c"
    break;

  case 52: /* expreRel: expreRel opRel expreAd  */
#line 363 "src/asin.y"
        {  
            if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
                if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) {
                    yyerror("Error en \"expresion de relacional\"");
                    (yyval.cent) = T_ERROR;
                } else (yyval.cent) = T_LOGICO;
            } else (yyval.cent) = T_ERROR;
        }
#line 1896 "asin.c"
    break;

  case 54: /* expreAd: expreAd opAd expreMul  */
#line 375 "src/asin.y"
       {
           if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
               if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) {
                   yyerror("Error de tipos en \"expresion aditiva\"");
                   (yyval.cent) = T_ERROR;
               } else (yyval.cent) = T_ENTERO;
           } else (yyval.cent) = T_ERROR;
       }
#line 1909 "asin.c"
    break;

  case 56: /* expreMul: expreMul opMul expreUna  */
#line 387 "src/asin.y"
        {
            if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
                if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) {
                    yyerror("Error de tipos en \"expresion multiplicativa\"");
                    (yyval.cent) = T_ERROR;
                } else (yyval.cent) = T_ENTERO;
            } else (yyval.cent) = T_ERROR;
        }
#line 1922 "asin.c"
    break;

  case 58: /* expreUna: opUna expreUna  */
#line 399 "src/asin.y"
        {
            if ((yyvsp[0].cent) != T_ERROR) {
                if ((yyvsp[-1].cent) == NOT_) { 
                    if ((yyvsp[0].cent) != T_LOGICO) {
                        yyerror("Error en \"expresion unaria\"");
                        (yyval.cent) = T_ERROR;
                    } else (yyval.cent) = T_LOGICO;
                } else { 
                    if ((yyvsp[0].cent) != T_ENTERO) {
                        yyerror("Error en \"expresion unaria\"");
                        (yyval.cent) = T_ERROR;
                    } else (yyval.cent) = T_ENTERO;
                }
            } else (yyval.cent) = T_ERROR;
        }
#line 1942 "asin.c"
    break;

  case 59: /* expreSufi: const  */
#line 416 "src/asin.y"
                 { (yyval.cent) = (yyvsp[0].attr).tipo; }
#line 1948 "asin.c"
    break;

  case 60: /* expreSufi: PARA_ expre PARC_  */
#line 417 "src/asin.y"
                             { (yyval.cent) = (yyvsp[-1].cent); }
#line 1954 "asin.c"
    break;

  case 61: /* expreSufi: ID_  */
#line 419 "src/asin.y"
         {
             SIMB sim = obtTdS((yyvsp[0].ident));
             if (sim.t == T_ERROR) {
                 yyerror("Objeto no declarado");
                 (yyval.cent) = T_ERROR;
             } else {
                 if (sim.t == T_ARRAY) (yyval.cent) = T_ARRAY;
                 else (yyval.cent) = sim.t;
             }
         }
#line 1969 "asin.c"
    break;

  case 62: /* expreSufi: ID_ CORA_ expre CORC_  */
#line 430 "src/asin.y"
         {
             SIMB sim = obtTdS((yyvsp[-3].ident));
             if (sim.t == T_ERROR) {
                 yyerror("Objeto no declarado");
                 (yyval.cent) = T_ERROR;
             } else if (sim.t != T_ARRAY) {
                 yyerror("La variable debe ser de tipo \"array\"");
                 (yyval.cent) = T_ERROR;
             } else {
                 if ((yyvsp[-1].cent) != T_ENTERO && (yyvsp[-1].cent) != T_ERROR) 
                     yyerror("El indice del \"array\" debe ser entero");
                 
                 DIM dim = obtTdA(sim.ref);
                 (yyval.cent) = dim.telem;
             }
         }
#line 1990 "asin.c"
    break;

  case 63: /* expreSufi: ID_ PARA_ paramAct PARC_  */
#line 447 "src/asin.y"
         {
             SIMB sim = obtTdS((yyvsp[-3].ident));
             if (sim.t == T_ERROR) {
                 yyerror("Función no declarada");
                 (yyval.cent) = T_ERROR;
             } else {
                 
                 if (sim.ref == -1 && sim.t != T_ARRAY) {//si no es array pero ref == -1
                     yyerror("El identificador no es una función");
                     (yyval.cent) = T_ERROR;
                 } else if (sim.t == T_ARRAY) {
                     yyerror("El identificador no es una función");
                     (yyval.cent) = T_ERROR;
                 } else {
                     /* Es una función válida */
                     if (!cmpDom(sim.ref, (yyvsp[-1].cent))) {
                         yyerror("Error en el dominio de los parametros actuales");
                     }
                     (yyval.cent) = sim.t;
                 }
             }
         }
#line 2017 "asin.c"
    break;

  case 64: /* paramAct: %empty  */
#line 471 "src/asin.y"
                        { (yyval.cent) = insTdD(-1, T_VACIO); }
#line 2023 "asin.c"
    break;

  case 65: /* paramAct: listParamAct  */
#line 472 "src/asin.y"
                        { (yyval.cent) = (yyvsp[0].cent); }
#line 2029 "asin.c"
    break;

  case 66: /* listParamAct: expre  */
#line 475 "src/asin.y"
                                       { (yyval.cent) = insTdD(-1, (yyvsp[0].cent)); }
#line 2035 "asin.c"
    break;

  case 67: /* listParamAct: expre COMA_ listParamAct  */
#line 476 "src/asin.y"
                                       { (yyval.cent) = insTdD((yyvsp[0].cent), (yyvsp[-2].cent)); }
#line 2041 "asin.c"
    break;

  case 68: /* opLogic: AND_  */
#line 479 "src/asin.y"
                { (yyval.cent) = AND_; }
#line 2047 "asin.c"
    break;

  case 69: /* opLogic: OR_  */
#line 480 "src/asin.y"
                { (yyval.cent) = OR_; }
#line 2053 "asin.c"
    break;

  case 70: /* opIgual: IGUAL_  */
#line 483 "src/asin.y"
                     { (yyval.cent) = IGUAL_; }
#line 2059 "asin.c"
    break;

  case 71: /* opIgual: DISTINTO_  */
#line 484 "src/asin.y"
                     { (yyval.cent) = DISTINTO_; }
#line 2065 "asin.c"
    break;

  case 72: /* opRel: MAYOR_  */
#line 487 "src/asin.y"
                       { (yyval.cent) = MAYOR_; }
#line 2071 "asin.c"
    break;

  case 73: /* opRel: MENOR_  */
#line 488 "src/asin.y"
                       { (yyval.cent) = MENOR_; }
#line 2077 "asin.c"
    break;

  case 74: /* opRel: MAYORIGUAL_  */
#line 489 "src/asin.y"
                       { (yyval.cent) = MAYORIGUAL_; }
#line 2083 "asin.c"
    break;

  case 75: /* opRel: MENORIGUAL_  */
#line 490 "src/asin.y"
                       { (yyval.cent) = MENORIGUAL_; }
#line 2089 "asin.c"
    break;

  case 76: /* opAd: MAS_  */
#line 493 "src/asin.y"
                  { (yyval.cent) = MAS_; }
#line 2095 "asin.c"
    break;

  case 77: /* opAd: MENOS_  */
#line 494 "src/asin.y"
                  { (yyval.cent) = MENOS_; }
#line 2101 "asin.c"
    break;

  case 78: /* opMul: POR_  */
#line 497 "src/asin.y"
                { (yyval.cent) = POR_; }
#line 2107 "asin.c"
    break;

  case 79: /* opMul: DIV_  */
#line 498 "src/asin.y"
                { (yyval.cent) = DIV_; }
#line 2113 "asin.c"
    break;

  case 80: /* opUna: MAS_  */
#line 501 "src/asin.y"
                  { (yyval.cent) = MAS_; }
#line 2119 "asin.c"
    break;

  case 81: /* opUna: MENOS_  */
#line 502 "src/asin.y"
                  { (yyval.cent) = MENOS_; }
#line 2125 "asin.c"
    break;

  case 82: /* opUna: NOT_  */
#line 503 "src/asin.y"
                  { (yyval.cent) = NOT_; }
#line 2131 "asin.c"
    break;


#line 2135 "asin.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 506 "src/asin.y"

/* --- CÓDIGO DE USUARIO --- */
