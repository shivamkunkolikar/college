#include<stdio.h>
#include<stdlib.h>
struct edge;
struct vertex {
    int info;
    struct edge *start_edge;
    struct vertex *next;
};
struct edge {
    struct vertex *ptr;
    struct edge *next;
};

struct vertex *start = NULL;

void add_vertex(int v) {
    struct vertex *tmp = (struct vertex*)malloc(sizeof(struct vertex));
    tmp->info = v;
    tmp->start_edge = NULL;
    tmp->next = start;
    start = tmp;
}

struct vertex *find_vertex(int u) {
    struct vertex *p;
    for(p = start ; p!=NULL ; p = p->next) {
        if(p->info == u) return p;
    }
    return NULL;
}

void add_edge(int u, int v) {
    struct vertex *loc = find_vertex(u);
    struct vertex *des = find_vertex(v);
    if(loc == NULL || des == NULL) {
        printf("Edge cannot be added \n");
        return;
    }
    struct edge *new_edge = (struct edge*)malloc(sizeof(struct edge));
    new_edge->ptr = des;
    new_edge->next = loc->start_edge;
    loc->start_edge = new_edge;
}

void delete_edge(int u, int v) {
    struct vertex *loc = find_vertex(u);
    struct vertex *des = find_vertex(v);
    struct edge *tmp;
    if(loc == NULL || des == NULL) {
        printf("Edge Not found \n");
        return;
    }
    struct edge *p = loc->start_edge;
    if(p == NULL) { printf("Edge Not found \n"); return; }
    if(p->ptr == des) {
        tmp = p;
        loc->start_edge = tmp->next;
        free(tmp);
        return;
    }
    p = loc->start_edge;
    while(p->next != NULL) {
        if(p->next->ptr == des) {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return;
        }
    }
    printf("Edge Not Found \n");
}


void delete_vertex(int v) {
    struct vertex *p = start, *tmp = NULL;
    if(p == NULL) return;
    if(p->info == v) {
        tmp = p;
        start = tmp->next;
    }
    else {
        for(p = start ; p->next != NULL ; p = p->next) {
            if(p->next->info == v) {
                tmp = p->next;
                p->next = tmp->next;
                break;
            }
        }
    }
    if(tmp == NULL) return;
    struct edge *q = tmp->start_edge, *a;
    while(q != NULL) {
        a = q;
        q = q->next;
        free(a);
    }
    struct vertex *r = tmp;
    free(tmp);
    for(p = start ; p != NULL ; p = p->next) {
        q = p->start_edge;
        if(q == NULL) continue;
        if(q->ptr == r) { 
            a = q; 
            p->start_edge = q->next; 
            free(a); 
        }
        else {
            for(q = p->start_edge ; q->next != NULL ; q = q->next) {
                if(q->next->ptr == r) {
                    a = q->next;
                    q->next = a->next;
                    free(a);
                    break;
                }
            }
        }
    }
}

void display_list() {
    if(start == NULL) return;
    struct vertex *v;
    struct edge *e;
    for(v = start ; v != NULL ; v = v->next) {
        printf(" %d ", v->info);
        e = v->start_edge;
        for(e = v->start_edge ; e != NULL ; e = e->next) {
            printf(" -> %d ", e->ptr->info);
        }
        printf("\n");
    } 
}

