#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* link;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int element) {
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	if(tmp == NULL) {
		printf("Queue Overflow \n");
		return;
	}
	tmp->data = element;
	tmp->link = NULL;
	if(rear == NULL || front == NULL) {
		rear = tmp;
		front = tmp;
		return;
	}
	rear->link = tmp;
	rear = rear->link;
}

int dequeue() {
	if(front == NULL) {
		printf("Queue Underflow \n");
		return -1;
	}
	int element = front->data;
	struct node *tmp = front;
	front = front->link;
	free(tmp);
	return element;
}

void display() {
	if(front == NULL) {
		printf("Queue Empty \n");
		return;
	}
	struct node *i;
	for(i = front ; i != NULL ; i=i->link) 
		printf(" %d ", i->data);
	printf("\n");
}

int main() {
	int choice, data;
	while(1) {
		printf("\n\n");
		printf("\t1. Enqueue Element \n");
		printf("\t2. Dequeue Element \n");
		printf("\t3. Display Queue   \n");
		printf("\t4. Peek            \n");
		printf("\t5. Exit            \n");
		printf("Enter Choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\t\tEnter data : ");
				scanf("%d", &data);
				enqueue(data);
				printf("Queue Contents : ");
				display();
				break;

			case 2:
				printf("\t\tDequeued Element : %d \n", dequeue());
				printf("Queue Contents : ");
				display();
				break;

			case 3:
				printf("Queue Contents : ");
				display();
				break;

			case 4:
				if(front != NULL)
					printf("\t\tPeek : %d \n", front->data);
				else
					break;
				break;

			case 5:
				exit(1);
				break;

			default:
				printf("\t\tInvalid Choice  \n");
				break;
		}
	}
	return 0;
}
/*
OUTPUT :


        1. Enqueue Element
        2. Dequeue Element
        3. Display Queue
        4. Peek
        5. Exit
Enter Choice : 1
                Enter data : 10
Queue Contents :  10 


        1. Enqueue Element 
        2. Dequeue Element 
        3. Display Queue   
        4. Peek
        5. Exit
Enter Choice : 1
                Enter data : 20
Queue Contents :  10  20 


        1. Enqueue Element 
        2. Dequeue Element 
        3. Display Queue   
        4. Peek
        5. Exit
Enter Choice : 1
                Enter data : 30
Queue Contents :  10  20  30 


        1. Enqueue Element 
        2. Dequeue Element 
        3. Display Queue   
        4. Peek
        5. Exit
Enter Choice : 2
                Dequeued Element : 10
Queue Contents :  20  30


        1. Enqueue Element
        2. Dequeue Element
        3. Display Queue
        4. Peek
        5. Exit
Enter Choice : 1
                Enter data : 40
Queue Contents :  20  30  40 


        1. Enqueue Element 
        2. Dequeue Element 
        3. Display Queue   
        4. Peek
        5. Exit
Enter Choice : 3
Queue Contents :  20  30  40 


        1. Enqueue Element 
        2. Dequeue Element 
        3. Display Queue   
        4. Peek
        5. Exit
Enter Choice : 4
                Peek : 20 


        1. Enqueue Element 
        2. Dequeue Element 
        3. Display Queue   
        4. Peek
        5. Exit
Enter Choice : 5

*/
