#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
#define BLANK ' '
#define TAB '\t'
char infix[50];
char postfix[50];
char stack[50];
int top = -1;

int isFull(){
	if(top == (MAX - 1))
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}
void push(char symbol) {
	if(isFull()){
		printf("Stack Overflow \n");
		return;
	}
	top = top + 1;
	stack[top] = symbol;
}
char pop() {
	if(isFull()){
		printf("Stack Overflow \n");
		return -1;
	}
	char element = stack[top];
	top = top - 1;
	return element;
}
char peek() {
	return stack[top];
}
int instackPriority(char symbol) {
	switch(symbol) {
		case '(':
		case ')':	return 0;

		case '+':
		case '-':	return 1;

		case '*':
		case '/':	return 2;

		case '^':	return 3;
		default: 	return -1;
			
	}
}
int iswhitespace(char symbol) {
	if(symbol == BLANK || symbol == TAB)
		return 1;
	else
		return 0;
}
int outstackPriority(char symbol) {
	switch(symbol) {
		case '(':
		case ')':	return 0;

		case '+':
		case '-':	return 1;

		case '*':
		case '/':	return 2;

		case '^':	return 4;
		default: 	return -1;
	}
}

void display_stack() {
	if(top == -1) {
		printf("Empty               ");
		return;
	}
	for(int i=0 ; i<=top ; i++) {
		printf("%c", stack[i]);
	}
	for(int i=top+1 ; i<20 ; i++) {
		printf(" ");
	}
}
void infix_postfix() {
	int i, p = 0;
	char symbol;
	printf("\n\n");
	printf(" Symbol \t  Stack \t\tPostfix Array \n");
	printf("--------------------------------------------------------\n");
	for(i=0 ; i<strlen(infix) ; i++){
		symbol = infix[i];
		if(!iswhitespace(symbol)) {
			switch(symbol) {
				case '(':	push(symbol);
							break;

				case ')':	while(peek() != '('){
								postfix[p] = pop();
								p = p + 1;							
							}
							pop();
							break;				
				
				case '+':
				case '-':
				case '/':
				case '*':
				case '^':	while(instackPriority(peek()) >= outstackPriority(symbol)){
								postfix[p] = pop();
								p = p + 1;
							}
							push(symbol);
							break;

				default:	postfix[p] = symbol;
							p = p + 1;
						
			}
			printf(" %c		 ", symbol);
			display_stack();
			printf(" %-20s ", postfix);
			printf(" \n");
		}
	}
	printf("\nRemaining contents of stack : ");
	display_stack();
	printf("\n");
	while(!isEmpty()) {
		postfix[p] = pop();
		p = p + 1;
	}
	printf("\n\n");
}

int main() {
	printf("	Enter infix expresion : ");
	scanf("%s", infix);
	infix_postfix();
	printf("	Postfix Expression    : %s \n", postfix);
	return 0;
}
/*
OUTPUT:
        Enter infix expresion : (B^F^(C/E)^(E+F+A)/F^E)


 Symbol           Stack                 Postfix Array 
--------------------------------------------------------
 (               (
 B               (                    B
 ^               (^                   B
 F               (^                   BF
 ^               (^^                  BF
 (               (^^(                 BF
 C               (^^(                 BFC
 /               (^^(/                BFC
 E               (^^(/                BFCE
 )               (^^                  BFCE/
 ^               (^^^                 BFCE/
 (               (^^^(                BFCE/
 E               (^^^(                BFCE/E
 +               (^^^(+               BFCE/E
 F               (^^^(+               BFCE/EF
 +               (^^^(+               BFCE/EF+
 A               (^^^(+               BFCE/EF+A
 )               (^^^                 BFCE/EF+A+
 /               (/                   BFCE/EF+A+^^^
 F               (/                   BFCE/EF+A+^^^F
 ^               (/^                  BFCE/EF+A+^^^F
 E               (/^                  BFCE/EF+A+^^^FE
 )               Empty                BFCE/EF+A+^^^FE^/

Remaining contents of stack : Empty


        Postfix Expression    : BFCE/EF+A+^^^FE^/

*/