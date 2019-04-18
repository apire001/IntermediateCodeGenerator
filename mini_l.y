/*
Andrew Pirelli
William Spalding
README:
How to run:
make clean
make
cat filename.min | parser > filename.mil  
./mil_run filename.mil < input.txt
*/
%{
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
using namespace std;
 
void yyerror(const char *msg);
extern int yylineno;
extern int line_num;
extern int col_num;
extern FILE * yyin;
int yylex(void);

//function declarations
void opFunction(string);
void spaceAllocate(int);
int findLastSpace();
int findLastContinue();
bool vectorSearch(string input, vector<string> target);
void fillTerminalSymbolTable();
void outputErrors();
 
//Counters to help calculate tags for labels, temps and continues
int tempCount = 0;
int labelCount = 0;
int continueCount = 0;

//Tables used for code generation
vector<string> symbol_table;
vector<string> equation_table;
vector<string> cond_table;
vector<string> function_table;
vector<string> variable_table;
vector<string> array_table;
vector<string> terminal_symbol_table;
  
//Stack for program
vector<string> program_stack;
 
//Stack of generated code
vector<string> generated_code;
 
//temporary vector for intermediate storage
vector<string> temp_vector;

//vector to store error string messages
vector<string> error_messages;

//Flag to check if in loop
bool loopFlag = false;

%}

%union{
  int ival;
  char* s;
}

%error-verbose
%start input
%token <s> MULT DIV ADD SUB MOD EQUAL L_PAREN R_PAREN END PROGRAM BEGIN_PROGRAM END_PROGRAM ELSEIF FUNCTION BEGINPARAM ENDPARAM BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO IN BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_BRACKET R_BRACKET ASSIGN
%type <s> idents
%type <s> ident
%type <s> rel_expr
%type <s> expr
%type <s> mult_expr
%type <s> term
%type <s> var
%type <s> param_dec
%type <s> dec

%token <ival> NUMBER
%token <s> IDENTIFIER

%left SUB ADD
%left MULT DIV MOD

%nonassoc NOT
%nonassoc USUB


%% 
input: 
    funcs {
        if (vectorSearch("main", function_table) != true) {
            //error 3
            yyerror("Not defining a main function.");
        }
        outputErrors();
        //cout << terminal_symbol_table.at(0) << endl;
    }
    ;
        
funcs: {
        //funcs -> epsilon
        //do nothing
    }
    | 
    func {
        //cout << "Entered funcs\n";
        variable_table.clear(); 
        array_table.clear();
        //rest handled in func
    } 
    funcs {
        //do nothing, handled by next funcs call
    }
    ;

func: 
    FUNCTION ident SEMICOLON { 
        //cout << "Entered func\n";
        function_table.push_back(symbol_table.back());
        cout << "func " << symbol_table.back() << endl; 
        symbol_table.pop_back();
    } 
    BEGINPARAM param_decs ENDPARAM BEGINLOCALS decs ENDLOCALS BEGINBODY stats ENDBODY {
        for(int i = 0; i < generated_code.size(); i++){
            cout << generated_code.at(i) << endl;
        }
        generated_code.clear();
        cout << "endfunc\n\n";
    }
    ;

decs: {
        //do nothing
    }  
    | 
    dec SEMICOLON decs {
        //do nothing
    }
    ;
        
dec: 
    idents COLON INTEGER {
        //cout << "Entered dec\n";
        for( int i = 0; i < symbol_table.size(); i++){
          	if (vectorSearch(symbol_table.at(i), variable_table) == false) {
          		if (vectorSearch(symbol_table.at(i), terminal_symbol_table) == false) {
          			cout << ". " << symbol_table.at(i) << endl;
					variable_table.push_back(symbol_table.at(i));
          		}
          		else {
          		    //error 5
          			yyerror("Trying to name a variable with the same name as a reserved keyword.");
          		}
          	}
          	else {
          	    //error 4
          		yyerror("Defining a variable more than once.");
          	}
        }
        symbol_table.clear();
    }
    | 
    idents COLON ARRAY L_BRACKET NUMBER[num] R_BRACKET OF INTEGER {
        //cout << "Entered dec pt2\n";
        cout << ".[] " << symbol_table.back() << ", " << $num << endl;
		variable_table.push_back(symbol_table.back());
		array_table.push_back(symbol_table.back());
        symbol_table.pop_back();
        //for(int i = 0; i < symbol_table.size(); ++i){
        //    cout << symbol_table.at(i);
        //}
    }  
	;

