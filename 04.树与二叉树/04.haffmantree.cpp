/*************************************************************************
	> File Name: 04.haffmantree.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Jul 2024 10:23:16 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define MAX_CHR 128

typedef struct Node {
    char ch;
    int freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char ch, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

int findMinNode(Node **arr, int n) {
    int ind = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[ind]->freq > arr[i]->freq ) ind = i;
    }
    return ind;
} 

void swap_node(Node **arr, int i, int j) {
    Node *tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    return ;
}


Node *buildHaffManTree(Node **arr, int n) {

    for (int i = 1; i < n; i++) {
        //find two node
        int ind1 = findMinNode(arr, n - i);
        swap_node(arr, ind1, n - i);
        
        int ind2 = findMinNode(arr, n - i - 1);
        swap_node(arr, ind2, n - i - 1);
        
        //build new node
        int freq_tmp = arr[n - i]->freq + arr[n - i - 1]->freq;
        Node *new_node = getNewNode(0, freq_tmp);
        new_node->lchild = arr[n - i - 1];
        new_node->rchild = arr[n - i];
        arr[n - i - 1] = new_node;
    }

    return arr[0];
}


char *ch_code[MAX_CHR + 5] = {0};
int k = 0;

void extractHaffManTree(Node *root, char buff[], int k) {
    buff[k] = 0;
    if (root->lchild == NULL && root->rchild == NULL) {
        ch_code[root->ch] = strdup(buff);
        return ;
    }

    buff[k] = '0';
    extractHaffManTree(root->lchild, buff, k + 1);
    buff[k] = '1';
    extractHaffManTree(root->rchild, buff, k + 1);

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
    int n;
    char s[10] = {0};
    scanf("%d", &n);
    
    Node **array = (Node **)malloc(sizeof(Node *) * n);

    for (int i = 0; i < n; i++) {
        int freq;
        scanf("%s%d", s, &freq);
        array[i] = getNewNode(s[0], freq);
    }

    Node *root = buildHaffManTree(array, n);
    char buff[1000] = {0};
    extractHaffManTree(root, buff, 0);
    
    for (int i = 0; i < MAX_CHR; i++) {
        if (ch_code[i] == NULL) continue;
        printf("%c : %s\n", i, ch_code[i]);
    }

    clear(root);
    #undef MAX_CHR
    return 0;
}
