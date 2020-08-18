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
#line 1 "lab5.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char bool;

//atributos do OPREL
#define 	LT 		1
#define 	LE 		2
#define	    GT		3
#define	    GE		4
#define	    EQ		5
#define	    NE		6

//atributos do OPAD
#define		SOMA	1
#define		SUB		2

//atributos do OPMULT
#define		MULT	1
#define		DIV		2
#define		MOD		3
/*   Definicao dos tipos de identificadores   */

#define     IDGLOB        1
#define     IDVAR         2
#define     IDFUNC        3
#define     IDPROC        4
#define     IDPROG        5
#define     IDBLOC        6

/*  Definicao dos tipos de 
    passagem de parametros  */

#define     PARAMVAL    1       
#define     PARAMREF    2   

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
#define     PARAM           21
#define     OPREAD          22
#define     OPWRITE         23
#define     OPIND           24
#define     OPINDEX         25
#define     OPCONTAPONT     26
#define     OPATRIBPONT     27
#define     OPCALL          28
#define     OPEXIT          29
#define     OPRETURN        30

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

#define	NCLASSHASH	23
#define	TRUE		1
#define	FALSE		0
#define MAXDIMS     10

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[7] = {" ", "IDGLOB","IDVAR","IDFUNC","IDPROC","IDPROG", "IDBLOC"};

/*  Strings para nomes dos tipos de variaveis  */

char *nometipvar[5] = {"NOTVAR",
	"INTEGER", "LOGICAL", "FLOAT", "CHAR"
};

/* Strings para operadores de quadruplas */

char *nomeoperquad[31] = {"",
	"OR", "AND", "LT", "LE", "GT", "GE", "EQ", "NE", "MAIS",
	"MENOS", "MULT", "DIV", "RESTO", "MENUN", "NOT", "ATRIB",
	"OPENMOD", "NOP", "JUMP", "JF", "PARAM", "READ", "WRITE", "IND", "INDEX", "CONTAPONT", "ATRIBPONT", "CALL",
    "EXIT", "RETURN"
};

/*
	Strings para tipos de operandos de quadruplas
 */

char *nometipoopndquad[9] = {"IDLE",
	"VAR", "INT", "REAL", "CARAC", "LOGIC", "CADEIA", "ROTULO", "MODULO"
};

/* Typedefs para Tabela e Listas de Símbolos */

typedef struct celsimb celsimb;
typedef celsimb *simbolo;
typedef struct elemlistsimb elemlistsimb;
typedef elemlistsimb *pontelemlistsimb;
typedef elemlistsimb *listsimb;

typedef union atribopnd atribopnd;
typedef struct operando operando;
typedef struct celquad celquad;
typedef celquad *quadrupla;
typedef struct celmodhead celmodhead;
typedef celmodhead *modhead;

/*    Declaracoes para a tabela de simbolos     */

struct celsimb {
	char *cadeia;
	int tid, tvar,nparam, ndims, dims[MAXDIMS+1];
	char inic, ref, array, param;
    listsimb listvardecl, listparam, listfunc;
    modhead funchead;
	simbolo escopo, prox;
};

/*  Listas de simbolos  */

struct elemlistsimb {
    simbolo simb; 
    pontelemlistsimb prox;
};

/*    Declaracoes para lista de expressões     */

typedef int  tipovar;
typedef struct elemlistexpr elemlistexpr;
typedef struct infolistexpr infolistexpr;
typedef elemlistexpr *pontexprtipo; 



struct infolistexpr { 
    pontexprtipo listtipo;
    int nargs;
};
struct elemlistexpr{
    tipovar exprtipo;
    pontexprtipo prox;
};
/*  Variaveis globais para a tabela de simbolos e analise semantica */

simbolo tabsimb[NCLASSHASH];
simbolo simb;
int tipoCorrente, ndimsCorrente;

/*
	Prototipos das funcoes para a tabela de simbolos
    	e analise semantica
 */

void InicTabSimb (void);
void ImprimeTabSimb (void);
simbolo InsereSimb (char *, int, int, simbolo);
int hash (char *);
simbolo ProcuraSimb (char *, simbolo);
void VerificaInicRef (void);
void InsereListSimb(simbolo , pontelemlistsimb);
pontexprtipo InicListTipo(tipovar);
pontexprtipo ConcatListTipo (pontexprtipo , pontexprtipo);
void ChecArgumentos(pontexprtipo, listsimb);
char* NovoBloco();


/*Prototipos de Mensagens de erro */
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);
void Incompatibilidade (char *);
void ExpressaoTipoInadequado (char *);
void Esperado (char *);
void NaoEsperado (char *);
void AlteracaoVariavelControle (char *);
void Recursividade(void);

/* Declaracoes para a estrutura do codigo intermediario */


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

quadrupla quadcorrente, quadaux, quadaux2;
modhead codintermed, modcorrente, modeprincipal;
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


/*  Outras Variáveis Globais*/ 

int tab = 0;
simbolo escopo,escaux;
pontelemlistsimb pontfunc, pontvardecl, pontparam;
bool declparam, proxblocoehfuncao =FALSE;
char msg[200];
int blocos_gerados = 0;
char bloco[30];

/* Protótipo de tabular()*/

void tabular (void);

/* Definição de Pilha para CmdPara*/

typedef struct noh noh;
typedef noh *pilha;
struct noh {
    char elem[30]; noh *prox;
};
pilha PFor;
void Empilhar(char*, pilha *);
void Desempilhar (pilha *);
char *Topo (pilha);
void InicPilha (pilha *);
bool Vazia(pilha);
noh *Procurar (char*, pilha);


