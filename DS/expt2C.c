#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
#define BLANK ' '
#define TAB '\t'
char infix[50];
char prefix[50];
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

		case '^':	return 4;
			
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

		case '^':	return 3;
			
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

void infix_prefix() {
	int i, p = 0;
	char symbol;
	printf("\n\n");
	printf(" Symbol \t  Stack \t\t Prefix Array \n");
	printf("--------------------------------------------------------\n");
	for(i=(strlen(infix) - 1) ; i>=0 ; i--){
		symbol = infix[i];
		if(iswhitespace(symbol) == 0) {
			switch(symbol) {
				case ')':	push(symbol);
							break;

				case '(':	while(peek() != ')'){
								prefix[p] = pop();
								p = p + 1;							
							}
							pop();
							break;				
				
				case '+':
				case '-':
				case '/':
				case '*':
				case '^':	while((top != -1) && (instackPriority(peek()) > outstackPriority(symbol))){
								prefix[p] = pop();
								p = p + 1;
							}
							push(symbol);
							break;

				default:	prefix[p] = symbol;
							p = p + 1;
						
			}
			printf(" %c		 ", symbol);
			display_stack();
			printf(" %-20s ", prefix);
			printf(" \n");
		}
	}
	printf("\nRemaining contents of stack : ");
	display_stack();
	printf("\n");
	while(!isEmpty()) {
		prefix[p] = pop();
		p = p + 1;
	}
	int end = strlen(prefix) - 1;
	char tmp;
	for(i=0 ; i<strlen(prefix)/2 ; i++) {
		tmp = prefix[i];
		prefix[i] = prefix[end];
		prefix[end] = tmp;
		end = end - 1;
	}
}

int main() {
	printf("	Enter infix expresion : ");
	scanf("%s", infix);
	infix_prefix();
	printf("	Prefix Expression    : %s \n", prefix);
	return 0;
}
/*
OUTPUT:
       Enter infix expresion : (D*D+D/(A+C)^F-(A^B^B))


 Symbol           Stack                  Prefix Array
--------------------------------------------------------
 )               )
 )               ))
 B               ))                   B
 ^               ))^                  B
 B               ))^                  BB                    
 ^               ))^                  BB^
 A               ))^                  BB^A
 (               )                    BB^A^
 -               )-                   BB^A^
 F               )-                   BB^A^F
 ^               )-^                  BB^A^F
 )               )-^)                 BB^A^F
 C               )-^)                 BB^A^FC
 +               )-^)+                BB^A^FC
 A               )-^)+                BB^A^FCA
 (               )-^                  BB^A^FCA+
 /               )-/                  BB^A^FCA+^
 D               )-/                  BB^A^FCA+^D
 +               )-+                  BB^A^FCA+^D/
 D               )-+                  BB^A^FCA+^D/D
 *               )-+*                 BB^A^FCA+^D/D
 D               )-+*                 BB^A^FCA+^D/DD
 (               Empty                BB^A^FCA+^D/DD*+-

Remaining contents of stack : Empty
        Prefix Expression    : -+*DD/D^+ACF^A^BB

*/