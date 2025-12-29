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
#line 11 "src/asin.y"

#include <stdio.h>
#include "header.h" // Fichero de cabeceras del proyecto
#include "libtds.h"
#include "libgci.h"
#include <string.h> //añadido para contar cantidad de funciones main

void yyerror(const char *s);
extern int yylex();
extern int yylineno;
extern char *yytext;

int ref;    // referencia para arrays
int tipoRetornoActual; //guardar el tipo de retorno de las funciones para errores del return
int numMain;


#line 89 "asin.c"

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
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_paramForm = 49,                 /* paramForm  */
  YYSYMBOL_listParamForm = 50,             /* listParamForm  */
  YYSYMBOL_bloque = 51,                    /* bloque  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_declaVarLocal = 53,             /* declaVarLocal  */
  YYSYMBOL_listInst = 54,                  /* listInst  */
  YYSYMBOL_inst = 55,                      /* inst  */
  YYSYMBOL_instExpre = 56,                 /* instExpre  */
  YYSYMBOL_instEntSal = 57,                /* instEntSal  */
  YYSYMBOL_instSelec = 58,                 /* instSelec  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_instIter = 60,                  /* instIter  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_expreOP = 62,                   /* expreOP  */
  YYSYMBOL_expre = 63,                     /* expre  */
  YYSYMBOL_expreLogic = 64,                /* expreLogic  */
  YYSYMBOL_expreIgual = 65,                /* expreIgual  */
  YYSYMBOL_expreRel = 66,                  /* expreRel  */
  YYSYMBOL_expreAd = 67,                   /* expreAd  */
  YYSYMBOL_expreMul = 68,                  /* expreMul  */
  YYSYMBOL_expreUna = 69,                  /* expreUna  */
  YYSYMBOL_expreSufi = 70,                 /* expreSufi  */
  YYSYMBOL_paramAct = 71,                  /* paramAct  */
  YYSYMBOL_listParamAct = 72,              /* listParamAct  */
  YYSYMBOL_opLogic = 73,                   /* opLogic  */
  YYSYMBOL_opIgual = 74,                   /* opIgual  */
  YYSYMBOL_opRel = 75,                     /* opRel  */
  YYSYMBOL_opAd = 76,                      /* opAd  */
  YYSYMBOL_opMul = 77,                     /* opMul  */
  YYSYMBOL_opUna = 78                      /* opUna  */
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
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

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
       0,    73,    73,    73,   100,   101,   104,   105,   108,   119,
     134,   159,   160,   161,   164,   165,   169,   178,   188,   168,
     201,   205,   210,   223,   237,   236,   250,   251,   254,   255,
     258,   259,   260,   261,   262,   265,   266,   269,   279,   287,
     287,   296,   295,   311,   311,   313,   314,   342,   371,   372,
     383,   384,   396,   397,   408,   409,   422,   423,   434,   435,
     473,   477,   478,   490,   507,   532,   533,   536,   537,   540,
     541,   544,   545,   548,   549,   550,   551,   554,   555,   558,
     559,   562,   563,   564
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
  "$@4", "paramForm", "listParamForm", "bloque", "$@5", "declaVarLocal",
  "listInst", "inst", "instExpre", "instEntSal", "instSelec", "$@6",
  "instIter", "$@7", "expreOP", "expre", "expreLogic", "expreIgual",
  "expreRel", "expreAd", "expreMul", "expreUna", "expreSufi", "paramAct",
  "listParamAct", "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -61,     7,    24,   -61,   -61,   -61,    24,   -61,   -61,    10,
     -61,   -61,    38,    -4,    23,   -61,    15,   -61,   -61,   -61,
      13,    35,    24,   -61,    44,    77,    68,   -61,   -61,    65,
     -61,    24,   -61,   -61,    74,   -61,   -61,    24,   -61,    95,
       6,    38,    80,    85,    86,    91,    92,    -5,   -61,   -61,
     -61,    80,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
      84,    56,    64,   -22,    90,   100,   -61,   -61,    97,    87,
     110,    80,    80,    80,    80,    80,    80,    94,    37,   -61,
     -61,   -61,    97,   -61,   -61,    97,   -61,   -61,   -61,   -61,
      97,   -61,   -61,    97,   -61,   -61,    97,     9,   -61,   -61,
      98,    99,   -61,    96,   -61,   -61,    89,   102,   -61,   101,
     -61,   -61,    64,   -22,    90,   100,   -61,    80,    93,   103,
     104,   105,    80,    80,   -61,   108,   109,   -61,   -61,   -61,
      49,   -61,   -61,    80,   -61,   123,   107,   -61,    49,    80,
     -61,   106,    49,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    14,    15,     3,     4,     6,     0,
       7,     5,    16,     0,     0,     8,     0,    12,    13,    11,
       0,     0,    20,     9,     0,     0,     0,    21,    10,    22,
      17,     0,    18,    23,     0,    26,    19,    28,    27,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    81,    82,
      83,     0,    28,    36,    60,    29,    31,    32,    33,    34,
       0,    45,    48,    50,    52,    54,    56,    58,     0,     0,
       0,     0,     0,    43,     0,    65,     0,     0,     0,    35,
      69,    70,     0,    71,    72,     0,    73,    74,    75,    76,
       0,    77,    78,     0,    79,    80,     0,    62,    59,    24,
       0,     0,    39,     0,    44,    46,    67,     0,    66,     0,
      61,    30,    49,    51,    53,    55,    57,     0,     0,     0,
       0,     0,     0,     0,    64,    63,     0,    25,    37,    38,
       0,    41,    68,     0,    63,     0,     0,    47,     0,    43,
      40,     0,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   -61,   131,   111,   127,    52,   -61,   -61,
     -61,   -61,   -61,   112,   -61,   -61,   -61,   113,   -38,   -61,
     -61,   -61,   -61,   -61,   -61,     5,   -42,   -61,    63,    61,
      57,    58,   -60,   -61,   -61,    26,   -61,   -61,   -61,   -61,
     -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    54,     9,    10,    16,
      32,    34,    26,    27,    36,   118,    37,    40,    55,    56,
      57,    58,   121,    59,   136,   103,    60,    61,    62,    63,
      64,    65,    66,    67,   107,   108,    82,    85,    90,    93,
      96,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    17,    18,    86,    87,    88,    89,     3,    98,    77,
      19,    17,    18,    42,    43,    44,    45,    74,    46,    47,
      19,    48,    49,    12,    75,    50,    76,     4,     5,   101,
     102,   104,   105,   106,   109,    51,   116,    21,    75,    52,
     117,    53,    17,    18,    22,    43,    44,    45,    23,    46,
      47,    19,    48,    49,    17,    18,    50,    43,    44,    45,
      13,    46,    47,    19,    48,    49,    51,    24,    50,    14,
      52,   111,    53,    15,    25,   126,    80,    81,    51,    28,
     131,   106,    52,    25,    53,    17,    18,    83,    84,    39,
      29,   137,   135,    47,    19,    48,    49,   104,    30,    50,
     140,    31,    17,    18,   143,    91,    92,    35,    41,    51,
      97,    19,    48,    49,    70,    71,    50,    94,    95,    79,
      72,    73,    99,   100,   110,   123,    51,   127,   119,   120,
     133,   122,   124,   125,   138,   130,   142,    11,   128,   129,
      20,   134,   139,    33,   141,   112,   113,   114,    38,   132,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78
};

