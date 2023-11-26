#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node {
    int info;
    int balance;
    struct node *lchild;
    struct node *rchild;
};

struct node *leftRotate(struct node *pptr) {
    struct node *aptr = pptr->rchild;
    pptr->rchild = aptr->lchild;
    aptr->lchild = pptr;
    return aptr;
}

struct node *rightRotate(struct node *pptr) {
    struct node *aptr = pptr->lchild;
    pptr->lchild = aptr->rchild;
    aptr->rchild = pptr;
    return aptr;
}

struct node *insert_leftBalance(struct node *pptr) {
    struct node *aptr = pptr->lchild;
    if(aptr->balance == 1) {
        aptr->balance = 0;
        pptr->balance = 0;
        pptr = rightRotate(pptr);
    }
    else {
        struct node *bptr = aptr->rchild;
        switch(bptr->balance) {
            case 1:
                aptr->balance = 0;
                pptr->balance = -1;
                break;

            case -1:
                aptr->balance = 1;
                pptr->balance = 0;
                break;

            case 0:
                aptr->balance = 0;
                pptr->balance = 0;
                break;
        }
        bptr->balance = 0;
        pptr->lchild = leftRotate(pptr->lchild);
        pptr = rightRotate(pptr);
    }
    return pptr;
}

struct node *insert_rightBalance(struct node *pptr) {
    struct node *aptr = pptr->rchild;
    if(aptr->balance == -1) {
        aptr->balance = 0;
        pptr->balance = 0;
        pptr = leftRotate(pptr);
    }
    else {
        struct node *bptr = aptr->lchild;
        switch(bptr->balance) {
            case 1:
                aptr->balance = -1;
                pptr->balance = 0;
                break;

            case -1:
                aptr->balance = 0;
                pptr->balance = 1;
                break;

            case 0:
                aptr->balance = 0;
                bptr->balance = 0;
                break;
        }
        bptr->balance = 0;
        pptr->rchild = rightRotate(pptr->rchild);
        pptr = leftRotate(pptr);
    }
    return pptr;
}

struct node *insert_right_check(struct node *pptr, int *ptaller) {
    switch(pptr->balance) {
        case 1:
            *ptaller = FALSE;
            pptr->balance = 0;
            break;
        
        case 0:
            pptr->balance = -1;
            break;

        case -1:
            pptr = insert_rightBalance(pptr);
            *ptaller = FALSE;
            break;
    }
    return pptr;
}

struct node *insert_left_check(struct node *pptr, int *ptaller) {
    switch(pptr->balance) {
        case -1:    
            *ptaller = FALSE;
            pptr->balance = 0;
            break;

        case 0:
            pptr->balance = 1;
            break;

        case 1:
            pptr = insert_leftBalance(pptr);
            *ptaller = FALSE;
            break;
    }
    return pptr;
}

struct node *insert_node(struct node *root, int ikey) {
    static int taller;
    if(root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->info = ikey;
        root->lchild = NULL;
        root->rchild = NULL;
        root->balance = 0;
        taller = TRUE;
    }
    else if(ikey < root->info) {
        root->lchild = insert_node(root->lchild, ikey);
        if(taller == TRUE)
            root = insert_left_check(root, &taller);
    }
    else if(ikey > root->info) {
        root->rchild = insert_node(root->rchild, ikey);
        if(taller == TRUE)
            root = insert_right_check(root, &taller);
    }
    else {
        taller = FALSE;
    }
    return root;
}

struct node *delete_leftBalalnce(struct node *pptr, int *pshorter) {
    struct node *aptr, *bptr;
    aptr = pptr->lchild;
    if(aptr->balance == 0) {
        pptr->balance = 1;
        aptr->balance = -1;
        *pshorter = FALSE;
        pptr = rightRotate(pptr);
    }
    else if(aptr->balance == 1) {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rightRotate(pptr);
    }
    else {
        bptr = aptr->rchild;
        switch(bptr->balance) {
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                break;

            case 1:
                pptr->balance = -1;
                aptr->balance = 0;
                break;

            case -1:
                pptr->balance = 0;
                aptr->balance = 1;
                break;
        }
        bptr->balance = 0;
        pptr->lchild = leftRotate(aptr);
        pptr = rightRotate(pptr);
    }
    return pptr;
}

