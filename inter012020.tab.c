/* A Bison parser, made by GNU Bison 3.6.4.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "inter012020.y"

/* Inclusao de arquivos da biblioteca de C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao dos atributos dos atomos operadores */

#define 	LT 		    1
#define 	LE 	    	2
#define		GT			3
#define		GE			4
#define		EQ			5
#define		NE			6
#define		MAIS        7
#define		MENOS       8
#define		MULT    	9
#define		DIV   	    10
#define		RESTO   	11

/*   Definicao dos tipos de identificadores   */

#define 	IDPROG		1
#define 	IDVAR		2
#define     IDFUNC      3
#define     IDPROC      4

/*  Definicao dos tipos de variaveis   */

#define 	NOTVAR		0
#define 	INTEGER		1
#define 	LOGICAL		2
#define 	FLOAT		3
#define 	CHAR		4

/* Definicao de constantes para os operadores de quadruplas */

#define		OPOR			1
#define		OPAND	 		2
#define 	OPLT	 		3
#define 	OPLE	 		4
#define		OPGT		    5
#define		OPGE			6
#define		OPEQ			7
#define		OPNE			8
#define		OPMAIS		    9
#define		OPMENOS		    10
#define		OPMULTIP		11
#define		OPDIV			12
#define		OPRESTO		    13
#define		OPMENUN		    14
#define		OPNOT			15
#define		OPATRIB		    16
#define		OPENMOD		    17
#define		NOP			    18
#define		OPJUMP		    19
#define		OPJF			20

/* Definicao de constantes para os tipos de operandos de quadruplas */

#define		IDLEOPND		0
#define		VAROPND		    1
#define		INTOPND		    2
#define		REALOPND		3
#define		CHAROPND		4
#define		LOGICOPND	    5
#define		CADOPND		    6
#define		ROTOPND		    7
#define		MODOPND		    8

/*   Definicao de outras constantes   */

#define	    NCLASSHASH	23
#define     TRUE		1
#define     FALSE		0
#define     MAXDIMS		10

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[5] = {" ", "IDPROG", "IDVAR", "IDFUNC", "IDPROC"};

/*  Strings para nomes dos tipos de variaveis  */

char *nometipvar[5] = {"NOTVAR",
	"INTEGER", "LOGICAL", "FLOAT", "CHAR"
};

/* Strings para operadores de quadruplas */

char *nomeoperquad[21] = {"",
	"OR", "AND", "LT", "LE", "GT", "GE", "EQ", "NE", "MAIS",
	"MENOS", "MULT", "DIV", "RESTO", "MENUN", "NOT", "ATRIB",
	"OPENMOD", "NOP", "JUMP", "JF"
};

/*
	Strings para tipos de operandos de quadruplas
 */

char *nometipoopndquad[9] = {"IDLE",
	"VAR", "INT", "REAL", "CARAC", "LOGIC", "CADEIA", "ROTULO", "MODULO"
};

/*    Declaracoes para a tabela de simbolos     */

typedef struct celsimb celsimb;
typedef celsimb *simbolo;
struct celsimb {
	char *cadeia;
	int tid, tvar, ndims, dims[MAXDIMS+1];
	char inic, ref, array;
	simbolo prox;
};

/*  Variaveis globais para a tabela de simbolos e analise semantica */

simbolo tabsimb[NCLASSHASH];
simbolo simb;
int tipocorrente;

/*
	Prototipos das funcoes para a tabela de simbolos
    	e analise semantica
 */

void InicTabSimb (void);
void ImprimeTabSimb (void);
simbolo InsereSimb (char *, int, int);
int hash (char *);
simbolo ProcuraSimb (char *);
void VerificaInicRef (void);
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);
void Incompatibilidade (char *);
void Esperado (char *);
void NaoEsperado (char *);

/* Declaracoes para a estrutura do codigo intermediario */

typedef union atribopnd atribopnd;
typedef struct operando operando;
typedef struct celquad celquad;
typedef celquad *quadrupla;
typedef struct celmodhead celmodhead;
typedef celmodhead *modhead;

union atribopnd {
	simbolo simb; int valint; float valfloat;
	char valchar; char vallogic; char *valcad;
	quadrupla rotulo; modhead modulo;
};

struct operando {
	int tipo; atribopnd atr;
};

struct celquad {
	int num, oper; operando opnd1, opnd2, result;
	quadrupla prox;
};

struct celmodhead {
	simbolo modname; modhead prox;
	quadrupla listquad;
};

/* Variaveis globais para o codigo intermediario */

quadrupla quadcorrente, quadaux;
modhead codintermed, modcorrente;
int oper, numquadcorrente;
operando opnd1, opnd2, result, opndaux;
int numtemp;
const operando opndidle = {IDLEOPND, 0};

/* Prototipos das funcoes para o codigo intermediario */

void InicCodIntermed (void);
void InicCodIntermMod (simbolo);
void ImprimeQuadruplas (void);
quadrupla GeraQuadrupla (int, operando, operando, operando);
simbolo NovaTemp (int);
void RenumQuadruplas (quadrupla, quadrupla);

/* Declaracoes para atributos das expressoes e variaveis */

typedef struct infoexpressao infoexpressao;
struct infoexpressao {
	int tipo;
	operando opnd;
};

typedef struct infovariavel infovariavel;
struct infovariavel {
	simbolo simb;
	operando opnd;
};


