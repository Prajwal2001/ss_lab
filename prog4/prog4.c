#include<stdio.h>

#include<string.h>

int k = 0, z = 0, i = 0, j = 0, len = 0;
char input[16], reduce[20], stk[15], shift[10];
void check();
int main() {
    puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
    puts("\nEnter input string :");
    gets(input);
    len = strlen(input);
    strcpy(shift, "SHIFT->");
    puts("stack \t input \t action");
    printf("\n$\t%s$\t-------", input);
    for (k = 0, i = 0; j < len; k++, i++, j++) {
        if (input[j] == 'i' && input[j + 1] == 'd') {
            stk[i] = input[j];
            stk[i + 1] = input[j + 1];
            stk[i + 2] = '\0';
            input[j] = ' ';
            input[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, input, shift);
            check();
        } else {
            stk[i] = input[j];
            stk[i + 1] = '\0';
            input[j] = ' ';
            printf("\n$%s\t%s$\t%ssymbols", stk, input, shift);
            check();
        }
    }
    printf("\n");
}
void check() {
    strcpy(reduce, "REDUCE TO E");
    for (z = 0; z < len; z++)
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, reduce);
            j++;
        }
    for (z = 0; z < len; z++)
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, reduce);
            i = i - 2;
        }
    for (z = 0; z < len; z++)
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, reduce);
            i = i - 2;
        }
    for (z = 0; z < len; z++)
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, reduce);
            i = i - 2;
        }
}
