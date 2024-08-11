/*************************************************************************
	> File Name: 11.hzoj242-最大平均值.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Aug 2024 02:18:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
long long a[MAX_N + 5], b[MAX_N + 5];


int check(long long *a, int n, int M, int A) {
    for (int i = 1; i <= n; i++) b[i] = a[i] - A;
    b[0] = 0;
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];//前缀和序列
    long long pre = 0;
    for (int i = M; i <= n; i++) {
        pre = min(pre, b[i - M]);
        if (b[i] - pre >= 0) return 1;
    }
    return 0;
}

int solve(long long *a, int n, int M, int max_num) {
    int head = 0, tail = max_num, mid;
    while (head < tail) {
        mid = (head + tail + 1) / 2;
        if (check(a, n, M, mid)) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    return head;
}

int main() {
    int n, m, max_num = 0;
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        x *= 1000;
        a[i] = x;
        max_num = max(max_num, x);
    }

    printf("%d\n", solve(a, n, m, max_num));
    

    return 0;
}