#line 273 "inter012020.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    CTCARAC = 259,                 /* CTCARAC  */
    CADEIA = 260,                  /* CADEIA  */
    CTINT = 261,                   /* CTINT  */
    CTREAL = 262,                  /* CTREAL  */
    OR = 263,                      /* OR  */
    AND = 264,                     /* AND  */
    NOT = 265,                     /* NOT  */
    OPREL = 266,                   /* OPREL  */
    OPAD = 267,                    /* OPAD  */
    OPMULT = 268,                  /* OPMULT  */
    NEG = 269,                     /* NEG  */
    ABPAR = 270,                   /* ABPAR  */
    FPAR = 271,                    /* FPAR  */
    ABCHAV = 272,                  /* ABCHAV  */
    FCHAV = 273,                   /* FCHAV  */
    ABCOL = 274,                   /* ABCOL  */
    FCOL = 275,                    /* FCOL  */
    ABTRIP = 276,                  /* ABTRIP  */
    FTRIP = 277,                   /* FTRIP  */
    VIRG = 278,                    /* VIRG  */
    PVIRG = 279,                   /* PVIRG  */
    ATRIB = 280,                   /* ATRIB  */
    CARAC = 281,                   /* CARAC  */
    COMANDOS = 282,                /* COMANDOS  */
    ENQUANTO = 283,                /* ENQUANTO  */
    ESCREVER = 284,                /* ESCREVER  */
    FALSO = 285,                   /* FALSO  */
    INT = 286,                     /* INT  */
    LER = 287,                     /* LER  */
    LOGIC = 288,                   /* LOGIC  */
    PROGRAMA = 289,                /* PROGRAMA  */
    REAL = 290,                    /* REAL  */
    SE = 291,                      /* SE  */
    SENAO = 292,                   /* SENAO  */
    VAR = 293,                     /* VAR  */
    VERDADE = 294,                 /* VERDADE  */
    INVAL = 295                    /* INVAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 205 "inter012020.y"

	char cadeia[50];
	int atr, valint;
	float valreal;
	char carac;
	simbolo simb;
	infoexpressao infoexpr;
	infovariavel infovar;
	int nsubscr;

#line 371 "inter012020.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_CTCARAC = 4,                    /* CTCARAC  */
  YYSYMBOL_CADEIA = 5,                     /* CADEIA  */
  YYSYMBOL_CTINT = 6,                      /* CTINT  */
  YYSYMBOL_CTREAL = 7,                     /* CTREAL  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_NOT = 10,                       /* NOT  */
  YYSYMBOL_OPREL = 11,                     /* OPREL  */
  YYSYMBOL_OPAD = 12,                      /* OPAD  */
  YYSYMBOL_OPMULT = 13,                    /* OPMULT  */
  YYSYMBOL_NEG = 14,                       /* NEG  */
  YYSYMBOL_ABPAR = 15,                     /* ABPAR  */
  YYSYMBOL_FPAR = 16,                      /* FPAR  */
  YYSYMBOL_ABCHAV = 17,                    /* ABCHAV  */
  YYSYMBOL_FCHAV = 18,                     /* FCHAV  */
  YYSYMBOL_ABCOL = 19,                     /* ABCOL  */
  YYSYMBOL_FCOL = 20,                      /* FCOL  */
  YYSYMBOL_ABTRIP = 21,                    /* ABTRIP  */
  YYSYMBOL_FTRIP = 22,                     /* FTRIP  */
  YYSYMBOL_VIRG = 23,                      /* VIRG  */
  YYSYMBOL_PVIRG = 24,                     /* PVIRG  */
  YYSYMBOL_ATRIB = 25,                     /* ATRIB  */
  YYSYMBOL_CARAC = 26,                     /* CARAC  */
  YYSYMBOL_COMANDOS = 27,                  /* COMANDOS  */
  YYSYMBOL_ENQUANTO = 28,                  /* ENQUANTO  */
  YYSYMBOL_ESCREVER = 29,                  /* ESCREVER  */
  YYSYMBOL_FALSO = 30,                     /* FALSO  */
  YYSYMBOL_INT = 31,                       /* INT  */
  YYSYMBOL_LER = 32,                       /* LER  */
  YYSYMBOL_LOGIC = 33,                     /* LOGIC  */
  YYSYMBOL_PROGRAMA = 34,                  /* PROGRAMA  */
  YYSYMBOL_REAL = 35,                      /* REAL  */
  YYSYMBOL_SE = 36,                        /* SE  */
  YYSYMBOL_SENAO = 37,                     /* SENAO  */
  YYSYMBOL_VAR = 38,                       /* VAR  */
  YYSYMBOL_VERDADE = 39,                   /* VERDADE  */
  YYSYMBOL_INVAL = 40,                     /* INVAL  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Prog = 42,                      /* Prog  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_Decls = 45,                     /* Decls  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_ListDecl = 47,                  /* ListDecl  */
  YYSYMBOL_Declaracao = 48,                /* Declaracao  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_Tipo = 50,                      /* Tipo  */
  YYSYMBOL_ListElem = 51,                  /* ListElem  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_Elem = 53,                      /* Elem  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_Dims = 55,                      /* Dims  */
  YYSYMBOL_56_7 = 56,                      /* $@7  */
  YYSYMBOL_ListDim = 57,                   /* ListDim  */
  YYSYMBOL_Comandos = 58,                  /* Comandos  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_CmdComp = 60,                   /* CmdComp  */
  YYSYMBOL_61_9 = 61,                      /* $@9  */
  YYSYMBOL_ListCmd = 62,                   /* ListCmd  */
  YYSYMBOL_Comando = 63,                   /* Comando  */
  YYSYMBOL_CmdSe = 64,                     /* CmdSe  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_67_12 = 67,                     /* $@12  */
  YYSYMBOL_CmdSenao = 68,                  /* CmdSenao  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_CmdEnquanto = 70,               /* CmdEnquanto  */
  YYSYMBOL_71_14 = 71,                     /* $@14  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_73_16 = 73,                     /* $@16  */
  YYSYMBOL_CmdLer = 74,                    /* CmdLer  */
  YYSYMBOL_75_17 = 75,                     /* $@17  */
  YYSYMBOL_ListLeit = 76,                  /* ListLeit  */
  YYSYMBOL_77_18 = 77,                     /* $@18  */
  YYSYMBOL_CmdEscrever = 78,               /* CmdEscrever  */
  YYSYMBOL_79_19 = 79,                     /* $@19  */
  YYSYMBOL_ListEscr = 80,                  /* ListEscr  */
  YYSYMBOL_81_20 = 81,                     /* $@20  */
  YYSYMBOL_ElemEscr = 82,                  /* ElemEscr  */
  YYSYMBOL_CmdAtrib = 83,                  /* CmdAtrib  */
  YYSYMBOL_84_21 = 84,                     /* $@21  */
  YYSYMBOL_85_22 = 85,                     /* $@22  */
  YYSYMBOL_Expressao = 86,                 /* Expressao  */
  YYSYMBOL_87_23 = 87,                     /* $@23  */
  YYSYMBOL_ExprAux1 = 88,                  /* ExprAux1  */
  YYSYMBOL_89_24 = 89,                     /* $@24  */
  YYSYMBOL_ExprAux2 = 90,                  /* ExprAux2  */
  YYSYMBOL_91_25 = 91,                     /* $@25  */
  YYSYMBOL_ExprAux3 = 92,                  /* ExprAux3  */
  YYSYMBOL_93_26 = 93,                     /* $@26  */
  YYSYMBOL_ExprAux4 = 94,                  /* ExprAux4  */
  YYSYMBOL_95_27 = 95,                     /* $@27  */
  YYSYMBOL_Termo = 96,                     /* Termo  */
  YYSYMBOL_97_28 = 97,                     /* $@28  */
  YYSYMBOL_Fator = 98,                     /* Fator  */
  YYSYMBOL_99_29 = 99,                     /* $@29  */
  YYSYMBOL_100_30 = 100,                   /* $@30  */
  YYSYMBOL_Variavel = 101,                 /* Variavel  */
  YYSYMBOL_102_31 = 102,                   /* @31  */
  YYSYMBOL_Subscritos = 103,               /* Subscritos  */
  YYSYMBOL_104_32 = 104,                   /* $@32  */
  YYSYMBOL_ListSubscr = 105,               /* ListSubscr  */
  YYSYMBOL_106_33 = 106                    /* $@33  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   266,   266,   267,   266,   283,   284,   284,   287,   287,
     289,   289,   292,   293,   294,   295,   297,   297,   297,   299,
     299,   309,   310,   310,   316,   321,   327,   327,   329,   329,
     332,   333,   335,   335,   335,   335,   336,   336,   338,   338,
     341,   338,   343,   344,   344,   346,   346,   349,   346,   351,
     351,   354,   355,   355,   357,   357,   360,   360,   360,   362,
     362,   364,   365,   364,   376,   376,   376,   382,   382,   382,
     388,   388,   388,   394,   395,   395,   418,   419,   419,   431,
     432,   432,   456,   463,   464,   465,   466,   467,   468,   468,
     478,   478,   481,   481,   502,   503,   503,   509,   514,   514
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "CTCARAC",
  "CADEIA", "CTINT", "CTREAL", "OR", "AND", "NOT", "OPREL", "OPAD",
  "OPMULT", "NEG", "ABPAR", "FPAR", "ABCHAV", "FCHAV", "ABCOL", "FCOL",
  "ABTRIP", "FTRIP", "VIRG", "PVIRG", "ATRIB", "CARAC", "COMANDOS",
  "ENQUANTO", "ESCREVER", "FALSO", "INT", "LER", "LOGIC", "PROGRAMA",
  "REAL", "SE", "SENAO", "VAR", "VERDADE", "INVAL", "$accept", "Prog",
  "$@1", "$@2", "Decls", "$@3", "ListDecl", "Declaracao", "$@4", "Tipo",
  "ListElem", "$@5", "Elem", "$@6", "Dims", "$@7", "ListDim", "Comandos",
  "$@8", "CmdComp", "$@9", "ListCmd", "Comando", "CmdSe", "$@10", "$@11",
  "$@12", "CmdSenao", "$@13", "CmdEnquanto", "$@14", "$@15", "$@16",
  "CmdLer", "$@17", "ListLeit", "$@18", "CmdEscrever", "$@19", "ListEscr",
  "$@20", "ElemEscr", "CmdAtrib", "$@21", "$@22", "Expressao", "$@23",
  "ExprAux1", "$@24", "ExprAux2", "$@25", "ExprAux3", "$@26", "ExprAux4",
  "$@27", "Termo", "$@28", "Fator", "$@29", "$@30", "Variavel", "@31",
  "Subscritos", "$@32", "ListSubscr", "$@33", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -123,     3,   -27,  -123,    10,     2,  -123,     1,    24,    20,
    -123,  -123,    27,    25,    40,  -123,  -123,  -123,  -123,  -123,
      54,  -123,    52,  -123,  -123,  -123,  -123,  -123,  -123,    67,
      45,  -123,    15,  -123,  -123,  -123,    71,    73,    77,    79,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    63,  -123,
    -123,    76,  -123,  -123,  -123,  -123,    72,  -123,  -123,    67,
    -123,  -123,    22,     5,    93,    22,  -123,    92,  -123,    39,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    94,    91,
    -123,  -123,     6,    88,  -123,  -123,  -123,    43,  -123,    94,
      68,  -123,    94,    22,  -123,    48,    95,    70,    39,    39,
      22,  -123,    87,  -123,  -123,  -123,  -123,    80,  -123,    81,
    -123,    96,    -2,  -123,   102,  -123,  -123,  -123,  -123,     8,
      22,  -123,    22,    39,    39,    39,  -123,     5,  -123,    93,
    -123,  -123,  -123,    39,  -123,    91,    47,  -123,    95,    88,
    -123,  -123,  -123,    47,    95,  -123,    74,  -123,  -123,    47,
    -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     5,     0,     0,
       6,    26,     0,     0,     0,     4,    14,    12,    15,    13,
       0,     8,     0,    28,    27,     7,     9,    10,    30,     0,
       0,    19,     0,    16,    92,    29,     0,     0,     0,     0,
      32,    31,    33,    34,    35,    36,    37,    61,    21,    11,
      17,    94,    45,    54,    49,    38,     0,    22,    20,     0,
      95,    93,     0,     0,     0,     0,    62,     0,    18,     0,
      85,    83,    84,    71,    88,    90,    87,    86,    46,    64,
      67,    70,    73,    76,    79,    82,    59,     0,    56,    60,
       0,    51,    39,     0,    24,     0,    97,     0,     0,     0,
       0,    65,     0,    68,    74,    77,    80,     0,    57,     0,
      52,     0,     0,    23,     0,    96,    98,    72,    89,     0,
       0,    47,     0,     0,     0,     0,    55,     0,    50,     0,
      40,    63,    25,     0,    91,    66,     0,    69,    75,    78,
      81,    58,    53,     0,    99,    48,    42,    43,    41,     0,
      44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,  -123,  -123,    89,  -123,  -123,
    -123,  -123,    51,  -123,  -123,  -123,  -123,  -123,  -123,   100,
    -123,  -123,  -122,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,   -12,  -123,  -123,  -123,   -60,  -123,    -4,  -123,    -5,
    -123,    23,  -123,   -68,  -123,    -6,  -123,   -95,  -123,  -123,
     -30,  -123,  -123,  -123,  -123,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     9,    13,    20,    21,    29,    22,
      32,    59,    33,    48,    58,    67,    95,    12,    14,    40,
      28,    30,    41,    42,    65,   111,   143,   148,   149,    43,
      62,   102,   136,    44,    64,    90,   129,    45,    63,    87,
     127,    88,    46,    56,    93,    89,   120,    79,   122,    80,
      98,    81,   123,    82,   124,    83,   125,    84,    99,   100,
      85,    51,    61,    69,    97,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    96,    78,     3,   118,    92,   101,     4,    34,    70,
      86,    71,    72,     5,   145,    73,   101,   104,   105,    74,
      75,   146,   131,     6,   134,    34,    70,   150,    71,    72,
     140,    49,    73,   112,    91,    76,    74,    75,    50,     8,
     119,    10,    34,    70,    77,    71,    72,    11,    34,    15,
      34,    16,    76,    74,    75,   138,    17,    23,    18,   107,
      19,    77,    23,    35,    23,   144,   108,    27,   113,    76,
      31,   114,    25,    36,    37,    36,    37,    38,    77,    38,
      16,    39,    57,    39,   109,    17,    52,    18,    53,    19,
     115,   110,    54,   116,    55,    60,    34,    66,    94,   142,
     103,   106,   101,   121,   126,   128,    47,   105,   132,    26,
      68,   147,   130,    47,    24,   141,   135,   137,   139,    47,
       0,   117
};

static const yytype_int16 yycheck[] =
{
      30,    69,    62,     0,    99,    65,     8,    34,     3,     4,
       5,     6,     7,     3,   136,    10,     8,    11,    12,    14,
      15,   143,    24,    21,    16,     3,     4,   149,     6,     7,
     125,    16,    10,    93,    64,    30,    14,    15,    23,    38,
     100,    17,     3,     4,    39,     6,     7,    27,     3,    22,
       3,    26,    30,    14,    15,   123,    31,    17,    33,    16,
      35,    39,    17,    18,    17,   133,    23,    15,    20,    30,
       3,    23,    18,    28,    29,    28,    29,    32,    39,    32,
      26,    36,    19,    36,    16,    31,    15,    33,    15,    35,
      20,    23,    15,    23,    15,    19,     3,    25,     6,   129,
       9,    13,     8,    16,    24,    24,   136,    12,     6,    20,
      59,    37,    16,   143,    14,   127,   120,   122,   124,   149,
      -1,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,    34,     3,    21,    44,    38,    45,
      17,    27,    58,    46,    59,    22,    26,    31,    33,    35,
      47,    48,    50,    17,    60,    18,    48,    15,    61,    49,
      62,     3,    51,    53,     3,    18,    28,    29,    32,    36,
      60,    63,    64,    70,    74,    78,    83,   101,    54,    16,
      23,   102,    15,    15,    15,    15,    84,    19,    55,    52,
      19,   103,    71,    79,    75,    65,    25,    56,    53,   104,
       4,     6,     7,    10,    14,    15,    30,    39,    86,    88,
      90,    92,    94,    96,    98,   101,     5,    80,    82,    86,
      76,   101,    86,    85,     6,    57,    94,   105,    91,    99,
     100,     8,    72,     9,    11,    12,    13,    16,    23,    16,
      23,    66,    86,    20,    23,    20,    23,    92,    98,    86,
      87,    16,    89,    93,    95,    97,    24,    81,    24,    77,
      16,    24,     6,   106,    16,    88,    73,    90,    94,    96,
      98,    82,   101,    67,    94,    63,    63,    37,    68,    69,
      63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    44,    42,    45,    46,    45,    47,    47,
      49,    48,    50,    50,    50,    50,    51,    52,    51,    54,
      53,    55,    56,    55,    57,    57,    59,    58,    61,    60,
      62,    62,    63,    63,    63,    63,    63,    63,    65,    66,
      67,    64,    68,    69,    68,    71,    72,    73,    70,    75,
      74,    76,    77,    76,    79,    78,    80,    81,    80,    82,
      82,    84,    85,    83,    86,    87,    86,    88,    89,    88,
      90,    91,    90,    92,    93,    92,    94,    95,    94,    96,
      97,    96,    98,    98,    98,    98,    98,    98,    99,    98,
     100,    98,   102,   101,   103,   104,   103,   105,   106,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     0,     5,     1,     2,
       0,     5,     1,     1,     1,     1,     1,     0,     4,     0,
       3,     0,     0,     4,     1,     3,     0,     3,     0,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     0,     0,
       0,     9,     0,     0,     3,     0,     0,     0,     8,     0,
       6,     1,     0,     4,     0,     6,     1,     0,     4,     1,
       1,     0,     0,     6,     1,     0,     4,     1,     0,     4,
       1,     0,     3,     1,     0,     4,     1,     0,     4,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     4,     0,     3,     0,     0,     4,     1,     0,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
  case 2:
#line 266 "inter012020.y"
                                {InicTabSimb (); InicCodIntermed(); numtemp = 0;}
#line 1576 "inter012020.tab.c"
    break;

  case 3:
#line 267 "inter012020.y"
                    {
                        printf ("programa %s {{{\n", (yyvsp[-1].cadeia)); 
                        simb = InsereSimb ((yyvsp[-1].cadeia), IDPROG, NOTVAR);
                        InicCodIntermMod(simb);
                        opnd1.tipo = MODOPND;
                        opnd1.atr.modulo = modcorrente;
                        GeraQuadrupla(OPENMOD, opnd1, opndidle, opndidle);
                    }
#line 1589 "inter012020.tab.c"
    break;

  case 4:
#line 276 "inter012020.y"
                    {
                        printf ("}}}\n");
                        VerificaInicRef ();
                        ImprimeTabSimb ();
                        ImprimeQuadruplas();
                    }
#line 1600 "inter012020.tab.c"
    break;

  case 6:
#line 284 "inter012020.y"
                                 {printf ("var {\n");}
#line 1606 "inter012020.tab.c"
    break;

  case 7:
#line 285 "inter012020.y"
                           {printf ("}\n");}
#line 1612 "inter012020.tab.c"
    break;

  case 10:
#line 289 "inter012020.y"
                                     {printf ("( ");}
#line 1618 "inter012020.tab.c"
    break;

  case 11:
#line 290 "inter012020.y"
                          {printf (")\n");}
#line 1624 "inter012020.tab.c"
    break;

  case 12:
#line 292 "inter012020.y"
                                     {printf ("int "); tipocorrente = INTEGER;}
#line 1630 "inter012020.tab.c"
    break;

  case 13:
#line 293 "inter012020.y"
                          {printf ("real "); tipocorrente = FLOAT;}
#line 1636 "inter012020.tab.c"
    break;

  case 14:
#line 294 "inter012020.y"
                           {printf ("carac "); tipocorrente = CHAR;}
#line 1642 "inter012020.tab.c"
    break;

  case 15:
#line 295 "inter012020.y"
                           {printf ("logic "); tipocorrente = LOGICAL;}
#line 1648 "inter012020.tab.c"
    break;

  case 17:
#line 297 "inter012020.y"
                                                 {printf (", ");}
#line 1654 "inter012020.tab.c"
    break;

  case 19:
#line 299 "inter012020.y"
                            {
                        printf ("%s ", (yyvsp[0].cadeia));
                        if  (ProcuraSimb ((yyvsp[0].cadeia))  !=  NULL)
                            DeclaracaoRepetida ((yyvsp[0].cadeia));
                        else {
                            simb = InsereSimb ((yyvsp[0].cadeia),  IDVAR,  tipocorrente);
                            simb->array = FALSE; simb->ndims = 0;
                        }
                    }
#line 1668 "inter012020.tab.c"
    break;

  case 22:
#line 310 "inter012020.y"
                           {printf ("[ ");}
#line 1674 "inter012020.tab.c"
    break;

  case 23:
#line 311 "inter012020.y"
                          {
                        printf ("] ");
                        simb->array = TRUE;
                    }
#line 1683 "inter012020.tab.c"
    break;

  case 24:
#line 316 "inter012020.y"
                                {
                        printf ("%d ", (yyvsp[0].valint));
                        if ((yyvsp[0].valint) <= 0) Esperado ("Valor inteiro positivo");
                        simb->ndims++; simb->dims[simb->ndims] = (yyvsp[0].valint);
                    }
#line 1693 "inter012020.tab.c"
    break;

  case 25:
#line 321 "inter012020.y"
                                             {
                        printf (", %d ", (yyvsp[0].valint));
                        if ((yyvsp[0].valint) <= 0) Esperado ("Valor inteiro positivo");
                        simb->ndims++; simb->dims[simb->ndims] = (yyvsp[0].valint);
                    }
#line 1703 "inter012020.tab.c"
    break;

  case 26:
#line 327 "inter012020.y"
                              {printf ("comandos ");}
#line 1709 "inter012020.tab.c"
    break;

  case 28:
#line 329 "inter012020.y"
                                    {printf ("{\n");}
#line 1715 "inter012020.tab.c"
    break;

  case 29:
#line 330 "inter012020.y"
                    {printf ("}\n");}
#line 1721 "inter012020.tab.c"
    break;

  case 38:
#line 338 "inter012020.y"
                                     {printf ("se ( ");}
#line 1727 "inter012020.tab.c"
    break;

  case 39:
#line 338 "inter012020.y"
                                                                     {
                        if ((yyvsp[0].infoexpr).tipo != LOGICAL)
                            Incompatibilidade ("Expressao nao logica em comando se");
                    }
#line 1736 "inter012020.tab.c"
    break;

  case 40:
#line 341 "inter012020.y"
                             {printf (")\n");}
#line 1742 "inter012020.tab.c"
    break;

  case 43:
#line 344 "inter012020.y"
                           {printf ("senao\n");}
#line 1748 "inter012020.tab.c"
    break;

  case 45:
#line 346 "inter012020.y"
                                         {printf ("enquanto ( ");}
#line 1754 "inter012020.tab.c"
    break;

  case 46:
#line 346 "inter012020.y"
                                                                               {
                        if ((yyvsp[0].infoexpr).tipo != LOGICAL)
                            Incompatibilidade ("Expressao nao logica em comando enquanto");
                    }
#line 1763 "inter012020.tab.c"
    break;

  case 47:
#line 349 "inter012020.y"
                             {printf (")\n");}
#line 1769 "inter012020.tab.c"
    break;

  case 49:
#line 351 "inter012020.y"
                                    {printf ("ler ( ");}
#line 1775 "inter012020.tab.c"
    break;

  case 50:
#line 352 "inter012020.y"
                    {printf (") ;\n");}
#line 1781 "inter012020.tab.c"
    break;

  case 51:
#line 354 "inter012020.y"
                                      {if  ((yyvsp[0].infovar).simb != NULL) (yyvsp[0].infovar).simb->inic = (yyvsp[0].infovar).simb->ref = TRUE;}
#line 1787 "inter012020.tab.c"
    break;

  case 52:
#line 355 "inter012020.y"
                                    {printf (", ");}
#line 1793 "inter012020.tab.c"
    break;

  case 53:
#line 355 "inter012020.y"
                                                                {if  ((yyvsp[0].infovar).simb != NULL) (yyvsp[0].infovar).simb->inic = (yyvsp[0].infovar).simb->ref = TRUE;}
#line 1799 "inter012020.tab.c"
    break;

  case 54:
#line 357 "inter012020.y"
                                         {printf ("escrever ( ");}
#line 1805 "inter012020.tab.c"
    break;

  case 55:
#line 358 "inter012020.y"
                           {printf (") ;\n");}
#line 1811 "inter012020.tab.c"
    break;

  case 57:
#line 360 "inter012020.y"
                                                             {printf (", ");}
#line 1817 "inter012020.tab.c"
    break;

  case 59:
#line 362 "inter012020.y"
                                    {printf ("\"%s\" ", (yyvsp[0].cadeia));}
#line 1823 "inter012020.tab.c"
    break;

  case 61:
#line 364 "inter012020.y"
                              {if  ((yyvsp[0].infovar).simb != NULL) (yyvsp[0].infovar).simb->inic = (yyvsp[0].infovar).simb->ref = TRUE;}
#line 1829 "inter012020.tab.c"
    break;

  case 62:
#line 365 "inter012020.y"
                           {printf ("= ");}
#line 1835 "inter012020.tab.c"
    break;

  case 63:
#line 366 "inter012020.y"
                    {
                        printf (";\n");
                        if ((yyvsp[-5].infovar).simb != NULL)
                            if ((((yyvsp[-5].infovar).simb->tvar == INTEGER || (yyvsp[-5].infovar).simb->tvar == CHAR) &&
                                ((yyvsp[-1].infoexpr).tipo == FLOAT || (yyvsp[-1].infoexpr).tipo == LOGICAL)) ||
                                ((yyvsp[-5].infovar).simb->tvar == FLOAT && (yyvsp[-1].infoexpr).tipo == LOGICAL) ||
                                ((yyvsp[-5].infovar).simb->tvar == LOGICAL && (yyvsp[-1].infoexpr).tipo != LOGICAL))
                                Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                    }
#line 1849 "inter012020.tab.c"
    break;

  case 65:
#line 376 "inter012020.y"
                                                {printf ("|| ");}
#line 1855 "inter012020.tab.c"
    break;

  case 66:
#line 376 "inter012020.y"
                                                                             {
                        if ((yyvsp[-3].infoexpr).tipo != LOGICAL || (yyvsp[0].infoexpr).tipo != LOGICAL)
                            Incompatibilidade ("Operando improprio para operador or");
                        (yyval.infoexpr).tipo = LOGICAL;
                    }
#line 1865 "inter012020.tab.c"
    break;

  case 68:
#line 382 "inter012020.y"
                                                {printf ("&& ");}
#line 1871 "inter012020.tab.c"
    break;

  case 69:
#line 382 "inter012020.y"
                                                                             {
                        if ((yyvsp[-3].infoexpr).tipo != LOGICAL || (yyvsp[0].infoexpr).tipo != LOGICAL)
                            Incompatibilidade ("Operando improprio para operador and");
                        (yyval.infoexpr).tipo = LOGICAL;
                    }
#line 1881 "inter012020.tab.c"
    break;

  case 71:
#line 388 "inter012020.y"
                                      {printf ("! ");}
#line 1887 "inter012020.tab.c"
    break;

  case 72:
#line 388 "inter012020.y"
                                                                  {
                        if ((yyvsp[0].infoexpr).tipo != LOGICAL)
                            Incompatibilidade ("Operando improprio para operador not");
                        (yyval.infoexpr).tipo = LOGICAL;
                    }
#line 1897 "inter012020.tab.c"
    break;

  case 74:
#line 395 "inter012020.y"
                                     {
                        switch ((yyvsp[0].atr)) {
                            case LT: printf ("< "); break;
                            case LE: printf ("<= "); break;
                            case EQ: printf ("== "); break;
                            case NE: printf ("!= "); break;
                            case GT: printf ("> "); break;
                            case GE: printf (">= "); break;
                        }
                    }
#line 1912 "inter012020.tab.c"
    break;

  case 75:
#line 404 "inter012020.y"
                                 {
                        switch ((yyvsp[-2].atr)) {
                            case LT: case LE: case GT: case GE:
                                if ((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != FLOAT && (yyvsp[-3].infoexpr).tipo != CHAR || (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != FLOAT && (yyvsp[0].infoexpr).tipo != CHAR)
                                    Incompatibilidade	("Operando improprio para operador relacional");
                                break;
                            case EQ: case NE:
                                if (((yyvsp[-3].infoexpr).tipo == LOGICAL || (yyvsp[0].infoexpr).tipo == LOGICAL) && (yyvsp[-3].infoexpr).tipo != (yyvsp[0].infoexpr).tipo)
                                    Incompatibilidade ("Operando improprio para operador relacional");
                                break;
                        }
                        (yyval.infoexpr).tipo = LOGICAL;
                    }
#line 1930 "inter012020.tab.c"
    break;

  case 77:
#line 419 "inter012020.y"
                                    {
                        switch ((yyvsp[0].atr)) {
                            case MAIS: printf ("+ "); break;
                            case MENOS: printf ("- "); break;
                        }
                    }
#line 1941 "inter012020.tab.c"
    break;

  case 78:
#line 424 "inter012020.y"
                              {
                        if ((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != FLOAT && (yyvsp[-3].infoexpr).tipo != CHAR || (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo!=FLOAT && (yyvsp[0].infoexpr).tipo!=CHAR)
                            Incompatibilidade ("Operando improprio para operador aritmetico");
                        if ((yyvsp[-3].infoexpr).tipo == FLOAT || (yyvsp[0].infoexpr).tipo == FLOAT) (yyval.infoexpr).tipo = FLOAT;
                        else (yyval.infoexpr).tipo = INTEGER;
                    }
#line 1952 "inter012020.tab.c"
    break;

  case 80:
#line 432 "inter012020.y"
                                   {
                        switch ((yyvsp[0].atr)) {
                            case MULT: printf ("* "); break;
                            case DIV: printf ("/ "); break;
                            case RESTO: printf ("%% "); break;
                        }
                    }
#line 1964 "inter012020.tab.c"
    break;

  case 81:
#line 438 "inter012020.y"
                              {
                        switch ((yyvsp[-2].atr)) {
                            case MULT: case DIV:
                                if ((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != FLOAT && (yyvsp[-3].infoexpr).tipo != CHAR
                                    || (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo!=FLOAT && (yyvsp[0].infoexpr).tipo!=CHAR)
                                    Incompatibilidade ("Operando improprio para operador aritmetico");
                                if ((yyvsp[-3].infoexpr).tipo == FLOAT || (yyvsp[0].infoexpr).tipo == FLOAT) (yyval.infoexpr).tipo = FLOAT;
                                else (yyval.infoexpr).tipo = INTEGER;
                                break;
                            case RESTO:
                                if ((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != CHAR
                                    ||  (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                                    Incompatibilidade ("Operando improprio para operador resto");
                                (yyval.infoexpr).tipo = INTEGER;
                                break;
                        }
                    }
#line 1986 "inter012020.tab.c"
    break;

  case 82:
#line 456 "inter012020.y"
                                  {
                        if  ((yyvsp[0].infovar).simb != NULL) {
                            (yyvsp[0].infovar).simb->ref  =  TRUE;
                            (yyval.infoexpr).tipo = (yyvsp[0].infovar).simb->tvar;
                            (yyval.infoexpr).opnd = (yyvsp[0].infovar).opnd;
                        }
                    }
#line 1998 "inter012020.tab.c"
    break;

  case 83:
#line 463 "inter012020.y"
                           {printf ("%d ", (yyvsp[0].valint)); (yyval.infoexpr).tipo = INTEGER; (yyval.infoexpr).opnd.tipo = INTOPND; (yyval.infoexpr).opnd.atr.valint = (yyvsp[0].valint);}
#line 2004 "inter012020.tab.c"
    break;

  case 84:
#line 464 "inter012020.y"
                            {printf ("%g ", (yyvsp[0].valreal)); (yyval.infoexpr).tipo = FLOAT; (yyval.infoexpr).opnd.tipo = REALOPND; (yyval.infoexpr).opnd.atr.valfloat = (yyvsp[0].valreal);}
#line 2010 "inter012020.tab.c"
    break;

  case 85:
#line 465 "inter012020.y"
                             {printf ("\'%c\' ", (yyvsp[0].carac)); (yyval.infoexpr).tipo = CHAR; (yyval.infoexpr).opnd.tipo = CHAROPND; (yyval.infoexpr).opnd.atr.valchar = (yyvsp[0].carac);}
#line 2016 "inter012020.tab.c"
    break;

  case 86:
#line 466 "inter012020.y"
                             {printf ("verdade "); (yyval.infoexpr).tipo = LOGICAL; (yyval.infoexpr).opnd.tipo = LOGICOPND; (yyval.infoexpr).opnd.atr.vallogic = 1;}
#line 2022 "inter012020.tab.c"
    break;

  case 87:
#line 467 "inter012020.y"
                           {printf ("falso "); (yyval.infoexpr).tipo = LOGICAL; (yyval.infoexpr).opnd.tipo = LOGICOPND; (yyval.infoexpr).opnd.atr.vallogic = 0;}
#line 2028 "inter012020.tab.c"
    break;

  case 88:
#line 468 "inter012020.y"
                         {printf ("~ ");}
#line 2034 "inter012020.tab.c"
    break;

  case 89:
#line 468 "inter012020.y"
                                                  {
                        if ((yyvsp[0].infoexpr).tipo != INTEGER &&
                            (yyvsp[0].infoexpr).tipo != FLOAT && (yyvsp[0].infoexpr).tipo != CHAR)
                            Incompatibilidade  ("Operando improprio para menos unario");
                            if ((yyvsp[0].infoexpr).tipo == FLOAT) (yyval.infoexpr).tipo = FLOAT;
                            else (yyval.infoexpr).tipo = INTEGER;
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                            GeraQuadrupla(OPMENUN, (yyvsp[0].infoexpr).opnd, opndidle, (yyval.infoexpr).opnd);
                    }
#line 2049 "inter012020.tab.c"
    break;

  case 90:
#line 478 "inter012020.y"
                           {printf ("( ");}
#line 2055 "inter012020.tab.c"
    break;

  case 91:
#line 479 "inter012020.y"
                    {printf (") "); (yyval.infoexpr).tipo = (yyvsp[-1].infoexpr).tipo; (yyval.infoexpr).opnd = (yyvsp[-1].infoexpr).opnd;}
#line 2061 "inter012020.tab.c"
    break;

  case 92:
#line 481 "inter012020.y"
                                {
                        printf ("%s ", (yyvsp[0].cadeia));
                        simb = ProcuraSimb ((yyvsp[0].cadeia));
                        if (simb == NULL)   NaoDeclarado ((yyvsp[0].cadeia));
                        else if (simb->tid != IDVAR)   TipoInadequado ((yyvsp[0].cadeia));
                        (yyval.simb) = simb;
                    }
#line 2073 "inter012020.tab.c"
    break;

  case 93:
#line 487 "inter012020.y"
                                   {
                        (yyval.infovar).simb = (yyvsp[-1].simb);
                        if ((yyval.infovar).simb != NULL) {
                            if ((yyval.infovar).simb->array == FALSE && (yyvsp[0].nsubscr) > 0)
                                NaoEsperado ("Subscrito\(s)");
                            else if ((yyval.infovar).simb->array == TRUE && (yyvsp[0].nsubscr) == 0)
                                Esperado ("Subscrito\(s)");
                            else if ((yyval.infovar).simb->ndims != (yyvsp[0].nsubscr))
                                Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                            (yyval.infovar).opnd.tipo = VAROPND;
                            if((yyvsp[0].nsubscr) == 0)
                                (yyval.infovar).opnd.atr.simb = (yyval.infovar).simb;
                        }
                    }
#line 2092 "inter012020.tab.c"
    break;

  case 94:
#line 502 "inter012020.y"
                    {(yyval.nsubscr) = 0;}
#line 2098 "inter012020.tab.c"
    break;

  case 95:
#line 503 "inter012020.y"
                           {printf ("[ ");}
#line 2104 "inter012020.tab.c"
    break;

  case 96:
#line 504 "inter012020.y"
                          {
                        printf ("] ");
                        (yyval.nsubscr) = (yyvsp[-1].nsubscr);
                    }
#line 2113 "inter012020.tab.c"
    break;

  case 97:
#line 509 "inter012020.y"
                              {
                        if ((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                            Incompatibilidade ("Tipo inadequado para subscrito");
                        (yyval.nsubscr) = 1;
                    }
#line 2123 "inter012020.tab.c"
    break;

  case 98:
#line 514 "inter012020.y"
                                      {printf (", ");}
#line 2129 "inter012020.tab.c"
    break;

  case 99:
#line 514 "inter012020.y"
                                                                  {
                        if ((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                            Incompatibilidade ("Tipo inadequado para subscrito");
                        (yyval.nsubscr) = (yyvsp[-3].nsubscr) + 1;
                    }
#line 2139 "inter012020.tab.c"
    break;


#line 2143 "inter012020.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 520 "inter012020.y"


/* Inclusao do analisador lexico  */