static const yytype_int16 yycheck[] =
{
      42,     5,     6,    25,    26,    27,    28,     0,    68,    51,
      14,     5,     6,     7,     8,     9,    10,    22,    12,    13,
      14,    15,    16,    13,    29,    19,    31,     3,     4,    71,
      72,    73,    74,    75,    76,    29,    96,    14,    29,    33,
      31,    35,     5,     6,    29,     8,     9,    10,    35,    12,
      13,    14,    15,    16,     5,     6,    19,     8,     9,    10,
      22,    12,    13,    14,    15,    16,    29,    32,    19,    31,
      33,    34,    35,    35,    22,   117,    20,    21,    29,    35,
     122,   123,    33,    31,    35,     5,     6,    23,    24,    37,
      13,   133,   130,    13,    14,    15,    16,   139,    30,    19,
     138,    36,     5,     6,   142,    15,    16,    33,    13,    29,
      13,    14,    15,    16,    29,    29,    19,    17,    18,    35,
      29,    29,    35,    13,    30,    36,    29,    34,    30,    30,
      22,    35,    30,    32,    11,    30,    30,     6,    35,    35,
      13,    32,    35,    31,   139,    82,    85,    90,    37,   123,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,     4,    40,    41,    42,    44,
      45,    41,    13,    22,    31,    35,    46,     5,     6,    14,
      43,    14,    29,    35,    32,    44,    49,    50,    35,    13,
      30,    36,    47,    50,    48,    33,    51,    53,    42,    44,
      54,    13,     7,     8,     9,    10,    12,    13,    15,    16,
      19,    29,    33,    35,    43,    55,    56,    57,    58,    60,
      63,    64,    65,    66,    67,    68,    69,    70,    78,    63,
      29,    29,    29,    29,    22,    29,    31,    63,    54,    35,
      20,    21,    73,    23,    24,    74,    25,    26,    27,    28,
      75,    15,    16,    76,    17,    18,    77,    13,    69,    35,
      13,    63,    63,    62,    63,    63,    63,    71,    72,    63,
      30,    34,    65,    66,    67,    68,    69,    31,    52,    30,
      30,    59,    35,    36,    30,    32,    63,    34,    35,    35,
      30,    63,    72,    22,    32,    55,    61,    63,    11,    35,
      55,    62,    30,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      42,    43,    43,    43,    44,    44,    46,    47,    48,    45,
      49,    49,    50,    50,    52,    51,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    59,
      58,    61,    60,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     1,     1,     1,     0,     0,     0,     9,
       0,     1,     2,     4,     0,     8,     0,     2,     0,     2,
       3,     1,     1,     1,     1,     2,     1,     5,     5,     0,
       8,     0,    10,     0,     1,     1,     3,     6,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     4,     4,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 73 "src/asin.y"
         {
            niv = 0;
            cargaContexto(niv);
            dvar = 0;
            numMain = 0;
            si=0;// damos valor a siguiente instruccion

            emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));//vamos al main
        }
