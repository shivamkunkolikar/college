#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* addtoEmpty(struct node *start, int data) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->prev = NULL;
    tmp->next = start;
    if(start != NULL) 
        start->prev = tmp;
    start = tmp;
    return start;
}

struct node* addatEnd(struct node *start, int data) {
    if(start == NULL){
        start = (struct node*)malloc(sizeof(struct node));
        start->prev = NULL;
        start->next = NULL;
        start->data = data;
        return start;
    }
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    struct node *p = start;
    while(p->next != NULL) 
        p = p->next;
    p->next = tmp;
    tmp->prev = p;
    return start;
}

struct node* createList(struct node *start, int num) {
    start = addtoEmpty(start, num%10);
    num = num / 10;
    while(num != 0) {
        start = addatEnd(start, num%10);
        num = num / 10;
    }
    return start;
}

struct node *addLists(struct node *a, struct node *b) {
    struct node *c = NULL;
    int carry = 0;
    int curr_num = 0;
    while(a != NULL && b != NULL) {
        curr_num = a->data + b->data + carry;
        c = addatEnd(c, curr_num % 10);
        carry = curr_num / 10;
        a = a->next;
        b = b->next;
    }
    while(a != NULL) {
        curr_num = a->data + carry;
        c = addatEnd(c, curr_num%10);
        carry = curr_num / 10;
        a = a->next;
    }
    while(b != NULL) {
        curr_num = b->data + carry;
        c = addatEnd(c, curr_num%10);
        carry = curr_num / 10;
        b = b->next;
    }
    return c;
}

void displayList(struct node *start) {
    if(start == NULL){
    printf("NO\n");
        return;
    }
    while(start != NULL) {
        printf(" %d ", start->data);
        start = start->next;
    }
    printf("\n");
}

int solveList(struct node *start) {
    if(start == NULL)
        return 0;
    int ans = 0;
    while(start->next != NULL) {
        start = start->next;
    }
    while(start != NULL){
        ans = (ans * 10) + start->data;
        start = start->prev;
    }
    return ans;
}

int main() {
    int an, bn;
    printf("Enter number 1 : ");
    scanf("%d", &an);
    printf("Enter number 2 : ");
    scanf("%d", &bn);
    struct node *a = NULL, *b = NULL, *c = NULL;
    a = createList(a, an);
    b = createList(b, bn);
    c = addLists(a, b);
    printf("Answer is : %d \n", solveList(c));
    return 0;
}
/*
OUTPUT :
Enter number 1 : 123
Enter number 2 : 111
Answer is : 234
*/