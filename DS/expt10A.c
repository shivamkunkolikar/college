#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define initial 0
#define waiting 1
#define visited 2
#define finished 3
int adj[MAX][MAX] = {};
int state[MAX];
int queue[MAX], front = -1, rear = -1, n;
int d[MAX];
int f[MAX];
int time = 0;

void enqueue(int v) {
    if(rear == MAX - 1) printf("\t Stack Overflow\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = v; 
    }
}

int dequeue() {
    if(rear < front || front == -1) return -1;
    else return queue[front++];
}

void display() {
    if(front == -1 || front > rear) { 
        printf("Empty \n");
        return;
    }
    for(int i=front ; i<=rear ; i++)
        printf(" %d ", queue[i]);
    printf("\n");
}

void create_graph() {
    int u, v;
    printf("\tEnter number of vertices : ");
    scanf("%d", &n);
    int max_edges = n * (n - 1);
    for(int i=0 ; i<max_edges ; i++) {
        printf("\tEnter Edge %d (-1 and -1 to Quit) : ", i);
        scanf("%d%d", &u, &v);
        if(u == -1 && v == -1) break;
        else if(u < 0 || u > n || v < 0 || v > n) {
            printf("Invalid Vertex \n");
            i--;
        }
        else adj[u][v] = 1;
    }
}

void BFS(int a) {
    enqueue(a);
    int v;
    while((v = dequeue()) != -1) {
        state[v] = visited;
        printf(" %d \t\t\t", v);
        display();
        for(int i=0 ; i<n ; i++) {
            if(adj[v][i] == 1 && state[i] == initial) {
                enqueue(i);
                state[i] = waiting;
            }
        }
    }
}

void BF_traversal() {
    int v;
    for(int i=0 ; i<n ; i++) state[i] = initial;
    printf("\tEnter start Vertex : ");
    scanf("%d", &v);
    printf(" BFS Treversal \t Queue Contents \n");
    BFS(v);
    for(int i=0 ; i<n ; i++) { 
        if(state[i] == initial) 
            BFS(i);
    }
}

void DFS(int v) {
    d[v] = ++time;
    printf(" %d ", v);
    state[v] = visited;
    for(int i=0 ; i<n ; i++) {
        if(adj[v][i] == 1 && state[i] == initial)
                DFS(i);
    }
    f[v] = ++time;
    state[v] = finished;
}

void DF_treversal() {
    int v;
    time = 0;
    for(int i=0 ; i<n ; i++) state[i] = initial;
    printf("\tEnter Start Vertex : ");
    scanf("%d", &v);
    time = 0;
    printf("\n");
    printf(" DFS Traversal : ");  
    DFS(v);
    for(int i=0 ; i<n ; i++) {
        if(state[i] == initial) 
            DFS(i);
    }
    printf("\n");
    printf("Vertex \t Discovery Time    Finished Time \n");
    for(int i=0 ; i<n ; i++) {
        printf(" %d \t\t %d \t\t %d \n", i, d[i], f[i]);
    }
}

int main() {
    create_graph();
    int choice, data;
    while(1) {
        printf("\n\nEnter following option :\n");
        printf("\t1. BFS Traversal \n");
        printf("\t2. DFS Traversal \n");
        printf("\t3. Exit \n");
        printf("Enter code : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                BF_traversal();
                front = -1; rear = -1;
                break;

            case 2:
                DF_treversal();
                break;

            case 3: 
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
Enter number of vertices : 8
        Enter Edge 0 (-1 and -1 to Quit) : 0 1
        Enter Edge 1 (-1 and -1 to Quit) : 0 2
        Enter Edge 2 (-1 and -1 to Quit) : 0 3
        Enter Edge 3 (-1 and -1 to Quit) : 1 3
        Enter Edge 4 (-1 and -1 to Quit) : 1 6
        Enter Edge 5 (-1 and -1 to Quit) : 2 3
        Enter Edge 6 (-1 and -1 to Quit) : 2 4
        Enter Edge 7 (-1 and -1 to Quit) : 2 5
        Enter Edge 8 (-1 and -1 to Quit) : 3 5
        Enter Edge 9 (-1 and -1 to Quit) : 4 5
        Enter Edge 10 (-1 and -1 to Quit) : 5 7
        Enter Edge 11 (-1 and -1 to Quit) : 6 7
        Enter Edge 12 (-1 and -1 to Quit) : -1 -1


Enter following option :
        1. BFS Traversal 
        2. DFS Traversal 
        3. Exit 
Enter code : 1
        Enter start Vertex : 0
 BFS Treversal   Queue Contents 
 0                      Empty 
 1                       2  3 
 2                       3  6 
 3                       6  4  5 
 6                       4  5 
 4                       5  7 
 5                       7 
 7                      Empty


Enter following option :
        1. BFS Traversal
        2. DFS Traversal
        3. Exit
Enter code : 2
        Enter Start Vertex : 0

 DFS Traversal :  0  1  3  5  7  6  2  4
Vertex   Discovery Time    Finished Time
 0               1               16
 1               2               11
 2               12              15
 3               3               8
 4               13              14
 5               4               7
 6               9               10
 7               5               6


Enter following option :
        1. BFS Traversal
        2. DFS Traversal
        3. Exit
Enter code : 3
*/