#include<stdio.h>
#include<stdlib.h>
#define TRUE '1'
#define FALSE '0'
struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
    char lthread;
    char rthread;
};

struct node *insert(struct node *root, int ikey) {
    struct node *p = root;
    struct node *par = NULL;
    while(p != NULL) {
        if(ikey < p->data && p->lthread == FALSE) {
            par = p;
            p = p->lchild;
        }
        else if(ikey > p->data && p->rthread == FALSE) {
            par = p;
            p = p->rchild;
        }
        else {
            break;
        }
    }
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = ikey;
    tmp->lthread = TRUE;
    tmp->rthread = TRUE;
    if(p == NULL) {
        root = tmp;
        root->lchild = NULL;
        root->rchild = NULL;
    }
    else if(ikey < p->data) {
        tmp->lchild = p->lchild;
        tmp->rchild = p;
        p->lthread = FALSE;
        p->lchild = tmp;
    }
    else if(ikey > p->data) {
        tmp->lchild = p;
        tmp->rchild = p->rchild;
        p->rthread = FALSE;
        p->rchild = tmp;
    }
    return root;
}

struct node *caseA(struct node *root, struct node *par, struct node *ptr) {
    if(par == NULL) root = NULL;
    else if(ptr == par->lchild) {
        par->lthread = TRUE;
        par->lchild = ptr->lchild;
    }
    else if(ptr == par->rchild) {
        par->rthread = TRUE;
        par->rchild = ptr->rchild;
    }
    free(ptr);
    return root;
}

struct node* inSucc(struct node* ptr) {
    if (ptr->rthread == TRUE) return ptr->rchild;
    ptr = ptr->rchild;
    while (ptr->lthread == FALSE) ptr = ptr->lchild;
    return ptr;
}

struct node* inPred(struct node* ptr)
{
    if (ptr->lthread == TRUE) return ptr->lchild;
    ptr = ptr->lchild;
    while (ptr->rthread == FALSE) ptr = ptr->rchild;
    return ptr;
}

struct node *caseB(struct node *root, struct node *par, struct node *ptr) {
    struct node* child;
    if (ptr->lthread == FALSE) child = ptr->lchild;
    else child = ptr->rchild;
    
    if (par == NULL) root = child;
    else if (ptr == par->lchild) par->lchild = child;
    else par->rchild = child;
 
    struct node* s = inSucc(ptr);
    struct node* p = inPred(ptr);
 
    if (ptr->lthread == TRUE) p->rchild = s;
    else s->lchild = p;
 
    free(ptr);
    return root;
}

struct node *caseC(struct node *root, struct node *par, struct node *ptr) {
    struct node* parsucc = ptr;
    struct node* succ = ptr->rchild;
 
    while (succ->lthread==FALSE) {
        parsucc = succ;
        succ = succ->lchild;
    }
    ptr->data = succ->data;
    if (succ->lthread == TRUE && succ->rthread == TRUE)
        root = caseA(root, parsucc, succ);
    else root = caseB(root, parsucc, succ);
 
    return root;
}

struct node* delete_node(struct node* root, int dkey) {
    struct node *par = NULL, *ptr = root;
    int found = 0;
 
    while (ptr != NULL) {
        if (dkey == ptr->data) { found = 1; break;}
        if (dkey < ptr->data && ptr->lthread == FALSE) {
                ptr = ptr->lchild;
                par = ptr;
        }
        else if(dkey > ptr->data && ptr->rthread == FALSE) {
                ptr = ptr->rchild;
                par = ptr;
        }
        else break;
    }
 
    if (found == 0) 
        printf("dkey not present in tree\n");
    else if (ptr->lthread == FALSE && ptr->rthread == FALSE)
        root = caseC(root, par, ptr);
    else if (ptr->lthread == FALSE)
        root = caseB(root, par, ptr);
    else if (ptr->rthread == FALSE)
        root = caseB(root, par, ptr);
    else
        root = caseA(root, par, ptr);
 
    return root;
}

struct node *search(struct node *root, int skey) {
    while(root != NULL) {
        if(root->data == skey)
            return root;
        else if(skey < root->data && root->lthread == FALSE)
            root = root->lchild;
        else if(skey > root->data && root->rthread == TRUE)
            root = root->rchild;
        else break;
    }
    printf("Node Not found \n");
    return NULL;
}

void inorder(struct node *root) {
    struct node *p = root;
    while(p->lthread == FALSE) p = p->lchild;
    while(p != NULL) {
        printf(" %d ", p->data);
        p = inSucc(p);
    }
    printf("\n");
}

void preorder(struct node *root) {
    if(root != NULL) printf(" %d ", root->data);
    if(root->lthread == FALSE)
        preorder(root->lchild);
    if(root->rthread == FALSE)
        preorder(root->rchild);
}

int max_element(struct node *root) {
    if(root == NULL) return -1;
    while(root->rthread != TRUE) {
        root = root->rchild;
    }
    return root->data;
}

int min_element(struct node *root) {
    if(root == NULL) return -1;
    while(root->lthread != TRUE) {
        root = root->lchild;
    }
    return root->data;
}

int main() {
	struct node *root = NULL;
	int choice, data;
	while(1) {
		printf("\n");
		printf("\t1. Insert Data \n");
		printf("\t2. Delete Data \n");
		printf("\t3. Search Element \n");
		printf("\t4. Inorder And Postorder Traversal \n");
		printf("\t5. To Find Maximum and Minimum value \n");
        printf("\t6. To Exit \n");
		printf("Enter code : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\n\t\tEnter Data : ");
				scanf("%d", &data);
				root = insert(root, data);
				printf("\t\tInorder Tree : ");
				inorder(root);
				break;
				
			case 2:
				printf("\n\t\tEnter Data : ");
				scanf("%d", &data);
				root = delete_node(root, data);
				printf("\t\tInorder Tree : ");
				inorder(root);
				break;
				
			case 3 :
				printf("\n\t\tEnter Data : ");
				scanf("%d", &data);
                printf("Element found at : %u \n", search(root, data));
				break;
				
			case 4 :
                printf("\n\t\tInorder Tree  : ");
				inorder(root);
                printf("\n\t\tPreorder Tree : ");
				preorder(root);
				break;
				
			case 5 :
				printf("\n\t\tMaximum value : %d \n", max_element(root));
                printf("\n\t\tMinimum value : %d \n", min_element(root));
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
 1. Insert Data 
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 20
                Inorder Tree :  20

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 10
                Inorder Tree :  10  20

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 30
                Inorder Tree :  10  20  30

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal 
        5. To Find Maximum and Minimum value 
        6. To Exit
Enter code : 1

                Enter Data : 15
                Inorder Tree :  10  15  20  30

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 25
                Inorder Tree :  10  15  20  25  30

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 2

                Enter Data : 20
                Inorder Tree :  10  15  25  30

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit 
Enter code : 3

                Enter Data : 10
Element found at : 3523744784

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 4

                Inorder Tree  :  10  15  25  30

                Preorder Tree :  25  10  15  30
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 5

                Maximum value : 30

                Minimum value : 10

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder And Postorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 6

*/