int main() {
    int choice, data, des, n;
    while(1) {
        printf("\n\nEnter following option :\n");
        printf("\t1. Insert Vertices \n");
        printf("\t2. Insert Edges \n");
        printf("\t3. Delete Vertex \n");
        printf("\t4. Delete Edge \n");
        printf("\t5. Display List \n");
        printf("\t6. Exit \n");
        printf("Enter code : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\tEnter no. of vertices : ");
                scanf("%d", &n);
                for(int i=0 ; i<n ; i++) {
                    printf("\t\tEnter vertex %d : ", i+1);
                    scanf("%d", &data);
                    add_vertex(data);
                }
                break;

            case 2:
                printf("\tEnter no. of Edges : ");
                scanf("%d", &n);
                for(int i=0 ; i<n ; i++) {
                    printf("Enter Source and Destination of %d : ", i+1);
                    scanf("%d%d", &data, &des);
                    add_edge(data, des);
                }
                break;

            case 3:
                printf("Enter Data : ");
                scanf("%d", &data);
                delete_vertex(data);
                break;

            case 4:
                printf("Enter Source and Destination : ");
                scanf("%d%d", &data, &des);
                delete_edge(data, des);
                break;

            case 5:
                printf("\n");
                display_list();
                break;

            case 6:
                exit(1);
                break;

            default:
                printf("\t Invalid Option \n");
                break;
        }
    } 
    return 0;
}
/*
OUTPUT:
Enter following option :
        1. Insert Vertices 
        2. Insert Edges 
        3. Delete Vertex 
        4. Delete Edge 
        5. Display List 
        6. Exit 
Enter code : 1
        Enter no. of vertices : 8
                Enter vertex 1 : 8
                Enter vertex 2 : 7
                Enter vertex 3 : 6
                Enter vertex 4 : 5
                Enter vertex 5 : 4
                Enter vertex 6 : 3
                Enter vertex 7 : 2
                Enter vertex 8 : 1


Enter following option :
        1. Insert Vertices
        2. Insert Edges
        3. Delete Vertex
        4. Delete Edge
        5. Display List
        6. Exit
Enter code : 2
        Enter no. of Edges : 12
Enter Source and Destination of 1 : 1 4
Enter Source and Destination of 2 : 1 3
Enter Source and Destination of 3 : 1 2
Enter Source and Destination of 4 : 2 7
Enter Source and Destination of 5 : 2 4
Enter Source and Destination of 6 : 3 6
Enter Source and Destination of 7 : 3 5
Enter Source and Destination of 8 : 3 4
Enter Source and Destination of 9 : 4 6
Enter Source and Destination of 10 : 5 6
Enter Source and Destination of 11 : 6 8
Enter Source and Destination of 12 : 7 8


Enter following option :
        1. Insert Vertices 
        2. Insert Edges 
        3. Delete Vertex 
        4. Delete Edge 
        5. Display List 
        6. Exit 
Enter code : 5

 1  -> 2  -> 3  -> 4 
 2  -> 4  -> 7 
 3  -> 4  -> 5  -> 6 
 4  -> 6 
 5  -> 6 
 6  -> 8 
 7  -> 8 
 8 


Enter following option :
        1. Insert Vertices
        2. Insert Edges
        3. Delete Vertex
        4. Delete Edge
        5. Display List
        6. Exit
Enter code : 3
Enter Data : 5


Enter following option :
        1. Insert Vertices
        2. Insert Edges
        3. Delete Vertex
        4. Delete Edge
        5. Display List
        6. Exit
Enter code : 5

 1  -> 2  -> 3  -> 4
 2  -> 4  -> 7
 3  -> 4  -> 6
 4  -> 6
 6  -> 8
 7  -> 8
 8


Enter following option :
        1. Insert Vertices
        2. Insert Edges
        3. Delete Vertex
        4. Delete Edge
        5. Display List
        6. Exit
Enter code : 4
Enter Source and Destination : 3 6


Enter following option :
        1. Insert Vertices
        2. Insert Edges
        3. Delete Vertex
        4. Delete Edge
        5. Display List
        6. Exit
Enter code : 5

 1  -> 2  -> 3  -> 4
 2  -> 4  -> 7
 3  -> 4
 4  -> 6
 6  -> 8
 7  -> 8
 8


Enter following option :
        1. Insert Vertices
        2. Insert Edges 
        3. Delete Vertex
        4. Delete Edge
        5. Display List
        6. Exit 
Enter code : 6
*/