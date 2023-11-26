#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *divide(struct node *p) {
    struct node *q, *start2;
    q = p->next->next;
    while(q != NULL) {
        p = p->next;
        q = q->next;
        if(q != NULL) q = q->next;
    }
    start2 = p->next;
    p->next = NULL;
    return start2;
}

struct node *merge(struct node *p1, struct node *p2) {
    struct node *startm, *q;
    if(p1->info <= p2->info) {
        startm = p1;
        p1 = p1->next;
    }
    else {
        startm = p2;
        p2 = p2->next;
    }
    q = startm;
    while(p1 != NULL && p2 != NULL) {
        if(p1->info <= p2->info){
            q->next = p1;
            q = q->next;
            p1 = p1->next;
        }
        else {
            q->next = p2;
            q = q->next;
            p2 = p2->next;
        }
    }
    if(p1 != NULL) {
        q->next = p1;
    }
    else {
        q->next = p2;
    }
    return startm;
}

void display(struct node *start) {
    if(start == NULL) {printf("Hi\n"); return;}
    struct node *p;
    for(p = start ; p != NULL ; p = p->next)
        printf("%d ", p->info);
    printf("\n");
}

struct node *addatend(struct node *start, int data) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = NULL;
    struct node *p = start;
    if(start == NULL) start = tmp;
    else {
        for(p = start ; p->next != NULL ; p = p->next) {}
        p->next = tmp;
    } 
    return start;
}

struct node *merge_sort(struct node *start) {
    struct node *start1, *start2, *start_m;
    if(start != NULL && start->next != NULL) {
        start1 = start;
        start2 = divide(start);
        start1 = merge_sort(start1);
        start2 = merge_sort(start2);
        start_m = merge(start1, start2);
        return start_m;
    }
    else return start;
}

void insertion_sort(char arr[], int n) {
    int tmp, j;
    for(int i=1 ; i<n ; i++) {
        tmp = arr[i];
        for(j=i ; j>=0 && tmp <= arr[j] ; j--) 
            arr[j] = arr[j - 1];
        arr[j + 1] = tmp;
    }
}

void restore_down(int arr[], int i, int size) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int num = arr[i];
    while(right <= size) {
        if(num >= arr[left] && num >= arr[right]){
            arr[i] = num;
            break;
        }
        else if(arr[left] > arr[right]) {
            arr[i] = arr[left];
            i = left;
        }
        else {
            arr[i] = arr[right];
            i = right;
        }
        left = i * 2;
        right = left + 1;
    }
    if(left == size && num < arr[left]) {
        arr[i] = arr[left];
        i = left;
    }
    arr[i] = num;
}

void build_heap(int arr[], int n) {
    for(int i = n/2 ; i>=1 ; i--)
        restore_down(arr, i, n);
}

int del_root(int arr[], int *size) {
    int max = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    restore_down(arr, 1, *size);
    return max;
}

void heap_sort(int arr[], int n) {
    int max;
    build_heap(arr, n);
    while(n > 1) {
        max = del_root(arr, &n);
        arr[n + 1] = max;
    }
}

int partition(int arr[], int low, int high) {
    int i = low + 1, j = high;
    int pivot = arr[low], tmp;
    while(i <= j) {
        while(arr[i] < pivot && i < high) i++;
        while(arr[j] > pivot) j--;
        if(i < j){ 
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
        else i++;
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quick_sort(int arr[], int low, int high) {
    if(high > low) {
        int piv_loc = partition(arr, low, high);
        quick_sort(arr, low, piv_loc - 1);
        quick_sort(arr, piv_loc + 1, high);
    }
}

int main() {
    int n, data;
    struct node *start = NULL;
    
    printf(" Enter no. of elements for Insertion sort : "); scanf("%d", &n);
    char ins_arr[n];
    printf(" Enter characters for insertion sort :- \n");
    printf(" Array         : "); scanf("%s", ins_arr);
    insertion_sort(ins_arr, n);
    printf("Insertion Sort : ");
    for(int i=0 ; i<n ; i++) printf("%c ", ins_arr[i]);
    printf("\n\n");
    
    printf(" Enter no. of elements for Merge sort     : "); scanf("%d", &n);
    printf(" Enter elements for merge sort :- \n");
    printf(" list elements : ");
    for(int i=0 ; i<n ; i++) { scanf("%d", &data); start = addatend(start, data); }
    start = merge_sort(start);
    printf(" Merge Sort    : ");
    display(start);
    printf("\n");

    printf(" Enter no. of elements for Quick sort     : "); scanf("%d", &n);
    int quik_arr[n];
    printf(" Enter elements for Quick Sort :- \n");
    printf(" Array         : ");
    for(int i=0 ; i<n ; i++) scanf("%d", &quik_arr[i]);
    quick_sort(quik_arr, 0, n - 1);
    printf(" Quick Sort    : ");
    for(int i=0 ; i<n ; i++) printf("%d ", quik_arr[i]);
    printf("\n\n");

    printf(" Enter no. of elements for Heap sort     : "); scanf("%d", &n);
    int heap_arr[n+1];
    printf(" Enter elements for Heap Sort :- \n");
    printf(" Array         : ");
    for(int i=1 ; i<=n ; i++) scanf("%d", &heap_arr[i]);
    heap_sort(heap_arr, n);
    printf(" Heap Sort     : ");
    for(int i=1 ; i<=n ; i++) printf("%d ", heap_arr[i]);
    printf("\n\n");

    return 0;     
}
/*
OUTPUT:
Enter no. of elements for Insertion sort : 10
 Enter characters for insertion sort :- 
 Array         : STRUCTURES
Insertion Sort : C E R R S S T T U U 

 Enter no. of elements for Merge sort     : 10        
 Enter elements for merge sort :- 
 list elements : 62 46 40 89 70 95 25 51 80 43
 Merge Sort    : 25 40 43 46 51 62 70 80 89 95 

 Enter no. of elements for Quick sort     : 10
 Enter elements for Quick Sort :- 
 Array         : 62 46 40 89 70 95 25 51 80 43
 Quick Sort    : 25 40 43 46 51 62 70 80 89 95 

 Enter no. of elements for Heap sort     : 10
 Enter elements for Heap Sort :- 
 Array         : 62 46 40 89 70 95 25 51 80 43
 Heap Sort     : 25 40 43 46 51 62 70 80 89 95 
*/