/*************************************************************************
	> File Name: 05.hzoj636_旅行计划.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 17 Aug 2024 09:24:33 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAX_N 100000
int indeg[MAX_N + 5];//入度情况
int ans[MAX_N + 5] = {0};
vector<vector<int>> g(MAX_N  + 5);//存储结点信息



int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0, x, y; i < m; i++) {
        scanf("%d%d", &x, &y);
        indeg[y] += 1;
        g[x].push_back(y);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i]) continue;
        q.push(i);
        ans[i] = 1;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i =0, I = g[now].size(); i < I; i++) {
            int t = g[now][i];
            indeg[t] -= 1;
            if (indeg[t] == 0) {
                q.push(t);
            }
            ans[t] = max(ans[t],  ans[now] + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}
