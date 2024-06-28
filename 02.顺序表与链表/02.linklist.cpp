/*************************************************************************
	> File Name: 02.linklist.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Jun 2024 05:21:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;


Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL; 
    return p;
}



Node *insert(Node *head, int pos, int val) {
    Node new_head, *p = &new_head, *node = getNewNode(val);
    new_head.next = head;
    for (int i = 0; i < pos; i++)  p = p->next;
    node->next = p->next;
    p->next = node;
    return new_head.next;
}

void clear(Node *head) {
    if (head == NULL) return ;
    for (Node *p = head, *q; p; p = q) {
        q = p->next;
        free(p);
    }
    return ;
}


void output_linlist(Node *head, int flag) {
    int  n = 0; 
    for (Node *p = head; p; p = p->next) n += 1;
    for (int i = 0; i < n; i++) {
        printf("%3d", i);
        printf("  ");
    }
    printf("\n");
    for (Node *p = head; p; p = p->next) {
        printf("%3d", p->data);
        printf("->");
    }
    printf("\n");
    if (flag == 0) printf("\n\n");
    return ;
}


int find(Node *head, int val) {
    Node *p = head;
    int n = 0;
    while (p) {
        if (p->data == val) {
            output_linlist(head, 1);
            int len = 5 * n + 2;
            for (int i = 0; i < len; i++) printf(" ");
            printf("^\n");
            for (int i = 0; i < len; i++) printf(" ");
            printf("|\n");
            return 1;
        }
        n++;
        p = p->next;
    }
    
    return 0;
}


int main() {
    srand(time(0));
    #define MAX_OP 10
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = rand() % (i + 1), val = rand() % 100, ret;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
        output_linlist(head, 0);
    }
    int val;
    while (~scanf("%d", &val)) {
        if (find(head, val) == 0) {
            printf("not found\n");
        }
    }
    clear(head);
    return 0;
}
