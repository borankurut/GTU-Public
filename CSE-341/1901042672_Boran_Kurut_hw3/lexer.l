%{
	#include "y.tab.h"
	#include <string.h>
	void executeCode(char code[1000]);
%}

%%

"defvar"				return DEFV;
"deffun"				return DEFF;
"while"					return KW_WHILE;
"if"					return KW_IF;
"exit"					return KW_EXIT;
"disp"					return KW_DISP;
"true"					{yylval.valb = 1; return KW_TRUE;}
"false"					{yylval.valb = 0; return KW_FALSE;}

[+]						return OP_PLUS;
[-]						return OP_MINUS;
[/]						return OP_DIV;
[*]						return OP_MULT;

[(]						return OP;
[)]						return CP;


"set"					return OP_SET;
[,]						return OP_COMMA;
"and"					return OP_AND;
"or"					return OP_OR;
"not" 					return OP_NOT;
"equal"					return OP_EQ;

"gt"					return OP_GT;
[;].*					return COMMENT;


[a-zA-Z][a-zA-Z0-9-]* 	{strncpy(yylval.id,yytext,20); return ID;}

[1-9][0-9]*[f]		{
	char* sep_at = strchr(yytext, 'f');
	*sep_at = '\0';
	yylval.valf = atoi(yytext);
	return VALUEF;
}

[1-9][0-9]*[f][0-9]*	{
						char given[100];
						strcpy(given, yytext);
						char * sep_at = strchr(given, 'f');
						if(sep_at != NULL)
  							*sep_at = '\0';
						else 
							error("wrong float value!");
						double first = atoi(given);
						double second = atoi(sep_at + 1);
						yylval.valf = first/second; 
						return VALUEF;}

[0]						{yylval.valf = atoi(yytext); return VALUEF;}


[ \t\n]					{;}

.						{printf("Syntax Error in: '%s'\n", yytext); exit(0);}



%%

int yywrap(void){
	return 1;
}

void executeCode(char *code) {
    YY_BUFFER_STATE buffer = yy_create_buffer(code, strlen(code));
    yy_switch_to_buffer(buffer);
    yyparse();
    yy_delete_buffer(buffer);
}