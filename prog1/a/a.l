%{
#include<stdio.h>
int v = 0, flag = 0, op = 0, id = 0;
%}
%%
[0-9]+ {id++; printf("id = "); ECHO; printf("\n");}
[\+\-\/\*] {op++; printf("op = "); ECHO; printf("\n");}
"(" v++;
")" v--;
";" flag=1;
. {;}
\n return;
%%
main() {
	printf("Enter the expression: ");
	yylex();
	if ((op + 1) == id && flag == 0 && v == 0) {
		printf("Identifiers: %d\n", id);
		printf("Operators: %d\n", op);
		printf("Valid expression\n");
	} else 
		printf("Invalid expression\n");
}

