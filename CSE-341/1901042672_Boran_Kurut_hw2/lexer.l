%{
#include <string.h>
//token list

#define UNKNOWN 	-1
#define WRONG_ID 	-2

#define IDENTIFIER 	10

#define VALUEI		20
#define VALUEF		21
#define VALUESTR	22

#define COMMENT		30

#define OP_PLUS			40
#define OP_MINUS		41
#define OP_DIV			42
#define OP_DIV2			43
#define OP_MULT			44
#define OP_OP			45
#define OP_CP			46
#define OP_DBLMULT		47
#define OP_OC			48
#define OP_CC			49
#define OP_COMMA		50

#define KW_AND			60
#define KW_OR			61
#define KW_NOT			62
#define KW_EQUAL		63
#define KW_LESS			64
#define KW_NIL			65
#define KW_LIST			66
#define KW_APPEND		67
#define KW_CONCAT		68
#define KW_SET			69
#define KW_DEFFUN		70
#define KW_FOR			71
#define KW_IF			72
#define KW_EXIT			73
#define KW_LOAD			74
#define KW_DISP			75
#define KW_TRUE			76
#define KW_FALSE		77

#define NEW_LINE		99

int OPcount = 0;		// open paranthese counter
int CPcount = 0;		// close paranthese counter
int quotationCount = 0;	// quotation counter
char bufferStr[100];	// strValue buffer
char bufferP[10000];	// string inside parantheses buffer

void error(char e[], char where[]){
	printf("\nSyntax error: %s, in: '%s'\n", e, where);
	exit(1);
}

void printToken(int token){
	switch(token){
		case 10:
			printf("IDENTIFIER");
			break;
			
		case 20:
			printf("VALUEI");
			break;
		case 21:
			printf("VALUEF");
			break;
		case 22:
			printf("VALUESTR");
			break;
			
		case 30:
			printf("COMMENT");
			break;
		
		case 40:
			printf("OP_PLUS");
			break;
		case 41:
			printf("OP_MINUS");
			break;
		case 42:
			printf("OP_DIV");
			break;
		case 43:
			printf("OP_DIV2");
			break;
		case 44:
			printf("OP_MULT");
			break;
		case 45:
			printf("OP_OP");
			break;
		case 46:
			printf("OP_CP");
			break;
		case 47:
			printf("OP_DBLMULT");
			break;
		case 48:
			printf("OP_OC");
			break;
		case 49:
			printf("OP_CC");
			break;
		case 50:
			printf("OP_COMMA");
			break;
			
		case 60:
			printf("KW_AND");
			break;
		case 61:
			printf("KW_OR");
			break;
		case 62:
			printf("KW_NOT");
			break;
		case 63:
			printf("KW_EQUAL");
			break;
		case 64:
			printf("KW_LESS");
			break;
		case 65:
			printf("KW_NIL");
			break;
		case 66:
			printf("KW_LIST");
			break;
		case 67:
			printf("KW_APPEND");
			break;
		case 68:
			printf("KW_CONCAT");
			break;
		case 69:
			printf("KW_SET");
			break;
		case 70:
			printf("KW_DEFFUN");
			break;
		case 71:
			printf("KW_FOR");
			break;
		case 72:
			printf("KW_IF");
			break;
		case 73:
			printf("KW_EXIT");
			break;
		case 74:
			printf("KW_LOAD");
			break;
		case 75:
			printf("KW_DISP");
			break;
		case 76:
			printf("KW_TRUE");
			break;
		case 77:
			printf("KW_FALSE");
			break;
	}
	printf("\n");
}
%}

%%

[;][;]					{return(COMMENT);} 			// comment


