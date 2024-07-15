/*************************************************************************
	> File Name: 01.tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Jul 2024 07:13:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
    return p;
} 

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (rand() % 2) {
        root->lchild = insert(root->lchild, val);
    } else {
        root->rchild = insert(root->rchild, val);
    }
    return root;
}

/*
* 两种遍历方式：深度优先遍历、广度优先遍历
* */

int tot = 0;

void dfs(Node *root) {
    if (root == NULL) return ;
    int l, r;
    l = tot;
    tot += 1;
    dfs(root->lchild);
    dfs(root->rchild);
    r = tot;
    
    printf("%d : l[%d] | r[%d]\n", root->key, l, r);

    return ;
}

#define MAX_QUEUE 15

void bfs(Node *root) {
   if (root == NULL) return ;

    Node *array[MAX_QUEUE] = {0};
    #undef MAX_QUEUE
    int head = 0, tail = 0;
    array[tail++] = root;
    while (tail != head) {
        Node *tmp = array[head++];
        if (tmp->lchild) array[tail++] = tmp->lchild;
        if (tmp->rchild) array[tail++] = tmp->rchild;
        printf("%d ", tmp->key);
    }
    printf("\n");
    return ;
}


void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
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

    dfs(root);
    printf(" ========================= \n");
    bfs(root);
    #undef MAX_NODE
    clear(root);
    
    return 0;
}