param_decs: {
        //param_decs -> epsilon
        //do nothing
    }
    | 
    param_dec SEMICOLON param_decs {
        //cout << "Entered param_decs\n";
        //handled in param_dec
    }
    ;
        
param_dec: 
    idents COLON INTEGER {
        //cout << "Entered param_dec\n";
        if (vectorSearch(symbol_table.back(), variable_table) == false) {
     		if (vectorSearch(symbol_table.back(), terminal_symbol_table) == false) {
      			cout << ". " << symbol_table.back() << endl;
      			cout << "= " << symbol_table.back() << ", $0" << endl; 
      			//cout << "$0 is: " << $0 << "\n";
      			variable_table.push_back(symbol_table.back());
      			symbol_table.pop_back();
      		}
      		else {
      			yyerror("Trying to name a variable with the same name as a reserved keyword");
      			}
    		}
    	else {
    		yyerror("Defining a variable more than once");
    	}
    } 
    | 
    idents COLON ARRAY L_BRACKET NUMBER[num] R_BRACKET OF INTEGER {
        //cout << "Entered param_dec bottom\n";
        if ($num <= 0) {
        	yyerror("Declaring an array of size <= 0");
        }
        else {
            if ($num <= 0) {
                yyerror("Declaring an array of size <= 0");
        	}
            else {
                cout << ".[] " << symbol_table.back() << ", " << $num << endl;
    			array_table.push_back(symbol_table.back());
    			//cout << "$num is: " << $num << "\n";
    			variable_table.push_back(symbol_table.back());
            	symbol_table.pop_back();
            }
        }
    }  
    ;
                   
idents: 
    ident {
        //do nothing, handled by ident
    }
    |   
    ident COMMA idents {
        //do nothing, handled by ident
    }
	;

ident: 
    IDENTIFIER{
        //add identifier to symbol table
        symbol_table.push_back($1);
    }
    ;

stats: {
        //stats -> epsilon
        //do nothing
    }
    | 
    stat SEMICOLON stats {
        //do nothing, handled by stat
    }
    ;
                       
