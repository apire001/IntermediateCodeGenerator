%option yylineno

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
SPACE [ \t]*
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
HASH ["##" .* "\n"]
	int col_num = 0;
%%

{FUNCTION} {printf("FUNCTION\n"); col_num += yyleng;}
{SEMICOLON} {printf("SEMICOLON\n"); col_num += yyleng;}
{BEGINPARAM} {printf("BEGIN_PARAMS\n"); col_num += yyleng;}
{ENDPARAM} {printf("END_PARAMS\n"); col_num += yyleng;}
{BEGINLOCALS} {printf("BEGIN_LOCALS\n"); col_num += yyleng;}
{ENDLOCALS} {printf("END_LOCALS\n"); col_num += yyleng;}
{BEGINBODY} {printf("BEGIN_BODY\n"); col_num += yyleng;}
{ENDBODY} {printf("END_BODY\n"); col_num += yyleng;}
{COLON} {printf("COLON\n"); col_num += yyleng;}
{INTEGER} {printf("INTEGER\n"); col_num += yyleng;}
{SPACE} {continue; col_num += yyleng;}
{ARRAY} {printf("ARRAY\n"); col_num += yyleng;}
{OF} {printf("OF\n"); col_num += yyleng;}
{IF} {printf("IF\n"); col_num += yyleng;}
{THEN} {printf("THEN\n"); col_num += yyleng;}
{ENDIF} {printf("ENDIF\n"); col_num += yyleng;}
{ELSE} {printf("ELSE\n"); col_num += yyleng;}
{WHILE} {printf("WHILE\n"); col_num += yyleng;}
{DO} {printf("DO\n"); col_num += yyleng;}
{BEGINLOOP} {printf("BEGINLOOP\n"); col_num += yyleng;}
{ENDLOOP} {printf("ENDLOOP\n"); col_num += yyleng;}
{CONTINUE} {printf("CONTINUE\n"); col_num += yyleng;}
{READ} {printf("READ\n"); col_num += yyleng;}
{WRITE} {printf("WRITE\n"); col_num += yyleng;}
{AND} {printf("AND\n"); col_num += yyleng;}
{OR} {printf("OR\n"); col_num += yyleng;}
{NOT} {printf("NOT\n"); col_num += yyleng;}
{TRUE} {printf("TRUE\n"); col_num += yyleng;}
{FALSE} {printf("FALSE\n"); col_num += yyleng;}
{RETURN} {printf("RETURN\n"); col_num += yyleng;}
{SUB} {printf("SUB\n"); col_num += yyleng;}
{ADD} {printf("ADD\n"); col_num += yyleng;}
{MULT} {printf("MULT\n"); col_num += yyleng;}
{DIV} {printf("DIV\n"); col_num += yyleng;}
{MOD} {printf("MOD\n"); col_num += yyleng;}
{EQ} {printf("EQ\n"); col_num += yyleng;}
{NEQ} {printf("NEQ\n"); col_num += yyleng;}
{LT} {printf("LT\n"); col_num += yyleng;}
{LTE} {printf("LTE\n"); col_num += yyleng;}
{GT}  {printf("GT\n"); col_num += yyleng;}
{GTE} {printf("GTE\n"); col_num += yyleng;}
{COMMA} {printf("COMMA\n"); col_num += yyleng;}
{R_PAREN} {printf("R_PAREN\n"); col_num += yyleng;}
{R_BRACKET} {printf("R_SQUARE_BRACKET\n"); col_num += yyleng;}
{L_PAREN} {printf("L_PAREN\n"); col_num += yyleng;}
{L_BRACKET} {printf("L_SQUARE_BRACKET\n"); col_num += yyleng;}
{ASSIGN} {printf("ASSIGN\n"); col_num += yyleng;}
{NEWLINE} {continue; col_num += yyleng;}
{HASH} continue; 

{NUMBER} printf("NUMBER %s\n", yytext);
{IDERROR1} printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", yylineno, col_num, yytext); exit(-1);
{IDERROR2} printf("Error at line %d, column %d: identifier \"%s\" cannot start with an underscore\n", yylineno, col_num, yytext); exit(-1);
{IDERROR3} printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", yylineno, col_num, yytext); exit(-1);
{IDENTIFIER} printf("IDENT %s\n", yytext);
. printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", yylineno, col_num, yytext); exit(-1);
%%


main(){
    yylex();
}