#include "lex.yy.c"

/*  InicTabSimb: Inicializa a tabela de simbolos   */

void InicTabSimb () {
	int i;
	for (i = 0; i < NCLASSHASH; i++)
		tabsimb[i] = NULL;
}

/*
	ProcuraSimb (cadeia): Procura cadeia na tabela de simbolos;
	Caso ela ali esteja, retorna um ponteiro para sua celula;
	Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia) {
	simbolo s; int i;
	i = hash (cadeia);
	for (s = tabsimb[i]; (s!=NULL) && strcmp(cadeia, s->cadeia);
		s = s->prox);
	return s;
}

/*
	InsereSimb (cadeia, tid, tvar): Insere cadeia na tabela de
	simbolos, com tid como tipo de identificador e com tvar como
	tipo de variavel; Retorna um ponteiro para a celula inserida
 */

simbolo InsereSimb (char *cadeia, int tid, int tvar) {
	int i; simbolo aux, s;
	i = hash (cadeia); aux = tabsimb[i];
	s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
	s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
	strcpy (s->cadeia, cadeia);
	s->tid = tid;		s->tvar = tvar;
	s->inic = FALSE;	s->ref = FALSE;
	s->prox = aux;	return s;
}

/*
	hash (cadeia): funcao que determina e retorna a classe
	de cadeia na tabela de simbolos implementada por hashing
 */

