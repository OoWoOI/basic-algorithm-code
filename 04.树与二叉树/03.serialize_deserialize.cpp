/*************************************************************************
	> File Name: 03.serialize_deserialize.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Jul 2024 05:27:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
}Node;

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

#define KEY(n) ((n) ? (n->key) : (-1))

//序列化
#define MAX_CHR 1000

char buff[MAX_CHR + 5];
int len = 0;

void serialize(Node *root) {
    if (root == NULL) return ;
    len += sprintf(buff + len, "%d", KEY(root));
    if (root->lchild == NULL && root->rchild == NULL) return ;
    len += sprintf(buff + len, "(");
    serialize(root->lchild);
    len += sprintf(buff + len, ",");
    serialize(root->rchild);
    len += sprintf(buff + len, ")");
    return ;
}

//反序列化

Node *deserialize(char *str) {
    Node *root = NULL, *preNode = NULL;
    
    Node **array = (Node **)malloc(sizeof(Node *) * MAX_CHR);

    int top = -1, scode = 0, flag = 0;

    for (int i = 0; str[i]; i++) {
        switch (scode) {
            case 0: {
                //读取关键词
                if (str[i] <= '9' && str[i] >= '0') {
                    scode = 1;//读取数字
                } else if (str[i] == '(') {
                    scode = 2;//入栈新元素
                } else if (str[i] == ',') {
                    scode = 3;//修改flag
                } else if (str[i] == ')') {
                    scode = 4;//完成栈顶元素的弹出
                }
                i -= 1;
            } break;

            case 1: {
                //读取数字
                int num = 0;
                while (str[i] <= '9' && str[i] >= '0') {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                
                preNode = getNewNode(num);
                
                if (root == NULL) {
                    root = preNode;
                } 

                if (top != -1 && flag == 0) {
                    array[top]->lchild = preNode;
                }
                
                if (top != -1 && flag == 1) {
                    array[top]->rchild = preNode;
                }
                scode = 0;
                i -= 1;
            } break;
            case 2: {
                //入栈新元素 "("
                array[++top] = preNode;
                flag = 0;
                scode = 0;
            } break;
            case 3: {
                //遇到逗号 ","
                flag = 1;
                scode = 0;
            } break;
            case 4: {
                //出栈 ")"
                --top;
                flag = 0;
                scode = 0;
            } break;
        }
    }

    return root;
}


void output(Node *root) {
    if (root == NULL) return ;
    printf("%d : l[%d] r[%d]\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    output(root->lchild);
    output(root->rchild);
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
    #define MAX_NODE 10
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100);
    }
    //输出
    output(root);
    printf("\n");
    //序列化
    serialize(root);
    printf("广义表 : %s\n", buff);
    //反序列化
    Node *new_root = deserialize(buff);
    output(new_root);
    printf("\n");
    clear(root);
    #undef MAX_NODE
    return 0;
}