#line 1538 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 81 "src/asin.y"
                    {
                
            SIMB sim_main = obtTdS("main");
            if (sim_main.t == T_ERROR) {
                yyerror("Debe existir una función 'main'");
            }
            if (numMain > 1){yyerror("El programa tiene más de un main");}
            //printf("Num mains %d \n", numMain);
            //mostrarTdS();   

            //ahora deberíamos rellanar el salto inicial


            if (numErrores == 0) {
            volcarCodigo("salida"); // El nombre suele ser el del fichero de entrada
        }
        }
#line 1560 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp ID_ PUNTOCOMA_  */
#line 109 "src/asin.y"
        {
                int tipo = (yyvsp[-2].cent);
                int talla = 1;//como es un tipo simple = 1
                if (! insTdS((yyvsp[-1].ident), VARIABLE, tipo, niv, dvar, -1)){
                        yyerror("Identificador de variable repetido");
                } else{
                        dvar += talla;
                }
                
        }
#line 1575 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp ID_ ASIG_ const PUNTOCOMA_  */
#line 120 "src/asin.y"
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
#line 1594 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp ID_ CORA_ CTE_ CORC_ PUNTOCOMA_  */
#line 135 "src/asin.y"
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
                yyerror ("Identificador de array repetido");
            } else{
                dvar += numelem;
            }
            
        }
#line 1621 "asin.c"
    break;

  case 11: /* const: CTE_  */
#line 159 "src/asin.y"
               {(yyval.attr).tipo = T_ENTERO; (yyval.attr).cent = (yyvsp[0].cent);}
#line 1627 "asin.c"
    break;

  case 12: /* const: TRUE_  */
#line 160 "src/asin.y"
                {(yyval.attr).tipo = T_LOGICO; (yyval.attr).cent = 1;}
#line 1633 "asin.c"
    break;

  case 13: /* const: FALSE_  */
#line 161 "src/asin.y"
                 {(yyval.attr).tipo = T_LOGICO; (yyval.attr).cent = 0;}
#line 1639 "asin.c"
    break;

  case 14: /* tipoSimp: INT_  */
#line 164 "src/asin.y"
                {(yyval.cent) = T_ENTERO;}
#line 1645 "asin.c"
    break;

  case 15: /* tipoSimp: BOOL_  */
