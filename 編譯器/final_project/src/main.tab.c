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
#line 1 "main.y"

#include "main.tab.h"

#ifdef _DEBUG_
const bool is_debug = true;
#else
const bool is_debug = false;
#endif

extern int yylex(void);
extern void yyerror(const char*);

Python py;
stack<void*> esp;

// 沒有全域區域之分，進入點為預設的 main_func，
// 宣告變數時往 parent 尋找最近 Function
Function main_func;
State scope(&main_func);

#line 92 "main.tab.c"

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

#include "main.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_BOOL_VAL = 4,                   /* BOOL_VAL  */
  YYSYMBOL_NUM_VAL = 5,                    /* NUM_VAL  */
  YYSYMBOL_ADD = 6,                        /* ADD  */
  YYSYMBOL_SUB = 7,                        /* SUB  */
  YYSYMBOL_MUL = 8,                        /* MUL  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_MOD = 10,                       /* MOD  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NOT = 13,                       /* NOT  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_PRINT_B = 17,                   /* PRINT_B  */
  YYSYMBOL_PRINT_N = 18,                   /* PRINT_N  */
  YYSYMBOL_DEF = 19,                       /* DEF  */
  YYSYMBOL_FUN = 20,                       /* FUN  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_LB = 22,                        /* LB  */
  YYSYMBOL_RB = 23,                        /* RB  */
  YYSYMBOL_YYACCEPT = 24,                  /* $accept  */
  YYSYMBOL_stmts = 25,                     /* stmts  */
  YYSYMBOL_stmt = 26,                      /* stmt  */
  YYSYMBOL_exec = 27,                      /* exec  */
  YYSYMBOL_print_stmt = 28,                /* print_stmt  */
  YYSYMBOL_29_1 = 29,                      /* $@1  */
  YYSYMBOL_30_2 = 30,                      /* $@2  */
  YYSYMBOL_exp = 31,                       /* exp  */
  YYSYMBOL_exps = 32,                      /* exps  */
  YYSYMBOL_opr_exp = 33,                   /* opr_exp  */
  YYSYMBOL_add = 34,                       /* add  */
  YYSYMBOL_35_3 = 35,                      /* $@3  */
  YYSYMBOL_substract = 36,                 /* substract  */
  YYSYMBOL_37_4 = 37,                      /* $@4  */
  YYSYMBOL_38_5 = 38,                      /* $@5  */
  YYSYMBOL_multiply = 39,                  /* multiply  */
  YYSYMBOL_40_6 = 40,                      /* $@6  */
  YYSYMBOL_divide = 41,                    /* divide  */
  YYSYMBOL_42_7 = 42,                      /* $@7  */
  YYSYMBOL_43_8 = 43,                      /* $@8  */
  YYSYMBOL_modulus = 44,                   /* modulus  */
  YYSYMBOL_45_9 = 45,                      /* $@9  */
  YYSYMBOL_46_10 = 46,                     /* $@10  */
  YYSYMBOL_greater = 47,                   /* greater  */
  YYSYMBOL_48_11 = 48,                     /* $@11  */
  YYSYMBOL_49_12 = 49,                     /* $@12  */
  YYSYMBOL_less = 50,                      /* less  */
  YYSYMBOL_51_13 = 51,                     /* $@13  */
  YYSYMBOL_52_14 = 52,                     /* $@14  */
  YYSYMBOL_equal = 53,                     /* equal  */
  YYSYMBOL_54_15 = 54,                     /* $@15  */
  YYSYMBOL_and_op = 55,                    /* and_op  */
  YYSYMBOL_56_16 = 56,                     /* $@16  */
  YYSYMBOL_or_op = 57,                     /* or_op  */
  YYSYMBOL_58_17 = 58,                     /* $@17  */
  YYSYMBOL_not_op = 59,                    /* not_op  */
  YYSYMBOL_60_18 = 60,                     /* $@18  */
  YYSYMBOL_if_exp = 61,                    /* if_exp  */
  YYSYMBOL_62_19 = 62,                     /* $@19  */
  YYSYMBOL_63_20 = 63,                     /* $@20  */
  YYSYMBOL_64_21 = 64,                     /* $@21  */
  YYSYMBOL_def_stmt = 65,                  /* def_stmt  */
  YYSYMBOL_66_22 = 66,                     /* $@22  */
  YYSYMBOL_variable = 67,                  /* variable  */
  YYSYMBOL_fun_exp = 68,                   /* fun_exp  */
  YYSYMBOL_69_23 = 69,                     /* $@23  */
  YYSYMBOL_fun_ids = 70,                   /* fun_ids  */
  YYSYMBOL_fun_body = 71,                  /* fun_body  */
  YYSYMBOL_fun_call = 72,                  /* fun_call  */
  YYSYMBOL_73_24 = 73,                     /* $@24  */
  YYSYMBOL_fun_var = 74,                   /* fun_var  */
  YYSYMBOL_params = 75,                    /* params  */
  YYSYMBOL_fun_name = 76,                  /* fun_name  */
  YYSYMBOL_local_def_stmts = 77,           /* local_def_stmts  */
  YYSYMBOL_local_def_stmt = 78             /* local_def_stmt  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    69,    71,    73,    80,    80,    83,    83,
      89,    89,    96,    98,   100,   102,   104,   106,   108,   112,
     112,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   115,   117,   117,   126,   128,   126,   136,   136,   145,
     147,   145,   155,   157,   155,   165,   167,   165,   175,   177,
     175,   185,   185,   194,   194,   203,   203,   212,   212,   220,
     222,   224,   220,   232,   232,   241,   247,   247,   255,   257,
     259,   263,   263,   280,   280,   282,   291,   295,   302,   302,
     304
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "BOOL_VAL",
  "NUM_VAL", "ADD", "SUB", "MUL", "DIV", "MOD", "AND", "OR", "NOT", "GT",
  "LT", "EQ", "PRINT_B", "PRINT_N", "DEF", "FUN", "IF", "LB", "RB",
  "$accept", "stmts", "stmt", "exec", "print_stmt", "$@1", "$@2", "exp",
  "exps", "opr_exp", "add", "$@3", "substract", "$@4", "$@5", "multiply",
  "$@6", "divide", "$@7", "$@8", "modulus", "$@9", "$@10", "greater",
  "$@11", "$@12", "less", "$@13", "$@14", "equal", "$@15", "and_op",
  "$@16", "or_op", "$@17", "not_op", "$@18", "if_exp", "$@19", "$@20",
  "$@21", "def_stmt", "$@22", "variable", "fun_exp", "$@23", "fun_ids",
  "fun_body", "fun_call", "$@24", "fun_var", "params", "fun_name",
  "local_def_stmts", "local_def_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -40,   -40,   -40,    96,     4,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,    -2,   -16,   -40,     5,   -40,   -40,   -40,   -40,   -40,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   -40,   -40,   125,   -40,   149,   125,   -40,
     125,   -40,   -40,   125,   125,     8,   -40,   -40,   125,    11,
      14,   125,   -40,   -40,     7,   -40,    10,   125,    13,   125,
     125,    16,    19,   -40,   125,   125,    41,   -40,   -40,    17,
      24,   125,   -40,   -40,   -40,   -40,    20,   -40,    25,    26,
     -40,   -40,    45,    46,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,    49,   163,   125,   -40,   129,   -40,
     -40,    50,    -2,   -40,   125,    51,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    65,    12,    13,     0,     0,     3,     5,     7,     6,
      15,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    18,     4,    14,    16,    17,    77,    32,    34,
      37,    39,    42,    53,    55,    57,    45,    48,    51,     8,
      10,     0,     0,    59,     0,    73,    71,    74,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    66,     0,    76,     0,     0,    35,
       0,    40,    43,     0,     0,     0,    46,    49,     0,     0,
       0,     0,    69,    60,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     9,    11,     0,
       0,     0,    72,    75,    33,    19,     0,    38,     0,     0,
      54,    56,     0,     0,    52,    64,    68,    79,    61,    36,
      41,    44,    47,    50,     0,     0,     0,    67,     0,    70,
      78,     0,     0,    62,     0,     0,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,    23,   -40,   -40,   -40,   -40,     0,    -3,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -39,    -1,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    61,    62,    85,    86,    10,
      11,    50,    12,    51,    87,    13,    52,    14,    53,    89,
      15,    54,    90,    16,    58,    94,    17,    59,    95,    18,
      60,    19,    55,    20,    56,    21,    57,    22,    65,   101,
     126,    23,    81,    24,    25,    82,   100,   124,    26,    66,
      46,    84,    47,   125,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       9,     1,    63,    45,    48,     9,    64,     1,     2,     3,
       1,     2,     3,     1,     2,     3,     1,     2,     3,     1,
       2,     3,     1,     2,     3,    42,     4,   116,    49,    67,
     102,    93,    67,   104,    97,    67,   107,    98,    67,   110,
     115,    67,   111,   119,     1,     2,     3,   117,   120,   121,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    67,   114,    83,    45,    88,   122,   123,
      91,    92,   127,   133,   136,    96,     0,     0,     1,     2,
       3,    99,     0,     0,   103,     0,   105,   106,   105,   108,
     109,   105,   105,   134,   112,   113,   105,     4,     0,    27,
       0,   118,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
       0,     0,     0,     0,     0,   129,   131,    45,     1,     2,
       3,     0,    27,     0,   135,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,    67,   132,    42,
      43,    44,    27,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     1,     2,     3,    42,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128
};

static const yytype_int16 yycheck[] =
{
       0,     3,    41,     4,     0,     5,    22,     3,     4,     5,
       3,     4,     5,     3,     4,     5,     3,     4,     5,     3,
       4,     5,     3,     4,     5,    20,    22,     3,     5,    22,
      23,    23,    22,    23,    23,    22,    23,    23,    22,    23,
      23,    22,    23,    23,     3,     4,     5,    23,    23,    23,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    22,    23,    65,    67,    70,    23,    23,
      73,    74,    23,    23,    23,    78,    -1,    -1,     3,     4,
       5,    81,    -1,    -1,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,   132,    94,    95,    96,    22,    -1,     3,
      -1,   101,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   128,     3,     4,
       5,    -1,     3,    -1,   134,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    22,    19,    20,
      21,    22,     3,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     3,     4,     5,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    22,    25,    26,    27,    28,    31,
      33,    34,    36,    39,    41,    44,    47,    50,    53,    55,
      57,    59,    61,    65,    67,    68,    72,     3,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    68,    74,    76,     0,    26,
      35,    37,    40,    42,    45,    56,    58,    60,    48,    51,
      54,    29,    30,    67,    22,    62,    73,    22,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    66,    69,    31,    75,    31,    32,    38,    32,    43,
      46,    32,    32,    23,    49,    52,    32,    23,    23,    31,
      70,    63,    23,    31,    23,    31,    31,    23,    31,    31,
      23,    23,    31,    31,    23,    23,     3,    23,    31,    23,
      23,    23,    23,    23,    71,    77,    64,    23,    22,    31,
      78,    31,    19,    23,    67,    31,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    24,    25,    25,    26,    26,    27,    27,    29,    28,
      30,    28,    31,    31,    31,    31,    31,    31,    31,    32,
      32,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    35,    34,    37,    38,    36,    40,    39,    42,
      43,    41,    45,    46,    44,    48,    49,    47,    51,    52,
      50,    54,    53,    56,    55,    58,    57,    60,    59,    62,
      63,    64,    61,    66,    65,    67,    69,    68,    70,    70,
      71,    73,    72,    74,    74,    75,    75,    76,    77,    77,
      78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     0,     5,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     0,     0,     7,     0,     6,     0,
       0,     7,     0,     0,     7,     0,     0,     7,     0,     0,
       7,     0,     6,     0,     6,     0,     6,     0,     5,     0,
       0,     0,     9,     0,     6,     1,     0,     8,     2,     0,
       2,     0,     5,     1,     1,     2,     0,     1,     2,     0,
       5
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
  case 4: /* stmt: def_stmt  */