struct node *delete_rightBalalnce(struct node *pptr, int *pshorter) {
    struct node *aptr, *bptr;
    aptr = pptr->rchild;
    if(aptr->balance == 0) {
        pptr->balance = -1;
        aptr->balance = 1;
        *pshorter = FALSE;
        pptr = leftRotate(pptr);
    }
    else if(aptr->balance == 1) {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = leftRotate(pptr);
    }
    else {
        bptr = aptr->lchild;
        switch(bptr->balance) {
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                break;

            case 1:
                pptr->balance = 0;
                aptr->balance = -1;
                break;

            case -1:
                pptr->balance = 1;
                aptr->balance = 0;
                break;
        }
        bptr->balance = 0;
        pptr->lchild = rightRotate(aptr);
        pptr = leftRotate(pptr);
    }
    return pptr;
}

struct node *delete_left_check(struct node *pptr, int *pshorter) {
    switch(pptr->balance) {
        case 0:
            pptr->balance = -1;
            *pshorter = FALSE;
            break;

        case 1:
            pptr->balance = 0;
            break;

        case -1:
            pptr = delete_rightBalalnce(pptr, pshorter);
            break;
    }
    return pptr;
}

struct node *delete_right_check(struct node *pptr, int *pshorter) {
    switch(pptr->balance) {
        case 0:
            pptr->balance = 1;
            *pshorter = FALSE;
            break;

        case -1:
            pptr->balance = 0;
            break;

        case 1:
            pptr = delete_leftBalalnce(pptr, pshorter);
            break;
    }
    return pptr;
}

struct node *delete_node(struct node *pptr, int dkey) {
    struct node *tmp, *succ;
    static int shorter;
    if(pptr == NULL) {
        printf("Key not found \n");
        shorter = FALSE;
        return pptr;
    }
    if(dkey < pptr->info) {
        pptr->lchild = delete_node(pptr->lchild, dkey);
        if(shorter == TRUE)
            pptr = delete_left_check(pptr, &shorter); 
    }
    else if(dkey > pptr->info) {
        pptr->rchild = delete_node(pptr->rchild, dkey);
        if(shorter == TRUE)
            pptr = delete_right_check(pptr, &shorter);
    }
    else {
        if(pptr->lchild != NULL && pptr->rchild != NULL) {
            succ = pptr->rchild;
            while(succ->lchild) 
                succ = succ->lchild;
            pptr->info = succ->info;
            pptr->rchild = delete_node(pptr->rchild, succ->info);
            if(shorter == TRUE)
                pptr = delete_right_check(pptr, &shorter);
        }
        else {
            tmp = pptr;
            if(pptr->lchild != NULL) 
                pptr = pptr->lchild;
            else if(pptr->rchild != NULL)
                pptr = pptr->rchild;
            else 
                pptr = NULL;
        }
    }
    return pptr;
}

void inorder(struct node *root) {
    if(root == NULL) return;
    inorder(root->lchild);
    printf(" %2d ", root->info);
    inorder(root->rchild);
}

void levelorder(struct node *root) {
    struct node *queue[100];
    struct node *pop_element;
    int rear = -1;
    int front = 0;
    if(root == NULL) {
        printf("Empty \n");
        return;
    }
    queue[++rear] = root;
    while(rear >= front) {
        printf(" %2d ", queue[front]->info);
        pop_element = queue[front++];
        if(pop_element->lchild) {
            queue[++rear] = pop_element->lchild;
        }
        if(pop_element->rchild) {
            queue[++rear] = pop_element->rchild;
        }
    }
    printf("\n");
}

int max_element(struct node *root) {
    if(root == NULL) {printf("Tree empty \n"); return -1;}
    while(root->rchild != NULL) root = root->rchild;
    return root->info;
}

