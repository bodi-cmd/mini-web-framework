/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    BODY = 258,
    DIV = 259,
    H1 = 260,
    SPAN = 261,
    CLASS = 262,
    DECLARE = 263,
    BUTTON = 264,
    ID = 265,
    CODE_START = 266,
    CODE_END = 267,
    IF = 268,
    ACTION = 269,
    WHILE = 270,
    FOR = 271,
    DELAY = 272,
    VARIABLE = 273,
    BINDING = 274,
    VALUE = 275,
    STRING = 276,
    INTEGER = 277,
    FUNCNAME = 278
  };
#endif
/* Tokens.  */
#define BODY 258
#define DIV 259
#define H1 260
#define SPAN 261
#define CLASS 262
#define DECLARE 263
#define BUTTON 264
#define ID 265
#define CODE_START 266
#define CODE_END 267
#define IF 268
#define ACTION 269
#define WHILE 270
#define FOR 271
#define DELAY 272
#define VARIABLE 273
#define BINDING 274
#define VALUE 275
#define STRING 276
#define INTEGER 277
#define FUNCNAME 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 104 "proj.y"
 
        char* varname;
        char* value;
        char* string;
        int integer;
        char* funcname;
        struct elm *element_pointer;
        struct _cond *cond_pointer;
        struct exp *expr_pointer;
        struct _stmt_node *statement_pointer;
        

#line 116 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
