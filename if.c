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