#line 165 "src/asin.y"
                 {(yyval.cent) = T_LOGICO;}
#line 1651 "asin.c"
    break;

  case 16: /* @2: %empty  */
#line 169 "src/asin.y"
    {
        tipoRetornoActual = (yyvsp[-1].cent);//var global
        (yyval.cent) = dvar; // Usamos para guardar el dvar actual 
        niv++;     
        dvar = TALLA_SEGENLACES + TALLA_ESTADO_MAQUINA; 
        cargaContexto(niv); 

    }
#line 1664 "asin.c"
    break;

  case 17: /* $@3: %empty  */
#line 178 "src/asin.y"
    {
        //insertamos la función en el ámbito padre
        //printf("Entró en insertarfunción \n");
        if (strcmp((yyvsp[-4].ident), "main") == 0) { numMain += 1; }//para contar funciones main, error de b04

        if (!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv - 1, -1, (yyvsp[-1].attr).cent)) {
            yyerror("Identificación de función repetido");
            tipoRetornoActual = T_ERROR;
        }
    }
#line 1679 "asin.c"
    break;

  case 18: /* $@4: %empty  */
#line 188 "src/asin.y"
    {dvar = 0;}
#line 1685 "asin.c"
    break;

  case 19: /* declaFunc: tipoSimp ID_ @2 PARA_ paramForm PARC_ $@3 $@4 bloque  */
#line 190 "src/asin.y"
    {
        mostrarTdS();
        descargaContexto(niv);
        niv--;
        /* Restauramos el dvar global */
        dvar = (yyvsp[-6].cent);
        // poner desplazamiento en bloque 
    }
#line 1698 "asin.c"
    break;

  case 20: /* paramForm: %empty  */
#line 201 "src/asin.y"
    { 
        /* Si no hay parámetros, creamos entrada vacía en TdD */
        (yyval.attr).cent = insTdD(-1, T_VACIO); 
    }
#line 1707 "asin.c"
    break;

  case 21: /* paramForm: listParamForm  */
#line 206 "src/asin.y"
    { 
        (yyval.attr) = (yyvsp[0].attr); 
    }
#line 1715 "asin.c"
    break;

  case 22: /* listParamForm: tipoSimp ID_  */
#line 211 "src/asin.y"
    {
        /* b04.c: Identificador de parametro repetido */
        //printf("Entró en listaparámetros");

        // antes estaba en el else
        dvar += TALLA_TIPO_SIMPLE;
        if (!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -dvar, -1)) {
            yyerror("Identificador de parámetro repetido");
        } 
        /* Crear nueva entrada en TdD (final de la lista) */
        (yyval.attr).cent = insTdD(-1, (yyvsp[-1].cent));
    }
#line 1732 "asin.c"
    break;

  case 23: /* listParamForm: tipoSimp ID_ COMA_ listParamForm  */
#line 224 "src/asin.y"
    {   
            // antes estaba en el else
            dvar += TALLA_TIPO_SIMPLE;

            if (!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -dvar, -1)) {
                yyerror("Identificador de parámetro repetido");
            }
        /* Insertar al principio de la lista existente */
        (yyval.attr).cent = insTdD((yyvsp[0].attr).cent, (yyvsp[-3].cent));
    }
#line 1747 "asin.c"
    break;

  case 24: /* $@5: %empty  */
#line 237 "src/asin.y"
    {
        /* b04.c: Error de tipos en el "return" */
        if (tipoRetornoActual == T_ERROR){
            yyerror("No se puede comprobar el tipo del return porque no se instació la función");
        }
        else if ((yyvsp[-1].attr).tipo != T_ERROR) {
            if ((yyvsp[-1].attr).tipo != tipoRetornoActual) {
                yyerror("Error de tipos en el 'return'");
            }
        }
        
    }
#line 1764 "asin.c"
    break;

  case 37: /* instEntSal: READ_ PARA_ ID_ PARC_ PUNTOCOMA_  */
#line 270 "src/asin.y"
    {
        /* b03.c: El argumento del "read" debe ser "entero" */
        SIMB sim = obtTdS((yyvsp[-2].ident));
        if (sim.t == T_ERROR) {
            yyerror("Objeto no declarado");
        } else if (sim.t != T_ENTERO) {
            yyerror("El argumento del \"read\" debe ser \"entero\"");
        }
    }
