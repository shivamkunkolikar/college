#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *createList(struct node *start) {
	struct node *tmp;
	int n;
	printf("Enter number of nodes : ");
	scanf("%d", &n);
	if(n == 0)
		return NULL;
	tmp = (struct node*)malloc(sizeof(struct node));
	printf("enter value of node 1 : ");
	scanf("%d", &tmp->data);
	tmp->next = NULL;
	tmp->prev = NULL;
	start = tmp;
	int i;
	for(i=2 ; i<=n ; i++) {
		tmp->next = (struct node*)malloc(sizeof(struct node));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		printf("enter value of node %d : ", i);
		scanf("%d", &tmp->data);
		tmp->next = NULL;
	}
	return start;
}


struct node* swapList(struct node *start) {
    if(start == NULL)
        return start;
    if(start->next == NULL) {
        return start;
    }
    struct node *nx_st = start->next->next;
    struct node *re_start = start->next;
    start->next->prev = start->prev;
    start->prev = start->next;
    start->next->next = start;
    if(nx_st != NULL)
        nx_st->prev = start;
    start->next = swapList(nx_st);
    return re_start;
}

void displayList(struct node *start) {
	if(start == NULL) {
		printf("List is Empty \n");
		return;
	}
	//printf("reached\n");
	struct node *i = start;
	while(i != NULL) {
		printf(" %d ", i->data);
		i = i->next;
	}
	printf("\n");
}
int main() {
	struct node *start = NULL;
	start = createList(start);
	printf("Initial : ");
	displayList(start);
	start = swapList(start);
	printf("Swapped : ");
	displayList(start);
	return 0;
}
/*
OUTPUT :
Enter number of nodes : 5
enter value of node 1 : 10
enter value of node 2 : 20
enter value of node 3 : 30
enter value of node 4 : 40
enter value of node 5 : 50
Initial :  10  20  30  40  50
Swapped :  20  10  40  30  50
*/