#include<stdio.h>
#include<stdlib.h>

struct Employee {
    int id;
    char name[30];
    char address[30];
}empL[100], empB[100];
int empLN = 0, empBN = 0;

int linear_search(struct Employee arr[], int low, int high, int skey) {
    for(int i=low ; i<=high ; i++) if(skey == arr[i].id) return i;
    return -1;
}

int binary_search(struct Employee arr[], int low, int high, int skey) {
    int mid = (high + low) / 2;
    if(arr[mid].id == skey) return mid;
    else if(high == mid) return -1;
    else if(skey < arr[mid].id) return binary_search(arr, low, mid - 1,  skey);
    else if(skey > arr[mid].id) return binary_search(arr, mid + 1, high, skey);
}

int main() {
    int choice, data, loc;
    while(1) {
        printf("\n");
        printf("Enter following options : \n");
        printf("\t1. Enter data for Linear Search \n");
        printf("\t2. Enter data for Binary Search \n");
        printf("\t3. Linear Search \n");
        printf("\t4. Binary Search \n");
        printf("\t5. Exit \n");
        printf("Enter code : "); scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\t\tEnter number of Employees : "); scanf("%d", &empLN);
                printf("\t\tEnter id, name and address space seperated :- \n");
                for(int i=0 ; i<empLN ; i++) {
                    printf("\t\tEmployee %d : ", i+1);
                    scanf("%d%s%s", &empL[i].id, empL[i].name, empL[i].address);
                }
                break;

            case 2:
                printf("\t\tEnter number of Employees : "); scanf("%d", &empBN);
                printf("\t\tEnter id, name and address space seperated in sorted order:-\n");
                for(int i=0 ; i<empBN ; i++) {
                    printf("\t\tEmployee %d : ", i+1);
                    scanf("%d%s%s", &empB[i].id, empB[i].name, empB[i].address);
                }
                break;

            case 3:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                loc = linear_search(empL, 0, empLN - 1, data);
                if(loc == -1) printf("\t\tData Not Found ");
                else printf("\t\tName     : %s \n\t\tAddress  : %s", empL[loc].name, empL[loc].address);
                break;

            case 4:
                printf("\t\tEnter employee id : "); scanf("%d", &data);
                loc = binary_search(empB, 0, empBN - 1, data);
                if(loc == -1) printf("\t\tData Not Found ");
                else printf("\t\tName     : %s \n\t\tAddress  : %s", empB[loc].name, empB[loc].address);
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
Enter following options : 
        1. Enter data for Linear Search 
        2. Enter data for Binary Search
        5. Linear Search
        4. Binary Search
        5. Exit
Enter code : 1
                Enter number of Employees : 5
                Enter id, name and address space seperated :-
                Employee 1 : 100 abcd margao
                Employee 2 : 200 efgh panjim
                Employee 3 : 150 ijkl ^C
C:\clg\DS>gcc expt11A.c

C:\clg\DS>a.exe

Enter following options : 
        1. Enter data for Linear Search 
        2. Enter data for Binary Search 
        3. Linear Search 
        4. Binary Search 
        5. Exit 
Enter code : 1
                Enter number of Employees : 5
                Enter id, name and address space seperated :- 
                Employee 1 : 100 abcd margao
                Employee 2 : 200 efgh panjim
                Employee 3 : 150 jklm mapusa
                Employee 4 : 300 nopq vasco
                Employee 5 : 400 rstu curchorem

Enter following options : 
        1. Enter data for Linear Search 
        2. Enter data for Binary Search 
        3. Linear Search 
        4. Binary Search 
        5. Exit 
Enter code : 3
                Enter employee id : 150
                Name     : jklm 
                Address  : mapusa
Enter following options : 
        1. Enter data for Linear Search 
        2. Enter data for Binary Search 
        3. Linear Search 
        4. Binary Search 
        5. Exit 
Enter code : 3
                Enter employee id : 500
                Data Not Found
Enter following options :
        1. Enter data for Linear Search
        2. Enter data for Binary Search
        3. Linear Search
        4. Binary Search
        5. Exit
Enter code : 2
                Enter number of Employees : 5
                Enter id, name and address space seperated in sorted order:-
                Employee 1 : 100 abcd margao
                Employee 2 : 200 efgh panjim
                Employee 3 : 300 ijkl mapusa
                Employee 4 : 400 mnop vasco
                Employee 5 : 500 qrst curchorem

Enter following options :
        1. Enter data for Linear Search
        2. Enter data for Binary Search
        3. Linear Search
        4. Binary Search
        5. Exit
Enter code : 4
                Enter employee id : 400
                Name     : mnop
                Address  : vasco
Enter following options :
        1. Enter data for Linear Search
        2. Enter data for Binary Search
        3. Linear Search
        4. Binary Search
        5. Exit
Enter code : 100
                Invalid option

Enter following options :
        1. Enter data for Linear Search
        2. Enter data for Binary Search
        3. Linear Search
        4. Binary Search
        5. Exit
Enter code : 4
                Enter employee id : 100
                Name     : abcd
                Address  : margao
Enter following options :
        1. Enter data for Linear Search
        2. Enter data for Binary Search
        3. Linear Search
        4. Binary Search
        5. Exit
Enter code : 4
                Enter employee id : 600
                Data Not Found
Enter following options :
        1. Enter data for Linear Search
        2. Enter data for Binary Search
        3. Linear Search
        4. Binary Search
        5. Exit
Enter code : 5
*/