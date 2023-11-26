#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MEM_ALOC (struct node*)malloc(sizeof(struct node))
struct node {
    int coefficient;
    int exponent;
    struct node *link;
};

struct node* createList(struct node *start);
struct node* addPolynimial(struct node *a, struct node *b);
struct node* multiplyPolynomial(struct node *a, struct node *b);
struct node* addAtPos(struct node *start, int pos, int coef, int exp);
struct node* modOption(struct node *a);
void modifyPolynomial(struct node **a, struct node **b);
void f_createList(struct node **a, struct node **b);
void displayList(struct node *start);

int main() {
    struct node *poly1, *poly2, *poly3;
    int choice;
    poly1 = NULL;
    poly2 = NULL;
    poly3 = NULL;
    while(1) {
        printf("\n\n");
        printf("    1. Enter 2 Polynomials \n");
        printf("    2. Add 2 Polynomials \n");
        printf("    3. Multiply 2 Polynimials \n");
        printf("    4. Modify Polynomial \n");
        printf("    5. Enter Polynimial from file \n");
        printf("    6. To Display Polynomials \n");
        printf("    7. To Exit \n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\n    Enter polynomial 1 : \n");
                poly1 = createList(poly1);
                printf("\n    Enter polynomial 2 : \n");
                poly2 = createList(poly2);
                printf("\n    Polynomial 1 : ");
                displayList(poly1);
                printf("\n    Polynomial 2 : ");
                displayList(poly2);
                break;

            case 2:
                if(poly1 == NULL || poly2 == NULL) {
                    printf("    Please Enter both polynomials first !!! \n");
                    break;
                }
                poly3 = NULL;
                poly3 = addPolynimial(poly1, poly2);
                printf("    Polynimal : ");
                displayList(poly3);
                break;

            case 3:
                if(poly1 == NULL || poly2 == NULL) {
                    printf("    Please Enter both polynomials first !!! \n");
                    break;
                }
                poly3 = NULL;
                poly3 = multiplyPolynomial(poly1, poly2);
                printf("    Polynimal : ");
                displayList(poly3);
                break;

            case 4:
                if(poly1 == NULL || poly2 == NULL) {
                    printf("    Please Enter both polynomials first !!! \n");
                    break;
                }
                modifyPolynomial(&poly1, &poly2);
                break;

            case 5:
                f_createList(&poly1, &poly2);
                break;

            case 6:
                if(poly1 == NULL || poly2 == NULL) {
                    printf("    Please Enter both polynomials first !!! \n");
                    break;
                }
                printf("    Polynomial 1 : ");
                displayList(poly1);
                printf("    Polynomial 2 : ");
                displayList(poly2);
                break;

            case 7:
                exit(1);
                break;

            default:
                printf("Invalid Option !!! \n");
                break;

        }
    }
}

struct node* createList(struct node *start) {
    struct node *tmp;
    int n;
    printf("    Enter number of terms : ");
    scanf("%d", &n);
    if(n == 0)
        return start;
    tmp = (struct node*)malloc(sizeof(struct node));
    start = tmp;
    printf("    Enter coefficient 1 : ");
    scanf("%d", &tmp->coefficient);
    printf("    Enter exponent    1 : ");
    scanf("%d", &tmp->exponent);
    tmp->link = NULL;
    for(int i=2 ; i<=n ; i++) {
        tmp->link = (struct node*)malloc(sizeof(struct node));
        tmp = tmp->link;
        printf("    Enter coefficient %d : ", i);
        scanf("%d", &tmp->coefficient);
        printf("    Enter exponent    %d : ", i);
        scanf("%d", &tmp->exponent);
        tmp->link = NULL;
    }
    return start;
}

void displayList(struct node *start) {
    struct node *p;
    if(start == NULL) {
        printf("List is Empty \n");
        return;
    }
    p = start;
    while(p != NULL) {
            printf(" ( %dx^%d ) ", p->coefficient, p->exponent);
        p = p->link;
    }
    printf("\n");
}

struct node* addPolynimial(struct node *a, struct node *b) {
    struct node *c = NULL,*d, *p, *q;
    c = MEM_ALOC;
    d = c;
    c->link = NULL;
    while(a != NULL && b != NULL) {
        if(a->exponent > b->exponent) {
            c->link = MEM_ALOC;
            c = c->link;
            c->coefficient = a->coefficient;
            c->exponent = a->exponent;
            c->link = NULL;
            a = a->link;
        }
        else if(b->exponent > a->exponent) {
            c->link = MEM_ALOC;
            c = c->link;
            c->coefficient = b->coefficient;
            c->exponent = b->exponent;
            c->link = NULL;
            b = b->link;
        }
        else {
            c->link = MEM_ALOC;
            c = c->link;
            c->coefficient = a->coefficient + b->coefficient;
            c->exponent = a->exponent;
            c->link = NULL;
            a = a->link;
            b = b->link;
        }
    }
    if(a != NULL) {
        while(a != NULL) {
            c->link = MEM_ALOC;
            c = c->link;
            c->coefficient = a->coefficient;
            c->exponent = a->exponent;
            c->link = NULL;
            a = a->link;
        }
    }
    if(b != NULL) {
        while(b != NULL) {
            c->link = MEM_ALOC;
            c = c->link;
            c->coefficient = b->coefficient;
            c->exponent = b->exponent;
            c->link = NULL;
            b = b->link;
        }
    }
    return d->link;
}

