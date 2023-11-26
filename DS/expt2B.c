#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
#define BLANK ' '
#define TAB '\t'
char infix[50];
char postfix[50];
long int stack[50];
int top = -1;
int powe(int base, int exp){
	int ans = 1, i;
	for(i=0 ; i<exp ; i++)
		ans = ans * base;
	return ans;
}

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
void push(int symbol) {
	if(isFull()){
		printf("Stack Overflow \n");
		return;
	}
	top = top + 1;
	stack[top] = symbol;
}
int pop() {
	if(isFull()){
		printf("Stack Overflow \n");
		return -1;
	}
	int element = stack[top];
	top = top - 1;
	return element;
}
int peek() {
	return stack[top];
}

void display() {
	if(top == -1) {
		printf(" Empty \n");
		return;
	}
	for(int i=0; i<top ; i++)
		printf(" %d," ,stack[i]);
	printf(" %d \n", stack[top]);
}

long int postfix_eval(){
	char symbol;
	int i,num, a, b, d[6];
	for(int i=0 ; i<6 ; i++){
		printf("Enter %c : ", ('A' + i));
		scanf("%d", &d[i]);
	}
	printf(" Symbol \t ");
	printf(" Stack \n");
	printf("------------------------------------------------------------\n");
	for(i=0 ; i<strlen(postfix) ; i++) {
		symbol = postfix[i];
		if(symbol >= 'A' && symbol <= 'F') {
			num = d[symbol - 'A'];
			push(num);		
		}
		else{
			a = pop();
			b = pop();
			switch(symbol) {
				case '+' :	push(b + a);
							break;

				case '-' :	push(b - a);
							break;

				case '*' :	push(b * a);
							break;

				case '/' :	push(b / a);
							break;

				case '^' : 	push(powe(b, a));
							break;
			}
		}
		printf(" %c ", symbol);
		printf("\t\t");
		display();
	}
	return pop();
}
int main() {
	printf("	Enter postfix expresion : ");
	scanf("%s", postfix);
	printf("	Postfix Expression    : %ld \n", postfix_eval());
	return 0;
}
/*
OUTPUT:
        Enter postfix expresion : BFCE/EF+A+^^^FE^/
Enter A : 3
Enter B : 2
Enter C : 2
Enter D : 2
Enter E : 2
Enter F : 1
 Symbol           Stack
------------------------------------------------------------
 B               2
 F               2, 1
 C               2, 1, 2
 E               2, 1, 2, 2
 /               2, 1, 1
 E               2, 1, 1, 2
 F               2, 1, 1, 2, 1
 +               2, 1, 1, 3
 A               2, 1, 1, 3, 3
 +               2, 1, 1, 6
 ^               2, 1, 1
 ^               2, 1
 ^               2
 F               2, 1
 E               2, 1, 2
 ^               2, 1
 /               2
        Postfix Expression    : 2

*/