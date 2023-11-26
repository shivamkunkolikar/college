#include<stdio.h>
#include<stdlib.h>
struct treenode {
    int data;
    struct treenode *lchild;
    struct treenode *rchild;
};

struct listnode {
    int data;
    struct listnode *link;
};

struct listnode *createList(struct listnode *start) {
    printf("Enter number of nodes : ");
    int n;
    scanf("%d", &n);
    if(n == 0)
        return start;
    start = (struct listnode*)malloc(sizeof(struct listnode));
    printf("Enter node 1 : ");
    scanf("%d", &start->data);
    start->link = NULL;
    struct listnode *tmp = start;
    for(int i=2 ; i<=n ; i++) {
        tmp->link = (struct listnode*)malloc(sizeof(struct listnode));
        tmp = tmp->link;
        printf("Enter node %d : ", i);
        scanf("%d", &tmp->data);
        tmp->link = NULL;
    }
    return start;
}

struct treenode* createTree(struct listnode *inorder, struct listnode *postorder, int num) {
    if(inorder == NULL || postorder == NULL || num == 0) {
        return NULL;
    }
    struct treenode *tmp = (struct treenode*)malloc(sizeof(struct treenode));
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    struct listnode *postorder_trev = postorder;
    for(int i=0 ; i<num-1 ; i++) {
        postorder_trev = postorder_trev->link;
    }
    tmp->data = postorder_trev->data;
    int n = 0;
    struct listnode *inorder_trev = inorder;
    while(inorder_trev->data != postorder_trev->data) {
        inorder_trev = inorder_trev->link;
        n++;
    }
    tmp->lchild = createTree(inorder, postorder, n);
    postorder_trev = postorder;
    for(int i=0 ; i<n ; i++) {
        postorder_trev = postorder_trev->link;
    }
    tmp->rchild = createTree(inorder_trev->link, postorder_trev, num - n - 1);
    return tmp;
}

void inorder_treversal(struct treenode *root) {
    if(root == NULL) {
        return;
    }
    inorder_treversal(root->lchild);
    printf(" %d ", root->data);
    inorder_treversal(root->rchild);
} 

int get_height(struct treenode *root) {
    if(root == NULL) return 0;
    int l_h = get_height(root->lchild);
    int r_h = get_height(root->rchild);
    return ((l_h > r_h ? l_h : r_h) + 1);
}

void levelorder(struct treenode *root) {
    if(root == NULL) return;
    struct treenode *queue[100];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while(rear >= front) {
        printf(" %d ", queue[front]->data);
        if(queue[front]->lchild) queue[++rear] = queue[front]->lchild;
        if(queue[front]->rchild) queue[++rear] = queue[front]->rchild;
        front++;
    }
    printf("\n");
}

int get_depth(struct treenode *root, int data, int curr_dp) {
    if(root == NULL) return -1;
    if(root->data == data) return curr_dp;
    int lst_d = get_depth(root->lchild, data, curr_dp + 1);
    int rst_d = get_depth(root->rchild, data, curr_dp + 1);
    if(lst_d != -1) return lst_d;
    if(rst_d != -1) return rst_d;
    return -1;
}

int main() {
    struct listnode *inorder = NULL, *postorder = NULL;
    struct treenode *root = NULL;
    int choice, data;
    inorder = createList(inorder);
    postorder = createList(postorder);
    root = createTree(inorder, postorder, 5);
    while(1) {
        printf("\t1. To find Height of Tree \n");
        printf("\t2. To find Depth  of given node \n");
        printf("\t3. To Display Level order tree \n");
        printf("\t4. To Exit \n");
        printf("Enter code : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 : 
                printf("\n\t\tHeight of tree is : %d \n", get_height(root));
                break;

            case 2 :
                printf("\n\t\tEnter Data of node : ");
                scanf("%d", &data);
                printf("\t\tDepth of node is   : %d \n", get_depth(root, data, 0));
                break;

            case 3 :
                printf("\n\t\tLevel order Tree : ");
                levelorder(root);
                break;

            case 4:
                exit(1);
                break;

            default:
                printf("\t\tInvalid Option \n");
                break;
        }
    }
    return 0;
}
/*
OUTPUT:
Enter number of nodes : 5
Enter node 1 : 4
Enter node 2 : 3
Enter node 3 : 5
Enter node 4 : 7
Enter node 5 : 9
Enter number of nodes : 5
Enter node 1 : 4
Enter node 2 : 5
Enter node 3 : 3
Enter node 4 : 9
Enter node 5 : 7
        1. To find Height of Tree
        2. To find Depth  of given node
        3. To Display Level order tree
        4. To Exit
Enter code : 1

                Height of tree is : 3
        1. To find Height of Tree
        2. To find Depth  of given node
        3. To Display Level order tree
        4. To Exit
Enter code : 2

                Enter Data of node : 3
                Depth of node is   : 1
        1. To find Height of Tree
        2. To find Depth  of given node
        3. To Display Level order tree
        4. To Exit
Enter code : 3

                Level order Tree :  7  3  9  4  5
        1. To find Height of Tree
        2. To find Depth  of given node
        3. To Display Level order tree
        4. To Exit
Enter code : 4
*/