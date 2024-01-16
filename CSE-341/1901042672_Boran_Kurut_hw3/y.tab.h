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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DEFV = 258,
    DEFF = 259,
    KW_WHILE = 260,
    KW_IF = 261,
    KW_EXIT = 262,
    KW_DISP = 263,
    KW_TRUE = 264,
    KW_FALSE = 265,
    OP_PLUS = 266,
    OP_MINUS = 267,
    OP_DIV = 268,
    OP_MULT = 269,
    OP = 270,
    CP = 271,
    OP_SET = 272,
    OP_COMMA = 273,
    OP_AND = 274,
    OP_OR = 275,
    OP_NOT = 276,
    OP_EQ = 277,
    OP_GT = 278,
    COMMENT = 279,
    VALUEF = 280,
    ID = 281
  };
#endif
/* Tokens.  */
#define DEFV 258
#define DEFF 259
#define KW_WHILE 260
#define KW_IF 261
#define KW_EXIT 262
#define KW_DISP 263
#define KW_TRUE 264
#define KW_FALSE 265
#define OP_PLUS 266
#define OP_MINUS 267
#define OP_DIV 268
#define OP_MULT 269
#define OP 270
#define CP 271
#define OP_SET 272
#define OP_COMMA 273
#define OP_AND 274
#define OP_OR 275
#define OP_NOT 276
#define OP_EQ 277
#define OP_GT 278
#define COMMENT 279
#define VALUEF 280
#define ID 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "interpreter.y"
double valf; char id[20]; char valb; char code[1000];

#line 112 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
