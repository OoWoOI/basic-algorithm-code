/*************************************************************************
	> File Name: 01.priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Jul 2024 10:12:10 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct priority_queue {
    int *__data, *data;
    int size, n;
} priority_queue;

#define ROOT 1
#define CMP >
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * + 1)

#define SWAP(a, b) {\
    __typeof((a)) c = (a);\
    (a) = (b);\
    (b) = (c);\
}

priority_queue *initPQ(int size) {
    priority_queue *p = (priority_queue *)malloc(sizeof(priority_queue));
    p->__data = (int *)malloc(sizeof(int) * size);
    p->data = p->__data - ROOT;
    p->n = 0;
    p->size = size;
    return p;
}

int full(priority_queue *p) {
    return p->n == p->size;
}

int empty(priority_queue *p) {
    return p->n == 0;
}

int top(priority_queue *p) {
    if (empty(p)) return -1;
    return p->data[ROOT];
}

void up_update(priority_queue *p, int i) {
    while (i CMP ROOT && p->data[i] CMP p->data[FATHER(i)]) {
        SWAP(p->data[i], p->data[FATHER(i)]);
        i = FATHER(i);
    }
    return ;
}

void down_update(priority_queue *p, int i, int n) {
    while (RIGHT(i) <= n) {
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if (l <= n && p->data[l] CMP p->data[ind]) ind = l;
        if (r <= n && p->data[r] CMP p->data[ind]) ind = r;
        if (ind == i) break;
        SWAP(p->data[i], p->data[ind]);
        i = ind;
    }
    return ;
}

int push(priority_queue *p, int x) {
    if (full(p)) return 0;
    p->data[++p->n] = x;
    up_update(p, p->n);
    return 1;
} 

int pop(priority_queue *p) {
    if (empty(p)) return 0;
    SWAP(p->data[ROOT], p->data[p->n]);
    down_update(p, ROOT, p->n - 1);
    p->n -= 1;
    return 1;
}

void output(priority_queue *p) {
    printf("priority_queue : ");
    for (int i = ROOT; i <= p->n; i++) {
        if (i != ROOT) printf(" ");
        printf("%d", p->data[i]);
    }
    printf("\n");
    return ;
}

void clearPQ(priority_queue *p) {
    if (p == NULL) return ;
    free(p->__data);
    free(p);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    
    priority_queue *p = initPQ(n);
    int op, x;
    while (~scanf("%d", &op)) {
        if (op == 0) {
            scanf("%d", &x);
            printf("insert val(%d) into priority_queue!\n", x);
            push(p, x);
        } else {
            printf("pop top val from priority_queue!\n");
            pop(p);
        }
        output(p);
    }
    clearPQ(p);

    return 0;
}