int min_element(struct node *root) {
    if(root == NULL) {printf("Tree Empty \n"); return -1;}
    while(root->lchild != NULL) root = root->lchild;
    return root->info;
}

void search_element(struct node *root, int skey) {
    while(root != NULL) {
        if(skey < root->info) 
            root = root->lchild;
        else if(skey > root->info)
            root = root->rchild;
        else {
            printf("\n\t\tElement %d found, at address : %u \n", skey, root);
            return;
        }
    }
    printf("\n\t\tElement not found \n");
}

int main() {
    struct node *root = NULL;
	int choice, data;
	while(1) {
		printf("\n");
		printf("\t1. Insert New Element \n");
		printf("\t2. Delete Element \n");
		printf("\t3. Search Element \n");
		printf("\t4. To Find Maximum and Minimum value \n");
        printf("\t5. To Find Inorder and Levelorder \n");
        printf("\t6. To Exit \n");
		printf("Enter code : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\n\t\tEnter Data : ");
				scanf("%d", &data);
				root = insert_node(root, data);
				printf("\t\tInorder Tree    : ");
				inorder(root);
                printf("\n\t\tLevelorder Tree : ");
                levelorder(root);
				break;
				
			case 2:
				printf("\n\t\tEnter Data : ");
				scanf("%d", &data);
				root = delete_node(root, data);
				printf("\t\tInorder Tree    : ");
				inorder(root);
                printf("\n\t\tLevelorder Tree : ");
                levelorder(root);
				break;
				
			case 3 :
				printf("\n\t\tEnter Data : ");
				scanf("%d", &data);
                search_element(root, data);
				break;
				
			case 4 :
				printf("\n\t\tMaximum value : %d \n", max_element(root));
                printf("\n\t\tMinimum value : %d \n", min_element(root));
				break;

            case 5 :
                printf("\n\t\t  Inorder Tree  : ");
				inorder(root);
                printf("\n\t\tLevelorder Tree : ");
				levelorder(root);
				break;
				
			case 6 :
				exit(1);
                break;
				
			default:
				printf("\n\t\tInvalid Data \n");
				break;
		}
	}
	return 0;
}
/*
OUTPUT:
 1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value 
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 1

                Enter Data : 26
                Inorder Tree    :  26
                Levelorder Tree :  26

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 1

                Enter Data : 29
                Inorder Tree    :  26  29
                Levelorder Tree :  26  29

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 1

                Enter Data : 44
                Inorder Tree    :  26  29  44
                Levelorder Tree :  29  26  44

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 1

                Enter Data : 45
                Inorder Tree    :  26  29  44  45
                Levelorder Tree :  29  26  44  45

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 1

                Enter Data : 81
                Inorder Tree    :  26  29  44  45  81
                Levelorder Tree :  29  26  45  44  81

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 1

                Enter Data : 61
                Inorder Tree    :  26  29  44  45  61  81
                Levelorder Tree :  45  29  81  26  44  61

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 1

                Enter Data : 66
                Inorder Tree    :  26  29  44  45  61  66  81
                Levelorder Tree :  45  29  66  26  44  61  81

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 2

                Enter Data : 45
                Inorder Tree    :  26  29  44  61  66  81
                Levelorder Tree :  61  29  66  26  44  81

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 2

                Enter Data : 26
                Inorder Tree    :  29  44  61  66  81
                Levelorder Tree :  61  29  66  44  81

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 2

                Enter Data : 66
                Inorder Tree    :  29  44  61  81
                Levelorder Tree :  61  29  81  44

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 2

                Enter Data : 81
                Inorder Tree    :  29  44  61
                Levelorder Tree :  61  29  44

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 2

                Enter Data : 61
                Inorder Tree    :  29  44
                Levelorder Tree :  29  44

        1. Insert New Element
        2. Delete Element
        3. Search Element
        4. To Find Maximum and Minimum value
        5. To Find Inorder and Levelorder
        6. To Exit
Enter code : 6
*/