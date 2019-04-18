%{ 
#include <stdio.h> 
#include <stdlib.h> 
void yyerror(const char *msg); 
extern int col_num; 
extern int yylineno; 
 
%} 
%union
{  
  int ival;
  char *s; 
} 

%error-verbose 
%start input
%token FUNCTION BEGINPARAM ENDPARAM SEMICOLON COLON INTEGER BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE COMMA R_PAREN L_PAREN L_BRACKET R_BRACKET ASSIGN NEWLINE
 
%token <ival> NUMBER
%token <s> IDENTIFIER

%left SUB ADD 
%left MULT DIV MOD
%left EQ NEQ LT GT LTE GTE

%right NOT
%right AND OR
%right ASSIGN

%%
input: funcs {printf("input -> funcs \n");};

funcs: {printf("funcs -> epsilon \n");} | func funcs {printf("funcs -> func funcs \n");}

func: FUNCTION ident SEMICOLON BEGINPARAM decs ENDPARAM BEGINLOCALS decs ENDLOCALS BEGINBODY stats ENDBODY {printf("FUNCTION ident SEMICOLON BEGINPARAM decs ENDPARAM BEGINLOCALS decs ENDLOCALS BEGINBODY stats ENDBODY \n");};

decs: {printf("decs -> epsilon \n");} | dec SEMICOLON decs {printf("decs -> dec SEMICOLON decs \n");}

dec: idents COLON INTEGER {printf("dec -> idents COLON INTEGER \n");} | idents COLON ARRAY L_BRACKET NUMBER R_BRACKET OF INTEGER {printf("dec -> idents COLON ARRAY L_BRACKET NUMBER R_BRACKET OF INTEGER \n");};

idents: ident {printf("idents -> ident \n");} | ident COMMA idents {printf("idents ->  ident COMMA idents\n");};

ident: IDENTIFIER {printf("ident -> IDENTIFIER %s \n", $1);};

stats: {printf("stats -> epsilon");} | stat SEMICOLON stats {printf("stats -> stat SEMICOLON stats \n");};

stat: READ vars {printf("stat -> READ vars \n");} | vars ASSIGN expr {printf("stat -> vars ASSIGN expr \n");} | CONTINUE {printf("stat -> CONTINUE\n");} | IF bool_expr THEN stats ENDIF {printf("stat -> IF bool_expr THEN stats ENDIF\n");} | DO BEGINLOOP stats ENDLOOP WHILE bool_expr {printf("stat -> DO BEGINLOOP stats ENDLOOP WHILE bool_expr\n");} | WRITE vars {printf("stat -> WRITE vars\n");} | RETURN expr {printf("stat -> RETURN expr\n");} | IF bool_expr THEN stats ELSE stats ENDIF {printf("stat -> IF bool_expr THEN stats ELSE stats ENDIF\n");} | WHILE bool_expr BEGINLOOP stats ENDLOOP {printf("stat -> WHILE bool_expr BEGINLOOP stats ENDLOOP\n");};

vars: var {printf("vars -> var\n");} | var COMMA vars {printf("vars -> var COMMA vars\n");};

var: ident {printf("var -> ident\n");} | ident L_BRACKET expr R_BRACKET {printf("var -> ident L_BRACKET expr R_BRACKET\n");};

expr: mult_expr {printf("expr -> mult_expr\n");} | expr ADD mult_expr {printf("expr -> expr ADD mult_expr\n");} | expr SUB mult_expr {printf("expr -> expr SUB mult_expr\n");};

mult_expr: term {printf("mult_expr -> term\n");} | mult_expr MOD term {printf("mult_expr -> term MOD term\n");} | mult_expr DIV term {printf("mult_expr -> term DIV term\n");} | mult_expr MULT term {printf("mult_expr -> term MULT term\n");};

exprs: expr {printf("exprs -> expr\n");} | expr COMMA exprs {printf("exprs -> expr COMMA exprs\n");};

term: var {printf("term -> var\n");} | NUMBER {printf("term -> NUMBER \n");} | L_PAREN expr R_PAREN {printf("term -> L_PAREN expr R_PAREN\n");} | SUB var {printf("term -> SUB var\n");} | SUB NUMBER {printf("term -> SUB NUMBER \n");} | SUB L_PAREN expr R_PAREN {printf("term -> SUB L_PAREN expr R_PAREN\n");} | ident L_PAREN exprs R_PAREN {printf("term -> ident L_PAREN exprs R_PAREN\n");}; 

comp: EQ {printf("comp -> EQ\n");} | LT {printf("comp -> LT\n");} | GT {printf("comp -> GT\n");} | GTE {printf("comp -> GTE\n");} | LTE {printf("comp -> LTE\n");} | NEQ {printf("comp -> NEQ\n");};

bool_expr: rel_and_expr {printf("bool_expr -> rel_and_expr\n");} | bool_expr OR rel_and_expr {printf("bool_expr -> bool_expr OR rel_and_expr\n");};

rel_and_expr: rel_expr {printf("bool_expr -> rel_and_expr\n");} | rel_and_expr AND rel_expr {printf("bool_expr -> rel_and_expr AND rel_expr\n");};

rel_expr: expr comp expr {printf("rel_expr -> expr comp expr\n");} | TRUE {printf("rel_expr -> TRUE\n");} | FALSE {printf("rel_expr -> FALSE\n");} | L_PAREN bool_expr R_PAREN {printf("rel_expr -> L_PAREN bool_expr R_PAREN\n");} | NOT expr comp expr {printf("rel_expr -> NOT expr comp expr\n");} | NOT TRUE {printf("rel_expr -> NOT TRUE\n");} | NOT FALSE {printf("rel_expr -> NOT FALSE\n");} | NOT L_PAREN bool_expr R_PAREN {printf("rel_expr -> NOT L_PAREN bool_expr R_PAREN\n");};

%%

int main(int argc, char** argv)
{
  yyparse();
  return 0;
}

void yyerror(const char *message)
{
  printf("** line: %d, position: %d \n %s \n", yylineno, col_num, message);
}


