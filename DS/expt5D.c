#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

struct node* addatEnd(struct node *last, int data) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    if(last == NULL) {
        tmp->link = tmp;
        last = tmp;
        return last;
    }
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}

void display(struct node *last) {
    struct node *p = last->link;
    do{
        printf(" %d ", p->data);
        p = p->link;
    }while(p != last->link);
    printf("\n");
}

struct node* delete_alternate(struct node *last) {
    struct node *p = last->link, *tmp;
    while(p != last) {
        tmp = p->link;
        p->link = tmp->link;
        if(tmp == last)
            last = p;
        else    
            p = p->link;
        free(tmp);
    }
    return last;
}

int main() {
    int t, data;
    struct node *last = NULL;
    printf("Enter number of nodes : ");
    scanf("%d", &t);
    for(int i=0 ; i<t ; i++){
        printf("\tEnter node %d : ", i+1);
        scanf("%d", &data);
        last = addatEnd(last, data);
    }
    printf("\n Initial List        : ");
    display(last);
    last = delete_alternate(last);
    printf("\n List after Deletion : ");
    display(last);

    return 0;
}
/*
OUTPUT : 
Enter number of nodes : 5
        Enter node 1 : 10
        Enter node 2 : 20
        Enter node 3 : 30
        Enter node 4 : 40
        Enter node 5 : 50

 Initial List        :  10  20  30  40  50

 List after Deletion :  10  30  50

*/