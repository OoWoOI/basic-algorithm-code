/*************************************************************************
	> File Name: 02.quick_union.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Aug 2024 03:02:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10000
int fa[MAX_N + 5];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    return ;
}

int find(int x) {
    if (fa[x] == x) return x;
    return find(fa[x]);
}

int merge(int a, int b) {
    int aa = find(a), bb = find(b);
    if (aa == bb) return 0;
    fa[aa] = bb;
    return 1;
}


void output(int n) {
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < ret; i++) printf("-");
    printf("\n");
    for (int i = 0;  i <= n; i++) {
        printf("%3d", fa[i]);
    }
    printf("\n");
    return ;
}


int main() {
    int n, a, b;
    cin >> n;
    init(n);
    while (cin >> a >> b) {
        printf("merge %d with %d : %d\n", a, b, merge(a, b));
        output(n);
    }

    return 0;
}
