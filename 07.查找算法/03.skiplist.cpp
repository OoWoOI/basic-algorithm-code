/*************************************************************************
	> File Name: 03.skiplist.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 09 Aug 2024 02:57:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<inttypes.h>

//skiplist node struct
typedef struct Node {
    int key, level;
    struct Node *next, *up, *down;
}Node;

//skiplist struct
#define MAX_LEVEL 32
#define min(a, b) ((a < b) ? (a) : (b))
typedef struct Skiplist {
    Node *head, *tail;
    int max_level;
}Skiplist;



//get new skiplist node
Node *getNewNode(int key, int n) {
    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        nodes[i].key = key;
        nodes[i].level = i;
        nodes[i].next = NULL;
        nodes[i].down = (i ? nodes + (i - 1) : NULL);
        nodes[i].up = (i + 1 < n ? nodes + (i + 1) : NULL);

    }
    return nodes + n - 1;
}

//get new Skiplist
Skiplist *getNewSkiplist(int n) {
    Skiplist *s = (Skiplist *)malloc(sizeof(Skiplist));
    s->head = getNewNode(INT32_MIN, n);
    s->tail = getNewNode(INT32_MAX, n);
    s->max_level = n;

    Node *p = s->head, *q = s->tail;
    while (p) {
        p->next = q;
        p = p->down, q = q->down;
    }
    while (s->head->level != 0) s->head = s->head->down;
    return s;
}

//find x
Node *find(Skiplist *s, int x) {
    Node *p = s->head;
    while (p && p->key != x) {
        if (p->next->key <= x) p = p->next;//右边
        else p = p->down;//下移
    }
    
    return p;
}


//rand level
double rand_double() {
#define MAX_RAND_N 1000000
    return (rand() % MAX_RAND_N ) * 1.0 / MAX_RAND_N;
#undef MAX_RAND_N
}

int rand_level(Skiplist *s) {
    int level = 1;
    double p = 1.0 / 2.0;
    while (rand_double() < p) level += 1;
    return min(s->max_level, level);
}

//insert 
void insert(Skiplist *s, int x) {
    //make new node and rand level
    int level = rand_level(s);
    printf("rand level = %d\n", level);
    while (s->head->level + 1 < level) s->head = s->head->up; 
    Node *node = getNewNode(x, level);
    //find node better x
    Node *p = s->head;
    printf("insert begin\n");
    while (p->level != node->level) p = p->down;
    while (p) {
        while (p->next->key < node->key) p = p->next;
        node->next = p->next;
        p->next = node;
        p = p->down;
        node = node->down;
    }
    return ;
}

//free Skiplist struct 
void clearNode(Node *p) {
    if (p == NULL) return ;
    free(p);
    return ;
}

void clearSkiplist(Skiplist *s) {
    Node *p = s->head, *q;
    while (p->level != 0) p = p->down;
    while (p) {
        q = p->next;
        clearNode(p);
        p = q;
    }
    free(s);
    return ;
}

void output(Skiplist *s) {
    Node *p = s->head;
    int len = 0;
    for (int i = 0; i <= s->head->level; i++) {
        len += printf("%4d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("-");
    }
    printf("\n");
    while(p->level > 0) p = p->down; 
    while (p) {
        bool flag = (p->key != INT32_MIN && p->key != INT32_MAX);
        for (Node *q = p; flag && q; q = q->up) {
            printf("%4d", p->key);
        }
        if (flag) printf("\n");
        p = p->next;
    }
    
}

int main() {
    srand(time(0));
    int x;
    Skiplist *s = getNewSkiplist(MAX_LEVEL);
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        insert(s, x);
        output(s);
    }
    output(s);
    //find
    while (~scanf("%d", &x)) {
        Node *p = find(s, x);
        printf("find result : ");
        if (p) {
            printf("key : %d, level = %d\n", p->key, p->level);
        } else {
            printf("NULL\n");
        }
    }

    return 0;
}