#line 1778 "asin.c"
    break;

  case 38: /* instEntSal: PRINT_ PARA_ expre PARC_ PUNTOCOMA_  */
#line 280 "src/asin.y"
    {
        /* b03.c: La expresion del "print" debe ser "entera" */
        if ((yyvsp[-2].attr).tipo != T_ERROR && (yyvsp[-2].attr).tipo != T_ENTERO) {
            yyerror("La expresion del \"print\" debe ser \"entera\"");
        }
    }
#line 1789 "asin.c"
    break;

  case 39: /* $@6: %empty  */
#line 287 "src/asin.y"
                           {
        /* b04.c: La expresion del `if' debe ser 'logico' */
        if ((yyvsp[0].attr).tipo != T_ERROR && (yyvsp[0].attr).tipo != T_LOGICO) {
            yyerror("La expresion del \"if\" debe ser \"logica\"");
        }
    }
#line 1800 "asin.c"
    break;

  case 41: /* $@7: %empty  */
#line 296 "src/asin.y"
    {
        /* b03.c: La expresion del "for" debe ser "logica" (la del medio $5) */
        if ((yyvsp[0].attr).tipo != T_ERROR && (yyvsp[0].attr).tipo != T_LOGICO) {
            yyerror("La expresion del \"for\" debe ser \"logica\"");
        }
    }
#line 1811 "asin.c"
    break;

  case 42: /* instIter: FOR_ PARA_ expreOP PUNTOCOMA_ expre $@7 PUNTOCOMA_ expreOP PARC_ inst  */
#line 302 "src/asin.y"
    {
        /* b02.c: La `expreOp' del `for' debe ser de tipo simple */
        if ((yyvsp[-7].attr).tipo == T_ARRAY || (yyvsp[-2].attr).tipo == T_ARRAY || (yyvsp[-7].attr).tipo == T_ERROR || (yyvsp[-2].attr).tipo == T_ERROR) {
                yyerror("La `expreOp' del `for' debe ser de tipo simple");
        }
    
    }
#line 1823 "asin.c"
    break;

  case 43: /* expreOP: %empty  */
#line 311 "src/asin.y"
                       { (yyval.attr).tipo = T_VACIO; }
#line 1829 "asin.c"
    break;

  case 46: /* expre: ID_ ASIG_ expre  */
#line 315 "src/asin.y"
     {
         SIMB sim = obtTdS((yyvsp[-2].ident));
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             (yyval.attr).tipo = T_ERROR;
         } else if (sim.t == T_ARRAY || sim.ref >= 0) { 
             /* b03.c: i = x (x es array) -> Error variable debe ser simple */
             /* Usamos ref >= 0 para detectar funciones y arrays */
             yyerror("La variable debe ser de tipo simple"); 
             (yyval.attr).tipo = T_ERROR;
         } else if ((yyvsp[0].attr).tipo != T_ERROR) {
             if ((yyvsp[0].attr).tipo == T_ARRAY) {
                 /* b03.c: "El variable debe ser de tipo simple" para RHS array */
                 yyerror("La variable debe ser de tipo simple");
                 (yyval.attr).tipo = T_ERROR;
             } else if (sim.t != (yyvsp[0].attr).tipo) {
                 yyerror("Error de tipos en la \"asignacion\"");
                 (yyval.attr).tipo = T_ERROR;
             } else {
                 (yyval.attr).tipo = sim.t;
             }
         } else { // si esta todo correcto
             (yyval.attr).tipo = T_ERROR;
             (yyval.attr).d = sim.d; // el resultado de la asignación es la propia variable
             emite(EASIG, crArgPos(niv, (yyvsp[0].attr).d), crArgNul(), crArgPos(sim.n, sim.d));
         }
     }
#line 1861 "asin.c"
    break;

  case 47: /* expre: ID_ CORA_ expre CORC_ ASIG_ expre  */