int hash (char *cadeia) {
	int i, h;
	for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
	h = h % NCLASSHASH;
	return h;
}

/* ImprimeTabSimb: Imprime todo o conteudo da tabela de simbolos  */

void ImprimeTabSimb () {
	int i; simbolo s;
	printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			printf ("Classe %d:\n", i);
			for (s = tabsimb[i]; s!=NULL; s = s->prox){
				printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
				if (s->tid == IDVAR) {
					printf (", %s, %d, %d",
						nometipvar[s->tvar], s->inic, s->ref);
                    if (s->array == TRUE) {
                        int j;
                        printf (", EH ARRAY\n\tndims = %d, dimensoes:", s->ndims);
						for (j = 1; j <= s->ndims; j++)
                            printf ("  %d", s->dims[j]);
					}
                }
				printf(")\n");
			}
		}
}

void VerificaInicRef () {
	int i; simbolo s;

	printf ("\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i])
			for (s = tabsimb[i]; s!=NULL; s = s->prox)
				if (s->tid == IDVAR) {
					if (s->inic == FALSE)
						printf ("%s: Nao Inicializada\n", s->cadeia);
					if (s->ref == FALSE)
						printf ("%s: Nao Referenciada\n", s->cadeia);
				}
}


/*  Mensagens de erros semanticos  */

void DeclaracaoRepetida (char *s) {
	printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
    printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
    printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

void Incompatibilidade (char *s) {
    printf ("\n\n***** Incompatibilidade: %s *****\n\n", s);
}

void Esperado (char *s) {
    printf ("\n\n***** Esperado: %s *****\n\n", s);
}

void NaoEsperado (char *s) {
	printf ("\n\n***** Nao Esperado: %s *****\n\n", s);
}

/* Funcoes para o codigo intermediario */

void InicCodIntermed () {
	modcorrente = codintermed = malloc (sizeof (celmodhead));
    modcorrente->listquad = NULL;
	modcorrente->prox = NULL;
}

void InicCodIntermMod (simbolo simb) {
	modcorrente->prox = malloc (sizeof (celmodhead));
	modcorrente = modcorrente->prox;
	modcorrente->prox = NULL;
	modcorrente->modname = simb;
	modcorrente->listquad = malloc (sizeof (celquad));
	quadcorrente = modcorrente->listquad;
	quadcorrente->prox = NULL;
	numquadcorrente = 0;
	quadcorrente->num = numquadcorrente;
}

quadrupla GeraQuadrupla (int oper, operando opnd1, operando opnd2,
	operando result) {
	quadcorrente->prox = malloc (sizeof (celquad));
	quadcorrente = quadcorrente->prox;
	quadcorrente->oper = oper;
	quadcorrente->opnd1 = opnd1;
	quadcorrente->opnd2 = opnd2;
	quadcorrente->result = result;
	quadcorrente->prox = NULL;
	numquadcorrente ++;
    quadcorrente->num = numquadcorrente;
    return quadcorrente;
}

simbolo NovaTemp (int tip) {
	simbolo simb; int temp, i, j;
	char nometemp[10] = "##", s[10] = {0};

	numtemp ++; temp = numtemp;
	for (i = 0; temp > 0; temp /= 10, i++)
		s[i] = temp % 10 + '0';
	i --;
	for (j = 0; j <= i; j++)
		nometemp[2+i-j] = s[j];
	simb = InsereSimb (nometemp, IDVAR, tip);
	simb->inic = simb->ref = TRUE;
    simb->array = FALSE;
	return simb;
}

void ImprimeQuadruplas () {
	modhead p;
	quadrupla q;
	for (p = codintermed->prox; p != NULL; p = p->prox) {
		printf ("\n\nQuadruplas do modulo %s:\n", p->modname->cadeia);
		for (q = p->listquad->prox; q != NULL; q = q->prox) {
			printf ("\n\t%4d) %s", q->num, nomeoperquad[q->oper]);
			printf (", (%s", nometipoopndquad[q->opnd1.tipo]);
			switch (q->opnd1.tipo) {
				case IDLEOPND: break;
				case VAROPND: printf (", %s", q->opnd1.atr.simb->cadeia); break;
				case INTOPND: printf (", %d", q->opnd1.atr.valint); break;
				case REALOPND: printf (", %g", q->opnd1.atr.valfloat); break;
				case CHAROPND: printf (", %c", q->opnd1.atr.valchar); break;
				case LOGICOPND: printf (", %d", q->opnd1.atr.vallogic); break;
				case CADOPND: printf (", %s", q->opnd1.atr.valcad); break;
				case ROTOPND: printf (", %d", q->opnd1.atr.rotulo->num); break;
				case MODOPND: printf(", %s", q->opnd1.atr.modulo->modname->cadeia);
					break;
			}
			printf (")");
			printf (", (%s", nometipoopndquad[q->opnd2.tipo]);
			switch (q->opnd2.tipo) {
				case IDLEOPND: break;
				case VAROPND: printf (", %s", q->opnd2.atr.simb->cadeia); break;
				case INTOPND: printf (", %d", q->opnd2.atr.valint); break;
				case REALOPND: printf (", %g", q->opnd2.atr.valfloat); break;
				case CHAROPND: printf (", %c", q->opnd2.atr.valchar); break;
				case LOGICOPND: printf (", %d", q->opnd2.atr.vallogic); break;
				case CADOPND: printf (", %s", q->opnd2.atr.valcad); break;
				case ROTOPND: printf (", %d", q->opnd2.atr.rotulo->num); break;
				case MODOPND: printf(", %s", q->opnd2.atr.modulo->modname->cadeia);
					break;
			}
			printf (")");
			printf (", (%s", nometipoopndquad[q->result.tipo]);
			switch (q->result.tipo) {
				case IDLEOPND: break;
				case VAROPND: printf (", %s", q->result.atr.simb->cadeia); break;
				case INTOPND: printf (", %d", q->result.atr.valint); break;
				case REALOPND: printf (", %g", q->result.atr.valfloat); break;
				case CHAROPND: printf (", %c", q->result.atr.valchar); break;
				case LOGICOPND: printf (", %d", q->result.atr.vallogic); break;
				case CADOPND: printf (", %s", q->result.atr.valcad); break;
				case ROTOPND: printf (", %d", q->result.atr.rotulo->num); break;
				case MODOPND: printf(", %s", q->result.atr.modulo->modname->cadeia);
					break;
			}
			printf (")");
		}
	}
   printf ("\n");
}

void RenumQuadruplas (quadrupla quad1, quadrupla quad2) {
	quadrupla q; int nquad;
	for (q = quad1->prox, nquad = quad1->num; q != quad2; q = q->prox) {
      nquad++;
		q->num = nquad;
	}
}


