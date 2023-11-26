#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
#define BLANK ' '
#define TAB '\t'
char infix[50];
char prefix[50];
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

long int prefix_eval(){
	char symbol;
	int i,num, a, b, d[6];
	for(int i=0 ; i<6 ; i++){
		printf("Enter %c : ", ('A' + i));
		scanf("%d", &d[i]);
	}
	printf(" Symbol \t ");
	printf(" Stack \n");
	printf("------------------------------------------------------------\n");
	for(i=strlen(prefix)-1 ; i>=0 ; i--) {
		symbol = prefix[i];
		if(symbol >= 'A' && symbol <= 'F') {
			num = d[symbol - 'A'];
			push(num);		
		}
		else{
			a = pop();
			b = pop();
			switch(symbol) {
				case '+' :	push(a + b);
							break;

				case '-' :	push(a - b);
							break;

				case '*' :	push(a * b);
							break;

				case '/' :	push(a / b);
							break;

				case '^' : 	push(powe(a, b));
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
	printf("	Enter prefix expresion : ");
	scanf("%s", prefix);
	printf("	Prefix Expression    : %ld \n", prefix_eval());
	return 0;
}
/*
OUTPUT:
        Enter prefix expresion : -+*DD/D^+ACF^A^BB
Enter A : 3
Enter B : 2
Enter C : 2
Enter D : 2
Enter E : 2
Enter F : 1
 Symbol           Stack
------------------------------------------------------------
 B               2
 B               2, 2
 ^               4
 A               4, 3
 ^               81
 F               81, 1
 C               81, 1, 2
 A               81, 1, 2, 3
 +               81, 1, 5
 ^               81, 5
 D               81, 5, 2
 /               81, 0
 D               81, 0, 2
 D               81, 0, 2, 2
 *               81, 0, 4
 +               81, 4
 -               -77
        Prefix Expression    : -77

*/