#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* add_at_begining(struct node *start, int data) {
    if(start == NULL) {
        start = (struct node*)malloc(sizeof(struct node));
        start->data = data;
        start->prev = NULL;
        start->next = NULL;
        return start;
    }
    start->prev = (struct node*)malloc(sizeof(struct node));
    start->prev->next = start;
    start = start->prev;
    start->data = data;
    start->prev = NULL;
    return start;
}

struct node* add_at_end(struct node *start, int data) {
    struct node *p, *tmp;
    if(start == NULL) {
        printf("List is Empty \n");
        return start;
    }
    p = start;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = (struct node*)malloc(sizeof(struct node));
    p->next->prev = p;
    p = p->next;
    p->data = data;
    p->next = NULL;
    return start;
}

struct node* delete_node(struct node *start, int data) {
    struct node *p, *tmp;
    if(start == NULL) {
        printf("List is Empty \n");
        return start;
    }
    p = start;
    if(start->data == data) {
        tmp = start;
        start = start->next;
        if(start != NULL)
            start->prev = NULL;
        free(tmp);
        return start;
    }
    while(p->next != NULL) {
        if(p->next->data == data) {
            tmp = p->next;
            if(tmp->next != NULL)
                tmp->next->prev = p;
            p->next = tmp->next;
            free(tmp);
            return start;
        }
        p = p->next;
    }
    printf("Item Not Found \n");
    return start;
}

struct node *reverse_list(struct node *start) {
    struct node *p, *tmp;
    if(start == NULL) {
        printf("List is Empty \n");
        return start;
    }
    p = start;
    while(p->next != NULL) {
        tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = tmp;
    }
    p->next = p->prev;
    p->prev = NULL;
    return p;
}

void display_list(struct node *start) {
    if(start == NULL) {
        printf("List is Empty \n");
        return;
    }
    while(start != NULL) {
        printf(" %d ", start->data);
        start = start->next;
    }
    printf("\n");
}

int main() {
    struct node *start = NULL;
    int choice, data;
    while(1) {
        printf("Enter Following Code : \n");
        printf("\t1. Add At Begining \n");
        printf("\t2. Add At End \n");
        printf("\t3. Delete Node \n");
        printf("\t4. Reverse List \n");
        printf("\t5. Exit \n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\t\tEnter data : ");
                scanf("%d", &data);
                start = add_at_begining(start, data);
                printf("\t\tList Content : ");
                display_list(start);
                break;
            
            case 2:
                printf("\t\tEnter data : ");
                scanf("%d", &data);
                start = add_at_end(start, data);
                printf("\t\tList Content : ");
                display_list(start);
                break;

            case 3:
                printf("\t\tEnter data : ");
                scanf("%d", &data);
                start = delete_node(start, data);
                printf("\t\tList Content : ");
                display_list(start);
                break;

            case 4:
                start = reverse_list(start);
                printf("\t\tList Content : ");
                display_list(start);
                break;

            case 5:
                exit(1);
                break;

            default:
                printf("\t\tInvalid Choice \n");
                break;
        }
    }
}
/*
OUTPUT :
Enter Following Code : 
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List
        5. Exit
Enter choice : 1
                Enter data : 10
                List Content :  10
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List
        5. Exit
Enter choice : 2
                Enter data : 20
                List Content :  10  20
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List 
        5. Exit
Enter choice : 2
                Enter data : 30
                List Content :  10  20  30
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List 
        5. Exit
Enter choice : 1
                Enter data : 5
                List Content :  5  10  20  30
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List
        5. Exit
Enter choice : 3
                Enter data : 5
                List Content :  10  20  30
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List
        5. Exit
Enter choice : 3
                Enter data : 30
                List Content :  10  20
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List
        5. Exit
Enter choice : 2
                Enter data : 30
                List Content :  10  20  30
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List
        5. Exit
Enter choice : 4
                List Content :  30  20  10
Enter Following Code :
        1. Add At Begining
        2. Add At End
        3. Delete Node
        4. Reverse List
        5. Exit
Enter choice : 5

*/