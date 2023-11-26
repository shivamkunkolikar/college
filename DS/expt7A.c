#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node* insert_data(struct node *root, int ikey) {
	if(root == NULL) {
		root = (struct node*)malloc(sizeof(struct node));
		root->data = ikey;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	else if(ikey < root->data)
		root->lchild = insert_data(root->lchild, ikey);
	else if(ikey > root->data)
		root->rchild = insert_data(root->rchild, ikey);
	return root;
}

struct node* delete_node(struct node *root, int dkey) {
	struct node *tmp;
	if(root == NULL) {
		printf("Node not found \n");
		return root;
	}
	if(dkey < root->data)
		root->lchild = delete_node(root->lchild, dkey);
	else if(dkey > root->data)
		root->rchild = delete_node(root->rchild, dkey);
	else {
		if(root->lchild == NULL && root->rchild == NULL){
			tmp = root;
			root = NULL;
			free(tmp);
		}
		else if(root->lchild == NULL) {
			tmp = root;
			root = root->rchild;
			free(tmp);
		}
		else if(root->rchild == NULL) {
			tmp = root;
			root = root->lchild;
			free(tmp);
		}
		else {
			struct node *pre = root, *succ = root->rchild;
			while(succ->lchild != NULL) {
				pre = succ;
				succ = succ->lchild;
			}
			root->data = succ->data;
			tmp = succ;
			if(pre == root)
				root->rchild = succ->rchild;
			else 
				pre->lchild = succ->rchild;
			free(tmp);		
		}
	}
	return root;
}

void search_element(struct node *root, int skey) {
    while(root != NULL) {
        if(skey < root->data) 
            root = root->lchild;
        else if(skey > root->data)
            root = root->rchild;
        else {
            printf("\n\t\tElement %d found, at address : %u \n", skey, root);
            return;
        }
    }
    printf("\n\t\tElement not found \n");
}

int max_element(struct node *root) {
    if(root == NULL) {printf("Tree empty \n"); return -1;}
    while(root->rchild != NULL) root = root->rchild;
    return root->data;
}

int min_element(struct node *root) {
    if(root == NULL) {printf("Tree Empty \n"); return -1;}
    while(root->lchild != NULL) root = root->lchild;
    return root->data;
}

void inorder(struct node *root) {
	if(root == NULL) return;
	inorder(root->lchild);
	printf(" %d ", root->data);
	inorder(root->rchild);
}

void postorder(struct node *root) {
	if(root == NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf(" %d ", root->data);
}

void preorder(struct node *root) {
	if(root == NULL) return;
	printf(" %d ", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

int main() {
	struct node *root = NULL;
	int choice, data;
	while(1) {
		printf("\n");
		printf("\t1. Insert Data \n");
		printf("\t2. Delete Data \n");
		printf("\t3. Search Element \n");
		printf("\t4. Inorder,Postorder,Preorder Traversal \n");
		printf("\t5. To Find Maximum and Minimum value \n");
        printf("\t6. To Exit \n");
		printf("Enter code : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\n\t\tEnter Data : ");
				scanf("%d", &data);
				root = insert_data(root, data);
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
				search_element(root, data);
				break;
				
			case 4 :
                printf("\n\t\tInorder Tree : ");
				inorder(root);
				printf("\n\t\tPostrder Tree : ");
				postorder(root);
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
OUTPUT :
1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 20
                Inorder Tree :  20
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value 
        6. To Exit
Enter code : 1

                Enter Data : 10
                Inorder Tree :  10  20
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 30
                Inorder Tree :  10  20  30
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 15
                Inorder Tree :  10  15  20  30
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 1

                Enter Data : 25
                Inorder Tree :  10  15  20  25  30
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 2

                Enter Data : 20
                Inorder Tree :  10  15  25  30
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 3

                Enter Data : 15

                Element 15 found, at address : 1431573568

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 4

                Inorder Tree :  10  15  25  30
                Postrder Tree :  15  10  30  25
                Preorder Tree :  25  10  15  30
        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 5

                Maximum value : 30

                Minimum value : 10

        1. Insert Data
        2. Delete Data
        3. Search Element
        4. Inorder,Postorder,Preorder Traversal
        5. To Find Maximum and Minimum value
        6. To Exit
Enter code : 6
*/