stat: 
    var ASSIGN expr {
        //cout << "Entered stat1\n";
        if(symbol_table.back() == "[]"){ 
            symbol_table.pop_back();
            string temp2 = temp_vector.back();
            temp_vector.pop_back();
            //cout << "temp2 is: " << temp2 << "\n";
            string temp1 = temp_vector.back();
            temp_vector.pop_back();
            //cout << "temp1 is: " << temp1 << "\n";
            generated_code.push_back("[]= " + symbol_table.back() + ", " + temp1 + ", " + temp2);
            symbol_table.pop_back();
        }
        else {
            generated_code.push_back("= " + symbol_table.back() + ", " + temp_vector.back());
            //cout << "symbol_table.back is: " << symbol_table.back() << "\n";
            //cout << "temp_vector.back is: " << temp_vector.back() << "\n";
            symbol_table.pop_back();
            temp_vector.pop_back();
        }
    }
    | 
    if_stat ENDIF {
        //cout << "Entered stat2\n";
        //cout << "labelCount is: " << labelCount << "\n";
        generated_code.push_back(": __label__" + to_string(labelCount+1));
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
        generated_code.at(findLastSpace()) = ":= __label__" + to_string(labelCount+1);
        generated_code.at(findLastSpace()) = "?:= __label__" + to_string(labelCount) + ", " + cond_table.back();
        labelCount+=2;
        cond_table.pop_back();                    
    }
    | 
    if_stat ELSE {
        //cout << "Entered stat3\n";
        spaceAllocate(2);
    } 
    stats ENDIF {
        //cout << "Entered stat3 pt2\n";
        //cout << "labelCount is: " << labelCount << "\n";
        generated_code.push_back(": __label__" + to_string(labelCount+2));
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount+1); 
        generated_code.at(findLastSpace()) = ":=  __label__" + to_string(labelCount+2);
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
        generated_code.at(findLastSpace()) = ":= __label__" + to_string(labelCount+1);
        generated_code.at(findLastSpace()) = "?:= __label__" + to_string(labelCount) + ", " + cond_table.back();
        labelCount+=3;
        cond_table.pop_back();
    }                
    |   
    WHILE {
        //cout << "Entered stat4\n";
        loopFlag = true; 
        generated_code.push_back("_ALLOCATED_SPACE_");
    } 
    bool_expr {
        //cout << "Entered stat4 pt2\n";
        spaceAllocate(3);
    } 
    BEGINLOOP {
        loopFlag = true;
    } 
    stat SEMICOLON stats ENDLOOP{
        //cout << "Entered stat4 pt3\n";
        if(continueCount){
            generated_code.push_back(": __label__" + to_string(labelCount+3));
            generated_code.at(findLastContinue()) = ":= __label__" + to_string(labelCount+3);
        } 
        generated_code.push_back(":= __label__" + to_string(labelCount+2));
        generated_code.push_back(": __label__" + to_string(labelCount+1));
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
      	generated_code.at(findLastSpace()) = ":= __label__" + to_string(labelCount+1);
      	generated_code.at(findLastSpace()) = "?:= __label__" + to_string(labelCount) + ", " + cond_table.back();
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount+2);
      	labelCount+=3;
        if(continueCount){
            labelCount++;
            continueCount--;
        }
        cond_table.pop_back();
    }
    |   
    DO {
        //cout << "Entered stat5\n";
        generated_code.push_back("_ALLOCATED_SPACE_");
        loopFlag = true;
        
    } 
    BEGINLOOP stat SEMICOLON stats ENDLOOP WHILE bool_expr { 
        //cout << "Entered stat5 pt2\n";
        if(continueCount){
            generated_code.push_back(": __label__" + to_string(labelCount+1));
            generated_code.at(findLastContinue()) = ":= __label__" + to_string(labelCount+1);
        }                      
        generated_code.push_back("?:= __label__" + to_string(labelCount) + ", " + temp_vector.back());  
        generated_code.at(findLastSpace()) = ": __label__" + to_string(labelCount);
        labelCount++;
        if(continueCount){
            labelCount++;
            continueCount--;
        }
		loopFlag = false; 
        temp_vector.pop_back();                  
    }                
    |   
    READ vars {
        //cout << "Entered stat6\n";
        for(int i = 0; i < symbol_table.size(); i++){
            generated_code.push_back(".< " + symbol_table.at(i));
        }
        symbol_table.clear();
    }
    |  
    WRITE vars {
        //cout << "Entered stat7\n";
        if(symbol_table.back() == "[]") {
            symbol_table.pop_back();
            generated_code.push_back(".[]> " + symbol_table.back() + ", " + temp_vector.back());
            temp_vector.pop_back();
            symbol_table.pop_back();
        }
        else { 
            for(int i = 0; i < symbol_table.size(); i++){
                generated_code.push_back(".> " + symbol_table.at(i));
            }
            symbol_table.clear();
        }
    }
    |   
    CONTINUE {
        //cout << "Entered stat8\n";
        if(loopFlag == false){
            yyerror("Using continue statement outside a loop");
        }
        else{
            generated_code.push_back("_ALLOCATED_CONTINUE_");
            continueCount++;
        }
    }
    |   
    RETURN expr {
        //cout << "Entered stat9\n";
        generated_code.push_back("ret " + temp_vector.back());
        temp_vector.pop_back();
    } 
    ;
       
