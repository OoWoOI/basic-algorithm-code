/*************************************************************************
	> File Name: 02.avl_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Aug 2024 06:03:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

//get new node
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;;
    p->h = 1;
    p->lchild = p->rchild = NULL;
    return p;
}

#define KEY(n) ((n) ? (n->key) : -1)
#define H(n) ((n) ? (n->h) : 0)
#define L(n) ((n) ? (n->lchild) : NULL)
#define R(n) ((n) ? (n->rchild) : NULL)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void update_height(Node *root) {
    //更新高度
    printf("更新高度!\n");
    if (root == NULL) return ;
    root->h = MAX(H(L(root)), H(R(root))) + 1;
    return ;
}

//左旋
Node *rotta_left(Node *root) {
    printf("左旋\n");
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

//右旋
Node *rotta_right(Node *root) {
    printf("右旋\n");
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild= root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (root == NULL) return root;
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {
        //L类型: LX
        if (H(L(L(root))) < H(L(R(root)))) {
            //R类型: LR 左旋
            root->lchild = rotta_left(L(root)); 
        } 
        //LL 右旋
        root = rotta_right(root);
    } else {
        //R类型 : RX
        if (H(R(R(root))) < H(R(L(root)))) {
            //RL
            root->rchild = rotta_right(R(root));
        }
        //RR
        root = rotta_left(root);
    }
    update_height(root);
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) {
        root->rchild = insert(root->rchild, key);
    } else {
        root->lchild = insert(root->lchild, key);
    }
    update_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            root = temp;
        } else {
            Node *p = predecessor(root);//前驱结点
            root->key = p->key;
            root->lchild = erase(root->lchild, p->key);
        }
    }
    update_height(root);
    return maintain(root);
}


//clear
void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

//output by pre order
void output(Node *root) {
    if (root == NULL); return ;
    printf("(%d : %d, %d)\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    output(root->lchild);
    output(root->rchild);
    return ;
}

//output by in order
void in_order(Node *root) {
    if (root == NULL) return ;
    in_order(root->lchild);
    printf("VAL (%4d : %4d, %4d) ===> H(%d : %d, %d)\n", 
           KEY(root),
           KEY(L(root)),
           KEY(R(root)),
           H(root),
           H(L(root)),
           H(R(root))
          );
    in_order(root->rchild);
    return ;
}


int main() {
    Node *root = NULL;
    int x;
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("insert %d to AVL tree\n", x);
        root = insert(root, x);
    }
    output(root);
    printf("in order : \n");
    in_order(root);
    printf("\n");
    printf("Enter you want del val : \n");
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("erase %d from AVL tree\n", x);
        root = erase(root, x);
        in_order(root);
        printf("\n");
    }
    clear(root);
    return 0;
}