#line 367 "lab5.tab.c"

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
    CTINT = 260,                   /* CTINT  */
    CTREAL = 261,                  /* CTREAL  */
    CADEIA = 262,                  /* CADEIA  */
    OPREL = 263,                   /* OPREL  */
    OPAD = 264,                    /* OPAD  */
    OPMULT = 265,                  /* OPMULT  */
    NEG = 266,                     /* NEG  */
    CARAC = 267,                   /* CARAC  */
    CHAMAR = 268,                  /* CHAMAR  */
    COMANDOS = 269,                /* COMANDOS  */
    ENQUANTO = 270,                /* ENQUANTO  */
    ESCREVER = 271,                /* ESCREVER  */
    FALSO = 272,                   /* FALSO  */
    FUNCAO = 273,                  /* FUNCAO  */
    INT = 274,                     /* INT  */
    LER = 275,                     /* LER  */
    LOGIC = 276,                   /* LOGIC  */
    PARA = 277,                    /* PARA  */
    PRINCIPAL = 278,               /* PRINCIPAL  */
    PROCEDIMENTO = 279,            /* PROCEDIMENTO  */
    PROGRAMA = 280,                /* PROGRAMA  */
    REAL = 281,                    /* REAL  */
    REPETIR = 282,                 /* REPETIR  */
    RETORNAR = 283,                /* RETORNAR  */
    SE = 284,                      /* SE  */
    SENAO = 285,                   /* SENAO  */
    VAR = 286,                     /* VAR  */
    VERDADE = 287,                 /* VERDADE  */
    OR = 288,                      /* OR  */
    AND = 289,                     /* AND  */
    NOT = 290,                     /* NOT  */
    ATRIB = 291,                   /* ATRIB  */
    ABPAR = 292,                   /* ABPAR  */
    FPAR = 293,                    /* FPAR  */
    ABCOL = 294,                   /* ABCOL  */
    FCOL = 295,                    /* FCOL  */
    ABCHAV = 296,                  /* ABCHAV  */
    FCHAV = 297,                   /* FCHAV  */
    ABTRIP = 298,                  /* ABTRIP  */
    FTRIP = 299,                   /* FTRIP  */
    PVIRG = 300,                   /* PVIRG  */
    VIRG = 301,                    /* VIRG  */
    INVAL = 302                    /* INVAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 296 "lab5.y"

	char cadeia[50];
	int atr, valint;
	float valreal;
	char carac;
	simbolo simb;
    infoexpressao infoexpr;
    infovariavel infovar;
    infolistexpr infolexpr;
    int nsubscr;
    int nargs;
    quadrupla quad;

#line 475 "lab5.tab.c"

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
  YYSYMBOL_CTINT = 5,                      /* CTINT  */
  YYSYMBOL_CTREAL = 6,                     /* CTREAL  */
  YYSYMBOL_CADEIA = 7,                     /* CADEIA  */
  YYSYMBOL_OPREL = 8,                      /* OPREL  */
  YYSYMBOL_OPAD = 9,                       /* OPAD  */
  YYSYMBOL_OPMULT = 10,                    /* OPMULT  */
  YYSYMBOL_NEG = 11,                       /* NEG  */
  YYSYMBOL_CARAC = 12,                     /* CARAC  */
  YYSYMBOL_CHAMAR = 13,                    /* CHAMAR  */
  YYSYMBOL_COMANDOS = 14,                  /* COMANDOS  */
  YYSYMBOL_ENQUANTO = 15,                  /* ENQUANTO  */
  YYSYMBOL_ESCREVER = 16,                  /* ESCREVER  */
  YYSYMBOL_FALSO = 17,                     /* FALSO  */
  YYSYMBOL_FUNCAO = 18,                    /* FUNCAO  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_LER = 20,                       /* LER  */
  YYSYMBOL_LOGIC = 21,                     /* LOGIC  */
  YYSYMBOL_PARA = 22,                      /* PARA  */
  YYSYMBOL_PRINCIPAL = 23,                 /* PRINCIPAL  */
  YYSYMBOL_PROCEDIMENTO = 24,              /* PROCEDIMENTO  */
  YYSYMBOL_PROGRAMA = 25,                  /* PROGRAMA  */
  YYSYMBOL_REAL = 26,                      /* REAL  */
  YYSYMBOL_REPETIR = 27,                   /* REPETIR  */
  YYSYMBOL_RETORNAR = 28,                  /* RETORNAR  */
  YYSYMBOL_SE = 29,                        /* SE  */
  YYSYMBOL_SENAO = 30,                     /* SENAO  */
  YYSYMBOL_VAR = 31,                       /* VAR  */
  YYSYMBOL_VERDADE = 32,                   /* VERDADE  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_ATRIB = 36,                     /* ATRIB  */
  YYSYMBOL_ABPAR = 37,                     /* ABPAR  */
  YYSYMBOL_FPAR = 38,                      /* FPAR  */
  YYSYMBOL_ABCOL = 39,                     /* ABCOL  */
  YYSYMBOL_FCOL = 40,                      /* FCOL  */
  YYSYMBOL_ABCHAV = 41,                    /* ABCHAV  */
  YYSYMBOL_FCHAV = 42,                     /* FCHAV  */
  YYSYMBOL_ABTRIP = 43,                    /* ABTRIP  */
  YYSYMBOL_FTRIP = 44,                     /* FTRIP  */
  YYSYMBOL_PVIRG = 45,                     /* PVIRG  */
  YYSYMBOL_VIRG = 46,                      /* VIRG  */
  YYSYMBOL_INVAL = 47,                     /* INVAL  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Prog = 49,                      /* Prog  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_Decls = 52,                     /* Decls  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_ListDecl = 54,                  /* ListDecl  */
  YYSYMBOL_Declaracao = 55,                /* Declaracao  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_Tipo = 58,                      /* Tipo  */
  YYSYMBOL_ListElem = 59,                  /* ListElem  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_Elem = 61,                      /* Elem  */
  YYSYMBOL_62_7 = 62,                      /* $@7  */
  YYSYMBOL_Dims = 63,                      /* Dims  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_ListDim = 65,                   /* ListDim  */
  YYSYMBOL_ListMod = 66,                   /* ListMod  */
  YYSYMBOL_Modulo = 67,                    /* Modulo  */
  YYSYMBOL_68_9 = 68,                      /* $@9  */
  YYSYMBOL_Cabecalho = 69,                 /* Cabecalho  */
  YYSYMBOL_CabFunc = 70,                   /* CabFunc  */
  YYSYMBOL_71_10 = 71,                     /* $@10  */
  YYSYMBOL_CabProc = 72,                   /* CabProc  */
  YYSYMBOL_73_11 = 73,                     /* $@11  */
  YYSYMBOL_PrintaFuncao = 74,              /* PrintaFuncao  */
  YYSYMBOL_PrintaProcedimento = 75,        /* PrintaProcedimento  */
  YYSYMBOL_ListParam = 76,                 /* ListParam  */
  YYSYMBOL_77_12 = 77,                     /* $@12  */
  YYSYMBOL_Parametro = 78,                 /* Parametro  */
  YYSYMBOL_Corpo = 79,                     /* Corpo  */
  YYSYMBOL_80_13 = 80,                     /* $@13  */
  YYSYMBOL_81_14 = 81,                     /* $@14  */
  YYSYMBOL_ModPrincipal = 82,              /* ModPrincipal  */
  YYSYMBOL_83_15 = 83,                     /* $@15  */
  YYSYMBOL_Comandos = 84,                  /* Comandos  */
  YYSYMBOL_85_16 = 85,                     /* $@16  */
  YYSYMBOL_CmdComp = 86,                   /* CmdComp  */
  YYSYMBOL_87_17 = 87,                     /* $@17  */
  YYSYMBOL_ListCmd = 88,                   /* ListCmd  */
  YYSYMBOL_Comando = 89,                   /* Comando  */
  YYSYMBOL_CmdSe = 90,                     /* CmdSe  */
  YYSYMBOL_91_18 = 91,                     /* $@18  */
  YYSYMBOL_92_19 = 92,                     /* @19  */
  YYSYMBOL_93_20 = 93,                     /* @20  */
  YYSYMBOL_CmdSenao = 94,                  /* CmdSenao  */
  YYSYMBOL_95_21 = 95,                     /* @21  */
  YYSYMBOL_CmdEnquanto = 96,               /* CmdEnquanto  */
  YYSYMBOL_97_22 = 97,                     /* $@22  */
  YYSYMBOL_98_23 = 98,                     /* @23  */
  YYSYMBOL_CmdRepetir = 99,                /* CmdRepetir  */
  YYSYMBOL_100_24 = 100,                   /* @24  */
  YYSYMBOL_101_25 = 101,                   /* $@25  */
  YYSYMBOL_102_26 = 102,                   /* $@26  */
  YYSYMBOL_CmdPara = 103,                  /* CmdPara  */
  YYSYMBOL_104_27 = 104,                   /* $@27  */
  YYSYMBOL_105_28 = 105,                   /* $@28  */
  YYSYMBOL_106_29 = 106,                   /* $@29  */
  YYSYMBOL_107_30 = 107,                   /* @30  */
  YYSYMBOL_108_31 = 108,                   /* @31  */
  YYSYMBOL_109_32 = 109,                   /* @32  */
  YYSYMBOL_110_33 = 110,                   /* @33  */
  YYSYMBOL_CmdLer = 111,                   /* CmdLer  */
  YYSYMBOL_112_34 = 112,                   /* $@34  */
  YYSYMBOL_113_35 = 113,                   /* $@35  */
  YYSYMBOL_ListLeit = 114,                 /* ListLeit  */
  YYSYMBOL_115_36 = 115,                   /* $@36  */
  YYSYMBOL_CmdEscrever = 116,              /* CmdEscrever  */
  YYSYMBOL_117_37 = 117,                   /* $@37  */
  YYSYMBOL_118_38 = 118,                   /* $@38  */
  YYSYMBOL_ListEscr = 119,                 /* ListEscr  */
  YYSYMBOL_120_39 = 120,                   /* $@39  */
  YYSYMBOL_ElemEscr = 121,                 /* ElemEscr  */
  YYSYMBOL_ChamadaProc = 122,              /* ChamadaProc  */
  YYSYMBOL_123_40 = 123,                   /* @40  */
  YYSYMBOL_Argumentos = 124,               /* Argumentos  */
  YYSYMBOL_CmdRetornar = 125,              /* CmdRetornar  */
  YYSYMBOL_126_41 = 126,                   /* $@41  */
  YYSYMBOL_CmdAtrib = 127,                 /* CmdAtrib  */
  YYSYMBOL_128_42 = 128,                   /* $@42  */
  YYSYMBOL_129_43 = 129,                   /* $@43  */
  YYSYMBOL_130_44 = 130,                   /* $@44  */
  YYSYMBOL_ListExpr = 131,                 /* ListExpr  */
  YYSYMBOL_132_45 = 132,                   /* $@45  */
  YYSYMBOL_Expressao = 133,                /* Expressao  */
  YYSYMBOL_134_46 = 134,                   /* $@46  */
  YYSYMBOL_ExprAux1 = 135,                 /* ExprAux1  */
  YYSYMBOL_136_47 = 136,                   /* $@47  */
  YYSYMBOL_ExprAux2 = 137,                 /* ExprAux2  */
  YYSYMBOL_138_48 = 138,                   /* $@48  */
  YYSYMBOL_ExprAux3 = 139,                 /* ExprAux3  */
  YYSYMBOL_140_49 = 140,                   /* $@49  */
  YYSYMBOL_ExprAux4 = 141,                 /* ExprAux4  */
  YYSYMBOL_142_50 = 142,                   /* $@50  */
  YYSYMBOL_Termo = 143,                    /* Termo  */
  YYSYMBOL_144_51 = 144,                   /* $@51  */
  YYSYMBOL_Fator = 145,                    /* Fator  */
  YYSYMBOL_146_52 = 146,                   /* $@52  */
  YYSYMBOL_147_53 = 147,                   /* $@53  */
  YYSYMBOL_Variavel = 148,                 /* Variavel  */
  YYSYMBOL_149_54 = 149,                   /* @54  */
  YYSYMBOL_Subscritos = 150,               /* Subscritos  */
  YYSYMBOL_151_55 = 151,                   /* $@55  */
  YYSYMBOL_ListSubscr = 152,               /* ListSubscr  */
  YYSYMBOL_153_56 = 153,                   /* $@56  */
  YYSYMBOL_ChamadaFunc = 154,              /* ChamadaFunc  */
  YYSYMBOL_155_57 = 155                    /* @57  */
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
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

#define YYMAXUTOK   302


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   368,   368,   379,   368,   395,   396,   396,   407,   408,
     411,   411,   411,   416,   417,   418,   419,   422,   423,   423,
     427,   426,   441,   442,   442,   445,   453,   463,   464,   467,
     467,   470,   471,   474,   494,   491,   517,   537,   534,   560,
     563,   567,   568,   568,   571,   589,   593,   589,   597,   596,
     636,   636,   639,   639,   650,   651,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,   664,   668,   674,   681,
     667,   696,   697,   697,   710,   717,   709,   735,   740,   741,
     735,   755,   757,   764,   773,   780,   786,   790,   755,   807,
     807,   807,   814,   820,   820,   828,   828,   828,   835,   839,
     839,   845,   851,   855,   854,   895,   896,   899,   914,   913,
     936,   937,   944,   936,   962,   968,   968,   976,   977,   977,
     988,   989,   989,  1000,  1001,  1001,  1012,  1014,  1013,  1063,
    1065,  1064,  1085,  1087,  1086,  1122,  1136,  1141,  1146,  1151,
    1156,  1161,  1161,  1172,  1172,  1175,  1179,  1178,  1223,  1224,
    1224,  1232,  1240,  1240,  1250,  1249
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
  "CTINT", "CTREAL", "CADEIA", "OPREL", "OPAD", "OPMULT", "NEG", "CARAC",
  "CHAMAR", "COMANDOS", "ENQUANTO", "ESCREVER", "FALSO", "FUNCAO", "INT",
  "LER", "LOGIC", "PARA", "PRINCIPAL", "PROCEDIMENTO", "PROGRAMA", "REAL",
  "REPETIR", "RETORNAR", "SE", "SENAO", "VAR", "VERDADE", "OR", "AND",
  "NOT", "ATRIB", "ABPAR", "FPAR", "ABCOL", "FCOL", "ABCHAV", "FCHAV",
  "ABTRIP", "FTRIP", "PVIRG", "VIRG", "INVAL", "$accept", "Prog", "$@1",
  "$@2", "Decls", "$@3", "ListDecl", "Declaracao", "$@4", "$@5", "Tipo",
  "ListElem", "$@6", "Elem", "$@7", "Dims", "$@8", "ListDim", "ListMod",
  "Modulo", "$@9", "Cabecalho", "CabFunc", "$@10", "CabProc", "$@11",
  "PrintaFuncao", "PrintaProcedimento", "ListParam", "$@12", "Parametro",
  "Corpo", "$@13", "$@14", "ModPrincipal", "$@15", "Comandos", "$@16",
  "CmdComp", "$@17", "ListCmd", "Comando", "CmdSe", "$@18", "@19", "@20",
  "CmdSenao", "@21", "CmdEnquanto", "$@22", "@23", "CmdRepetir", "@24",
  "$@25", "$@26", "CmdPara", "$@27", "$@28", "$@29", "@30", "@31", "@32",
  "@33", "CmdLer", "$@34", "$@35", "ListLeit", "$@36", "CmdEscrever",
  "$@37", "$@38", "ListEscr", "$@39", "ElemEscr", "ChamadaProc", "@40",
  "Argumentos", "CmdRetornar", "$@41", "CmdAtrib", "$@42", "$@43", "$@44",
  "ListExpr", "$@45", "Expressao", "$@46", "ExprAux1", "$@47", "ExprAux2",
  "$@48", "ExprAux3", "$@49", "ExprAux4", "$@50", "Termo", "$@51", "Fator",
  "$@52", "$@53", "Variavel", "@54", "Subscritos", "$@55", "ListSubscr",
  "$@56", "ChamadaFunc", "@57", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302
};
#endif