if_stat: 
    IF bool_expr {
        spaceAllocate(3);
    } 
    THEN stat SEMICOLON stats {
        //do nothing, handled by stat
    }
    ;       

vars:
    var {
        //do nothing, handled by var
    }
    |   
    vars COMMA var {
        //do nothing, handled by var
    }
    ;
      
var: 
    ident {
        if (vectorSearch(symbol_table.back(), variable_table) != true)  {
			yyerror("Using a variable without having first declared it");
		}
	} 
    |   
    ident L_BRACKET expr R_BRACKET {
        if (vectorSearch(symbol_table.back(), variable_table) != true)  {
		    yyerror("Using a variable without having first declared it");
		}
		else {
		    if (vectorSearch(symbol_table.back(), array_table) == true) {
                symbol_table.push_back("[]");
		    }
			else {
				yyerror("Specifying an array index when using a regular integer variable");
			}
		}
    }
    ;

expr: 
    mult_expr{
        //do nothing, handled by mult_expr
    } 
    |
    expr ADD mult_expr {
        opFunction("+ ");
    }
    |   
    expr SUB mult_expr {
        opFunction("- ");
    }
    ;

mult_expr: term {
        //do nothing, handled by term
    }
    |   
    mult_expr MULT term {
        opFunction("* ");
    }
    |   
    mult_expr DIV term {
        opFunction("/ ");
    }
    |   
    mult_expr MOD term {
        opFunction("% ");
    }
    ;

exprs: 
    expr {
        //do nothing, handled by expr
    } 
    |  
    expr COMMA exprs {
        //do nothing, handled by expr
    }
    ;

term: SUB term %prec USUB {
        //do nothing, handled by other cases
    }
    |   
    NUMBER {
        //cout << "Entered term NUMBER\n";
        string temp = "__temp__" + to_string(tempCount);
        ostringstream oss;
        oss << $1;
        generated_code.push_back(". " + temp);
        generated_code.push_back("= " + temp + ", " + oss.str());
        temp_vector.push_back(temp);
        //cout << temp_vector.back() << endl;
        ++tempCount;
    }
    |   
    var {
        //cout << "Entered term var\n";
        string temp = "__temp__" + to_string(tempCount);
        generated_code.push_back(". " + temp);
        //cout << generated_code.back() << endl;
        if(symbol_table.back() == "[]"){
            symbol_table.pop_back();
            generated_code.push_back("=[] " + temp + ", " + symbol_table.back() + ", " + temp_vector.back());
            //cout << generated_code.back() << endl;
            temp_vector.pop_back();                      
        }
        else {
            generated_code.push_back("= " + temp + ", " + symbol_table.back());
            //cout << generated_code.back() << endl;
        }
        symbol_table.pop_back();
        temp_vector.push_back(temp);
        //cout << temp_vector.back() << endl;
        ++tempCount;
    }
    |   
    L_PAREN expr R_PAREN {
        //do nothing, handled by expr
    }
    |   
    ident L_PAREN {
        //push identifier to program stack
        program_stack.push_back($1);
    } 
    exprs R_PAREN {
        string s = program_stack.back();
        s = s.substr(0,s.size()-2);
        if (vectorSearch(s, function_table) == true) {
            generated_code.push_back("param " + temp_vector.back());
            //cout << generated_code.back() << endl;
          	temp_vector.pop_back();
          	string temp = "__temp__" + to_string(tempCount);
          	generated_code.push_back(". " + temp);
          	//cout << generated_code.back() << endl;
          	generated_code.push_back("call " + s + ", " + temp);
          	//cout << generated_code.back() << endl;
          	temp_vector.push_back(temp);
          	program_stack.pop_back();
          	symbol_table.pop_back();
          	tempCount++;
        }
        else {
          	yyerror("Calling a function which has not been defined");
        }
    } 
    |   
    ident L_PAREN {
        program_stack.push_back($1);
    } 
    R_PAREN {
        string s = program_stack.back();
        s = s.substr(0,s.size()-2);
        if (vectorSearch(s, function_table) == true) {
            string temp = "__temp__" + to_string(tempCount);
          	generated_code.push_back(". " + temp);
          	//cout << generated_code.back() << endl;
          	generated_code.push_back("call " + s + ", " + temp);
          	//cout << generated_code.back() << endl;
          	temp_vector.push_back(temp);
          	program_stack.pop_back();
          	symbol_table.pop_back();
          	tempCount++;
        }
        else {
          	yyerror("Calling a function which has not been defined");
        }
    }                        
    ;
    