#line 343 "src/asin.y"
     {
         SIMB sim = obtTdS((yyvsp[-5].ident));
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             (yyval.attr).tipo = T_ERROR;
         } else {
             if (sim.t != T_ARRAY) {
                 /* b01.c error en arrays */
                 yyerror("La variable debe ser de tipo \"array\"");
                 (yyval.attr).tipo = T_ERROR;
             } else {
                 if ((yyvsp[-3].attr).tipo != T_ENTERO && (yyvsp[-3].attr).tipo != T_ERROR) {
                     yyerror("El indice del \"array\" debe ser entero");
                 }
                 
                 DIM dim = obtTdA(sim.ref);
                 if ((yyvsp[0].attr).tipo != T_ERROR && dim.telem != (yyvsp[0].attr).tipo) {
                     /* b01.c comprobamos que el tipo del array es el mismo que el de expre */
                     yyerror("Error de tipos en la asignacion a un `array'");
                     (yyval.attr).tipo = T_ERROR;
                 } else {
                     (yyval.attr).tipo = dim.telem;
                 }
             }
         }
     }
#line 1892 "asin.c"
    break;

  case 49: /* expreLogic: expreLogic opLogic expreIgual  */
#line 373 "src/asin.y"
          {
              if ((yyvsp[-2].attr).tipo != T_ERROR && (yyvsp[0].attr).tipo != T_ERROR) {
                  if ((yyvsp[-2].attr).tipo != T_LOGICO || (yyvsp[0].attr).tipo != T_LOGICO) {
                      yyerror("Error en \"expresion logica\"");
                      (yyval.attr).tipo = T_ERROR;
                  } else (yyval.attr).tipo = T_LOGICO;
              } else (yyval.attr).tipo = T_ERROR;
          }
#line 1905 "asin.c"
    break;

  case 51: /* expreIgual: expreIgual opIgual expreRel  */
#line 385 "src/asin.y"
          {
              if ((yyvsp[-2].attr).tipo != T_ERROR && (yyvsp[0].attr).tipo != T_ERROR) {
                  if ((yyvsp[-2].attr).tipo != (yyvsp[0].attr).tipo) {
                    //printf("Entro en operando igual \n");
                      yyerror("Error en \"expresion de igualdad\"");
                      (yyval.attr).tipo = T_ERROR;
                  } else (yyval.attr).tipo = T_LOGICO;
              } else (yyval.attr).tipo = T_ERROR;
          }
#line 1919 "asin.c"
    break;

  case 53: /* expreRel: expreRel opRel expreAd  */
#line 398 "src/asin.y"
        {  
            if ((yyvsp[-2].attr).tipo != T_ERROR && (yyvsp[0].attr).tipo != T_ERROR) {
                if ((yyvsp[-2].attr).tipo != T_ENTERO || (yyvsp[0].attr).tipo != T_ENTERO) {
                    yyerror("Error en \"expresion relacional\"");
                    (yyval.attr).tipo = T_ERROR;
                } else (yyval.attr).tipo = T_LOGICO;
            } else (yyval.attr).tipo = T_ERROR;
        }
#line 1932 "asin.c"
    break;

  case 55: /* expreAd: expreAd opAd expreMul  */
#line 410 "src/asin.y"
       {
        //ejemplo del enunciado
            (yyval.attr).tipo = T_ERROR;
            if (((yyvsp[-2].attr).tipo == T_ENTERO) && ((yyvsp[0].attr).tipo == T_ENTERO)) (yyval.attr).tipo = T_ENTERO;
            else yyerror("Error de tipos en \"expresion aditiva\"");
            (yyval.attr).d = creaVarTemp();
            /***************** Expresion a partir de operador arimetico */
            emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].attr).d), crArgPos(niv, (yyvsp[0].attr).d), crArgPos(niv, (yyval.attr).d));

       }
#line 1947 "asin.c"
    break;

  case 57: /* expreMul: expreMul opMul expreUna  */
#line 424 "src/asin.y"
        {
            (yyval.attr).tipo = T_ERROR;
            if (((yyvsp[-2].attr).tipo == T_ENTERO) && ((yyvsp[0].attr).tipo == T_ENTERO)) (yyval.attr).tipo = T_ENTERO;
            else yyerror("Error de tipos en \"expresion multiplicativa\"");
            (yyval.attr).d = creaVarTemp();
            /***************** Expresion a partir de operador arimetico */
            emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].attr).d), crArgPos(niv, (yyvsp[0].attr).d), crArgPos(niv, (yyval.attr).d));
        }
