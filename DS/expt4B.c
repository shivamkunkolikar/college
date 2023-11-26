#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char str[50];
    struct node *link;
};
struct node *top = NULL;
char popped_str[50];
char postfix[50];
char infix[50];

void push(char str[]) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL) {
        printf("Stack Overflow \n");
        return;
    }
    strcpy(tmp->str, str);
    tmp->link = NULL;
    if(top == NULL) {
        top = tmp;
        return;
    }
    tmp->link = top;
    top = tmp;
}

void pop() {
    struct node *tmp;
    if(top == NULL) {
        printf("Stack Underflow \n");
        return;
    }
    strcpy(popped_str, top->str);
    tmp = top;
    top = top->link;
    free(tmp);
}

void toInfix() {
    char sym;
    char tmp_str[50];
    for(int i=0 ; i<strlen(postfix) ; i++) {
        sym = postfix[i];
        if(sym >= '0' && sym <= '9') {
            strcpy(tmp_str, "");
            strncat(tmp_str, &sym, 1);
            push(tmp_str);
        }
        else if((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) {
            strcpy(tmp_str, "");
            strncat(tmp_str, &sym, 1);
            push(tmp_str);
        }
        else if(sym == '+' || sym == '-' || sym == '/' || sym == '*' || sym == '^') {
            char a[50], b[50];
            strcpy(a, top->str);
            strcpy(b, top->link->str);
            strcpy(tmp_str, "(");
            pop();
            pop();
            strcat(tmp_str, b);
            strncat(tmp_str, &sym, 1);
            strcat(tmp_str, a);
            strcat(tmp_str, ")");
            push(tmp_str);
        }
    }
    pop();
    strcpy(infix, popped_str);
}

int main() {
    printf("\tEnter string    : ");
    scanf("%s", postfix);
    toInfix();
    printf("\tInfix Expresion : %s \n", infix);
    return 0;
}
/*
OUTPUT :
Enter string    : BFCE/EF+A+^^^FE^/
Infix Expresion : ((B^(F^((C/E)^((E+F)+A))))/(F^E))
*/