comp: 
    EQ {
        equation_table.push_back("== ");
    } 
    |  
    NEQ {
        equation_table.push_back("!= ");
    } 
    |  
    LT {
        equation_table.push_back("< ");
    } 
    |  
    GT {
        equation_table.push_back("> ");
    } 
    |  
    LTE {
        equation_table.push_back("<= ");
    } 
    |  
    GTE {
        equation_table.push_back(">= ");
    } 
    ;
    
bool_expr: 
    rel_and_exp {
        //do nothing, handled by rel_and_expr
    }
    |   
    bool_expr OR rel_and_exp {
        opFunction("|| ");
    }
    ;

rel_and_exp:  
    rel_expr {
        //do nothing, handled by rel_expr
    }
    |  
    rel_and_exp AND rel_expr {
        opFunction("&& ");
    }
    ;

rel_expr: 
    NOT rel_expr %prec NOT {
        //do nothing, handled by other cases
    }
    |  
    expr comp expr {
        opFunction(equation_table.back());
        equation_table.pop_back();
    }
    |  
    TRUE { 
        string temp = "__temp__" + to_string(tempCount);
        generated_code.push_back(". " + temp);
        //cout << generated_code.back() << endl;
        generated_code.push_back("= " + temp + ", 1");
        //cout << generated_code.back() << endl;
        temp_vector.push_back(temp);
        ++tempCount;
    }                  
    |  
    FALSE { 
        string temp = "__temp__" + to_string(tempCount);
        generated_code.push_back(". " + temp);
        //cout << generated_code.back() << endl;
        generated_code.push_back("= " + temp + ", 0");
        //cout << generated_code.back() << endl;
        temp_vector.push_back(temp);
        ++tempCount;
    }  
    |  
    L_PAREN bool_expr R_PAREN {
        //do nothing, handled by bool_expr
    }
    ;
    
%%

int main(int argc, char **argv) {
   fillTerminalSymbolTable();
   yyparse();
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", yylineno, col_num, msg);
}

//returns true if vector contains string, othwerwise false
bool vectorSearch(string input, vector<string> target) {
	for (unsigned i = 0; i < target.size(); ++i) {
		if (target.at(i) == input) {
			   return true;
		}
	}
	return false;
}

//allocates space for embedded calls
void spaceAllocate(int spaces) {
    //cout << "Called spaceAllocate for " << spaces << " spaces" << endl;
    generated_code.push_back("_ALLOCATED_SPACE_");
    generated_code.push_back("_ALLOCATED_SPACE_");
    if(spaces == 3) {
        generated_code.push_back("_ALLOCATED_SPACE_"); 
        cond_table.push_back(temp_vector.back());
        temp_vector.pop_back();
    }
}

