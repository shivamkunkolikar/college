#include<stdio.h>
#include<stdlib.h>
#define MAX 17

enum state { empty, occupied, deleted };
struct Employee {
    int id;
    char name[30];
    char address[30];
};
struct Record {
    enum state st;
    struct Employee emp;
};
struct Record table_line[MAX], table_quad[MAX], table_dh[MAX];

int hash(int key) {
    return (key % MAX);
}

int d_hash(int key) {
    return (7 + (key % 7));
}

void insert_linear(struct Employee e) {
    for(int i=0 ; i<MAX ; i++) {
        int h = (hash(e.id) + i) % MAX;
        if(table_line[h].st != occupied) {
            table_line[h].emp = e;
            table_line[h].st = occupied;
            return;
        }
        else if(table_line[h].st == occupied && table_line[h].emp.id == e.id) {
            printf("Duplicate key \n");
            return;
        }
    }
    printf("\t\tElement cannot be placed in linear probing table!!! \n");
}

int search_line(int key) {
    for(int i=0 ; i<MAX ; i++) {
        int h = (hash(key) + i) % MAX;
        if(table_line[h].st == occupied && table_line[h].emp.id == key)
            return h;
    }
    return -1;
}

void delete_line(int key) {
    int loc = search_line(key);
    if(loc == -1) printf("\t\tData Not Found \n");
    else table_line[loc].st = deleted;
}

void insert_quad(struct Employee e) {
    for(int i=0 ; i<MAX ; i++) {
        int h = (hash(e.id) + (i * i)) % MAX;
        if(table_quad[h].st != occupied) {
            table_quad[h].emp = e;
            table_quad[h].st = occupied;
            return;
        }
        else if(table_quad[h].st == occupied && table_quad[h].emp.id == e.id) {
            printf("Duplicate key \n");
            return;
        }
    }
    printf("\t\tElement cannot be placed in quadratic probing table!!! \n");
}

int search_quad(int key) {
    for(int i=0 ; i<MAX ; i++) {
        int h = (hash(key) + (i * i)) % MAX;
        if(table_quad[h].st == occupied && table_quad[h].emp.id == key)
            return h;
    }
    return -1;
}

void delete_quad(int key) {
    int loc = search_quad(key);
    if(loc == -1) printf("\t\tData Not Found \n");
    else table_quad[loc].st = deleted;
}

void insert_dh(struct Employee e) {
    for(int i=0 ; i<MAX ; i++) {
        int h = (hash(e.id) + (i * d_hash(e.id))) % MAX;
        if(table_dh[h].st != occupied) {
            table_dh[h].emp = e;
            table_dh[h].st = occupied;
            return;
        }
        else if(table_dh[h].st == occupied && table_dh[h].emp.id == e.id) {
            printf("Duplicate key \n");
            return;
        }
    }
    printf("\t\tElement cannot be placed in double hash table !!! \n");
}

int search_dh(int key) {
    for(int i=0 ; i<MAX ; i++) {
        int h = (hash(key) + (i * d_hash(key))) % MAX;
        if(table_dh[h].st == occupied && table_dh[h].emp.id == key)
            return h;
    }
    return -1;
}

void delete_dh(int key) {
    int loc = search_dh(key);
    if(loc == -1) printf("\t\tData Not Found \n");
    else table_dh[loc].st = deleted;
}

int main() {
    int n, choice, data, loc;
    struct Employee e;
    for(int i=0 ; i<MAX ; i++) {
        table_line[i].st = empty;
        table_quad[i].st = empty;
        table_dh[i].st = empty;
    }
    printf(" Enter number of employees : "); scanf("%d", &n);
    printf(" Enter id, name, address space separated :- \n");
    for(int i=0 ; i<n ; i++) {
        printf("\tEmployee %d : ", i+1);
        scanf("%d%s%s", &e.id, e.name, e.address);
        insert_linear(e);
        insert_quad(e);
        insert_dh(e);
    }
    while(1) {
        printf("\n");
        printf("\t1. Search in Linear probing table \n");
        printf("\t2. Search in Quadratic probing table \n");
        printf("\t3. Search in Double hashed table \n");
        printf("\t4. Delete element from all tables \n");
        printf("\t5. Exit \n");
        printf("Enter code : "); scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                loc = search_line(data);
                if(loc == -1) printf(" \t\tData Not found \n");
                else { 
                    printf("\t\tName     : %s \n", table_line[loc].emp.name);
                    printf("\t\tAddress  : %s \n", table_line[loc].emp.address);
                }
                break;

            case 2:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                loc = search_quad(data);
                if(loc == -1) printf(" \t\tData Not found \n");
                else { 
                    printf("\t\tName     : %s \n", table_quad[loc].emp.name);
                    printf("\t\tAddress  : %s \n", table_quad[loc].emp.address);
                }
                break;

            case 3:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                loc = search_dh(data);
                if(loc == -1) printf(" \t\tData Not found \n");
                else { 
                    printf("\t\tName     : %s \n", table_dh[loc].emp.name);
                    printf("\t\tAddress  : %s \n", table_dh[loc].emp.address);
                }
                break;

            case 4:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                delete_line(data);
                delete_quad(data);
                delete_dh(data);
                break;

            case 5:
                exit(1);
                break;

            default:
                printf("\t\tInvalid option \n");
                break;
        }
    }
    return 0;
}
/*
OUTPUT:
 Enter number of employees : 10
 Enter id, name, address space separated :- 
        Employee 1 : 11 abcd margao
        Employee 2 : 22 efgh panjim
        Employee 3 : 50 ijkl vasco
        Employee 4 : 20 mnop mapusa
        Employee 5 : 52 qrst panjim
        Employee 6 : 84 uvwx margao
        Employee 7 : 94 qwrt vasco
        Employee 8 : 53 poiu mapusa
        Employee 9 : 48 qazw margao
        Employee 10 : 63 edcr margao

        1. Search in Linear probing table 
        2. Search in Quadratic probing table 
        3. Search in Double hashed table 
        4. Delete element from all tables 
        5. Exit 
Enter code : 1
                Enter employee id : 22
                Name     : efgh 
                Address  : panjim 

        1. Search in Linear probing table 
        2. Search in Quadratic probing table 
        3. Search in Double hashed table 
        4. Delete element from all tables 
        5. Exit 
Enter code : 2
                Enter employee id : 11
                Name     : abcd 
                Address  : margao

        1. Search in Linear probing table
        2. Search in Quadratic probing table
        3. Search in Double hashed table
        4. Delete element from all tables
        5. Exit
Enter code : 3
                Enter employee id : 20
                Name     : mnop
                Address  : mapusa

        1. Search in Linear probing table
        2. Search in Quadratic probing table
        3. Search in Double hashed table
        4. Delete element from all tables
        5. Exit
Enter code : 4
                Enter employee id : 11

        1. Search in Linear probing table
        2. Search in Quadratic probing table
        3. Search in Double hashed table
        4. Delete element from all tables
        5. Exit
Enter code : 1
                Enter employee id : 11
                Data Not found

        1. Search in Linear probing table
        2. Search in Quadratic probing table
        3. Search in Double hashed table
        4. Delete element from all tables
        5. Exit
Enter code : 2
                Enter employee id : 22
                Name     : efgh
                Address  : panjim

        1. Search in Linear probing table
        2. Search in Quadratic probing table
        3. Search in Double hashed table
        4. Delete element from all tables
        5. Exit
Enter code : 5
*/