#line 1960 "asin.c"
    break;

  case 59: /* expreUna: opUna expreUna  */
#line 436 "src/asin.y"
        {
            if ((yyvsp[0].attr).tipo != T_ERROR) {
                if ((yyvsp[-1].cent) == NOT_) { 
                    if ((yyvsp[0].attr).tipo != T_LOGICO) {
                        yyerror("Error en \"expresion unaria\"");
                        (yyval.attr).tipo = T_ERROR;
                    } else {
                        (yyval.attr).tipo = T_LOGICO;
                        (yyval.attr).d = creaVarTemp();
                        
                        // Para negar x, hacemos 1-x
                        // si x = 1 (true) -> 1-1 = 0 (false)
                        // si x = 0 (false) -> 1-0 = 1 (true)
                        emite(EDIF, crArgEnt(1), crArgPos(niv, (yyvsp[0].attr).d), crArgPos(niv, (yyval.attr).d));
                    } 
                } else { // + o -
                    if ((yyvsp[0].attr).tipo != T_ENTERO) {
                        yyerror("Error en \"expresion unaria\"");
                        (yyval.attr).tipo = T_ERROR;
                    } else {
                        (yyval.attr).tipo = T_ENTERO;

                        if ((yyvsp[-1].cent) == ESIG) {
                            // caso -x
                            (yyval.attr).d = creaVarTemp();
                            emite(ESIG, crArgPos(niv, (yyvsp[0].attr).d), crArgNul(), crArgPos(niv, (yyval.attr).d));
                        } 
                        else {
                            // caso +x
                            (yyval.attr).d = (yyvsp[0].attr).d;
                        } 
                    }
                }
            } else (yyval.attr).tipo = T_ERROR;
        }
#line 2000 "asin.c"
    break;

  case 60: /* expreSufi: const  */
#line 473 "src/asin.y"
                 { (yyval.attr).tipo = (yyvsp[0].attr).tipo; 
                   (yyval.attr).d = creaVarTemp();
                   emite(EASIG, crArgEnt((yyvsp[0].attr).cent), crArgNul(), crArgPos(niv, (yyval.attr).d));
                 }
#line 2009 "asin.c"
    break;

  case 61: /* expreSufi: PARA_ expre PARC_  */
#line 477 "src/asin.y"
                             { (yyval.attr) = (yyvsp[-1].attr); }
#line 2015 "asin.c"
    break;

  case 62: /* expreSufi: ID_  */
#line 479 "src/asin.y"
         {
             SIMB sim = obtTdS((yyvsp[0].ident));
             if (sim.t == T_ERROR) {
                yyerror("Objeto no declarado");
                (yyval.attr).tipo = T_ERROR;
             } else {
                //guardamos tipo y desplazamiento para subirlo GCI
                (yyval.attr).tipo = sim.t;
                (yyval.attr).d = sim.d;
             }
         }
#line 2031 "asin.c"
    break;

  case 63: /* expreSufi: ID_ CORA_ expre CORC_  */
#line 491 "src/asin.y"
         {
             SIMB sim = obtTdS((yyvsp[-3].ident));
             if (sim.t == T_ERROR) {
                 yyerror("Objeto no declarado");
                 (yyval.attr).tipo = T_ERROR;
             } else if (sim.t != T_ARRAY) {
                 yyerror("La variable debe ser de tipo \"array\"");
                 (yyval.attr).tipo = T_ERROR;
             } else {
                 if ((yyvsp[-1].attr).tipo != T_ENTERO && (yyvsp[-1].attr).tipo != T_ERROR) 
                     yyerror("El indice del \"array\" debe ser entero");
                 
                 DIM dim = obtTdA(sim.ref);
                 (yyval.attr).tipo = dim.telem;
             }
         }
#line 2052 "asin.c"
    break;

  case 64: /* expreSufi: ID_ PARA_ paramAct PARC_  */