struct node* multiplyPolynomial(struct node *a, struct node *b) {
    struct node *c, *p, *q, *r;
    c = MEM_ALOC;
    c->link = NULL;
    r = c;
    p = a;
    q = b;
    while(p != NULL) {
        q = b;
        while(q != NULL) {
            r->link = MEM_ALOC;
            r = r->link;
            r->exponent = p->exponent + q->exponent;
            r->coefficient = p->coefficient * q->coefficient;
            r->link = NULL;
            q = q->link;  
        }
        p = p->link;
    }
    c = c->link;
    p = c;
    while(p->link != NULL) {
        q = p->link;
        while(q != NULL) {
            if(p->exponent == q->exponent) {
                p->coefficient += q->coefficient;
                q->coefficient = 0;
            }
            q = q->link;
        }
        p = p->link;
    }
    p = c;
    while(p->link != NULL){
        r = p->link;
        if(r->coefficient == 0){
            p->link = r->link;
            free(r);
        }
        else
            p = p->link;
    }
    return c;
}

struct node* addAtPos(struct node *start, int pos, int coef, int exp) {
    struct node *tmp, *p;
    int curr_pos = 1;
    if(start == NULL) {
        printf("Data Cannot Be Added \n");
        return start;
    }
    if(pos == 1) {
        tmp = MEM_ALOC;
        tmp->coefficient = coef;
        tmp->exponent = exp;
        start = tmp;
        return start;
    }
    p = start;
    while(p != NULL) {
        if(curr_pos == (pos - 1)) {
            tmp = MEM_ALOC;
            tmp->coefficient = coef;
            tmp->exponent = exp;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
        curr_pos++;
    }
    printf("Data Cannot Be Added \n");
    return start;
}

struct node* deleteItem(struct node *start, int pos) {
    struct node *p, *tmp;
    int curr_pos = 1;
    if(start == NULL) {
        printf("List is Empty \n");
        return start;
    }
    p = start;
    while(p->link != NULL) {
        if(curr_pos == (pos - 1)) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
        curr_pos++;
    }
    printf("Item Not Found \n");
    return start;
}

struct node *modOption(struct node *a) {
    int opt, pos, coef, exp;
    struct node *p = a;
    printf("\t\tEnter following option : \n");
    printf("\t\t\t1. To insert term \n");
    printf("\t\t\t2. To delete term \n");
    printf("\t\tEnter option : ");
    scanf("%d", &opt);
    switch(opt) {
        case 1:
            printf("\t\t\tEnter coeficient : ");
            scanf("%d", &coef);
            printf("\t\t\tEnter exponent   : ");
            scanf("%d", &exp);
            printf("\t\t\tEnter position to insert : ");
            scanf("%d", &pos);
            p = addAtPos(p, pos, coef, exp);
            break;

        case 2:
            printf("\t\t\tEnter position to delete : ");
            scanf("%d", &pos);
            p = deleteItem(p, pos);
            break;

        default:
            printf("\t\t\tInvalid Option !!! \n");
            break;
    }
    return p;
}

void modifyPolynomial(struct node **a, struct node **b) {
    struct node *p, *q;
    int option;
    p = *a;
    q = *b;
    printf("    Polynomial 1 : ");
    displayList(*a);
    printf("    Polynomial 2 : ");
    displayList(*b);
    printf("    Enter polynomial which you want to modify : \n");
    printf("\t\t1. Polynomial 1 \n");
    printf("\t\t2. Polynomial 2 \n");
    printf("    Enter option : ");
    scanf("%d", &option);
    switch(option) {
        case 1:
            *a = modOption(p);
            printf("\n\t\tPolynomial 1 : ");
            displayList(*a);
            break;

        case 2:
            *b = modOption(q);
            printf("\n\t\tPolynomial 2 : ");
            displayList(*b);
            break;

        default:
            printf("\t\tInvalid Option !!! \n");
            break;
    }
}

void f_createList(struct node **a, struct node **b) {
    char filename[50];
    struct node *p, *q;
    int n;
    printf("    Enter filename : ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    FILE *fin = fopen(filename, "r");
    if(fin == NULL) {
        printf("    File not found \n");
        return;
    }
    fscanf(fin, "%d", &n);
    p = MEM_ALOC;
    fscanf(fin, "%d%d", &p->coefficient, &p->exponent);
    p->link = NULL;
    *a = p;
    for(int i=2 ; i<=n ; i++) {
        p->link = MEM_ALOC;
        p = p->link;
        fscanf(fin, "%d%d", &p->coefficient, &p->exponent);
        p->link = NULL;
    }
    p = NULL;
    fscanf(fin, "%d", &n);
    p = MEM_ALOC;
    fscanf(fin, "%d%d", &p->coefficient, &p->exponent);
    p->link = NULL;
    *b = p;
    for(int i=2 ; i<=n ; i++) {
        p->link = MEM_ALOC;
        p = p->link;
        fscanf(fin, "%d%d", &p->coefficient, &p->exponent);
        p->link = NULL;
    }
    printf("    Polynomials Taken Successfully !!! \n");
}
/*
OUTPUT :
    1. Enter 2 Polynomials 
    2. Add 2 Polynomials 
    3. Multiply 2 Polynimials 
    4. Modify Polynomial 
    5. Enter Polynimial from file 
    6. To Display Polynomials 
    7. To Exit 
Enter choice : 1

    Enter polynomial 1 : 
    Enter number of terms : 3
    Enter coefficient 1 : 1
    Enter exponent    1 : 3
    Enter coefficient 2 : 2
    Enter exponent    2 : 2
    Enter coefficient 3 : 3
    Enter exponent    3 : 1

    Enter polynomial 2 : 
    Enter number of terms : 3
    Enter coefficient 1 : 1
    Enter exponent    1 : 3
    Enter coefficient 2 : 2
    Enter exponent    2 : 2
    Enter coefficient 3 : 3
    Enter exponent    3 : 1

    Polynomial 1 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )

    Polynomial 2 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )


    1. Enter 2 Polynomials
    2. Add 2 Polynomials
    3. Multiply 2 Polynimials
    4. Modify Polynomial
    5. Enter Polynimial from file
    6. To Display Polynomials 
    7. To Exit
Enter choice : 2
    Polynimal :  ( 2x^3 )  ( 4x^2 )  ( 6x^1 )


    1. Enter 2 Polynomials
    2. Add 2 Polynomials
    3. Multiply 2 Polynimials
    4. Modify Polynomial
    5. Enter Polynimial from file
    6. To Display Polynomials
    7. To Exit 
Enter choice : 3
    Polynimal :  ( 1x^6 )  ( 4x^5 )  ( 10x^4 )  ( 12x^3 )  ( 9x^2 )


    1. Enter 2 Polynomials
    2. Add 2 Polynomials
    3. Multiply 2 Polynimials
    4. Modify Polynomial
    5. Enter Polynimial from file
    6. To Display Polynomials
    7. To Exit
Enter choice : 4
    Polynomial 1 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )
    Polynomial 2 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )
    Enter polynomial which you want to modify :
                1. Polynomial 1
                2. Polynomial 2
    Enter option : 1
                Enter following option :
                        1. To insert term
                        2. To delete term
                Enter option : 1
                        Enter coeficient : 4
                        Enter exponent   : 0
                        Enter position to insert : 4

                Polynomial 1 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )  ( 4x^0 )


    1. Enter 2 Polynomials
    2. Add 2 Polynomials
    3. Multiply 2 Polynimials
    4. Modify Polynomial
    5. Enter Polynimial from file
    6. To Display Polynomials
    7. To Exit
Enter choice : 4
    Polynomial 1 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )  ( 4x^0 )
    Polynomial 2 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )
    Enter polynomial which you want to modify :
                1. Polynomial 1 
                2. Polynomial 2
    Enter option : 2
                Enter following option :
                        1. To insert term
                        2. To delete term
                Enter option : 2
                        Enter position to delete : 3

                Polynomial 2 :  ( 1x^3 )  ( 2x^2 )


    1. Enter 2 Polynomials
    2. Add 2 Polynomials
    3. Multiply 2 Polynimials
    4. Modify Polynomial
    5. Enter Polynimial from file
    6. To Display Polynomials
    7. To Exit
Enter choice : 6
    Polynomial 1 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 )  ( 4x^0 )
    Polynomial 2 :  ( 1x^3 )  ( 2x^2 )


    1. Enter 2 Polynomials
    2. Add 2 Polynomials
    3. Multiply 2 Polynimials
    4. Modify Polynomial
    5. Enter Polynimial from file
    6. To Display Polynomials
    7. To Exit
Enter choice : 5
    Enter filename : poly
    Polynomials Taken Successfully !!! 


    1. Enter 2 Polynomials 
    2. Add 2 Polynomials 
    3. Multiply 2 Polynimials 
    4. Modify Polynomial 
    5. Enter Polynimial from file 
    6. To Display Polynomials 
    7. To Exit 
Enter choice : 6
    Polynomial 1 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 ) 
    Polynomial 2 :  ( 1x^3 )  ( 2x^2 )  ( 3x^1 ) 


    1. Enter 2 Polynomials 
    2. Add 2 Polynomials 
    3. Multiply 2 Polynimials 
    4. Modify Polynomial 
    5. Enter Polynimial from file 
    6. To Display Polynomials 
    7. To Exit 
Enter choice : 7

[Programme Finished]

FILE : poly.txt
3
1 3
2 2
3 1
3
1 3
2 2
3 1

*/