#line 71 "main.y"
               {
    scope.reset();
}
#line 1265 "main.tab.c"
    break;

  case 5: /* stmt: exec  */
#line 73 "main.y"
         {
    if (is_debug)
        scope.back()->traverse();
    execute(scope);
    scope.reset();
}
#line 1276 "main.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 83 "main.y"
           {
    scope.append(new Operator(DataType::NONE, "pb"));
}
#line 1284 "main.tab.c"
    break;

  case 9: /* print_stmt: LB PRINT_B $@1 exp RB  */
#line 85 "main.y"
         {
    ((Operator*)scope.back())->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1293 "main.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 89 "main.y"
           {
    scope.append(new Operator(DataType::NONE, "pn"));
}
#line 1301 "main.tab.c"
    break;

  case 11: /* print_stmt: LB PRINT_N $@2 exp RB  */
#line 91 "main.y"
         {
    ((Operator*)scope.back())->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1310 "main.tab.c"
    break;

  case 12: /* exp: BOOL_VAL  */
#line 96 "main.y"
              {
    (yyval.node) = (ASTNode*)(yyvsp[0].bool_obj);
}
#line 1318 "main.tab.c"
    break;

  case 13: /* exp: NUM_VAL  */
#line 98 "main.y"
            {
    (yyval.node) = (ASTNode*)(yyvsp[0].num_obj);
}
#line 1326 "main.tab.c"
    break;

  case 14: /* exp: variable  */
#line 100 "main.y"
             {
    (yyval.node) = (ASTNode*)(yyvsp[0].obj);
}
#line 1334 "main.tab.c"
    break;

  case 15: /* exp: opr_exp  */
#line 102 "main.y"
            {
    (yyval.node) = (ASTNode*)(yyvsp[0].opr);
}
#line 1342 "main.tab.c"
    break;

  case 16: /* exp: fun_exp  */
#line 104 "main.y"
            {
    (yyval.node) = (ASTNode*)(yyvsp[0].fun_obj);
}
#line 1350 "main.tab.c"
    break;

  case 17: /* exp: fun_call  */
#line 106 "main.y"
             {
    (yyval.node) = (ASTNode*)(yyvsp[0].fun_obj);
}
#line 1358 "main.tab.c"
    break;

  case 18: /* exp: if_exp  */
#line 108 "main.y"
           {
    (yyval.node) = (ASTNode*)(yyvsp[0].opr);
}
#line 1366 "main.tab.c"
    break;

  case 19: /* exps: exps exp  */
#line 112 "main.y"
               { scope.back()->append((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1372 "main.tab.c"
    break;

  case 32: /* $@3: %empty  */
#line 117 "main.y"
            {
    scope.append(new Operator(DataType::NUMBER, "+"));
}
#line 1380 "main.tab.c"
    break;

  case 33: /* add: LB ADD $@3 exp exps RB  */
#line 119 "main.y"
              {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-2].node));
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1391 "main.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 126 "main.y"
                  {
    scope.append(new Operator(DataType::NUMBER, "-"));
}
#line 1399 "main.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 128 "main.y"
      {
    scope.back()->append((yyvsp[0].node));
}
#line 1407 "main.tab.c"
    break;

  case 36: /* substract: LB SUB $@4 exp $@5 exp RB  */
#line 130 "main.y"
         {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1417 "main.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 136 "main.y"
                 {
    scope.append(new Operator(DataType::NUMBER, "*"));
}
#line 1425 "main.tab.c"
    break;

  case 38: /* multiply: LB MUL $@6 exp exps RB  */
#line 138 "main.y"
              {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-2].node));
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1436 "main.tab.c"
    break;

  case 39: /* $@7: %empty  */
#line 145 "main.y"
               {
    scope.append(new Operator(DataType::NUMBER, "/"));
}
#line 1444 "main.tab.c"
    break;

  case 40: /* $@8: %empty  */
#line 147 "main.y"
      {
    scope.back()->append((yyvsp[0].node));
}
#line 1452 "main.tab.c"
    break;

  case 41: /* divide: LB DIV $@7 exp $@8 exp RB  */
#line 149 "main.y"
         {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1462 "main.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 155 "main.y"
                {
    scope.append(new Operator(DataType::NUMBER, "%"));
}
#line 1470 "main.tab.c"
    break;

  case 43: /* $@10: %empty  */
#line 157 "main.y"
      {
    scope.back()->append((yyvsp[0].node));
}
#line 1478 "main.tab.c"
    break;

  case 44: /* modulus: LB MOD $@9 exp $@10 exp RB  */
#line 159 "main.y"
         {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1488 "main.tab.c"
    break;

  case 45: /* $@11: %empty  */
#line 165 "main.y"
               {
    scope.append(new Operator(DataType::BOOLEAN, ">"));
}
#line 1496 "main.tab.c"
    break;

  case 46: /* $@12: %empty  */
#line 167 "main.y"
      {
    scope.back()->append((yyvsp[0].node));
}
#line 1504 "main.tab.c"
    break;

  case 47: /* greater: LB GT $@11 exp $@12 exp RB  */
#line 169 "main.y"
         {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1514 "main.tab.c"
    break;

  case 48: /* $@13: %empty  */
#line 175 "main.y"
            {
    scope.append(new Operator(DataType::BOOLEAN, "<"));
}
#line 1522 "main.tab.c"
    break;

  case 49: /* $@14: %empty  */
#line 177 "main.y"
      {
    scope.back()->append((yyvsp[0].node));
}
#line 1530 "main.tab.c"
    break;

  case 50: /* less: LB LT $@13 exp $@14 exp RB  */
#line 179 "main.y"
         {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1540 "main.tab.c"
    break;

  case 51: /* $@15: %empty  */
#line 185 "main.y"
             {
    scope.append(new Operator(DataType::BOOLEAN, "=="));
}
#line 1548 "main.tab.c"
    break;

  case 52: /* equal: LB EQ $@15 exp exps RB  */
#line 187 "main.y"
              {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-2].node));
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1559 "main.tab.c"
    break;

  case 53: /* $@16: %empty  */
#line 194 "main.y"
               {
    scope.append(new Operator(DataType::BOOLEAN, "&&"));
}
#line 1567 "main.tab.c"
    break;

  case 54: /* and_op: LB AND $@16 exp exps RB  */
#line 196 "main.y"
              {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-2].node));
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1578 "main.tab.c"
    break;

  case 55: /* $@17: %empty  */
#line 203 "main.y"
             {
    scope.append(new Operator(DataType::BOOLEAN, "||"));
}
#line 1586 "main.tab.c"
    break;

  case 56: /* or_op: LB OR $@17 exp exps RB  */
#line 205 "main.y"
              {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-2].node));
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1597 "main.tab.c"
    break;

  case 57: /* $@18: %empty  */
