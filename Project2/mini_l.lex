%option yylineno
%{
    #include "mini_l.tab.h"
    int col num = 0;
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

{FUNCTION} {col_num += yyleng; return FUNCTION;}
{SEMICOLON} {col_num += yyleng; return SEMICOLON;}
{BEGINPARAM} {col_num += yyleng; return BEGINPARAM;}
{ENDPARAM} {col_num += yyleng; return ENDPARAM;}
{BEGINLOCALS} {col_num += yyleng; return BEGINLOCALS;}
{ENDLOCALS} {col_num += yyleng; return ENDLOCALS;}
{BEGINBODY} {col_num += yyleng; return BEGINBODY;}
{ENDBODY} {col_num += yyleng; return ENDBODY;}
{COLON} {col_num += yyleng; return COLON;}
{INTEGER} {col_num += yyleng; return INTEGER;}
{SPACE} {col_num += yyleng; continue;}
{ARRAY} {col_num += yyleng; return ARRAY;}
{OF} {col_num += yyleng; return OF;}
{IF} {col_num += yyleng; return IF;}
{THEN} {col_num += yyleng; return THEN;}
{ENDIF} {col_num += yyleng; return ENDIF;}
{ELSE} {col_num += yyleng; return ELSE;}
{WHILE} {col_num += yyleng; return WHILE;}
{DO} {col_num += yyleng; return DO;}
{BEGINLOOP} {col_num += yyleng; return BEGINLOOP;}
{ENDLOOP} {col_num += yyleng; return ENDLOOP;}
{CONTINUE} {col_num += yyleng; return CONTINUE;}
{READ} {col_num += yyleng; return READ;}
{WRITE} {col_num += yyleng; return WRITE;}
{AND} {col_num += yyleng; return AND;}
{OR} {col_num += yyleng; return OR;}
{NOT} {col_num += yyleng; return NOT;}
{TRUE} {col_num += yyleng; return TRUE;}
{FALSE} {col_num += yyleng; return FALSE;}
{RETURN} {col_num += yyleng; return RETURN;}
{SUB} {col_num += yyleng; return SUB;}
{ADD} {col_num += yyleng; return ADD;}
{MULT} {col_num += yyleng; return MULT;}
{DIV} {col_num += yyleng; return DIV;}
{MOD} {col_num += yyleng; return MOD;}
{EQ} {col_num += yyleng; return EQ;}
{NEQ} {col_num += yyleng; return NEQ;}
{LT} {col_num += yyleng; return LT;}
{LTE} {col_num += yyleng; return LTE;}
{GT}  {col_num += yyleng; return GT;}
{GTE} {col_num += yyleng; return GTE;}
{COMMA} {col_num += yyleng; return COMMA;}
{R_PAREN} {col_num += yyleng; return R_PAREN;}
{R_BRACKET} {col_num += yyleng; return R_BRACKET;}
{L_PAREN} {col_num += yyleng; return L_PAREN;}
{L_BRACKET} {col_num += yyleng; return L_BRACKET;}
{ASSIGN} {col_num += yyleng; return ASSIGN;}
{NEWLINE} {col_num = 0; continue;}
{HASH} {col_num = 0; continue;} 

{NUMBER} col_num += yyleng; yylval.ival = atoi(yytext); return NUMBER;
{IDERROR1} printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", yylineno, col_num, yytext); exit(-1);
{IDERROR2} printf("Error at line %d, column %d: identifier \"%s\" cannot start with an underscore\n", yylineno, col_num, yytext); exit(-1);
{IDERROR3} printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", yylineno, col_num, yytext); exit(-1);
{IDENTIFIER} {col_num += yyleng; yylval.s = yytext; return IDENTIFIER;}
. printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", yylineno, col_num, yytext); exit(-1);
%%


