/*************************************************************************
	> File Name: 09.hzoj-259.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 09:52:31 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000
int n, m;
struct Node {
    int a, b;
    int code;
};

Node task[MAX_N + 5], mac[MAX_N + 5];


bool cmp(const Node &a, const Node &b) {
    if (a.a != b.a) return a.a > b.a;
    return a.b > b.b;
}

int cnt[105] = {0};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d%d", &mac[i].a, &mac[i].b);
    for (int i = 0; i < m; i++) scanf("%d%d", &task[i].a, &task[i].b);
    sort(task, task + m, cmp);
    sort(mac, mac + n, cmp);
    long long ans = 0, money = 0;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && mac[j].a >= task[i].a) {
            cnt[mac[j].b] += 1;
            j++;
        }
        for (int k = task[i].b; k <= 105; k++) {
            if (cnt[k] == 0) continue;
            cnt[k] -= 1;
            ans += 1;
            money += (task[i].a * 500 + task[i].b * 2);
            break;
        }
    }
    printf("%lld %lld\n", ans, money);
    
    return 0;
}