#line 508 "src/asin.y"
         {
             SIMB sim = obtTdS((yyvsp[-3].ident));
             if (sim.t == T_ERROR) {
                 yyerror("Función no declarada");
                 (yyval.attr).tipo = T_ERROR;
             } else {
                 
                 if (sim.ref == -1 && sim.t != T_ARRAY) {//si no es array pero ref == -1
                     yyerror("El identificador no es una función");
                     (yyval.attr).tipo = T_ERROR;
                 } else if (sim.t == T_ARRAY) {
                     yyerror("El identificador no es una función");
                     (yyval.attr).tipo = T_ERROR;
                 } else {
                     /* Es una función válida */
                     if (!cmpDom(sim.ref, (yyvsp[-1].attr).cent)) {
                         yyerror("Error en el dominio de los parametros actuales");
                     }
                     (yyval.attr).tipo = sim.t;
                 }
             }
         }
#line 2079 "asin.c"
    break;

  case 65: /* paramAct: %empty  */
#line 532 "src/asin.y"
                        { (yyval.attr).cent = insTdD(-1, T_VACIO); }
#line 2085 "asin.c"
    break;

  case 66: /* paramAct: listParamAct  */
#line 533 "src/asin.y"
                        { (yyval.attr) = (yyvsp[0].attr); }
#line 2091 "asin.c"
    break;

  case 67: /* listParamAct: expre  */
#line 536 "src/asin.y"
                                       { (yyval.attr).cent = insTdD(-1, (yyvsp[0].attr).tipo); }
#line 2097 "asin.c"
    break;

  case 68: /* listParamAct: expre COMA_ listParamAct  */
#line 537 "src/asin.y"
                                       { (yyval.attr).cent = insTdD((yyvsp[0].attr).cent, (yyvsp[-2].attr).tipo); }
#line 2103 "asin.c"
    break;

  case 69: /* opLogic: AND_  */
#line 540 "src/asin.y"
                { (yyval.cent) = AND_; }
#line 2109 "asin.c"
    break;

  case 70: /* opLogic: OR_  */
#line 541 "src/asin.y"
                { (yyval.cent) = OR_; }
#line 2115 "asin.c"
    break;

  case 71: /* opIgual: IGUAL_  */
#line 544 "src/asin.y"
                     { (yyval.cent) = EIGUAL; }
#line 2121 "asin.c"
    break;

  case 72: /* opIgual: DISTINTO_  */
#line 545 "src/asin.y"
                     { (yyval.cent) = EDIST; }
#line 2127 "asin.c"
    break;

  case 73: /* opRel: MAYOR_  */
#line 548 "src/asin.y"
                       { (yyval.cent) = EMAY; }
#line 2133 "asin.c"
    break;

  case 74: /* opRel: MENOR_  */
#line 549 "src/asin.y"
                       { (yyval.cent) = EMEN; }
#line 2139 "asin.c"
    break;

  case 75: /* opRel: MAYORIGUAL_  */
#line 550 "src/asin.y"
                       { (yyval.cent) = EMAYEQ; }
#line 2145 "asin.c"
    break;

  case 76: /* opRel: MENORIGUAL_  */
#line 551 "src/asin.y"
                       { (yyval.cent) = EMENEQ; }
#line 2151 "asin.c"
    break;

  case 77: /* opAd: MAS_  */
#line 554 "src/asin.y"
                  { (yyval.cent) = ESUM; }
#line 2157 "asin.c"
    break;

  case 78: /* opAd: MENOS_  */
#line 555 "src/asin.y"
                  { (yyval.cent) = EDIF; }
#line 2163 "asin.c"
    break;

  case 79: /* opMul: POR_  */
#line 558 "src/asin.y"
                { (yyval.cent) = EMULT; }
#line 2169 "asin.c"
    break;

  case 80: /* opMul: DIV_  */
#line 559 "src/asin.y"
                { (yyval.cent) = EDIVI; }
#line 2175 "asin.c"
    break;

  case 81: /* opUna: MAS_  */
#line 562 "src/asin.y"
                  { (yyval.cent) = ESUM; }
#line 2181 "asin.c"
    break;

  case 82: /* opUna: MENOS_  */
#line 563 "src/asin.y"
                  { (yyval.cent) = EDIF; }
#line 2187 "asin.c"
    break;

  case 83: /* opUna: NOT_  */
#line 564 "src/asin.y"
                  { (yyval.cent) = NOT_; }
#line 2193 "asin.c"
    break;


#line 2197 "asin.c"

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

#line 567 "src/asin.y"

/* --- CÓDIGO DE USUARIO --- */