#define YYPACT_NINF (-183)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -183,    15,    -1,  -183,    32,   -18,  -183,    -3,     8,  -183,
    -183,    49,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
      21,    34,  -183,    18,    18,  -183,    75,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,    53,    91,  -183,    -3,    67,
    -183,  -183,    68,  -183,    74,   104,    78,   105,  -183,    18,
    -183,     4,  -183,  -183,    18,  -183,  -183,   115,    23,  -183,
      84,  -183,  -183,    25,    83,  -183,  -183,  -183,  -183,  -183,
     104,  -183,  -183,  -183,    18,   121,  -183,  -183,  -183,  -183,
      12,    69,  -183,   122,   125,    94,    96,    98,  -183,  -183,
      85,    99,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,   126,  -183,   100,  -183,  -183,
    -183,   126,    93,  -183,    16,  -183,  -183,  -183,  -183,    16,
       6,   126,  -183,   124,   103,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,   -19,   107,  -183,  -183,    92,   132,  -183,
    -183,  -183,    16,   106,   108,    16,    41,  -183,    97,  -183,
     113,   101,  -183,   111,   112,  -183,    51,    51,    16,  -183,
    -183,  -183,  -183,  -183,  -183,    42,  -183,  -183,  -183,   114,
     109,   113,  -183,  -183,   116,  -183,   118,  -183,  -183,    16,
    -183,  -183,    54,    16,    16,    51,    51,    51,  -183,    51,
      16,   117,  -183,    93,     6,   119,   126,   120,    51,    16,
     123,  -183,   107,  -183,   141,   132,  -183,    93,   141,    24,
       1,  -183,    16,  -183,  -183,  -183,  -183,  -183,    -5,   113,
    -183,  -183,  -183,  -183,  -183,   113,  -183,   128,   127,    51,
      16,   129,  -183,  -183,   141,   113,  -183,    93,   130,  -183,
    -183,    51,    22,  -183,    93,  -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     5,     0,    27,
       6,     0,    10,    39,    48,    40,    28,    29,    31,    32,
       0,    10,     8,     0,     0,    45,     0,    45,     4,     7,
       9,    15,    13,    16,    14,     0,     0,    49,     5,     0,
      30,    11,     0,    46,    37,     0,    34,     0,    36,     0,
      20,     0,    17,    33,     0,    50,    47,     0,     0,    41,
      22,    12,    18,     0,     0,    44,    38,    42,    23,    21,
       0,    35,    52,    51,     0,     0,    19,    54,    43,    25,
       0,   110,    24,     0,     0,     0,     0,     0,    81,    77,
     108,     0,    53,    66,    56,    55,    57,    58,    59,    60,
      61,    62,    64,    65,    63,     0,    26,     0,    74,    95,
      89,     0,   110,   107,     0,    67,   146,   111,   103,     0,
       0,     0,    82,     0,   146,   138,   136,   137,   141,   140,
     139,   124,   143,     0,   117,   120,   123,   126,   129,   132,
     135,   145,     0,   148,     0,   105,     0,   101,    96,    98,
     102,    90,    92,     0,     0,   154,     0,     0,     0,   118,
     109,   121,   127,   130,   133,     0,   149,   147,   112,     0,
     106,   114,    75,    99,     0,    93,     0,    83,    78,   105,
     142,   125,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,   115,   110,     0,     0,     0,     0,     0,     0,
       0,   144,   119,   122,   128,   131,   134,   110,   151,     0,
       0,   104,     0,    76,   100,    97,    94,    91,     0,    79,
     155,    69,   150,   152,   113,   116,    84,     0,    71,     0,
       0,     0,    72,    70,   153,    85,    80,   110,     0,    73,
      86,     0,     0,    87,   110,    88
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,   131,  -183,  -183,   137,  -183,  -183,
      79,  -183,  -183,    81,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,   133,  -183,
      86,   136,  -183,  -183,  -183,  -183,  -183,  -183,    89,  -183,
    -183,  -112,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,   -35,  -183,  -183,   -12,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -113,  -183,   -15,  -183,   -14,
    -183,    14,  -183,  -182,  -183,   -13,  -183,  -151,  -183,  -183,
    -103,  -183,  -183,  -183,  -183,  -183,  -183,  -183
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     9,    12,    21,    22,    23,    45,
      57,    51,    70,    52,    60,    69,    75,    80,    11,    16,
      27,    17,    18,    54,    19,    49,    24,    26,    58,    74,
      59,    37,    38,    47,    20,    25,    56,    64,    94,    77,
      81,    95,    96,   142,   207,   228,   233,   237,    97,   119,
     193,    98,   112,   199,   227,    99,   111,   153,   198,   230,
     238,   241,   244,   100,   121,   176,   151,   196,   101,   120,
     174,   148,   194,   149,   102,   145,   169,   103,   114,   104,
     105,   144,   190,   170,   212,   150,   183,   134,   184,   135,
     157,   136,   185,   137,   186,   138,   187,   139,   156,   158,
     140,   143,   167,   189,   209,   229,   141,   179
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     123,   133,   117,   204,   163,   180,   146,   208,   122,   124,
     125,   126,   127,   147,   159,     3,   218,   128,   152,   124,
     125,   126,   127,   129,     4,     6,   160,   128,     8,   165,
      31,   163,   171,   129,   159,     5,   206,    32,   130,    33,
     226,   131,    61,   132,    34,   182,   224,   234,   130,    10,
      62,   131,    82,   132,   124,   125,   126,   127,    83,   242,
     243,    66,   128,    71,   222,    28,   171,    13,   129,    67,
     223,    67,    14,    15,   159,   159,    29,   210,    39,   172,
     188,   213,    84,   130,    85,    86,   219,   159,   132,    87,
      41,    88,   201,   216,    42,   221,    89,    90,    91,   225,
     162,   163,    35,    36,    44,    46,    84,    50,    85,    86,
      72,    92,    48,    87,    93,    88,    53,   235,    65,    55,
      89,    90,    91,    68,    72,   239,    79,   106,   107,   116,
     113,   108,   245,   109,    72,   110,   115,   118,    93,   154,
     155,   161,   164,   173,   168,   166,   159,   175,   177,   178,
     163,    76,   191,    73,   195,   192,   197,   232,    30,   214,
      78,   220,   211,    40,   215,   217,   231,   200,   202,    43,
     203,   181,     0,   205,   236,   240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
     112,   114,   105,   185,     9,   156,   119,   189,   111,     3,
       4,     5,     6,     7,    33,     0,   198,    11,   121,     3,
       4,     5,     6,    17,    25,    43,    45,    11,    31,   142,
      12,     9,   145,    17,    33,     3,   187,    19,    32,    21,
      45,    35,    38,    37,    26,   158,    45,   229,    32,    41,
      46,    35,    40,    37,     3,     4,     5,     6,    46,   241,
      38,    38,    11,    38,    40,    44,   179,    18,    17,    46,
      46,    46,    23,    24,    33,    33,    42,   190,     3,    38,
      38,   193,    13,    32,    15,    16,   199,    33,    37,    20,
      37,    22,    38,   196,     3,   207,    27,    28,    29,   212,
       8,     9,    23,    24,    37,    37,    13,     3,    15,    16,
      41,    42,    38,    20,    45,    22,    38,   230,     3,    14,
      27,    28,    29,    39,    41,   237,     5,     5,     3,     3,
      45,    37,   244,    37,    41,    37,    37,    37,    45,    15,
      37,    34,    10,    46,    36,    39,    33,    46,    37,    37,
       9,    70,    38,    64,    38,    46,    38,    30,    21,   194,
      74,    38,    45,    27,    45,    45,    38,   179,   183,    38,
     184,   157,    -1,   186,    45,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,    25,     3,    43,    51,    31,    52,
      41,    66,    53,    18,    23,    24,    67,    69,    70,    72,
      82,    54,    55,    56,    74,    83,    75,    68,    44,    42,
      55,    12,    19,    21,    26,    58,    58,    79,    80,     3,
      79,    37,     3,    52,    37,    57,    37,    81,    38,    73,
       3,    59,    61,    38,    71,    14,    84,    58,    76,    78,
      62,    38,    46,    76,    85,     3,    38,    46,    39,    63,
      60,    38,    41,    86,    77,    64,    61,    87,    78,     5,
      65,    88,    40,    46,    13,    15,    16,    20,    22,    27,
      28,    29,    42,    45,    86,    89,    90,    96,    99,   103,
     111,   116,   122,   125,   127,   128,     5,     3,    37,    37,
      37,   104,   100,    45,   126,    37,     3,   148,    37,    97,
     117,   112,   148,    89,     3,     4,     5,     6,    11,    17,
      32,    35,    37,   133,   135,   137,   139,   141,   143,   145,
     148,   154,    91,   149,   129,   123,   133,     7,   119,   121,
     133,   114,   148,   105,    15,    37,   146,   138,   147,    33,
      45,    34,     8,     9,    10,   133,    39,   150,    36,   124,
     131,   133,    38,    46,   118,    46,   113,    37,    37,   155,
     145,   139,   133,   134,   136,   140,   142,   144,    38,   151,
     130,    38,    46,    98,   120,    38,   115,    38,   106,   101,
     124,    38,   135,   137,   141,   143,   145,    92,   141,   152,
     133,    45,   132,    89,   121,    45,   148,    45,   141,   133,
      38,    89,    40,    46,    45,   133,    45,   102,    93,   153,
     107,    38,    30,    94,   141,   133,    45,    95,   108,    89,
      45,   109,   141,    38,   110,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    51,    49,    52,    53,    52,    54,    54,
      56,    57,    55,    58,    58,    58,    58,    59,    60,    59,
      62,    61,    63,    64,    63,    65,    65,    66,    66,    68,
      67,    69,    69,    70,    71,    70,    72,    73,    72,    74,
      75,    76,    77,    76,    78,    80,    81,    79,    83,    82,
      85,    84,    87,    86,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    91,    92,    93,
      90,    94,    95,    94,    97,    98,    96,   100,   101,   102,
      99,   104,   105,   106,   107,   108,   109,   110,   103,   112,
     113,   111,   114,   115,   114,   117,   118,   116,   119,   120,
     119,   121,   121,   123,   122,   124,   124,   125,   126,   125,
     128,   129,   130,   127,   131,   132,   131,   133,   134,   133,
     135,   136,   135,   137,   138,   137,   139,   140,   139,   141,
     142,   141,   143,   144,   143,   145,   145,   145,   145,   145,
     145,   146,   145,   147,   145,   145,   149,   148,   150,   151,
     150,   152,   153,   152,   155,   154
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     9,     0,     0,     5,     1,     2,
       0,     0,     6,     1,     1,     1,     1,     1,     0,     4,
       0,     3,     0,     0,     4,     1,     3,     0,     2,     0,
       3,     1,     1,     6,     0,     8,     5,     0,     7,     0,
       0,     1,     0,     4,     2,     0,     0,     4,     0,     3,
       0,     3,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     0,
       9,     0,     0,     3,     0,     0,     7,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     7,     1,     0,     4,     0,     0,     7,     1,     0,
       4,     1,     1,     0,     7,     0,     1,     2,     0,     4,
       0,     0,     0,     7,     1,     0,     4,     1,     0,     4,
       1,     0,     4,     1,     0,     3,     1,     0,     4,     1,
       0,     4,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     4,     1,     0,     3,     0,     0,
       4,     1,     0,     4,     0,     5
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
#line 368 "lab5.y"
                            {
                            InicTabSimb ();
                            InicCodIntermed();
                            numtemp = 0;
                            InicPilha(&PFor);
                            declparam=FALSE;
                            escopo = simb = InsereSimb("##global", IDGLOB, NOTVAR, NULL);
                            pontvardecl = simb->listvardecl;
                            pontfunc = simb->listfunc;
                        
                        }
