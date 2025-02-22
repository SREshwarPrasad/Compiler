//lex and yacc for approving if and else

LEX:

%{
	#include<stdio.h>
	#include "y.tab.h"
%}

%%
if {return IF;}
else {return ELSE;}
[a-zA-Z][a-zA-Z0-9]* {return id;}
[0-9]+ {return nums;}
"(" {return lp;}
")" {return rp;}
"{" {return lc;}
"}" {return rc;}
"+" {return plus;}
"-" {return minus;}
"<" {return LT;}
">" {return GT;}
";" {return scolon;}
"=" {return equal;}
"\n" {return NL;}
[ \t] {}
. {;}
%%


YACC:
%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror(char *);
%}

%token IF ELSE id nums plus minus LT GT scolon equal NL
%token lp rp lc rc

%%

S: W{printf("\nInput accepted\n"); exit(0);};
W: 			   IF lp cond rp NL lc NL W NL rc NL 											//if 
				| IF lp cond rp NL lc NL W NL rc NL ELSE NL lc NL W NL rc 		//if else
				| IF lp cond rp NL lc NL W NL rc G ELSE NL lc NL W NL rc   		//if else if
				|E; 

G: 			NL ELSE IF lp cond rp NL lc NL W NL rc NL 
				| NL ELSE IF lp cond rp NL lc NL W NL rc NL G;

cond: 		id op1 id
				|id op1 nums;

E: 			id equal K scolon;

K: 			val op2 K
				|val;

val:			id
				|nums;
				
op1:			LT
				|GT;

op2:			plus
				|minus;
%%

int main() { while(1) {yyparse();} return 0; }
int yywrap() {return 0;}
int yyerror(char *s){printf("error... %s\n",s); exit(0); return 0;}











*/






/*
IF lp cond rp  
lc  
	IF lp cond rp  
	lc  
		W  
	rc  
	ELSE IF lp cond rp  
	lc 
		 W  
	rc  
	 
	ELSE IF lp cond rp  
	lc  
		W  
	rc  
	 
	ELSE IF lp cond rp 
	lc  
		W  
	rc  
	 
	ELSE IF lp cond rp 
	lc  
		W  
	rc  
	ELSE  
	lc  
		W 
	rc 
	 
rc  

....

*/




