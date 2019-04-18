/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MULT = 258,
    DIV = 259,
    ADD = 260,
    SUB = 261,
    MOD = 262,
    EQUAL = 263,
    L_PAREN = 264,
    R_PAREN = 265,
    END = 266,
    PROGRAM = 267,
    BEGIN_PROGRAM = 268,
    END_PROGRAM = 269,
    ELSEIF = 270,
    FUNCTION = 271,
    BEGINPARAM = 272,
    ENDPARAM = 273,
    BEGINLOCALS = 274,
    ENDLOCALS = 275,
    BEGINBODY = 276,
    ENDBODY = 277,
    INTEGER = 278,
    ARRAY = 279,
    OF = 280,
    IF = 281,
    THEN = 282,
    ENDIF = 283,
    ELSE = 284,
    WHILE = 285,
    DO = 286,
    IN = 287,
    BEGINLOOP = 288,
    ENDLOOP = 289,
    CONTINUE = 290,
    READ = 291,
    WRITE = 292,
    AND = 293,
    OR = 294,
    NOT = 295,
    TRUE = 296,
    FALSE = 297,
    RETURN = 298,
    EQ = 299,
    NEQ = 300,
    LT = 301,
    GT = 302,
    LTE = 303,
    GTE = 304,
    SEMICOLON = 305,
    COLON = 306,
    COMMA = 307,
    L_BRACKET = 308,
    R_BRACKET = 309,
    ASSIGN = 310,
    NUMBER = 311,
    IDENTIFIER = 312,
    USUB = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 69 "mini_l.y" /* yacc.c:1909  */

  int ival;
  char* s;

#line 118 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