#line 1812 "lab5.tab.c"
    break;

  case 3:
#line 379 "lab5.y"
                                                {
                            tabular(); tab++; 
                            printf("programa %s {{{\n\n", (yyvsp[-1].cadeia));
                            simb = InsereSimb ((yyvsp[-1].cadeia), IDPROG, NOTVAR, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                        }
#line 1826 "lab5.tab.c"
    break;

  case 4:
#line 387 "lab5.y"
                                                                    {
                            tab--; tabular(); printf ("}}}\n");
                            VerificaInicRef ();
                            ImprimeTabSimb ();
                            ImprimeQuadruplas ();
                        }
#line 1837 "lab5.tab.c"
    break;

  case 6:
#line 396 "lab5.y"
                                    {
                            tabular();
                            printf("var {\n"); 
                            tab++;
                        }
#line 1847 "lab5.tab.c"
    break;

  case 7:
#line 400 "lab5.y"
                                           {
                            tab--; 
                            tabular();
                            printf("}\n\n");
                        }
#line 1857 "lab5.tab.c"
    break;

  case 10:
#line 411 "lab5.y"
                            {tabular();}
#line 1863 "lab5.tab.c"
    break;

  case 11:
#line 411 "lab5.y"
                                                     {printf("(");}
#line 1869 "lab5.tab.c"
    break;

  case 12:
#line 411 "lab5.y"
                                                                                    {
                            printf(")\n");
                        }
#line 1877 "lab5.tab.c"
    break;

  case 13:
#line 416 "lab5.y"
                                     {printf ("int "); tipoCorrente = INTEGER;}
#line 1883 "lab5.tab.c"
    break;

  case 14:
#line 417 "lab5.y"
                              {printf ("real "); tipoCorrente = FLOAT;}
#line 1889 "lab5.tab.c"
    break;

  case 15:
#line 418 "lab5.y"
                              {printf ("carac "); tipoCorrente = CHAR;}
#line 1895 "lab5.tab.c"
    break;

  case 16:
#line 419 "lab5.y"
                              {printf ("logic "); tipoCorrente = LOGICAL;}
#line 1901 "lab5.tab.c"
    break;

  case 18:
#line 423 "lab5.y"
                                       {printf(", ");}
#line 1907 "lab5.tab.c"
    break;

  case 20:
#line 427 "lab5.y"
                        {
                            printf ("%s", (yyvsp[0].cadeia));
                            simb = ProcuraSimb((yyvsp[0].cadeia), escopo);
                            if (simb !=  NULL)
                                DeclaracaoRepetida ((yyvsp[0].cadeia));
                            else{
                                simb = InsereSimb ((yyvsp[0].cadeia),  IDVAR,  tipoCorrente, escopo);
                                simb -> array = FALSE;
                                simb -> ndims = 0;
                            }
                        }
#line 1923 "lab5.tab.c"
    break;

  case 23:
#line 442 "lab5.y"
                              {printf("[");}
#line 1929 "lab5.tab.c"
    break;

  case 24:
#line 442 "lab5.y"
                                                         {printf("]"); simb->array = TRUE;}
#line 1935 "lab5.tab.c"
    break;

  case 25:
#line 446 "lab5.y"
                        {
                            printf ("%d", (yyvsp[0].valint));
                            if ((yyvsp[0].valint) <= 0)
                                Esperado("Valor inteiro positivo");
                            simb->ndims++;
                            simb->dims[simb->ndims-1] = (yyvsp[0].valint);
                        }
#line 1947 "lab5.tab.c"
    break;

  case 26:
#line 454 "lab5.y"
                        {
                            printf(", %d",(yyvsp[0].valint));
                            if ((yyvsp[0].valint) <= 0)
                                Esperado("Valor inteiro positivo");
                            simb->ndims++;
                            simb->dims[simb->ndims-1] = (yyvsp[0].valint);    
                        }
#line 1959 "lab5.tab.c"
    break;

  case 29:
#line 467 "lab5.y"
                                       {proxblocoehfuncao = TRUE;}
#line 1965 "lab5.tab.c"
    break;

  case 33:
#line 477 "lab5.y"
                        {
                            printf("%s ()\n\n",(yyvsp[-2].cadeia));
                            simb = ProcuraSimb((yyvsp[-2].cadeia), escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida((yyvsp[-2].cadeia));
                            escopo = simb = 
                            InsereSimb ((yyvsp[-2].cadeia), IDFUNC, tipoCorrente, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            simb->funchead = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                        }
#line 1984 "lab5.tab.c"
    break;

  case 34:
#line 494 "lab5.y"
                        {
                            printf("%s (",(yyvsp[-1].cadeia));
                            declparam = TRUE;
                            simb = ProcuraSimb((yyvsp[-1].cadeia), escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida((yyvsp[-1].cadeia));
                            escopo = simb = 
                            InsereSimb ((yyvsp[-1].cadeia), IDFUNC, tipoCorrente, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            simb->funchead = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                            pontparam = simb->listparam;
                        }
#line 2005 "lab5.tab.c"
    break;

  case 35:
#line 511 "lab5.y"
                        {
                            printf(")\n\n");
                            declparam = FALSE;
                        }
#line 2014 "lab5.tab.c"
    break;

  case 36:
#line 520 "lab5.y"
                        {
                            printf("%s ()\n\n",(yyvsp[-2].cadeia));
                            simb = ProcuraSimb((yyvsp[-2].cadeia), escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida((yyvsp[-2].cadeia));
                            escopo = simb = 
                            InsereSimb ((yyvsp[-2].cadeia), IDPROC, NOTVAR, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            simb->funchead = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                        }
#line 2033 "lab5.tab.c"
    break;

  case 37:
#line 537 "lab5.y"
                        {
                            printf("%s (",(yyvsp[-1].cadeia));
                            declparam=TRUE;
                            simb = ProcuraSimb((yyvsp[-1].cadeia), escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida((yyvsp[-1].cadeia));
                            escopo = simb = 
                            InsereSimb ((yyvsp[-1].cadeia), IDPROC, NOTVAR, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            simb->funchead = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                            pontparam = simb->listparam;
                        }
#line 2054 "lab5.tab.c"
    break;

  case 38:
#line 554 "lab5.y"
                        {
                            printf(")\n\n");
                            declparam = FALSE;
                        }
#line 2063 "lab5.tab.c"
    break;

  case 39:
#line 560 "lab5.y"
                             {tabular(); printf("funcao ");}
#line 2069 "lab5.tab.c"
    break;

  case 40:
#line 563 "lab5.y"
                             {tabular(); printf("procedimento ");}
#line 2075 "lab5.tab.c"
    break;

  case 42:
#line 568 "lab5.y"
                                        {printf(", ");}
#line 2081 "lab5.tab.c"
    break;

  case 44:
#line 572 "lab5.y"
                        {
                            printf("%s",(yyvsp[0].cadeia));
                            simb = ProcuraSimb((yyvsp[0].cadeia), escopo);
                            if (simb !=  NULL)
                                DeclaracaoRepetida ((yyvsp[0].cadeia));
                            escaux = escopo;
                            while(escaux->escopo != NULL)
                                escaux = escaux->escopo;
                            simb = ProcuraSimb((yyvsp[0].cadeia), escaux);
                            if (simb != NULL && (simb->tid == IDFUNC||simb->tid == IDPROC))
                                DeclaracaoRepetida(strcat((yyvsp[0].cadeia),". OBS : Nao eh permitido utilizar nome de modulos como parametro."));
                            simb = InsereSimb ((yyvsp[0].cadeia),  IDVAR,  tipoCorrente, escopo);
                            simb -> array = FALSE;
                            simb -> ndims = 0;
                        }
#line 2101 "lab5.tab.c"
    break;

  case 45:
#line 589 "lab5.y"
                                {
                            if(!proxblocoehfuncao)
                                escopo = InsereSimb(NovoBloco(),IDBLOC,NOTVAR,escopo);
                        }
#line 2110 "lab5.tab.c"
    break;

  case 46:
#line 593 "lab5.y"
                              {proxblocoehfuncao = FALSE;}
#line 2116 "lab5.tab.c"
    break;

  case 47:
#line 593 "lab5.y"
                                                                    {escopo = escopo->escopo;}
#line 2122 "lab5.tab.c"
    break;

  case 48:
#line 597 "lab5.y"
                        {
                            printf("\n");
                            tabular();
                            printf("principal ");
                            simb = ProcuraSimb("principal", escopo);
                            escaux = escopo;
                            while( !simb && escaux!= NULL){
                                escaux = escaux->escopo;
                                simb = ProcuraSimb("principal", escaux);
                            }
                            if (simb){
                                DeclaracaoRepetida("Só pode haver UM UNICO módulo 'principal'");
                            }
                            printf("\n\n");
                            declparam = FALSE;
                            escopo = simb = 
                            InsereSimb ("principal", IDFUNC, NOTVAR, escopo);
                            InicCodIntermMod (simb);
                            simb->funchead = modcorrente;
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                            proxblocoehfuncao = TRUE;

                            opnd2.tipo = INTOPND;
                            opnd2.atr.valint = 0;
                            quadcorrente = codintermed->prox->listquad->prox;
                            int temp = numquadcorrente;
                            numquadcorrente = 1;

                            GeraQuadrupla(OPCALL, opnd1, opnd2, opndidle);
                            GeraQuadrupla(OPEXIT, opndidle, opndidle, opndidle);
                            quadcorrente = modcorrente->listquad;
                            numquadcorrente = temp;
                        }
#line 2163 "lab5.tab.c"
    break;

  case 50:
#line 636 "lab5.y"
                                 {tabular();printf("comandos"); tab++;}
#line 2169 "lab5.tab.c"
    break;

  case 51:
#line 636 "lab5.y"
                                                                                 {printf("\n"); tab--;}
#line 2175 "lab5.tab.c"
    break;

  case 52:
#line 639 "lab5.y"
                                       {tab--;tabular();printf("{\n");tab++;}
#line 2181 "lab5.tab.c"
    break;

  case 53:
#line 639 "lab5.y"
                                                                                              {
                            tab--;
                            tabular();
                            printf("}\n");
                            tab++;
                            if (quadcorrente->oper != OPRETURN) {
                                GeraQuadrupla(OPRETURN, opndidle, opndidle, opndidle);
                            }
                        }
#line 2195 "lab5.tab.c"
    break;

  case 66:
#line 664 "lab5.y"
                              {printf(";\n");}
#line 2201 "lab5.tab.c"
    break;

  case 67:
#line 668 "lab5.y"
                        {
                            tabular();
                            tab++;
                            printf("se (");
                        }
#line 2211 "lab5.tab.c"
    break;

  case 68:
#line 674 "lab5.y"
                        {
                            printf(")\n");
                            if ((yyvsp[-1].infoexpr).tipo != LOGICAL)
                                ExpressaoTipoInadequado(nometipvar[(yyvsp[-1].infoexpr).tipo]);
                            opndaux.tipo = ROTOPND;
                            (yyval.quad) = GeraQuadrupla(OPJF, (yyvsp[-1].infoexpr).opnd, opndidle, opndaux);
                        }
#line 2223 "lab5.tab.c"
    break;

  case 69:
#line 681 "lab5.y"
                                {
                            tab--;
                            (yyval.quad) = quadcorrente;
                            (yyvsp[-1].quad)->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2233 "lab5.tab.c"
    break;

  case 70:
#line 685 "lab5.y"
                                   {
                            if ((yyvsp[-1].quad)->prox !=quadcorrente) {
                                quadaux = (yyvsp[-1].quad)->prox;
                                (yyvsp[-1].quad)->prox = quadaux->prox;
                                quadaux->prox = (yyvsp[-1].quad)->prox->prox;
                                (yyvsp[-1].quad)->prox->prox = quadaux;
                                RenumQuadruplas((yyvsp[-1].quad), quadcorrente);
                            }
                        }
#line 2247 "lab5.tab.c"
    break;

  case 72:
#line 697 "lab5.y"
                              {
                            tabular();
                            tab++;
                            printf("senao\n");
                            opndaux.tipo = ROTOPND;
                            (yyval.quad) = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                        }
#line 2259 "lab5.tab.c"
    break;

  case 73:
#line 703 "lab5.y"
                                  {
                            tab--;
                            (yyvsp[-1].quad)->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2268 "lab5.tab.c"
    break;

  case 74:
#line 710 "lab5.y"
                        {
                            tabular();
                            tab++;
                            printf("enquanto (");
                            quadaux = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2279 "lab5.tab.c"
    break;

  case 75:
#line 717 "lab5.y"
                        {
                            printf(")");
                            if ((yyvsp[-1].infoexpr).tipo != LOGICAL)
                                ExpressaoTipoInadequado(nometipvar[(yyvsp[-1].infoexpr).tipo]);
                            printf("\n");
                            opndaux.tipo = ROTOPND;
                            (yyval.quad) = GeraQuadrupla(OPJF, (yyvsp[-1].infoexpr).opnd, opndidle, opndaux);
                        }
#line 2292 "lab5.tab.c"
    break;

  case 76:
#line 725 "lab5.y"
                                {
                            tab--;
                            opndaux.tipo = ROTOPND;
                            opndaux.atr.rotulo = quadaux;
                            (yyval.quad) = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                            (yyval.quad) = quadcorrente;
                            (yyvsp[-1].quad)->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2305 "lab5.tab.c"
    break;

  case 77:
#line 735 "lab5.y"
                                {
                            tabular();
                            tab++;
                            printf("repetir\n");
                            (yyval.quad) = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2316 "lab5.tab.c"
    break;

  case 78:
#line 740 "lab5.y"
                                                   {tab--;tabular();printf("enquanto (");}
#line 2322 "lab5.tab.c"
    break;

  case 79:
#line 741 "lab5.y"
                                  {
                            opndaux.tipo = ROTOPND;
                            opndaux.atr.rotulo = (yyvsp[-5].quad);
                            GeraQuadrupla(OPJF, (yyvsp[0].infoexpr).opnd, opndidle, opndaux);
                        }
#line 2332 "lab5.tab.c"
    break;

  case 80:
#line 746 "lab5.y"
                        {
                            printf(");");
                                if((yyvsp[-3].infoexpr).tipo != LOGICAL)
                                    ExpressaoTipoInadequado(nometipvar[(yyvsp[-3].infoexpr).tipo]);
                            printf("\n");
                        }
#line 2343 "lab5.tab.c"
    break;

  case 81:
#line 755 "lab5.y"
                             {tabular();tab++;printf("para ");}
#line 2349 "lab5.tab.c"
    break;

  case 82:
#line 757 "lab5.y"
                        {
                            if((yyvsp[0].infovar).simb != NULL){
                                (yyvsp[0].infovar).simb->ref = (yyvsp[0].infovar).simb->inic = TRUE;
                                Empilhar((yyvsp[0].infovar).simb->cadeia,&PFor);
                            }
                        }
#line 2360 "lab5.tab.c"
    break;

  case 83:
#line 764 "lab5.y"
                        {
                            printf(" (");
                            if ((yyvsp[-2].infovar).simb->tvar != INTEGER && (yyvsp[-2].infovar).simb->tvar != CHAR){
                                strcpy(msg,"tipo incompativel ");
                                strcpy(msg,strcat(msg,nometipvar[(yyvsp[-2].infovar).simb->tvar]));
                                strcpy(msg,strcat(msg," da variável de controle"));
                                Incompatibilidade(msg);
                            }
                        }
#line 2374 "lab5.tab.c"
    break;

  case 84:
#line 773 "lab5.y"
                        {
                            if((yyvsp[-1].infoexpr).tipo != INTEGER && (yyvsp[-1].infoexpr).tipo != CHAR)
                                ExpressaoTipoInadequado(nometipvar[(yyvsp[-1].infoexpr).tipo]);
                            printf("; ");
                            (yyval.quad) = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2385 "lab5.tab.c"
    break;

  case 85:
#line 780 "lab5.y"
                        {
                            if((yyvsp[0].infoexpr).tipo != LOGICAL)
                                ExpressaoTipoInadequado(nometipvar[(yyvsp[0].infoexpr).tipo]);
                            printf("; ");
                            opndaux.tipo = ROTOPND;
                            (yyval.quad) = GeraQuadrupla(OPJF, (yyvsp[0].infoexpr).opnd, opndidle, opndaux);
                        }
#line 2397 "lab5.tab.c"
    break;

  case 86:
#line 786 "lab5.y"
                                {
                            (yyval.quad) = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2405 "lab5.tab.c"
    break;

  case 87:
#line 790 "lab5.y"
                        {
                            if((yyvsp[-1].infoexpr).tipo != INTEGER && (yyvsp[-1].infoexpr).tipo != CHAR)
                                ExpressaoTipoInadequado(nometipvar[(yyvsp[-1].infoexpr).tipo]);
                            printf(")\n");
                            (yyval.quad) = quadcorrente;
                            (yyval.quad) = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2417 "lab5.tab.c"
    break;

  case 88:
#line 796 "lab5.y"
                                  {
                            tab--;
                            Desempilhar(&PFor);
                            quadaux = quadcorrente;
                            opndaux.tipo = ROTOPND;
                            opndaux.atr.rotulo = (yyvsp[-8].quad);
                            quadaux2 = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                            (yyvsp[-6].quad)->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
#line 2431 "lab5.tab.c"
    break;

  case 89:
#line 807 "lab5.y"
                                       {tabular();printf("ler (");}
#line 2437 "lab5.tab.c"
    break;

  case 90:
#line 807 "lab5.y"
                                                                             {
                            opnd1.tipo = INTOPND;
                            opnd1.atr.valint = (yyvsp[0].nargs);
                            GeraQuadrupla(OPREAD, opnd1, opndidle, opndidle);
                        }
#line 2447 "lab5.tab.c"
    break;

  case 91:
#line 811 "lab5.y"
                                      {printf(");\n");}
#line 2453 "lab5.tab.c"
    break;

  case 92:
#line 815 "lab5.y"
                        {
                            if  ((yyvsp[0].infovar).simb != NULL) (yyvsp[0].infovar).simb->inic = (yyvsp[0].infovar).simb->ref = TRUE;
                            (yyval.nargs) = 1;
                            GeraQuadrupla(PARAM, (yyvsp[0].infovar).opnd, opndidle, opndidle);
                        }
#line 2463 "lab5.tab.c"
    break;

  case 93:
#line 820 "lab5.y"
                                       {printf(", ");}
#line 2469 "lab5.tab.c"
    break;

  case 94:
#line 821 "lab5.y"
                        {
                            if  ((yyvsp[0].infovar).simb != NULL) (yyvsp[0].infovar).simb->inic = (yyvsp[0].infovar).simb->ref = TRUE;
                            (yyval.nargs) = (yyvsp[-3].nargs) + 1;
                            GeraQuadrupla(PARAM, (yyvsp[0].infovar).opnd, opndidle, opndidle);
                        }
#line 2479 "lab5.tab.c"
    break;

  case 95:
#line 828 "lab5.y"
                                            {tabular();printf("escrever (");}
#line 2485 "lab5.tab.c"
    break;

  case 96:
#line 828 "lab5.y"
                                                                                       {
                            opnd1.tipo = INTOPND;
                            opnd1.atr.valint = (yyvsp[0].nargs);
                            GeraQuadrupla(OPWRITE, opnd1, opndidle, opndidle);
                        }
#line 2495 "lab5.tab.c"
    break;

  case 97:
#line 832 "lab5.y"
                                       {printf(");\n");}
#line 2501 "lab5.tab.c"
    break;

  case 98:
#line 835 "lab5.y"
                                             {
                            (yyval.nargs) = 1;
                            GeraQuadrupla(PARAM, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                        }
#line 2510 "lab5.tab.c"
    break;

  case 99:
#line 839 "lab5.y"
                                       {printf(", ");}
#line 2516 "lab5.tab.c"
    break;

  case 100:
#line 839 "lab5.y"
                                                                {
                            (yyval.nargs) = (yyvsp[-3].nargs) + 1;
                            GeraQuadrupla(PARAM, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                        }
#line 2525 "lab5.tab.c"
    break;

  case 101:
#line 845 "lab5.y"
                                        {
                            printf("\"%s\"",(yyvsp[0].cadeia));
                            (yyval.infoexpr).opnd.tipo = CADOPND;
                            (yyval.infoexpr).opnd.atr.valcad = malloc(strlen((yyvsp[0].cadeia)) + 1);
                            strcpy((yyval.infoexpr).opnd.atr.valcad, (yyvsp[0].cadeia));
                        }
#line 2536 "lab5.tab.c"
    break;

  case 103:
#line 855 "lab5.y"
                        {
                            tabular();
                            printf("chamar %s ",(yyvsp[-1].cadeia));
                            escaux = escopo->escopo;
                            while (escaux->escopo != NULL)
                                escaux = escaux->escopo;
                            simb = ProcuraSimb((yyvsp[-1].cadeia), escaux);
                            if (simb == NULL) 
                                NaoDeclarado((yyvsp[-1].cadeia));
                            else if (simb->tid != IDPROC)
                                TipoInadequado ((yyvsp[-1].cadeia));
                            else{ 
                                escaux = escopo;
                                while(escaux->tid!=IDGLOB&&escaux->tid!=IDFUNC&&escaux->tid!=IDPROC)
                                    escaux = escaux->escopo;
                                if (simb->tid == escaux->tid && strcmp(simb->cadeia, escaux->cadeia)==0)
                                    Recursividade();
                            }
                            (yyval.simb) = simb;
                            printf("(");
                        }
#line 2562 "lab5.tab.c"
    break;

  case 104:
#line 877 "lab5.y"
                        {
                            (yyval.infovar) = (yyvsp[-3].infovar);
                            if((yyval.infovar).simb != NULL && (yyval.infovar).simb->tid == IDPROC){
                                if((yyval.infovar).simb->nparam!=(yyvsp[-2].infolexpr).nargs)
                                    Incompatibilidade("Numero de argumentos diferente do numero de parametros");
                                if((yyvsp[-2].infolexpr).nargs > 0)
                                    ChecArgumentos((yyvsp[-2].infolexpr).listtipo, (yyval.infovar).simb->listparam);
                                opnd1.tipo = MODOPND;
                                opnd1.atr.modulo = (yyval.infovar).simb->funchead;
                                opnd2.tipo = INTOPND;
                                opnd2.atr.valint = (yyvsp[-2].infolexpr).nargs;
                                GeraQuadrupla(OPCALL, opnd1, opnd2, opndidle);
                            }
                            printf(");");
                            printf("\n");
                        }
#line 2583 "lab5.tab.c"
    break;

  case 105:
#line 895 "lab5.y"
                        {(yyval.infolexpr).nargs = 0;  (yyval.infolexpr).listtipo = NULL;}
#line 2589 "lab5.tab.c"
    break;

  case 107:
#line 900 "lab5.y"
                        {
                            tabular();
                            printf("retornar;\n");
                            escaux = escopo;
                            while(escaux->tid == IDBLOC){
                                escaux = escaux->escopo;
                            }
                            if(escaux->tid!=IDFUNC&&escaux->tid!=IDPROC)
                                NaoEsperado("   Nao era esperado 'retornar'");
                            else if (escaux->tid == IDFUNC)
                                Esperado("  Era esperada expressao apos RETORNAR");
                            GeraQuadrupla(OPRETURN, opndidle, opndidle, opndidle);
                        }
#line 2607 "lab5.tab.c"
    break;

  case 108:
#line 914 "lab5.y"
                        {
                            tabular();
                            printf("retornar ");

                        }
#line 2617 "lab5.tab.c"
    break;

  case 109:
#line 920 "lab5.y"
                        {
                            escaux = escopo;
                            while(escaux->tid == IDBLOC){
                                escaux = escaux->escopo;
                            }
                            if(escaux->tid!=IDFUNC&&escaux->tid!=IDPROC)
                                NaoEsperado("   Nao era esperado 'retornar'");
                            else if (escaux->tid == IDPROC)
                                NaoEsperado("  Nao era esperada expressao apos 'retornar'");
                            if ((yyvsp[-1].infoexpr).tipo != escaux->tvar)
                                ExpressaoTipoInadequado(nometipvar[(yyvsp[-1].infoexpr).tipo]);
                            printf(";\n");
                            GeraQuadrupla(OPRETURN, (yyvsp[-1].infoexpr).opnd, opndidle, opndidle);
                        }
#line 2636 "lab5.tab.c"
    break;

  case 110:
#line 936 "lab5.y"
                        {tabular();}
#line 2642 "lab5.tab.c"
    break;

  case 111:
#line 937 "lab5.y"
                        {
                            if  ((yyvsp[0].infovar).simb != NULL){
                                (yyvsp[0].infovar).simb->inic = (yyvsp[0].infovar).simb->ref = TRUE;
                                if (Procurar ((yyvsp[0].infovar).simb->cadeia, PFor)!=NULL)
                                    AlteracaoVariavelControle((yyvsp[0].infovar).simb->cadeia);
                            }
                        }
#line 2654 "lab5.tab.c"
    break;

  case 112:
#line 944 "lab5.y"
                              {printf(" = ");}
#line 2660 "lab5.tab.c"
    break;

  case 113:
#line 945 "lab5.y"
                        {
                            printf(";\n");
                            if ((yyvsp[-5].infovar).simb != NULL)
                                if ((((yyvsp[-5].infovar).simb->tvar == INTEGER || (yyvsp[-5].infovar).simb->tvar == CHAR) &&
                                    ((yyvsp[-1].infoexpr).tipo == FLOAT || (yyvsp[-1].infoexpr).tipo == LOGICAL)) ||
                                    ((yyvsp[-5].infovar).simb->tvar == FLOAT && (yyvsp[-1].infoexpr).tipo == LOGICAL) ||
                                    ((yyvsp[-5].infovar).simb->tvar == LOGICAL && (yyvsp[-1].infoexpr).tipo != LOGICAL))
                                    Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                                if ((yyvsp[-5].infovar).simb->ndims == 0) {
                                    GeraQuadrupla (OPATRIB, (yyvsp[-1].infoexpr).opnd, opndidle, (yyvsp[-5].infovar).opnd);
                                } else {
                                    GeraQuadrupla (OPATRIBPONT, (yyvsp[-1].infoexpr).opnd, opndidle, (yyvsp[-5].infovar).opnd);
                                }
                        }
#line 2679 "lab5.tab.c"
    break;

  case 114:
#line 963 "lab5.y"
                        {
                            (yyval.infolexpr).nargs = 1;
                            (yyval.infolexpr).listtipo = InicListTipo((yyvsp[0].infoexpr).tipo);
                            GeraQuadrupla(PARAM, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                        }
#line 2689 "lab5.tab.c"
    break;

  case 115:
#line 968 "lab5.y"
                                       {printf(", ");}
#line 2695 "lab5.tab.c"
    break;

  case 116:
#line 969 "lab5.y"
                        {
                            (yyval.infolexpr).nargs = (yyval.infolexpr).nargs+1;
                            (yyval.infolexpr).listtipo = ConcatListTipo ((yyvsp[-3].infolexpr).listtipo, InicListTipo ((yyvsp[0].infoexpr).tipo));
                            GeraQuadrupla(PARAM, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                        }
#line 2705 "lab5.tab.c"
    break;

  case 118:
#line 977 "lab5.y"
                                      {printf(" || ");}
#line 2711 "lab5.tab.c"
    break;

  case 119:
#line 978 "lab5.y"
                        {
                            if ((yyvsp[-3].infoexpr).tipo != LOGICAL || (yyvsp[0].infoexpr).tipo != LOGICAL)
                                Incompatibilidade ("Operando improprio para operador or");
                            (yyval.infoexpr).tipo = LOGICAL;
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyval.infoexpr).tipo);
                            GeraQuadrupla (OPOR, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                        }
#line 2724 "lab5.tab.c"
    break;

  case 121:
#line 989 "lab5.y"
                                      {printf(" && ");}
#line 2730 "lab5.tab.c"
    break;

  case 122:
#line 990 "lab5.y"
                        {
                            if ((yyvsp[-3].infoexpr).tipo != LOGICAL || (yyvsp[0].infoexpr).tipo != LOGICAL)
                                Incompatibilidade ("Operando improprio para operador and");
                            (yyval.infoexpr).tipo = LOGICAL;
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyval.infoexpr).tipo);
                            GeraQuadrupla (OPAND, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                        }
#line 2743 "lab5.tab.c"
    break;

  case 124:
#line 1001 "lab5.y"
                            {printf("!");}
#line 2749 "lab5.tab.c"
    break;

  case 125:
#line 1002 "lab5.y"
                        {
                            if ((yyvsp[0].infoexpr).tipo != LOGICAL)
                                Incompatibilidade ("Operando improprio para operador not");
                            (yyval.infoexpr).tipo = LOGICAL;
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyvsp[0].infoexpr).tipo);
                            GeraQuadrupla (OPNOT, (yyvsp[0].infoexpr).opnd, opndidle, (yyval.infoexpr).opnd);
                        }
#line 2762 "lab5.tab.c"
    break;

  case 127:
#line 1014 "lab5.y"
                        {
                            switch((yyvsp[0].atr)){
                                case LT: printf(" < ");break;
                                case LE: printf(" <= ");break;
                                case GT: printf(" > ");break;
                                case GE: printf(" >= ");break;
                                case EQ: printf(" == ");break;
                                case NE: printf(" != ");
                            }
                        }
#line 2777 "lab5.tab.c"
    break;

  case 128:
#line 1025 "lab5.y"
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
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyval.infoexpr).tipo);
                            switch ((yyvsp[-2].atr)) {
                                case LT:
                                    GeraQuadrupla (OPLT, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                                case LE:
                                    GeraQuadrupla (OPLE, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                                case GT:
                                    GeraQuadrupla (OPGT, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                                case GE:
                                    GeraQuadrupla (OPGE, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                                case EQ:
                                    GeraQuadrupla (OPEQ, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                                case NE:
                                    GeraQuadrupla (OPNE, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                            }

                        }
#line 2818 "lab5.tab.c"
    break;

  case 130:
#line 1065 "lab5.y"
                        {
                            switch((yyvsp[0].atr)){
                                case SOMA: printf("+");break;
                                case SUB: printf("-");break;
                            }
                        }
#line 2829 "lab5.tab.c"
    break;

  case 131:
#line 1071 "lab5.y"
                        {
                            if ((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != FLOAT && (yyvsp[-3].infoexpr).tipo != CHAR 
                                || (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo!=FLOAT && (yyvsp[0].infoexpr).tipo!=CHAR)
                                Incompatibilidade ("Operando improprio para operador aritmetico");
                            if ((yyvsp[-3].infoexpr).tipo == FLOAT || (yyvsp[0].infoexpr).tipo == FLOAT) (yyval.infoexpr).tipo = FLOAT;
                            else (yyval.infoexpr).tipo = INTEGER;
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyval.infoexpr).tipo);
                            if ((yyvsp[-2].atr) == SOMA)
                                GeraQuadrupla (OPMAIS, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            else  GeraQuadrupla (OPMENOS, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                        }
#line 2846 "lab5.tab.c"
    break;

  case 133:
#line 1087 "lab5.y"
                        {
                            switch((yyvsp[0].atr)){
                                case MULT: printf(" * ");break;
                                case DIV: printf(" / ");break;
                                case MOD: printf(" %% ");break;
                            }
                        }
#line 2858 "lab5.tab.c"
    break;

  case 134:
#line 1095 "lab5.y"
                        {
                            switch ((yyvsp[-2].atr)) {
                                case MULT: case DIV:
                                    if ((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != FLOAT && (yyvsp[-3].infoexpr).tipo != CHAR
                                        || (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo!=FLOAT && (yyvsp[0].infoexpr).tipo!=CHAR)
                                        Incompatibilidade ("Operando improprio para operador aritmetico");
                                    if ((yyvsp[-3].infoexpr).tipo == FLOAT || (yyvsp[0].infoexpr).tipo == FLOAT) (yyval.infoexpr).tipo = FLOAT;
                                    else (yyval.infoexpr).tipo = INTEGER;
                                    (yyval.infoexpr).opnd.tipo = VAROPND;
                                    (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyval.infoexpr).tipo);
                                    if ((yyvsp[-2].atr) == MULT)
                                        GeraQuadrupla   (OPMULTIP, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    else  GeraQuadrupla  (OPDIV, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                                case MOD:
                                    if ((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != CHAR
                                        ||  (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                                        Incompatibilidade ("Operando improprio para operador resto");
                                    (yyval.infoexpr).tipo = INTEGER;
                                    (yyval.infoexpr).opnd.tipo = VAROPND;
                                    (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyval.infoexpr).tipo);
                                    GeraQuadrupla (OPRESTO, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                                    break;
                            }
                        }
#line 2888 "lab5.tab.c"
    break;

  case 135:
#line 1123 "lab5.y"
                        {
                            if  ((yyvsp[0].infovar).simb != NULL) {
                                (yyvsp[0].infovar).simb->ref  =  TRUE;
                                (yyval.infoexpr).tipo = (yyvsp[0].infovar).simb->tvar;
                                if ((yyvsp[0].infovar).simb->ndims == 0) {
                                    (yyval.infoexpr).opnd = (yyvsp[0].infovar).opnd;
                                } else {
                                    (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyvsp[0].infovar).simb->tvar);
                                    GeraQuadrupla(OPCONTAPONT, (yyvsp[0].infovar).opnd, opndidle, (yyval.infoexpr).opnd);
                                }

                            }
                        }
#line 2906 "lab5.tab.c"
    break;

  case 136:
#line 1136 "lab5.y"
                               {
                            printf ("%d ", (yyvsp[0].valint)); (yyval.infoexpr).tipo = INTEGER;
                            (yyval.infoexpr).opnd.tipo = INTOPND;
                            (yyval.infoexpr).opnd.atr.valint = (yyvsp[0].valint);
                         }
#line 2916 "lab5.tab.c"
    break;

  case 137:
#line 1141 "lab5.y"
                                 {
                            printf ("%g ", (yyvsp[0].valreal)); (yyval.infoexpr).tipo = FLOAT;
                            (yyval.infoexpr).opnd.tipo = REALOPND;
                            (yyval.infoexpr).opnd.atr.valfloat = (yyvsp[0].valreal);
                         }
#line 2926 "lab5.tab.c"
    break;

  case 138:
#line 1146 "lab5.y"
                                  {
                            printf ("\'%c\' ", (yyvsp[0].carac)); (yyval.infoexpr).tipo = CHAR;
                            (yyval.infoexpr).opnd.tipo = CHAROPND;
                            (yyval.infoexpr).opnd.atr.valchar = (yyvsp[0].carac);
                         }
#line 2936 "lab5.tab.c"
    break;

  case 139:
#line 1151 "lab5.y"
                                  {
                            printf ("verdade "); (yyval.infoexpr).tipo = LOGICAL;
                            (yyval.infoexpr).opnd.tipo = LOGICOPND;
                            (yyval.infoexpr).opnd.atr.vallogic = 1;
                         }
#line 2946 "lab5.tab.c"
    break;

  case 140:
#line 1156 "lab5.y"
                                {
                            printf ("falso "); (yyval.infoexpr).tipo = LOGICAL;
                            (yyval.infoexpr).opnd.tipo = LOGICOPND;
                            (yyval.infoexpr).opnd.atr.vallogic = 0;
                        }
#line 2956 "lab5.tab.c"
    break;

  case 141:
#line 1161 "lab5.y"
                            {printf("~");}
#line 2962 "lab5.tab.c"
    break;

  case 142:
#line 1162 "lab5.y"
                        {
                            if ((yyvsp[0].infoexpr).tipo != INTEGER &&
                                (yyvsp[0].infoexpr).tipo != FLOAT && (yyvsp[0].infoexpr).tipo != CHAR)
                                Incompatibilidade  ("Operando improprio para menos unario");
                            if ((yyvsp[0].infoexpr).tipo == FLOAT) (yyval.infoexpr).tipo = FLOAT;
                            else (yyval.infoexpr).tipo = INTEGER;
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp ((yyval.infoexpr).tipo);
                            GeraQuadrupla  (OPMENUN, (yyvsp[0].infoexpr).opnd, opndidle, (yyval.infoexpr).opnd);
                        }
#line 2977 "lab5.tab.c"
    break;

  case 143:
#line 1172 "lab5.y"
                              {printf("(");}
#line 2983 "lab5.tab.c"
    break;

  case 144:
#line 1172 "lab5.y"
                                                              {
                                    printf (")"); (yyval.infoexpr).tipo = (yyvsp[-1].infoexpr).tipo; (yyval.infoexpr).opnd = (yyvsp[-1].infoexpr).opnd;
                        }
#line 2991 "lab5.tab.c"
    break;

  case 145:
#line 1175 "lab5.y"
                                    {(yyval.infoexpr).tipo = (yyvsp[0].infovar).simb->tvar; (yyval.infoexpr).opnd = (yyvsp[0].infovar).opnd;}
#line 2997 "lab5.tab.c"
    break;

  case 146:
#line 1179 "lab5.y"
                        {
                            printf("%s",(yyvsp[0].cadeia));
                            escaux = escopo;
                            simb = NULL;
                            while (escaux!=NULL && simb==NULL){
                                simb = ProcuraSimb((yyvsp[0].cadeia), escaux);
                                escaux = escaux->escopo;
                            }
                            if (simb == NULL){
                                NaoDeclarado((yyvsp[0].cadeia));
                                simb  = (simbolo) malloc (sizeof(celsimb));
                                simb->cadeia = (char*)malloc((strlen((yyvsp[0].cadeia))+1)*sizeof(char));
                                strcpy(simb->cadeia,(yyvsp[0].cadeia));
                            }
                            else if (simb -> tid != IDVAR)
                                TipoInadequado ((yyvsp[0].cadeia));
                            (yyval.simb) = simb;
                            
                        }
#line 3021 "lab5.tab.c"
    break;

  case 147:
#line 1199 "lab5.y"
                        {
                            (yyval.infovar).simb = (yyvsp[-1].simb);
                            if ((yyval.infovar).simb) {
                                if ((yyval.infovar).simb->array == FALSE && (yyvsp[0].nsubscr) > 0)
                                    NaoEsperado ("Subscrito\(s)");
                                else if ((yyval.infovar).simb->array == TRUE && (yyvsp[0].nsubscr) == 0)
                                    Esperado ("Subscrito\(s)");
                                else if ((yyval.infovar).simb->ndims != (yyvsp[0].nsubscr))
                                    Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                                (yyval.infovar).opnd.tipo = VAROPND;
                                if ((yyvsp[0].nsubscr) == 0) {
                                    (yyval.infovar).opnd.atr.simb = (yyval.infovar).simb;
                                } else {
                                    (yyval.infovar).opnd.atr.simb = NovaTemp ((yyval.infovar).simb->tvar);
                                    opnd1.tipo = VAROPND;
                                    opnd1.atr.simb = (yyval.infovar).simb;
                                    opnd2.tipo = INTOPND;
                                    opnd2.atr.valint = (yyvsp[0].nsubscr);
                                    GeraQuadrupla  (OPINDEX, opnd1, opnd2, (yyval.infovar).opnd);
                                }
                            }
                        }
#line 3048 "lab5.tab.c"
    break;

  case 148:
#line 1223 "lab5.y"
                            {(yyval.nsubscr)=0;}
#line 3054 "lab5.tab.c"
    break;

  case 149:
#line 1224 "lab5.y"
                              {printf("[");}
#line 3060 "lab5.tab.c"
    break;

  case 150:
#line 1226 "lab5.y"
                        {
                            printf("]");
                            (yyval.nsubscr) = (yyvsp[-1].nsubscr);
                        }
#line 3069 "lab5.tab.c"
    break;

  case 151:
#line 1233 "lab5.y"
                        {
                            if ((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR){
                                Incompatibilidade ("Tipo inadequado para subscrito");
                            }
                            GeraQuadrupla  (OPIND, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                            (yyval.nsubscr) = 1;
                        }
#line 3081 "lab5.tab.c"
    break;

  case 152:
#line 1240 "lab5.y"
                                         {printf(", ");}
#line 3087 "lab5.tab.c"
    break;

  case 153:
#line 1241 "lab5.y"
                        {
                            if ((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                                Incompatibilidade ("Tipo inadequado para subscrito");
                            GeraQuadrupla  (OPIND, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                            (yyval.nsubscr) = (yyvsp[-3].nsubscr) + 1;
                        }
#line 3098 "lab5.tab.c"
    break;

  case 154:
#line 1250 "lab5.y"
                        {
                            
                            printf("%s ", (yyvsp[-1].cadeia));
                            escaux = escopo->escopo;
                            while(escaux->escopo!=NULL)
                                escaux = escaux->escopo;
                            simb = ProcuraSimb((yyvsp[-1].cadeia), escaux);
                            if (simb == NULL) 
                                NaoDeclarado ((yyvsp[-1].cadeia));
                            else if (simb->tid != IDFUNC)
                                TipoInadequado ((yyvsp[-1].cadeia));
                            else{ 
                                escaux = escopo;
                                while(escaux->tid!=IDGLOB&&escaux->tid!=IDFUNC&&escaux->tid!=IDPROC)
                                    escaux = escaux->escopo;
                                if (simb->tid == escaux->tid && strcmp(simb->cadeia, escaux->cadeia)==0)
                                    Recursividade();
                            }
                            (yyval.simb) = simb;
                            printf("(");
                        }
#line 3124 "lab5.tab.c"
    break;

  case 155:
#line 1271 "lab5.y"
                                          {
                            printf(")");
                            (yyval.infovar) = (yyvsp[-2].infovar);
                            if((yyval.infovar).simb && (yyval.infovar).simb->tid == IDFUNC){
                                if((yyval.infovar).simb->nparam!=(yyvsp[-1].infolexpr).nargs)
                                    Incompatibilidade("Numero de argumentos diferente do numero de parametros");
                                if ((yyvsp[-1].infolexpr).nargs > 0)
                                    ChecArgumentos((yyvsp[-1].infolexpr).listtipo, (yyval.infovar).simb->listparam);
                                opnd1.tipo = MODOPND;
                                opnd1.atr.modulo = (yyval.infovar).simb->funchead;
                                opnd2.tipo = INTOPND;
                                opnd2.atr.valint = (yyvsp[-1].infolexpr).nargs;
                                opndaux.tipo = VAROPND;
                                opndaux.atr.simb = NovaTemp((yyval.infovar).simb->tvar);
                                GeraQuadrupla(OPCALL, opnd1, opnd2, opndaux);
                                (yyval.infovar).opnd = opndaux;
                            }
                        }
#line 3147 "lab5.tab.c"
    break;


#line 3151 "lab5.tab.c"

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

#line 1295 "lab5.y"
  

#include "lex.yy.c"

void tabular () {
    int i;
    for (i = 1; i <= tab; i++)
       printf ("\t");
}

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

simbolo ProcuraSimb (char *cadeia, simbolo escopo) {
	simbolo s; int i;
	i = hash (cadeia);
	for (s = tabsimb[i]; (s!=NULL);
		s = s->prox) {
        if (strcmp(cadeia, s->cadeia) == 0) {
            if (s->escopo == escopo) break;
        }
    }

    if (s!=NULL && s->escopo!=escopo)
        s = NULL;
	return s;
}

/*
	InsereSimb (cadeia, tid, tvar): Insere cadeia na tabela de
	simbolos, com tid como tipo de identificador e com tvar como
	tipo de variavel; Retorna um ponteiro para a celula inserida
 */

simbolo InsereSimb (char *cadeia, int tid, int tvar, simbolo escopo) {
	int i; simbolo aux, s;
	i = hash (cadeia); aux = tabsimb[i];
	s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
	s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
	strcpy (s->cadeia, cadeia);
	s->tid = tid;		
    s->tvar = tvar;
	s->prox = aux;      
    s->escopo = escopo;
    s->listvardecl = NULL;
    s->listfunc = NULL;
    s->listparam = NULL;
    if (declparam){
        s->inic = s->ref = s->param = TRUE;
        if (s->tid == IDVAR)
            InsereListSimb (s, pontparam);
        s->escopo->nparam++;
    }	
    else{
        s->inic = s->ref = s->param = FALSE;
        if (s->tid == IDVAR)
            InsereListSimb (s, pontvardecl);
    }
    if (tid == IDGLOB || tid == IDFUNC || tid == IDPROC) {
        s->listvardecl = (elemlistsimb *) 
            malloc  (sizeof (elemlistsimb));
        s->listvardecl->prox = NULL;
    }
    if (tid == IDGLOB) {
        s->listfunc = (elemlistsimb *) 
            malloc  (sizeof (elemlistsimb));
        s->listfunc->prox = NULL;
    }
    if (tid == IDFUNC || tid == IDPROC) {
        s->listparam = (elemlistsimb *) malloc  (sizeof (elemlistsimb));
        s->listparam->prox = NULL;
        s->nparam = 0;
        InsereListSimb (s, pontfunc);
    }
    return s;
}

void InsereListSimb(simbolo simb, pontelemlistsimb pont){
    elemlistsimb* new_pont_elemlistsimb;
    new_pont_elemlistsimb = (pontelemlistsimb) malloc (sizeof(elemlistsimb));
    new_pont_elemlistsimb->simb = simb;
    new_pont_elemlistsimb->prox = pont->prox;
    pont->prox = new_pont_elemlistsimb;
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
                if (s->escopo!=NULL)
                    printf ("  (%s, %s, %s", s->cadeia,  nometipid[s->tid],s->escopo->cadeia);
                else
                    printf ("  (%s, %s",s->cadeia,  nometipid[s->tid] );
				if (s->tid == IDVAR){
					printf (", %s, %d, %d",
						nometipvar[s->tvar], s->inic, s->ref);
                    if (s->array == TRUE) { 
                        int j;
                        printf (", EH ARRAY\n\tndims = %d, dimensoes:", s->ndims);
                        for (j = 0; j < s->ndims; j++)
                            printf ("  %d", s->dims[j]);
                    }
                }
                printf(")\n");
			}
		}
}

/* VerificaInicRef: Verifica se variável foi inicializada e/ou referenciada. */
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

void ChecArgumentos (pontexprtipo Ltiparg, listsimb Lparam){
    pontexprtipo p;
    pontelemlistsimb q;
    p = Ltiparg->prox;
    q = Lparam->prox;
    while(p!= NULL && q!=NULL){
        switch (q->simb->tvar) {
            case INTEGER: 
            case CHAR:
                if (p->exprtipo != INTEGER && p->exprtipo != CHAR){
                    strcpy(msg,"O tipo ");
                    strcpy(msg,strcat(msg,nometipvar[p->exprtipo]));
                    strcpy(msg,strcat(msg," passado eh incompativel com o esperado para esse parametro"));
                    Incompatibilidade(msg);
                }
                break;
            case FLOAT:
                if (p->exprtipo != INTEGER &&  p->exprtipo != CHAR && 
                                p->exprtipo != FLOAT){
                    strcpy(msg,"O tipo ");
                    strcpy(msg,strcat(msg,nometipvar[p->exprtipo]));
                    strcpy(msg,strcat(msg," passado eh incompativel com o esperado para esse parametro"));
                    Incompatibilidade(msg);
                }
                break;
            case LOGICAL:
                if (p->exprtipo != LOGICAL){
                    strcpy(msg,"O tipo ");
                    strcpy(msg,strcat(msg,nometipvar[p->exprtipo]));
                    strcpy(msg,strcat(msg," passado eh incompativel com o esperado para esse parametro"));
                    Incompatibilidade(msg);
                }
                break;
            default:
                if (q->simb->tvar != p->exprtipo){
                    strcpy(msg,"O tipo ");
                    strcpy(msg,strcat(msg,nometipvar[p->exprtipo]));
                    strcpy(msg,strcat(msg," passado eh incompativel com o esperado para esse parametro"));
                    Incompatibilidade(msg);
                }
                break;
        }
        p = p->prox; q = q->prox;

    }
}

pontexprtipo InicListTipo(tipovar tipo){
    pontexprtipo p = (pontexprtipo)malloc(sizeof(elemlistexpr));
    p->prox = (pontexprtipo)malloc(sizeof(elemlistexpr));
    p->prox->exprtipo = tipo; 
    p->prox->prox = NULL;
    return p; 
}

pontexprtipo ConcatListTipo (pontexprtipo toConcatList, pontexprtipo initializedList){
    initializedList->prox->prox = toConcatList->prox;
    toConcatList->prox = initializedList->prox;
    return toConcatList;
}

char* NovoBloco(){
    int tam_bloco;
    tam_bloco = sprintf(bloco,"%d",blocos_gerados);
    strcpy(bloco,strcat("##bloco",bloco));
    blocos_gerados++;
    return bloco;
}

/*Funções para manipulação da Pilha*/

void Empilhar(char* x, pilha *P){
    noh* temp;
    temp = *P;
    *P = (noh *) malloc (sizeof (noh));
    strcpy((*P)->elem,x); 
    (*P)->prox = temp;

}
void Desempilhar (pilha *P){
    noh *temp;
   if (*P != NULL) {
      temp = *P; 
      *P = (*P)->prox; 
      free (temp);  
    }
   else  printf ("\n\n**** ERRO NA PILHA:Delecao em pilha vazia\n\n");
}
char* Topo (pilha P){
    if (P != NULL)  
        return P->elem;
    else  
        printf ("\n\n**** ERRO NA PILHA:Topo de pilha vazia\n\n");
    return NULL;
}
void InicPilha (pilha *P){
    *P = NULL;
}
bool Vazia(pilha P){
    if (P == NULL) return TRUE;
    else return FALSE;
}
noh *Procurar (char* word, pilha P){
    noh* p = P;
    while (p!= NULL && strcmp(p->elem, word)!=0)
        p = p->prox;
    return p;
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

void ExpressaoTipoInadequado (char *s) {
    printf ("\n\n*****Tipo Inadequado de Expressao: %s *****\n\n", s);
}

void Esperado (char *s) {
    printf ("\n\n***** Esperado: %s *****\n\n", s);
}

void NaoEsperado (char *s) {
    printf ("\n\n***** Nao Esperado: %s *****\n\n", s);
}
void AlteracaoVariavelControle(char *s){
    printf ("\n\n***** Alteracao em variavel de controle de 'para': %s\n\n", s);
}    
void Recursividade(){
    printf("\n\n***** Recursividade: A linguagem não admite recursividade\n\n");
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
	simb = InsereSimb (nometemp, IDVAR, tip, NULL);
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


