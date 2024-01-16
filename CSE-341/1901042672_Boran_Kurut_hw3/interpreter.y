%{
    #include <stdio.h>
	#include <math.h>
    #include <stdlib.h>
    #include <string.h>
	#include "y.tab.h"
    void yyerror(char *s);
	void error(char* err);
    int yylex();
	
	typedef struct{
		char id[20];
		double valf;
	} Variable;

	Variable variable_new(char newId[20], double newValf);
	Variable nullVar();

	Variable variables[20];

	Variable idToVariable(char id[20]);
	int equalVar(Variable f, Variable s);
	void setVariable(char id[20], double v);
	void createVariable(char id[20], double v);
	void resetVariables();
	int idToIx(char id[20]);
	char* dblToFractional(double a);
	int gcd(int a, int b);
%}

%error-verbose

%debug

%union {double valf; char id[20]; char valb; char code[1000];}

%token DEFV;
%token DEFF;

%token KW_WHILE
%token KW_IF;
%token KW_EXIT
%token KW_DISP;
%token <valb> KW_TRUE;
%token <valb> KW_FALSE;

%token OP_PLUS;
%token OP_MINUS;
%token OP_DIV;
%token OP_MULT;
%token OP;
%token CP;
%token OP_SET;
%token OP_COMMA;
%token OP_AND;
%token OP_OR;
%token OP_NOT;
%token OP_EQ;
%token OP_GT;

%token COMMENT;


%token <valf> VALUEF;
%type <valb> VALUEB;

%token <id> ID;

%type <valb> EXPB
%type <valf> EXPF
%type INPUT
%type<code> BLOCK

%type<code> STATEMENT



%%

    START		: INPUT START  						{printf("Syntax OK.\n");}
		        | KW_EXIT							{exit(0);}

    INPUT   	: EXPF                              {printf("%s\n", dblToFractional($1));}
            	| EXPB                              {printf("%d\n", $1);}
            	| COMMENT                           {;}
            	| STATEMENT


    STATEMENT	: OP KW_DISP EXPF CP                      {printf("%f \n", $3); sprintf($$, " disp %f ", $3);}              
            	| OP KW_DISP EXPB CP                      {if($3 == 0) {
														printf("false\n");
														sprintf($$, " disp false %c", $3, '\0');
													}
													else{
															printf("true\n");
															sprintf($$, " disp true %c", $3, '\0');
													}
													}
				
				| OP DEFV ID EXPF CP				{createVariable($3, $4); 
													sprintf($$, " (defvar %s %d ) %c", $3, $4, '\0');}
				| OP OP_SET ID EXPF CP				{setVariable($3, $4);
													sprintf($$, " (set %s %d ) %c", $3, $4, '\0');}
				| WHILE_LOOP
				| IF_ST

	WHILE_LOOP: OP KW_WHILE EXPB BLOCK CP 			{	while($3)
															{executeCode($4); }
														
													}
	IF_ST: OP KW_IF EXPB BLOCK BLOCK CP 			{if($3) {executeCode($4);} else {executeCode($5);} }

	BLOCK	: STATEMENT								{strcpy($$, $1);}



    EXPF    	: OP OP_PLUS EXPF EXPF CP          	{$$ = $3 + $4;}
            	| OP OP_MINUS EXPF EXPF CP			{$$ = $3 - $4;}
            	| OP OP_MINUS EXPF CP               {$$ = -$3;}
            	| OP OP_MULT EXPF EXPF CP           {$$ = $3 * $4;}
            	| OP OP_DIV EXPF EXPF CP            {$$ = $3 / $4;}
				| ID 								{const Variable var = idToVariable($1);
													if(equalVar(var, nullVar())){
														printf("The '%s' is not declared before.\n", $1);
														exit(0);
													}
													else
														$$ = idToVariable($1).valf;}
            	| VALUEF                            {$$ = $1;}

    EXPB    	: OP OP_AND EXPB EXPB CP            {$$ = $3 && $4;}
            	| OP OP_OR EXPB EXPB CP             {$$ = $3 || $4;}
            	| OP OP_NOT EXPB CP                 {$$ = !$3;}
				| OP OP_EQ EXPF EXPF CP 			{$$ = ($3 == $4);}
				| OP OP_GT EXPF EXPF CP 			{$$ = ($3 > $4);}
				| VALUEB							{$$ = $1;}

    VALUEB  	: KW_TRUE                           {$$ = $1;}
            	| KW_FALSE                          {$$ = $1;}

%%

main()
{
	resetVariables();
 	return(yyparse());
}

void yyerror (char *s)
{                                                     
    printf("parser error: *%s* \n ",s);
    return 0;
}

Variable variable_new(char newId[20], double newValf){
	Variable v;
	strcpy(v.id, newId);
	v.valf = newValf;
	return v;
}

int equalVar(Variable f, Variable s){
	return strcmp(f.id, s.id) == 0;
}

Variable nullVar(){
	Variable nv = variable_new("0__", 0.0);	//variables can't start with number. 
	return nv;
}

int idToIx(char id[20]){
	int ix = -1;
	for(int i = 0; i < 20; ++i){
		if(strcmp(variables[i].id, id) == 0)
			return ix = i;
	}
	return ix;
}

Variable idToVariable(char id[20]){
	int i = idToIx(id);
	if(i == -1)
		return nullVar();
	else
		return variables[i];
}

void setVariable(char id[20], double v){
	int i = idToIx(id);
	if(i == -1)
		error("setVariable unknwon id.");
	else
		variables[i].valf = v;
}

void createVariable(char id[20], double v){
	if(idToIx(id) != -1){
		printf("Variable %s is already declared before.\n", id);
		exit(0);
	}
	int emptyIx = idToIx("");
	variables[emptyIx] = variable_new(id, v);
}

void resetVariables(){
	for(int i = 0; i < 20; ++i)
		strcpy(variables[i].id, "");
}

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	if (a < b)
		return gcd(a, b % a);
	else
		return gcd(b, a % b);
}

/*char* dblToFractional(double a){
	int i = 1;
	while(a != (int) a){
		a*= 10;
		++i;
	}

	int num = a;
	int denum = pow(10, i);

	int divisor = gcd(num, denum);

	num = num/ divisor;
	denum = denum/divisor;

	char* toReturn = (char*) malloc(100*sizeof(char));
	sprintf(toReturn, "%df%d", num, denum);
	return toReturn;
}*/

void error(char* err){
	printf("%s", err);
	exit(0);
}

int gcfFinder(int a, int b)
{
	int gcf = 1;
	for (int i = 1; i <= a && i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcf = i;
		}
	}
	return gcf;
}

int shortform(int* a, int* b)
{
	for (int i = 2; i <= *a && i <= *b; i++)
	{
		if (*a % i == 0 && *b % i == 0)
		{
			*a = *a / i;
			*b = *b / i;
		}
	}
	return 0;
}

// Driver Code
char* dblToFractional(double a)
{
	int c = 10000;
	double b = (a - floor(a)) * c;
	int d = (int)floor(a) * c + (int)(b + .5f);

	while (1)
	{
		if (d % 10 == 0)
		{
			d = d / 10;
			c = c / 10;
		}
		else
			break;
	}
	int* i = &d;
	int* j = &c;
	int t = 0;
	while (t != 1)
	{
		int gcf = gcfFinder(d, c);
		if (gcf == 1)
		{
			char* toReturn = (char*) malloc(100*sizeof(char));
			sprintf(toReturn, "%df%d", d, c);
			return toReturn;
			t = 1;
		}
		else
		{
			shortform(i, j);
		}
	}
}