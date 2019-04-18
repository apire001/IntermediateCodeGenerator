%option yylineno
%{
  #include "y.tab.h"
  int col_num = 1;
  int line_num = 1;
%}

FUNCTION "function"
BEGINPARAM "beginparams"
ENDPARAM "endparams"
SEMICOLON ";"
COLON ":"
INTEGER "integer"
BEGINLOCALS "beginlocals"
ENDLOCALS "endlocals"
BEGINBODY "beginbody"
ENDBODY "endbody"
NUMBER [0-9]+
IDERROR1 [0-9][a-z|A-Z|0-9|"_"]+
IDERROR2 ["_"][a-z|A-Z|0-9|"_"]*
IDERROR3 [a-z|A-Z][a-z|A-Z|0-9|"_"]*["_"]
IDENTIFIER [a-z|A-Z][a-z|A-Z|0-9|"_"]*
SPACE [ \t]+
ARRAY "array"
OF "of"
IF "if"
THEN "then"
ENDIF "endif"
ELSE "else"
WHILE "while"
DO "do"
BEGINLOOP "beginloop"
ENDLOOP "endloop"
CONTINUE "continue"
READ "read"
WRITE "write"
AND "and"
OR "or"
NOT "not"
TRUE "true"
FALSE "false"
RETURN "return"
SUB "-"
ADD "+"
MULT "*"
DIV  "/"
MOD  "%"
EQ  "=="
NEQ "<>"
LT  "<"
GT  ">"
LTE "<="
GTE ">="
COMMA ","
R_PAREN ")"
L_PAREN "("
L_BRACKET "["
R_BRACKET "]"
ASSIGN ":="
NEWLINE "\n"
HASH "##".*"\n"

%%

{FUNCTION} {return FUNCTION; col_num += yyleng;}
{SEMICOLON} {return SEMICOLON; col_num += yyleng;}
{BEGINPARAM} {return BEGINPARAM; col_num += yyleng;}
{ENDPARAM} {return ENDPARAM; col_num += yyleng;}
{BEGINLOCALS} {return BEGINLOCALS; col_num += yyleng;}
{ENDLOCALS} {return ENDLOCALS; col_num += yyleng;}
{BEGINBODY} {return BEGINBODY; col_num += yyleng;}
{ENDBODY} {return ENDBODY; col_num += yyleng;}
{COLON} {return COLON; col_num += yyleng;}
{INTEGER} {return INTEGER; col_num += yyleng;}
{SPACE} {continue; col_num += yyleng;}
{ARRAY} {return ARRAY; col_num += yyleng;}
{OF} {return OF; col_num += yyleng;}
{IF} {return IF; col_num += yyleng;}
{THEN} {return THEN; col_num += yyleng;}
{ENDIF} {return ENDIF; col_num += yyleng;}
{ELSE} {return ELSE; col_num += yyleng;}
{WHILE} {return WHILE; col_num += yyleng;}
{DO} {return DO; col_num += yyleng;}
{BEGINLOOP} {return BEGINLOOP; col_num += yyleng;}
{ENDLOOP} {return ENDLOOP; col_num += yyleng;}
{CONTINUE} {return CONTINUE; col_num += yyleng;}
{READ} {return READ; col_num += yyleng;}
{WRITE} {return WRITE; col_num += yyleng;}
{AND} {return AND; col_num += yyleng;}
{OR} {return OR; col_num += yyleng;}
{NOT} {return NOT; col_num += yyleng;}
{TRUE} {return TRUE; col_num += yyleng;}
{FALSE} {return FALSE; col_num += yyleng;}
{RETURN} {return RETURN; col_num += yyleng;}
{SUB} {return SUB; col_num += yyleng;}
{ADD} {return ADD; col_num += yyleng;}
{MULT} {return MULT; col_num += yyleng;}
{DIV} {return DIV; col_num += yyleng;}
{MOD} {return MOD; col_num += yyleng;}
{EQ} {return EQ; col_num += yyleng;}
{NEQ} {return NEQ; col_num += yyleng;}
{LT} {return LT; col_num += yyleng;}
{LTE} {return LTE; col_num += yyleng;}
{GT}  {return GT; col_num += yyleng;}
{GTE} {return GTE; col_num += yyleng;}
{COMMA} {return COMMA; col_num += yyleng;}
{R_PAREN} {return R_PAREN; col_num += yyleng;}
{R_BRACKET} {return R_BRACKET; col_num += yyleng;}
{L_PAREN} {return L_PAREN; col_num += yyleng;}
{L_BRACKET} {return L_BRACKET; col_num += yyleng;}
{ASSIGN} {return ASSIGN; col_num += yyleng;}
{NEWLINE} {continue; col_num = 0; ++line_num;}
{HASH} {continue; col_num = 0; ++line_num;} 

{NUMBER} col_num += yyleng; yylval.ival = atoi(yytext); return NUMBER;
{IDERROR1} printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", yylineno, col_num, yytext); exit(-1);
{IDERROR2} printf("Error at line %d, column %d: identifier \"%s\" cannot start with an underscore\n", yylineno, col_num, yytext); exit(-1);
{IDERROR3} printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", yylineno, col_num, yytext); exit(-1);
{IDENTIFIER} {col_num += yyleng; yylval.s = yytext; return IDENTIFIER;}
. printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", yylineno, col_num, yytext); exit(-1);

%%
