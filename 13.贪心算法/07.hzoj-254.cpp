/*************************************************************************
	> File Name: 07.hzoj-254.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Sep 2024 01:28:51 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 50000
struct Node {
    int l, r, id;//开始、结束时间
};

Node arr[MAX_N + 5];
int m_time[MAX_N + 5], ans[MAX_N + 5];
int n, cnt = 0;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr[i].l, &arr[i].r); 
        arr[i].id = i;
    }
    sort(arr, arr + n, [&](Node a, Node b)->bool {
        if (a.l != b.l) return a.l < b.l;
        return a.id < b.id;
    });
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < cnt; j++) {
            if (m_time[j] >= arr[i].l) continue;
            pos = j;
            break;
        }
        if (pos == -1) {
            pos = cnt++;
        }
        m_time[pos] = arr[i].r;
        ans[arr[i].id] = pos + 1;
    }

    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}
