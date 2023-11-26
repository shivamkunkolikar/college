#include<stdio.h>
#include<stdlib.h>
#define MAX 17 

struct Employee {
    int id;
    char name[30];
    char address[30];
};
struct Record {
    struct Employee emp;
    struct Record *next;
};
struct Record *table[MAX];

int hash(int key) {
    return (key % MAX);
}

void insert(struct Employee e) {
    int h = hash(e.id);
    struct Record *new_rec = (struct Record*)malloc(sizeof(struct Record));
    new_rec->emp = e;
    new_rec->next = table[h];
    table[h] = new_rec;
}

struct Record* search(int key) {
    int h = hash(key);
    struct Record *p = table[h];
    while(p != NULL) {
        if(p->emp.id == key) return p;
        p = p->next;
    }
    return NULL;
}

int delete(int key) {
    int h = hash(key);
    struct Record *p = table[h];
    if(p->emp.id == key) {
        table[h] = table[h]->next;
        free(p);
        return 1;
    }
    else {
        while(p->next != NULL) {
            if(p->next->emp.id == key) {
                struct Record *tmp = p->next;
                p->next = tmp->next;
                free(tmp);
                return 1;
            }
            p = p->next;
        }
        return -1;
    }
}

int main() {
    for(int i=0 ; i<MAX ; i++) table[i] = NULL;
    struct Record *curr_rec;
    struct Employee emp;
    int data, choice, n;
    printf(" Enter Number of Employees : "); scanf("%d", &n);
    printf(" Enter id, Name, Address space saperated \n");
    for(int i=0 ; i<n ; i++) {
        printf("\tEmployee %d : ", i+1);
        scanf("%d%s%s", &emp.id, emp.name, emp.address);
        insert(emp);
    }
    while(1) {
        printf("\n");
        printf("\t1. Search Employee \n");
        printf("\t2. Delete Employee \n"); 
        printf("\t3. Insert New employee \n");
        printf("\t4. Exit \n");
        printf("Enter code : "); scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                curr_rec = search(data);
                if(curr_rec == NULL) printf("\t\tData Not Found \n");
                else {
                    printf("\t\tName    : %s \n", curr_rec->emp.name);
                    printf("\t\tAddress : %s \n", curr_rec->emp.address);
                }
                break;

            case 2:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                n = delete(data);
                if(n == -1) printf("\t\tData Not Found \n");
                else printf("\t\tData Deleted successfully \n");
                break;

            case 3:
                printf("\t\tEnter ID      : "); scanf("%d", &emp.id);
                printf("\t\tEnter Name    : "); scanf("%s", emp.name);
                printf("\t\tEnter Address : "); scanf("%d", emp.address);
                insert(emp);

            case 4:
                exit(1);
                break;

            default:
                printf("\t\tInvalid Option \n");
                break;
        }
    }
    return 0;
}
/*
OUTPUT:
 Enter Number of Employees : 5
 Enter id, Name, Address space saperated
        Employee 1 : 17 abcd margao
        Employee 2 : 34 efgh vasco
        Employee 3 : 51 ijkl panjim
        Employee 4 : 35 mnop mapusa
        Employee 5 : 18 qrst margao

        1. Search Employee
        2. Delete Employee
        3. Insert New employee
        4. Exit
Enter code : 1
                Enter employee id : 17
                Name    : abcd
                Address : margao

        1. Search Employee
        2. Delete Employee
        3. Insert New employee
        4. Exit
Enter code : 1
                Enter employee id : 18
                Name    : qrst
                Address : margao

        1. Search Employee
        2. Delete Employee
        3. Insert New employee
        4. Exit
Enter code : 2
                Enter employee id : 51
                Data Deleted successfully

        1. Search Employee
        2. Delete Employee
        3. Insert New employee
        4. Exit
Enter code : 1
                Enter employee id : 51
                Data Not Found

        1. Search Employee
        2. Delete Employee
        3. Insert New employee
        4. Exit
Enter code : 4
*/