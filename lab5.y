%{
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

char *nomeoperquad[28] = {"",
	"OR", "AND", "LT", "LE", "GT", "GE", "EQ", "NE", "MAIS",
	"MENOS", "MULT", "DIV", "RESTO", "MENUN", "NOT", "ATRIB",
	"OPENMOD", "NOP", "JUMP", "JF", "PARAM", "READ", "WRITE", "IND", "INDEX", "CONTAPONT", "ATRIBPONT"
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

/*    Declaracoes para a tabela de simbolos     */

struct celsimb {
	char *cadeia;
	int tid, tvar,nparam, ndims, dims[MAXDIMS+1];
	char inic, ref, array, param;
    listsimb listvardecl, listparam, listfunc;
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

quadrupla quadcorrente, quadaux, quadaux2;
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

%}
%union {
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
}
%type	    <infovar>	        Variavel   ChamadaFunc ChamadaProc
%type 	    <infoexpr> 	    Expressao  ExprAux1  ExprAux2
                            ExprAux3   ExprAux4   Termo   Fator ElemEscr

%type       <nsubscr>       Subscritos  ListSubscr
%type       <nargs>         ListLeit    ListEscr
%type       <infolexpr>     ListExpr   Argumentos

%token	    <cadeia>    ID		    	
%token	   	<carac>     CTCARAC	    	
%token	    <valint>    CTINT		    
%token	    <valreal>   CTREAL		    
%token      <cadeia>    CADEIA		

%token	    <atr>        OPREL		    
%token	    <atr>        OPAD	    	
%token	    <atr>        OPMULT		    
%token	    NEG		    	

%token      CARAC			
%token      CHAMAR			
%token 	    COMANDOS		
%token		ENQUANTO		
%token		ESCREVER		
%token		FALSO			
%token		FUNCAO			
%token		INT				
%token		LER				
%token		LOGIC			
%token		PARA			
%token		PRINCIPAL		
%token		PROCEDIMENTO	
%token		PROGRAMA		
%token		REAL			
%token		REPETIR			
%token 	    RETORNAR		
%token		SE				
%token		SENAO			
%token		VAR				
%token		VERDADE			

%token	    OR		    	
%token	    AND		    	
%token	    NOT		    	

%token	    ATRIB	    	
%token	    ABPAR	    	
%token	    FPAR	    	
%token	    ABCOL	    	
%token	    FCOL	    	
%token	    ABCHAV	    	
%token	    FCHAV	    	
%token	    ABTRIP	    	
%token	    FTRIP	    	
%token	    PVIRG	    	
%token	    VIRG
%token		<carac>         INVAL

%%
Prog	        :	    {
                            InicTabSimb ();
                            InicCodIntermed();
                            numtemp = 0;
                            InicPilha(&PFor);
                            declparam=FALSE;
                            escopo = simb = InsereSimb("##global", IDGLOB, NOTVAR, NULL);
                            pontvardecl = simb->listvardecl;
                            pontfunc = simb->listfunc;
                        
                        }
                        PROGRAMA  ID    ABTRIP  {
                            tabular(); tab++; 
                            printf("programa %s {{{\n\n", $3);
                            simb = InsereSimb ($3, IDPROG, NOTVAR, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                        } Decls  ListMod	ModPrincipal  FTRIP {
                            tab--; tabular(); printf ("}}}\n");
                            VerificaInicRef ();
                            ImprimeTabSimb ();
                            ImprimeQuadruplas ();
                        }
                ;
                 
Decls 		    :	
                |       VAR  ABCHAV {
                            tabular();
                            printf("var {\n"); 
                            tab++;
                        }  ListDecl  FCHAV {
                            tab--; 
                            tabular();
                            printf("}\n\n");
                        }
                ;
                
ListDecl	    :	    Declaracao  
                |       ListDecl  Declaracao
                ;
                
Declaracao 	    :	    {tabular();} Tipo  ABPAR {printf("(");} ListElem  FPAR  {
                            printf(")\n");
                        }
                ;
                
Tipo			:   	INT  {printf ("int "); tipoCorrente = INTEGER;}
                |       REAL  {printf ("real "); tipoCorrente = FLOAT;}
                |       CARAC {printf ("carac "); tipoCorrente = CHAR;}
                |       LOGIC {printf ("logic "); tipoCorrente = LOGICAL;}
                ;
                
ListElem    	:	    Elem  
                |       ListElem  VIRG {printf(", ");}  Elem 
                ;
                
Elem        	:	    ID 
                        {
                            printf ("%s", $1);
                            simb = ProcuraSimb($1, escopo);
                            if (simb !=  NULL)
                                DeclaracaoRepetida ($1);
                            else{
                                simb = InsereSimb ($1,  IDVAR,  tipoCorrente, escopo);
                                simb -> array = FALSE;
                                simb -> ndims = 0;
                            }
                        }  
                        Dims
                ;
                
Dims          	:	
                |       ABCOL {printf("[");} ListDim FCOL{printf("]"); simb->array = TRUE;}  
                ;
                
ListDim	        : 	    CTINT  
                        {
                            printf ("%d", $1);
                            if ($1 <= 0)
                                Esperado("Valor inteiro positivo");
                            simb->ndims++;
                            simb->dims[simb->ndims-1] = $1;
                        }
                |       ListDim  VIRG  CTINT 
                        {
                            printf(", %d",$3);
                            if ($3 <= 0)
                                Esperado("Valor inteiro positivo");
                            simb->ndims++;
                            simb->dims[simb->ndims-1] = $3;    
                        }
                ;
                
ListMod 	    :
                |       ListMod  Modulo
                ;
                
Modulo        	:	    Cabecalho  {proxblocoehfuncao = TRUE;} Corpo
                ;
                
Cabecalho     	:   	CabFunc  
                |       CabProc
                ;

CabFunc	    	:   	FUNCAO PrintaFuncao Tipo  ID 
                        
                        ABPAR  FPAR
                        {
                            printf("%s ()\n\n",$4);
                            simb = ProcuraSimb($4, escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida($4);
                            escopo = simb = 
                            InsereSimb ($4, IDFUNC, tipoCorrente, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                        }
              	|   	FUNCAO PrintaFuncao Tipo  ID 
                        
                        ABPAR
                        {
                            printf("%s (",$4);
                            declparam = TRUE;
                            simb = ProcuraSimb($4, escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida($4);
                            escopo = simb = 
                            InsereSimb ($4, IDFUNC, tipoCorrente, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                            pontparam = simb->listparam;
                        }
                        ListParam  FPAR 
                        {
                            printf(")\n\n");
                            declparam = FALSE;
                        }
                ;
                    
CabProc	    	:   	PROCEDIMENTO PrintaProcedimento  ID 
                        
                        ABPAR  FPAR 
                        {
                            printf("%s ()\n\n",$3);
                            simb = ProcuraSimb($3, escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida($3);
                            escopo = simb = 
                            InsereSimb ($3, IDPROC, NOTVAR, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                        }  
              	|   	PROCEDIMENTO PrintaProcedimento  ID 
                        
                        ABPAR 
                        {
                            printf("%s (",$3);
                            declparam=TRUE;
                            simb = ProcuraSimb($3, escopo);
                            if (simb != NULL)
                                DeclaracaoRepetida($3);
                            escopo = simb = 
                            InsereSimb ($3, IDPROC, NOTVAR, escopo);
                            InicCodIntermMod (simb);
                            opnd1.tipo = MODOPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla (OPENMOD, opnd1, opndidle, opndidle);
                            pontvardecl = simb->listvardecl;
                            pontparam = simb->listparam;
                        }
                        ListParam  FPAR 
                        {
                            printf(")\n\n");
                            declparam = FALSE;
                        }   
                ;

PrintaFuncao         :       {tabular(); printf("funcao ");} 
                ;

PrintaProcedimento   :       {tabular(); printf("procedimento ");}
                ;


ListParam   	:   	Parametro  
                |       ListParam  VIRG {printf(", ");}  Parametro
                ;
                
Parametro   	:   	Tipo  ID
                        {
                            printf("%s",$2);
                            simb = ProcuraSimb($2, escopo);
                            if (simb !=  NULL)
                                DeclaracaoRepetida ($2);
                            escaux = escopo;
                            while(escaux->escopo != NULL)
                                escaux = escaux->escopo;
                            simb = ProcuraSimb($2, escaux);
                            if (simb != NULL && (simb->tid == IDFUNC||simb->tid == IDPROC))
                                DeclaracaoRepetida(strcat($2,". OBS : Nao eh permitido utilizar nome de modulos como parametro."));
                            simb = InsereSimb ($2,  IDVAR,  tipoCorrente, escopo);
                            simb -> array = FALSE;
                            simb -> ndims = 0;
                        }
                ;
                
Corpo     	    :   	{
                            if(!proxblocoehfuncao)
                                escopo = InsereSimb(NovoBloco(),IDBLOC,NOTVAR,escopo);
                        } 
                        Decls {proxblocoehfuncao = FALSE;} Comandos {escopo = escopo->escopo;}
                ;
                
ModPrincipal  	:   	PRINCIPAL 
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
                            pontvardecl = simb->listvardecl;
                            proxblocoehfuncao = TRUE;
                        }
                        Corpo
                ;
                
Comandos      	:   	COMANDOS {tabular();printf("comandos"); tab++;}  CmdComp {printf("\n"); tab--;}
                ;
                
CmdComp 		:   	ABCHAV {tab--;tabular();printf("{\n");tab++;}  ListCmd  FCHAV {tab--;tabular();printf("}\n");tab++;} 
                ;
                    
ListCmd 		:
                |       ListCmd  Comando
                ;
                
Comando         :       CmdComp  
                |       CmdSe  
                |       CmdEnquanto  
                |       CmdRepetir
            	|       CmdPara  
                |       CmdLer  
                |       CmdEscrever  
                |       CmdAtrib
            	|   	ChamadaProc  
                |       CmdRetornar  
                |       PVIRG {printf(";\n");}
                ;
                
CmdSe		    :   	SE  ABPAR 
                        {
                            tabular();
                            tab++;
                            printf("se (");
                        }
                        Expressao  FPAR
                        {
                            printf(")\n");
                            if ($4.tipo != LOGICAL)
                                ExpressaoTipoInadequado(nometipvar[$4.tipo]);
                            opndaux.tipo = ROTOPND;
                            $<quad>$ = GeraQuadrupla(OPJF, $4.opnd, opndidle, opndaux);
                        } 
                        Comando {
                            tab--;
                            $<quad>$ = quadcorrente;
                            $<quad>6->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        } CmdSenao {
                            if ($<quad>8->prox !=quadcorrente) {
                                quadaux = $<quad>8->prox;
                                $<quad>8->prox = quadaux->prox;
                                quadaux->prox = $<quad>8->prox->prox;
                                $<quad>8->prox->prox = quadaux;
                                RenumQuadruplas($<quad>8, quadcorrente);
                            }
                        }
                ;
                
CmdSenao		:
                |       SENAO {
                            tabular();
                            tab++;
                            printf("senao\n");
                            opndaux.tipo = ROTOPND;
                            $<quad>$ = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                        } Comando {
                            tab--;
                            $<quad>2->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
                ;
                
CmdEnquanto   	:	    ENQUANTO  ABPAR 
                        {
                            tabular();
                            tab++;
                            printf("enquanto (");
                            quadaux = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
                        Expressao  FPAR 
                        {
                            printf(")");
                            if ($4.tipo != LOGICAL)
                                ExpressaoTipoInadequado(nometipvar[$4.tipo]);
                            printf("\n");
                            opndaux.tipo = ROTOPND;
                            $<quad>$ = GeraQuadrupla(OPJF, $4.opnd, opndidle, opndaux);
                        }
                        Comando {
                            tab--;
                            opndaux.tipo = ROTOPND;
                            opndaux.atr.rotulo = quadaux;
                            $<quad>$ = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                            $<quad>$ = quadcorrente;
                            $<quad>6->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
                ;
                
CmdRepetir  	:       REPETIR {
                            tabular();
                            tab++;
                            printf("repetir\n");
                            $<quad>$ = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        } Comando  ENQUANTO  ABPAR {tab--;tabular();printf("enquanto (");} 
                        Expressao {
                            opndaux.tipo = ROTOPND;
                            opndaux.atr.rotulo = $<quad>2;
                            GeraQuadrupla(OPJF, $7.opnd, opndidle, opndaux);
                        } FPAR  PVIRG
                        {
                            printf(");");
                                if($7.tipo != LOGICAL)
                                    ExpressaoTipoInadequado(nometipvar[$7.tipo]);
                            printf("\n");
                        }

                ;
                
CmdPara	    	:       PARA {tabular();tab++;printf("para ");} 
                        Variavel 
                        {
                            if($3.simb != NULL){
                                $3.simb->ref = $3.simb->inic = TRUE;
                                Empilhar($3.simb->cadeia,&PFor);
                            }
                        }
                        ABPAR 
                        {
                            printf(" (");
                            if ($3.simb->tvar != INTEGER && $3.simb->tvar != CHAR){
                                strcpy(msg,"tipo incompativel ");
                                strcpy(msg,strcat(msg,nometipvar[$3.simb->tvar]));
                                strcpy(msg,strcat(msg," da variável de controle"));
                                Incompatibilidade(msg);
                            }
                        } ExprAux4  PVIRG 
                        {
                            if($7.tipo != INTEGER && $7.tipo != CHAR)
                                ExpressaoTipoInadequado(nometipvar[$7.tipo]);
                            printf("; ");
                            $<quad>$ = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
                        Expressao  
                        {
                            if($10.tipo != LOGICAL)
                                ExpressaoTipoInadequado(nometipvar[$10.tipo]);
                            printf("; ");
                            opndaux.tipo = ROTOPND;
                            $<quad>$ = GeraQuadrupla(OPJF, $10.opnd, opndidle, opndaux);
                        } PVIRG {
                            $<quad>$ = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
                        ExprAux4  FPAR
                        {
                            if($14.tipo != INTEGER && $14.tipo != CHAR)
                                ExpressaoTipoInadequado(nometipvar[$14.tipo]);
                            printf(")\n");
                            $<quad>$ = quadcorrente;
                            $<quad>$ = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        } Comando {
                            tab--;
                            Desempilhar(&PFor);
                            quadaux = quadcorrente;
                            opndaux.tipo = ROTOPND;
                            opndaux.atr.rotulo = $<quad>9;
                            quadaux2 = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                            $<quad>11->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                        }
                ;
                
CmdLer   	    :       LER  ABPAR {tabular();printf("ler (");} ListLeit {
                            opnd1.tipo = INTOPND;
                            opnd1.atr.valint = $4;
                            GeraQuadrupla(OPREAD, opnd1, opndidle, opndidle);
                        } FPAR  PVIRG {printf(");\n");}
                ;
                    
ListLeit		:       Variavel                    
                        {
                            if  ($1.simb != NULL) $1.simb->inic = $1.simb->ref = TRUE;
                            $$ = 1;
                            GeraQuadrupla(PARAM, $1.opnd, opndidle, opndidle);
                        }
                |       ListLeit  VIRG {printf(", ");}  Variavel
                        {
                            if  ($4.simb != NULL) $4.simb->inic = $4.simb->ref = TRUE;
                            $$ = $1 + 1;
                            GeraQuadrupla(PARAM, $4.opnd, opndidle, opndidle);
                        }
                ;
                
CmdEscrever   	:	    ESCREVER  ABPAR {tabular();printf("escrever (");} ListEscr {
                            opnd1.tipo = INTOPND;
                            opnd1.atr.valint = $4;
                            GeraQuadrupla(OPWRITE, opnd1, opndidle, opndidle);
                        } FPAR  PVIRG  {printf(");\n");}
                ;
                
ListEscr		:	    ElemEscr {
                            $$ = 1;
                            GeraQuadrupla(PARAM, $1.opnd, opndidle, opndidle);
                        }
                |       ListEscr  VIRG {printf(", ");} ElemEscr {
                            $$ = $1 + 1;
                            GeraQuadrupla(PARAM, $4.opnd, opndidle, opndidle);
                        }
                ;
                
ElemEscr		:   	CADEIA  {
                            printf("\"%s\"",$1);
                            $$.opnd.tipo = CADOPND;
                            $$.opnd.atr.valcad = malloc(strlen($1) + 1);
                            strcpy($$.opnd.atr.valcad, $1);
                        }
                |       Expressao
                ;
                
ChamadaProc   	:	    CHAMAR  ID  ABPAR
                        {
                            tabular();
                            printf("chamar %s ",$2);
                            escaux = escopo->escopo;
                            while (escaux->escopo != NULL)
                                escaux = escaux->escopo;
                            simb = ProcuraSimb($2, escaux);
                            if (simb == NULL) 
                                NaoDeclarado($2);
                            else if (simb->tid != IDPROC)
                                TipoInadequado ($2);
                            else{ 
                                escaux = escopo;
                                while(escaux->tid!=IDGLOB&&escaux->tid!=IDFUNC&&escaux->tid!=IDPROC)
                                    escaux = escaux->escopo;
                                if (simb->tid == escaux->tid && strcmp(simb->cadeia, escaux->cadeia)==0)
                                    Recursividade();
                            }
                            $<simb>$ = simb;
                            printf("(");
                        }
                        Argumentos  FPAR  PVIRG
                        {
                            $$ = $<infovar>4;
                            if($$.simb != NULL && $$.simb->tid == IDPROC){
                                if($$.simb->nparam!=$5.nargs)
                                    Incompatibilidade("Numero de argumentos diferente do numero de parametros");
                                if($5.nargs > 0)
                                    ChecArgumentos($5.listtipo, $$.simb->listparam);
                            }
                            printf(");");
                            printf("\n");
                        } 
                ;

Argumentos    	:       {$$.nargs = 0;  $$.listtipo = NULL;} 
                |       ListExpr /* default: $$ = $1; */
                ;

CmdRetornar  	:	    RETORNAR  PVIRG 
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
                        } 
                |       RETORNAR  
                        {
                            tabular();
                            printf("retornar ");

                        } Expressao  
                        PVIRG 
                        {
                            escaux = escopo;
                            while(escaux->tid == IDBLOC){
                                escaux = escaux->escopo;
                            }
                            if(escaux->tid!=IDFUNC&&escaux->tid!=IDPROC)
                                NaoEsperado("   Nao era esperado 'retornar'");
                            else if (escaux->tid == IDPROC)
                                NaoEsperado("  Nao era esperada expressao apos 'retornar'");
                            if ($3.tipo != escaux->tvar)
                                ExpressaoTipoInadequado(nometipvar[$3.tipo]);
                            printf(";\n");
                        }
                ;

CmdAtrib      	:   	{tabular();} Variavel 
                        {
                            if  ($2.simb != NULL){
                                $2.simb->inic = $2.simb->ref = TRUE;
                                if (Procurar ($2.simb->cadeia, PFor)!=NULL)
                                    AlteracaoVariavelControle($2.simb->cadeia);
                            }
                        } 
                        ATRIB {printf(" = ");} Expressao  PVIRG
                        {
                            printf(";\n");
                            if ($2.simb != NULL)
                                if ((($2.simb->tvar == INTEGER || $2.simb->tvar == CHAR) &&
                                    ($6.tipo == FLOAT || $6.tipo == LOGICAL)) ||
                                    ($2.simb->tvar == FLOAT && $6.tipo == LOGICAL) ||
                                    ($2.simb->tvar == LOGICAL && $6.tipo != LOGICAL))
                                    Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                        }
                        
                ;

ListExpr		:   	Expressao
                        {
                            $$.nargs = 1;
                            $$.listtipo = InicListTipo($1.tipo);
                        }
                |       ListExpr  VIRG {printf(", ");} Expressao
                        {
                            $$.nargs = $$.nargs+1;
                            $$.listtipo = ConcatListTipo ($1.listtipo, InicListTipo ($4.tipo));
                        }
                ;

Expressao     	:   	ExprAux1  
                |       Expressao  OR {printf(" || ");} ExprAux1
                        {
                            if ($1.tipo != LOGICAL || $4.tipo != LOGICAL)
                                Incompatibilidade ("Operando improprio para operador or");
                            $$.tipo = LOGICAL;
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp ($$.tipo);
                            GeraQuadrupla (OPOR, $1.opnd, $4.opnd, $$.opnd);
                        }
                ;

ExprAux1    	:   	ExprAux2  
                |       ExprAux1  AND {printf(" && ");} ExprAux2
                        {
                            if ($1.tipo != LOGICAL || $4.tipo != LOGICAL)
                                Incompatibilidade ("Operando improprio para operador and");
                            $$.tipo = LOGICAL;
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp ($$.tipo);
                            GeraQuadrupla (OPAND, $1.opnd, $4.opnd, $$.opnd);
                        }
                ;

ExprAux2    	:   	ExprAux3  
                |       NOT {printf("!");} ExprAux3
                        {
                            if ($3.tipo != LOGICAL)
                                Incompatibilidade ("Operando improprio para operador not");
                            $$.tipo = LOGICAL;
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp ($3.tipo);
                            GeraQuadrupla (OPNOT, $3.opnd, opndidle, $$.opnd);
                        }
                ;

ExprAux3    	:   	ExprAux4   
                |       ExprAux4  OPREL 
                        {
                            switch($2){
                                case LT: printf(" < ");break;
                                case LE: printf(" <= ");break;
                                case GT: printf(" > ");break;
                                case GE: printf(" >= ");break;
                                case EQ: printf(" == ");break;
                                case NE: printf(" != ");
                            }
                        }
                        ExprAux4
                        {
                            switch ($2) {
                                case LT: case LE: case GT: case GE:
                                    if ($1.tipo != INTEGER && $1.tipo != FLOAT && $1.tipo != CHAR || $4.tipo != INTEGER && $4.tipo != FLOAT && $4.tipo != CHAR)
                                        Incompatibilidade	("Operando improprio para operador relacional");
                                    break;
                                case EQ: case NE:
                                    if (($1.tipo == LOGICAL || $4.tipo == LOGICAL) && $1.tipo != $4.tipo)
                                        Incompatibilidade ("Operando improprio para operador relacional");
                                    break;
                            }
                            $$.tipo = LOGICAL;
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp ($$.tipo);
                            switch ($2) {
                                case LT:
                                    GeraQuadrupla (OPLT, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                                case LE:
                                    GeraQuadrupla (OPLE, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                                case GT:
                                    GeraQuadrupla (OPGT, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                                case GE:
                                    GeraQuadrupla (OPGE, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                                case EQ:
                                    GeraQuadrupla (OPEQ, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                                case NE:
                                    GeraQuadrupla (OPNE, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                            }

                        }
                ;

ExprAux4    	:   	Termo  
                |       ExprAux4  OPAD 
                        {
                            switch($2){
                                case SOMA: printf("+");break;
                                case SUB: printf("-");break;
                            }
                        } Termo 
                        {
                            if ($1.tipo != INTEGER && $1.tipo != FLOAT && $1.tipo != CHAR 
                                || $4.tipo != INTEGER && $4.tipo!=FLOAT && $4.tipo!=CHAR)
                                Incompatibilidade ("Operando improprio para operador aritmetico");
                            if ($1.tipo == FLOAT || $4.tipo == FLOAT) $$.tipo = FLOAT;
                            else $$.tipo = INTEGER;
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp ($$.tipo);
                            if ($2 == SOMA)
                                GeraQuadrupla (OPMAIS, $1.opnd, $4.opnd, $$.opnd);
                            else  GeraQuadrupla (OPMENOS, $1.opnd, $4.opnd, $$.opnd);
                        }
                ;

Termo  	    	:   	Fator  
                |       Termo  OPMULT 
                        {
                            switch($2){
                                case MULT: printf(" * ");break;
                                case DIV: printf(" / ");break;
                                case MOD: printf(" %% ");break;
                            }
                        } 
                        Fator 
                        {
                            switch ($2) {
                                case MULT: case DIV:
                                    if ($1.tipo != INTEGER && $1.tipo != FLOAT && $1.tipo != CHAR
                                        || $4.tipo != INTEGER && $4.tipo!=FLOAT && $4.tipo!=CHAR)
                                        Incompatibilidade ("Operando improprio para operador aritmetico");
                                    if ($1.tipo == FLOAT || $4.tipo == FLOAT) $$.tipo = FLOAT;
                                    else $$.tipo = INTEGER;
                                    $$.opnd.tipo = VAROPND;
                                    $$.opnd.atr.simb = NovaTemp ($$.tipo);
                                    if ($2 == MULT)
                                        GeraQuadrupla   (OPMULTIP, $1.opnd, $4.opnd, $$.opnd);
                                    else  GeraQuadrupla  (OPDIV, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                                case MOD:
                                    if ($1.tipo != INTEGER && $1.tipo != CHAR
                                        ||  $4.tipo != INTEGER && $4.tipo != CHAR)
                                        Incompatibilidade ("Operando improprio para operador resto");
                                    $$.tipo = INTEGER;
                                    $$.opnd.tipo = VAROPND;
                                    $$.opnd.atr.simb = NovaTemp ($$.tipo);
                                    GeraQuadrupla (OPRESTO, $1.opnd, $4.opnd, $$.opnd);
                                    break;
                            }
                        }
                ;

Fator		    :   	Variavel  
                        {
                            if  ($1.simb != NULL) {
                                $1.simb->ref  =  TRUE;
                                $$.tipo = $1.simb->tvar;
                                $$.opnd = $1.opnd;
                            }
                        }  
                |       CTINT  {
                            printf ("%d ", $1); $$.tipo = INTEGER;
                            $$.opnd.tipo = INTOPND;
                            $$.opnd.atr.valint = $1;
                         }
                |        CTREAL  {
                            printf ("%g ", $1); $$.tipo = FLOAT;
                            $$.opnd.tipo = REALOPND;
                            $$.opnd.atr.valfloat = $1;
                         }
                |        CTCARAC  {
                            printf ("\'%c\' ", $1); $$.tipo = CHAR;
                            $$.opnd.tipo = CHAROPND;
                            $$.opnd.atr.valchar = $1;
                         }
            	|        VERDADE  {
                            printf ("verdade "); $$.tipo = LOGICAL;
                            $$.opnd.tipo = LOGICOPND;
                            $$.opnd.atr.vallogic = 1;
                         }
            	|        FALSO  {
                            printf ("falso "); $$.tipo = LOGICAL;
                            $$.opnd.tipo = LOGICOPND;
                            $$.opnd.atr.vallogic = 0;
                        }
                |       NEG {printf("~");} Fator
                        {
                            if ($3.tipo != INTEGER &&
                                $3.tipo != FLOAT && $3.tipo != CHAR)
                                Incompatibilidade  ("Operando improprio para menos unario");
                            if ($3.tipo == FLOAT) $$.tipo = FLOAT;
                            else $$.tipo = INTEGER;
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp ($$.tipo);
                            GeraQuadrupla  (OPMENUN, $3.opnd, opndidle, $$.opnd);
                        }
                |   	ABPAR {printf("(");} Expressao  FPAR  {
                                    printf (")"); $$.tipo = $3.tipo; $$.opnd = $3.opnd;
                        }
                |       ChamadaFunc {$$.tipo = $1.simb->tvar;}
                ;

Variavel		:   	ID 
                        {
                            printf("%s",$1);
                            escaux = escopo;
                            simb = NULL;
                            while (escaux!=NULL && simb==NULL){
                                simb = ProcuraSimb($1, escaux);
                                escaux = escaux->escopo;
                            }
                            if (simb == NULL){
                                NaoDeclarado($1);
                                simb  = (simbolo) malloc (sizeof(celsimb));
                                simb->cadeia = (char*)malloc((strlen($1)+1)*sizeof(char));
                                strcpy(simb->cadeia,$1);
                            }
                            else if (simb -> tid != IDVAR)
                                TipoInadequado ($1);
                            $<simb>$ = simb;
                            
                        } 
                        Subscritos
                        {
                            $$.simb = $<simb>2;
                            if ($$.simb) {
                                if ($$.simb->array == FALSE && $3 > 0)
                                    NaoEsperado ("Subscrito\(s)");
                                else if ($$.simb->array == TRUE && $3 == 0)
                                    Esperado ("Subscrito\(s)");
                                else if ($$.simb->ndims != $3)
                                    Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                                $$.opnd.tipo = VAROPND;
                                if ($3 == 0) {
                                    $$.opnd.atr.simb = $$.simb;
                                } else {
                                    $$.opnd.atr.simb = NovaTemp ($$.simb->tvar);
                                }
                            }
                        }
                ;

Subscritos    	:	    {$$=0;}
                |       ABCOL {printf("[");} ListSubscr  
                        FCOL 
                        {
                            printf("]");
                            $$ = $3;
                        }  
                ;

ListSubscr  	:   	ExprAux4  
                        {
                            if ($1.tipo != INTEGER && $1.tipo != CHAR){
                                Incompatibilidade ("Tipo inadequado para subscrito");
                            }
                            GeraQuadrupla  (OPIND, $1.opnd, opndidle, opndidle);
                            $$ = 1;
                        }
                |       ListSubscr  VIRG {printf(", ");} ExprAux4
                        {
                            if ($4.tipo != INTEGER && $4.tipo != CHAR)
                                Incompatibilidade ("Tipo inadequado para subscrito");
                            GeraQuadrupla  (OPIND, $4.opnd, opndidle, opndidle);
                            $$ = $1 + 1;
                        }
                ;

ChamadaFunc     :   	ID ABPAR 
                        {
                            
                            printf("%s ", $1);
                            escaux = escopo->escopo;
                            while(escaux->escopo!=NULL)
                                escaux = escaux->escopo;
                            simb = ProcuraSimb($1, escaux);
                            if (simb == NULL) 
                                NaoDeclarado ($1);
                            else if (simb->tid != IDFUNC)
                                TipoInadequado ($1);
                            else{ 
                                escaux = escopo;
                                while(escaux->tid!=IDGLOB&&escaux->tid!=IDFUNC&&escaux->tid!=IDPROC)
                                    escaux = escaux->escopo;
                                if (simb->tid == escaux->tid && strcmp(simb->cadeia, escaux->cadeia)==0)
                                    Recursividade();
                            }
                            $<simb>$ = simb;
                            printf("(");
                        }
                         Argumentos  FPAR {
                            printf(")");
                            $$ = $<infovar>3;
                            if($$.simb && $$.simb->tid == IDFUNC){
                                if($$.simb->nparam!=$4.nargs)
                                    Incompatibilidade("Numero de argumentos diferente do numero de parametros");
                                if ($4.nargs > 0)
                                    ChecArgumentos($4.listtipo, $$.simb->listparam);
                            }
                        }
                ;





%%  

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


