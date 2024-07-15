/*************************************************************************
	> File Name: 02.binary_tree_output.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Jul 2024 12:06:40 PM CST
 ************************************************************************/
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>

 typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
 } Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->ltag = p->rtag = 0;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);

    if (rand() % 20) {
        root->lchild = insert(root->lchild, val);
    } else {
        root->rchild = insert(root->rchild, val);
    }
    
    return root;
}


//三种遍历方式：前、中、后

void preOrder(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->key);
    preOrder(root->lchild);
    preOrder(root->rchild);
    return ;
}

void inOrder(Node *root) {
    if (root == NULL) return ;
    inOrder(root->lchild);
    printf("%d ", root->key);
    inOrder(root->rchild);
    return ;
}

void lastOrder(Node *root) {
    if (root == NULL) return ;
    lastOrder(root->lchild);
    lastOrder(root->rchild);
    printf("%d ", root->key);
    return ;
}

Node *pre_node = NULL, *in_node = NULL;

void __build_thread(Node *root) {
    
    if (root == NULL) return ;

    if (root->ltag == 0) __build_thread(root->lchild);
    
    if (in_node == NULL) in_node = root;

    if (pre_node && root->lchild == NULL) {
        root->lchild = pre_node;
        root->ltag = 1;
    }
    
    if (pre_node && pre_node->rchild == NULL) {
        pre_node->rchild = root;
        pre_node->rtag = 1;
    }
    
    pre_node = root;
    
    if (root->rtag == 0) __build_thread(root->rchild);

    return ;
}

void build_thread(Node *root) {
    
    __build_thread(root);
    pre_node->rchild = NULL;
    pre_node->rtag = 1;
    
    return ;
}

Node *getNextNode(Node *root) {
    
    if (root->rtag == 1) return root->rchild;

    root = root->rchild;

    while (root->ltag == 0 && root->lchild) root = root->lchild;
    
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == 0) clear(root->lchild);
    if (root->rtag == 0) clear(root->rchild);
    free(root);
    return ;
}


 int main() {
    srand(time(0)); 
    #define MAX_NODE 10
    Node *root = NULL;
    
    for (int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100);
    }

    printf("前序: ");
    preOrder(root);
    printf("\n");
    printf("中序: ");
    inOrder(root);
    printf("\n");
    printf("后序: ");
    lastOrder(root);
    printf("\n");

    printf(" =========================== \n");

    build_thread(root);
    
    root = in_node;
    printf("中序线索化: ");
    while (root) {
        printf("%d ", root->key);
        root = getNextNode(root);
    }
    printf("\n");
    clear(root);

    return 0;
 }