//fills terminal symbol table with names of terminal symbols to check against
void fillTerminalSymbolTable(){
    //cout << "Called fillTerminalSymbolTable" << endl;
    terminal_symbol_table.push_back("*"); 
    terminal_symbol_table.push_back("/");  
    terminal_symbol_table.push_back("+"); 
    terminal_symbol_table.push_back("-");  
    terminal_symbol_table.push_back("%");  
    terminal_symbol_table.push_back("=");  
    terminal_symbol_table.push_back("(");  
    terminal_symbol_table.push_back(")"); 
    terminal_symbol_table.push_back("end"); 
    terminal_symbol_table.push_back("beginprogram");  
    terminal_symbol_table.push_back("endprogram");  
    terminal_symbol_table.push_back("elseif"); 
    terminal_symbol_table.push_back("function"); 
    terminal_symbol_table.push_back("beginparams"); 
    terminal_symbol_table.push_back("endparams"); 
    terminal_symbol_table.push_back("beginlocals"); 
    terminal_symbol_table.push_back("endlocals"); 
    terminal_symbol_table.push_back("beginbody"); 
    terminal_symbol_table.push_back("endbody"); 
    terminal_symbol_table.push_back("integer"); 
    terminal_symbol_table.push_back("array"); 
    terminal_symbol_table.push_back("["); 
    terminal_symbol_table.push_back("]"); 
    terminal_symbol_table.push_back("[]"); 
    terminal_symbol_table.push_back("of"); 
    terminal_symbol_table.push_back("if"); 
    terminal_symbol_table.push_back("then"); 
    terminal_symbol_table.push_back("endif"); 
    terminal_symbol_table.push_back("else"); 
    terminal_symbol_table.push_back("while"); 
    terminal_symbol_table.push_back("do"); 
    terminal_symbol_table.push_back("in"); 
    terminal_symbol_table.push_back("beginloop"); 
    terminal_symbol_table.push_back("endloop"); 
    terminal_symbol_table.push_back("continue"); 
    terminal_symbol_table.push_back("read"); 
    terminal_symbol_table.push_back("write"); 
    terminal_symbol_table.push_back("&&");
    terminal_symbol_table.push_back("and"); 
    terminal_symbol_table.push_back("or");
    terminal_symbol_table.push_back("||");
    terminal_symbol_table.push_back("true"); 
    terminal_symbol_table.push_back("false"); 
    terminal_symbol_table.push_back("return"); 
    terminal_symbol_table.push_back("=="); 
    terminal_symbol_table.push_back("!="); 
    terminal_symbol_table.push_back("<"); 
    terminal_symbol_table.push_back(">"); 
    terminal_symbol_table.push_back(">="); 
    terminal_symbol_table.push_back("<="); 
    terminal_symbol_table.push_back(";"); 
    terminal_symbol_table.push_back(":"); 
    terminal_symbol_table.push_back(",");
    return;
}

//finds last open space in generated code
int findLastSpace() {
    //cout << "Called findLastSpace" << endl;
    for(int i = generated_code.size()-1; i >= 0; i--){
        if(generated_code.at(i) == "_ALLOCATED_SPACE_") {
            //cout << "findLastSpace i is " << i << endl;
            return i;
        }
    }
    //cout << "findLastSpace did not find allocated space" << endl;
    return -1;
}

//finds last occurrence of continue in generated code
int findLastContinue() {
    //cout << "Called findLastContinue" << endl;
    for(int i = generated_code.size()-1; i >= 0; i--){
        if(generated_code.at(i) == "_ALLOCATED_CONTINUE_") {
            //cout << "findLastContinue i is " << i << endl;
            return i;
        }
    }
    //cout << "findLastContinue did not find allocated continue" << endl;
    return -1;
}

//handles operation statements
void opFunction(string op) {
    //cout << "Called opFunction" << endl;
    string temp = "__temp__" + to_string(tempCount);
    string src2 = temp_vector.back();
    temp_vector.pop_back();
    string src1 = temp_vector.back();
    temp_vector.pop_back();
    generated_code.push_back(". " + temp);
    //cout << generated_code.back() << endl;
    generated_code.push_back(op + temp + ", " + src1 + ", " + src2);
    //cout << generated_code.back() << endl;
    temp_vector.push_back(temp);
    tempCount++;
    return;
}

void outputErrors(){
    return;
}