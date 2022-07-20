%{
#include <stdio.h>
#include <stdlib.h>
%}
%token num
%left '+' '-'
%left '*' '/'
%%
input : exp {printf("result: %d\n", $$); exit(0);}
exp : 
exp '+' exp {$$ = $1 + $3;}
| exp '-' exp {$$ = $1 - $3;}
| exp '*' exp {$$ = $1 * $3;}
| exp '/' exp {if($3==0) {yyerror();} else {$$ = $1 / $3;}}
| num {$$ = $1;}
%%

int yyerror() {
	printf("Error\n");
	exit(0);
}
int main() {
	printf("Enter an expression: ");
	yyparse();
}
