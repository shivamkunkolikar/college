#include <stdio.h>
#include <stdlib.h>
struct node
{
	int ele;
	struct node *link;
};

struct node* createList(struct node*);
void displayList(struct node*);
struct node* get_intersection(struct node*, struct node*);
struct node* get_union(struct node*, struct node*);
struct node* subtract(struct node*, struct node*);



int main()
{
	struct node *s1 = NULL, *s2 = NULL, *s3 = NULL;
	int choice;
	printf("Enter Set 1 : \n");
	s1 = createList(s1);
	printf("Enter Set 2 : \n");
	s2 = createList(s2);
	printf("\n");
	printf("Set 1 : ");
	displayList(s1);
	printf("Set 2 : ");
	displayList(s2);
	while(1) 
	{
		printf("\n\n");
		printf("	1. Find Intersection \n");
		printf("	2. Find Union \n");
		printf("	3. To subtract set1 from set2 \n");
		printf("	4. To subtract set2 from set1 \n");
		printf("	5. To Exit \n");
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				s3 = get_intersection(s1, s2);
				printf("\tItersection : ");
				displayList(s3);
				break;

			case 2:
				s3 = get_union(s1, s2);
				printf("\tUnion : ");
				displayList(s3);
				break;

			case 3:
				s3 = subtract(s2, s1);
				printf("\tSet2 - Set1 : ");
				displayList(s3);
				break;

			case 4:
				s3 = subtract(s1, s2);
				printf("\tSet1 - Set2 : ");
				displayList(s3);
				break;

			case 5:
				exit(1);
				break;
		}
	}
	return 0;
}

struct node *createList(struct node *start)
{
	int n, i;
	struct node *tmp;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	if (n == 0)
		return start;
	tmp = (struct node *)malloc(sizeof(struct node));
	start = tmp;
	printf("Enter element 1 : ");
	scanf("%d", &tmp->ele);
	tmp->link = NULL;
	for (i = 2; i <= n; i++)
	{
		tmp->link = (struct node *)malloc(sizeof(struct node));
		tmp = tmp->link;
		printf("Enter element %d : ", i);
		scanf("%d", &tmp->ele);
		tmp->link = NULL;
	}
	return start;
}

void displayList(struct node *start)
{
	struct node *tmp = start;
	if (start == NULL)
	{
		printf("List is empty \n");
		return;
	}
	printf(" { ");
	while (tmp != NULL)
	{
		if(tmp->link != NULL)
			printf(" %d ,", tmp->ele);
		else
			printf(" %d ", tmp->ele);
		tmp = tmp->link;
	}
	printf(" } \n");
}

struct node *get_intersection(struct node *s1, struct node *s2)
{
	struct node *s3 = NULL, *p = s1, *q = s2, *r;
	r = (struct node *)malloc(sizeof(struct node));
	r->link = NULL;
	s3 = r;
	while (p != NULL)
	{
		q = s2;
		while (q != NULL)
		{
			if (p->ele == q->ele)
			{
				r->link = (struct node *)malloc(sizeof(struct node));
				r = r->link;
				r->ele = p->ele;
				r->link = NULL;
			}
			q = q->link;
		}
		p = p->link;
	}
	return s3->link;
}

struct node *get_union(struct node *s1, struct node *s2)
{
	struct node *s3, *p = s1, *q = s2, *r;
	r = (struct node *)malloc(sizeof(struct node));
	s3 = r;
	r->link = NULL;
	while (p != NULL)
	{
		r->link = (struct node *)malloc(sizeof(struct node));
		r = r->link;
		r->ele = p->ele;
		r->link = NULL;
		p = p->link;
	}
	while (q != NULL)
	{
		int flag = 0;
		while (p != NULL)
		{
			if (p->ele == q->ele)
			{
				flag = 1;
				break;
			}
			p = p->link;
		}
		if (flag == 0)
		{
			r->link = (struct node *)malloc(sizeof(struct node));
			r = r->link;
			r->ele = q->ele;
			r->link = NULL;
		}
		q = q->link;
	}
	return s3->link;
}

struct node *subtract(struct node *s1, struct node *s2)
{
	struct node *s3, *p = s1, *q = s2, *r;
	r = (struct node *)malloc(sizeof(struct node));
	r->link = NULL;
	s3 = r;
	while (p != NULL)
	{
		q = s2;
		int flag = 0;
		while (q != NULL)
		{
			if (p->ele == q->ele)
			{
				flag = 1;
				break;
			}
			q = q->link;
		}
		if (flag == 0)
		{
			r->link = (struct node *)malloc(sizeof(struct node));
			r = r->link;
			r->ele = p->ele;
			r->link = NULL;
		}
		p = p->link;
	}
	return s3->link;
}
/*
OUTPUT :
Enter Set 1 : 
Enter number of elements : 5
Enter element 1 : 1
Enter element 2 : 2
Enter element 3 : 3
Enter element 4 : 4
Enter element 5 : 5
Enter Set 2 : 
Enter number of elements : 6
Enter element 1 : 3
Enter element 2 : 4
Enter element 3 : 5
Enter element 4 : 6
Enter element 5 : 7
Enter element 6 : 8

Set 1 :  {  1 , 2 , 3 , 4 , 5  } 
Set 2 :  {  3 , 4 , 5 , 6 , 7 , 8  } 


        1. Find Intersection 
        2. Find Union 
        3. To subtract set1 from set2 
        4. To subtract set2 from set1 
        5. To Exit 
Enter choice : 1
        Itersection :  {  3 , 4 , 5  } 


        1. Find Intersection 
        2. Find Union 
        3. To subtract set1 from set2 
        4. To subtract set2 from set1 
        5. To Exit
Enter choice : 2
        Union :  {  1 , 2 , 3 , 4 , 5 , 3 , 4 , 5 , 6 , 7 , 8  }


        1. Find Intersection
        2. Find Union
        3. To subtract set1 from set2
        4. To subtract set2 from set1
        5. To Exit
Enter choice : 3
        Set2 - Set1 :  {  6 , 7 , 8  }


        1. Find Intersection
        2. Find Union
        3. To subtract set1 from set2
        4. To subtract set2 from set1
        5. To Exit
Enter choice : 4
        Set1 - Set2 :  {  1 , 2  }


        1. Find Intersection 
        2. Find Union
        3. To subtract set1 from set2
        4. To subtract set2 from set1 
        5. To Exit 
Enter choice : 5
*/