#line 212 "main.y"
               {
    scope.append(new Operator(DataType::BOOLEAN, "!"));
}
#line 1605 "main.tab.c"
    break;

  case 58: /* not_op: LB NOT $@18 exp RB  */
#line 214 "main.y"
         {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1615 "main.tab.c"
    break;

  case 59: /* $@19: %empty  */
#line 220 "main.y"
              {
    scope.append(new Operator(DataType::DYNAMIC, "?:"));
}
#line 1623 "main.tab.c"
    break;

  case 60: /* $@20: %empty  */
#line 222 "main.y"
      {
    scope.back()->append((yyvsp[0].node));
}
#line 1631 "main.tab.c"
    break;

  case 61: /* $@21: %empty  */
#line 224 "main.y"
      {
    scope.back()->append((yyvsp[0].node));
}
#line 1639 "main.tab.c"
    break;

  case 62: /* if_exp: LB IF $@19 exp $@20 exp $@21 exp RB  */
#line 226 "main.y"
         {
    (yyval.opr) = (Operator*)scope.back();
    (yyval.opr)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1649 "main.tab.c"
    break;

  case 63: /* $@22: %empty  */
#line 232 "main.y"
                          {
    if (scope.find((yyvsp[0].obj)->name) != nullptr)
        throw runtime_error(("'" + (yyvsp[0].obj)->name + "' has already been defined.").c_str());
}
#line 1658 "main.tab.c"
    break;

  case 64: /* def_stmt: LB DEF variable $@22 exp RB  */
#line 235 "main.y"
         {
    Object* obj = Object::from_ast_node((yyvsp[-1].node));
    obj->name = (yyvsp[-3].obj)->name;
    scope.declare(obj);
}
#line 1668 "main.tab.c"
    break;

  case 65: /* variable: ID  */
#line 241 "main.y"
             {
    auto obj_p = scope.find(*(yyvsp[0].text));
    if (obj_p != nullptr) (yyval.obj) = obj_p;
    else (yyval.obj) = new Object(*(yyvsp[0].text));
}
#line 1678 "main.tab.c"
    break;

  case 66: /* $@23: %empty  */
#line 247 "main.y"
                   {
    scope.append(new Function());
}
#line 1686 "main.tab.c"
    break;

  case 67: /* fun_exp: LB FUN LB $@23 fun_ids RB fun_body RB  */
#line 249 "main.y"
                         {
    (yyval.fun_obj) = (Function*)scope.back();
    (yyval.fun_obj)->append((yyvsp[-1].node));
    scope.pop_back();
}
#line 1696 "main.tab.c"
    break;

  case 68: /* fun_ids: fun_ids ID  */
#line 255 "main.y"
                    {
    ((Function*)scope.back())->params.push_back(*(yyvsp[0].text));
}
#line 1704 "main.tab.c"
    break;

  case 70: /* fun_body: local_def_stmts exp  */
#line 259 "main.y"
                              {
    (yyval.node) = (yyvsp[0].node);
}
#line 1712 "main.tab.c"
    break;

  case 71: /* $@24: %empty  */
#line 263 "main.y"
                     {
    scope.append((yyvsp[0].fun_obj));
    int* param_index = new int(0);
    esp.push(param_index);
}
#line 1722 "main.tab.c"
    break;

  case 72: /* fun_call: LB fun_var $@24 params RB  */
#line 267 "main.y"
            {
    (yyval.fun_obj) = (Function*)scope.back();
    auto param_index = (int*)esp.top();
    if ((yyvsp[-1].node) != nullptr) {
        auto obj = Object::from_ast_node((yyvsp[-1].node));
        obj->name = (yyval.fun_obj)->params[(*param_index)++];
        scope.declare(obj);
    }
    delete param_index;
    esp.pop();
    scope.pop_back();
}
#line 1739 "main.tab.c"
    break;

  case 74: /* fun_var: fun_name  */
#line 280 "main.y"
                            { (yyval.fun_obj) = new Function(*(yyvsp[0].fun_obj)); }
#line 1745 "main.tab.c"
    break;

  case 75: /* params: params exp  */
#line 282 "main.y"
                   {
    auto func = (Function*)scope.back();
    auto param_index = (int*)esp.top();
    if ((yyvsp[-1].node) != nullptr) {
        auto obj = Object::from_ast_node((yyvsp[-1].node));
        obj->name = func->params[(*param_index)++];
        scope.declare(obj);
    }
    (yyval.node) = (yyvsp[0].node);
}
#line 1760 "main.tab.c"
    break;

  case 76: /* params: %empty  */
#line 291 "main.y"
    {
    (yyval.node) = nullptr;
}
#line 1768 "main.tab.c"
    break;

  case 77: /* fun_name: ID  */
#line 295 "main.y"
             {
    auto obj = scope.find(*(yyvsp[0].text));
    if (obj == nullptr)
        throw std::runtime_error("'" + *(yyvsp[0].text) + "' has not been defined.");
    (yyval.fun_obj) = (Function*)obj;
}
#line 1779 "main.tab.c"
    break;

  case 80: /* local_def_stmt: LB DEF variable exp RB  */
#line 304 "main.y"
                                       {}
#line 1785 "main.tab.c"
    break;


#line 1789 "main.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 306 "main.y"


void yyerror(const char* message) {
    throw runtime_error("syntax error.");
}

int main(int argc, char** argv) {
    try {
        yyparse();
        cout << py.exec() << "\n";
    } catch (const exception& e) {
        cout << e.what() << "\n";
    }
    return 0;
}
