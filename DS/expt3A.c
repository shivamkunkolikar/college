#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue_arr[5];
int front = -1;
int rear = -1;
int isEmpty() {
    if(front == -1)
        return 1;
    else
        return 0;
}
int isFull() {
    if((front - rear == 1) || (front == 0 && rear == MAX-1))
        return 1;
    else
        return 0;
}
void enqueue(int element) {
    if(isFull()) {
        printf("Queue Full \n");
        return;
    }
    rear = (rear + 1)%MAX;
    if(front == -1)
        front = 0;
    queue_arr[rear] = element;
}
int dequeue() {
    if(isEmpty()) {
        printf("Queue Empty \n");
    }
    int element;
    element = queue_arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
        return element;
    }
    front = (front + 1)%MAX;
    return element;
}
void display() {
    if(front == -1) {
        printf("Queue Empty \n");
        return;
    }
    if(rear >= front) {
        for(int i=front ; i<=rear ; i++) {
            printf(" %d ", queue_arr[i]);
        }
    }
    else {
        for(int i=front ; i<MAX ; i++) {
            printf(" %d ", queue_arr[i]);
        }
        for(int i=0 ; i<=rear ; i++) {
            printf(" %d ", queue_arr[i]);
        }
    }
    printf("\n");
}
int peek() {
    return queue_arr[front];
}
int main() {
    int data, choice;
    while(1) {
        printf("    1. Enqueue \n");
        printf("    2. Dequeue \n");
        printf("    3. Dispalay \n");
        printf("    4. peek \n");
        printf("    5. Exit \n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("        Enter item : ");
                scanf("%d", &data);
                enqueue(data);
                printf("Queue Contents : ");
                display();
                break;

            case 2:
                printf("\t\tDequed Element : %d \n", dequeue());
                printf("Queue Contents : ");
                display();
                break;

            case 3:
                printf("\t\tDisplay : ");
                display();
                break;

            case 4:
                printf("\t\tPeek : %d \n", peek());
                break;

            case 5:
                exit(1);

            default:
                printf("\t\tInvalid Choice \n");
        }
    }
}
/*
1. Enqueue 
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
3
                Display : Queue Empty
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
1
        Enter item : 10
Queue Contents :  10
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
1
        Enter item : 20
Queue Contents :  10  20
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
1
        Enter item : 30
Queue Contents :  10  20  30
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
1
        Enter item : 40
Queue Contents :  10  20  30  40
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
1
        Enter item : 50
Queue Contents :  10  20  30  40  50
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
1
        Enter item : 60
Queue Full
Queue Contents :  10  20  30  40  50
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
2
                Dequed Element : 10
Queue Contents :  20  30  40  50
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
2
                Dequed Element : 20
Queue Contents :  30  40  50
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
2
                Dequed Element : 30
Queue Contents :  40  50
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
2
                Dequed Element : 40
Queue Contents :  50
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
2
                Dequed Element : 50
Queue Contents : Queue Empty
    1. Enqueue
    2. Dequeue
    3. Dispalay
    4. peek
    5. Exit
5
*/