[a][n][d] 				{return(KW_AND);}			// KEYWORDS
[o][r] 					{return(KW_OR);}
[n][o][t] 				{return(KW_NOT);}
[e][q][u][a][l]			{return(KW_EQUAL);}
[l][e][s][s]			{return(KW_LESS);}
[n][i][l]				{return(KW_NIL);}
[l][i][s][t]			{return(KW_LIST);}
[a][p][p][e][n][d]		{return(KW_APPEND);}
[c][o][n][c][a][t]		{return(KW_CONCAT);}
[s][e][t]				{return(KW_SET);}
[d][e][f][f][u][n]		{return(KW_DEFFUN);}
[f][o][r]				{return(KW_FOR);}
[i][f]					{return(KW_IF);}
[e][x][i][t]			{return(KW_EXIT);}
[l][o][a][d]			{return(KW_LOAD);}
[d][i][s][p]			{return(KW_DISP);}
[t][r][u][e]			{return(KW_TRUE);}
[f][a][l][s][e]			{return(KW_FALSE);}


[+]		{return(OP_PLUS);}							// operators
[-]		{return(OP_MINUS);}
[/]		{return(OP_DIV);}
[*][*]	{return(OP_DBLMULT);}
[*]		{return(OP_MULT);}
[(]		{return(OP_OP);}
[)]		{return(OP_CP);}
[,]		{return(OP_COMMA);}

["] 	{
			if(quotationCount % 2 == 0)
			{return OP_OC;}
			else
			{return OP_CC;}
		}

[a-zA-Z_][a-zA-Z0-9_]* 		{return(IDENTIFIER);}	// identifier, numbers, string

[1-9][0-9]* 				{return(VALUEI);}
[0]							{return(VALUEI);}
[1-9][0-9]*f[1-9][0-9]* 	{return(VALUEF);}
[0]f[0-9]*					{return(VALUEF);}

[0-9]+[a-zA-Z0-9-]* 		{return (WRONG_ID);}

[	] {} // ignore tab.
[ ] {}	// ignore space.

\n {return (NEW_LINE);}

. {return (UNKNOWN);}

<<EOF>> {
	if(OPcount != CPcount){
		error("parantheses don't match", bufferP);
	}
	
	if(quotationCount % 2 != 0){
		error("quotation marks don't match", bufferStr);
	}
	
	return 0;
}

%%

yywrap(){}

int main(int argc, char *argv[]){
	if(argc > 1){
		FILE* input = fopen(argv[1], "r");
		if(input == NULL){
			printf("\nERROR: file not found.\n");
			exit(1);
		}
		yyin = fopen(argv[1], "r");
	}
	int saveParanthese = 0;	// indicates whether the string in parantheses should be saved in buffer. 
	
	int token = 1;
	while(1)
	{
		token =	yylex();
		if(token == 0)		//EOF
			break;
			
		if(token == COMMENT){
			printToken(token);			// print COMMENT
			while(token != NEW_LINE)	// comments until new line
				token = yylex();		
			continue;					// current token is new line so continue
		}
		
		if(token == NEW_LINE)			// ignore the new line
			continue;
				
		printf("%s: ", yytext);			// print the lexeme
		printToken(token);				// print the corresponding token
		
		if(token == OP_OC){				// quotations
			quotationCount++;		
			
			while(token != OP_CC){	
				token = yylex();		// string inside quotation marks are not tokens.
				if(token == OP_CC){		
					quotationCount++;
					printf("%s: ", bufferStr);
				}
				else
					strcat(bufferStr, yytext); // if not OP_CC then continue saving string 
			}
			printToken(VALUESTR);				// string token
			
			printf("%s: ",yytext);				// string lexeme
			printToken(token);					// OP_CC token
			
			bufferStr[0] = '\0';
		}

		if(token == OP_CP){		// closing parantheses
			CPcount++;
			if(CPcount > OPcount)		// to prevent ")(" input
				error("parantheses don't match", bufferP);
			saveParanthese = 0;
			bufferP[0] = '\0';
		}		
		
		if(saveParanthese)
			strcat(bufferP, yytext);
		
		if(token == OP_OP){	// opening parantheses
			OPcount++;
			saveParanthese = 1;		// save string inside parantheses to determine the non matching closing paranthese location
		}
		if(token == UNKNOWN){
			error("unknown character", yytext);
		}
		
		if(token == WRONG_ID){
			error("identifiers cannot start with a number", yytext);
		}
	}
	
	fclose(yyin);	
	return 0;
}

