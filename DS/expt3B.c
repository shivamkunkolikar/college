#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 5
struct task {
	int taskID;
	char title[30];
	int duration;
	int status;
}s[100];
int n;
int front = -1;
int rear = -1;

struct task *task_queue[5];
//struct task task_array[10];

int isFull() {
    if((front == 0 && rear == MAX-1) || (((front) - (rear)) == 1))
        return 1;
    else
        return 0;
}

void enqueue(struct task *t) {
	if(isFull()) {
        printf("QUEUE FULL \n");
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    task_queue[rear] = t;
}

struct task* dequeue() {
    struct task *t;
    if(front == -1) {
        printf("QUEUE EMPTY \n");
        return t;
    }
    t = task_queue[front];
    if(front == rear) {
        front = -1;
        rear = -1;
        return t;
    }
    else {
        front = (front + 1) % MAX;
        return t;
    }
}

void input_task() {
    FILE *fin;
    int i;
    fin = fopen("taskinfo.txt", "r");
    if(fin == NULL) {
        printf("\t\tUnable to Fetch Tasks \n");
    }
    fscanf(fin, "%d", &n);
    for(i=0 ; i<n ; i++) {
        fscanf(fin, "%d%s%d", &s[i].taskID, s[i].title, &s[i].duration);  
        s[i].status = 0;  
    }
}

void putinQueue(int tid) {
    int i;
    for( i=0 ; i<n ; i++) {
        if(s[i].taskID == tid) {
            break;
        }
    }
    if(i == n) {
        printf("\t\tTask Not Found \n");
        return;
    }
    if(s[i].status == 0) {
        s[i].status = 1;
        enqueue(s+i);
        printf("\t\tTask Sheduled Successfully \n");
    }
    else if(s[i].status == 1) {
        printf("\t\tTask is already Queued \n");
        return;
    }
    else {
        printf("\t\tTask is already Finished \n");
        return;
    }
}

void display_queue() {
    int sno = 1;
    if(front == -1) {
        printf("\t\tNo Tasks in Queue \n");
        return;
    }
    if(rear < front) {
        for(int i=front ; i<MAX ; i++) {
            printf("\t\t[[%d] Task ID : %d --- ", sno, task_queue[i]->taskID);
            printf("Title : %-10s --- ", task_queue[i]->title);
            printf("time : %d ]\n", task_queue[i]->duration);
            sno++;
        }
        for(int i=0 ; i<=rear ; i++) {
            printf("\t\t[[%d] Task ID : %d --- ", sno++, task_queue[i]->taskID);
            printf("Title : %-10s --- ", task_queue[i]->title);
            printf("time : %d ]\n", task_queue[i]->duration);
        }
    }
    else{
        for(int i=front ; i<=rear ; i++) {
            printf("\t\t[[%d] Task ID : %d --- ", sno++, task_queue[i]->taskID);
            printf("Title : %-10s --- ", task_queue[i]->title);
            printf("time : %d ]\n", task_queue[i]->duration);
        }
    }
}

int main() {
    int choice, data;
    struct task *curr_task;
    input_task();
    while(1) {
        printf("\n\n");
        printf("\t1. Reset Tasks \n");
        printf("\t2. Enter tasks for sheduling \n");
        printf("\t3. Execute Task \n");
        printf("\t4. Display Queued Tasks\n");
        printf("\t5. Exit \n");
        printf("Enter code : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                input_task();
                break;

            case 2:
                printf("\t\tEnter Task ID : ");
                scanf("%d", &data);
                putinQueue(data);
                break;
                
            case 3:
                if(front == -1) {
                    printf("\t\tNo Task available for excution \n");
                    break;
                }
                curr_task = dequeue();
                printf("\t\tTask Execution Started \n");
                printf("\t\t[Executing Task]--------------------------------  \n");
                printf("\t\t    Task ID    : %d \n", curr_task->taskID);
                printf("\t\t    Task Title : %s \n", curr_task->title);
                printf("\t\t    Duration   : %d \n", curr_task->duration);
                sleep(curr_task->duration);
                curr_task->status = 2;
                printf("\t\t[Execution Finished]----------------------------  \n");
                break;

            case 4:
                display_queue();
                break;

            case 5:
                exit(1);
                break;
            
            default:
                printf("INVALID INPUT \n");
        }
    }
}
/*
  1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 2 
                Enter Task ID : 1
                Task Sheduled Successfully


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit 
Enter code : 2
                Enter Task ID : 2
                Task Sheduled Successfully


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 2
                Enter Task ID : 5
                Task Sheduled Successfully


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 2
                Enter Task ID : 1
                Task is already Queued


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 3
                Task Execution Started
                [Executing Task]--------------------------------
                    Task ID    : 1
                    Task Title : write
                    Duration   : 2
                [Execution Finished]----------------------------  


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task 
        4. Display Queued Tasks
        5. Exit
Enter code : 2
                Enter Task ID : 1
                Task is already Finished


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 2
                Enter Task ID : 6
                Task Sheduled Successfully


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 4
                [[1] Task ID : 2 --- Title : read       --- time : 2 ]
                [[2] Task ID : 5 --- Title : print      --- time : 5 ]
                [[3] Task ID : 6 --- Title : display    --- time : 5 ]


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 3
                Task Execution Started
                [Executing Task]--------------------------------
                    Task ID    : 2
                    Task Title : read
                    Duration   : 2
                [Execution Finished]----------------------------  


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 3
                Task Execution Started
                [Executing Task]--------------------------------
                    Task ID    : 5
                    Task Title : print
                    Duration   : 5
                [Execution Finished]----------------------------  


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task 
        4. Display Queued Tasks
        5. Exit
Enter code : 3
                Task Execution Started
                [Executing Task]--------------------------------
                    Task ID    : 6
                    Task Title : display
                    Duration   : 5 
                [Execution Finished]----------------------------  


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 4
                No Tasks in Queue


        1. Reset Tasks
        2. Enter tasks for sheduling
        3. Execute Task
        4. Display Queued Tasks
        5. Exit
Enter code : 5
*/