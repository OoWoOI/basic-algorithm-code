/*************************************************************************
	> File Name: 02.p1135_奇怪的电梯.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Aug 2024 03:38:05 PM CST
 ************************************************************************/

#include<iostream>

using namespace std;

#define MAX_N 200
int to[MAX_N + 5];
int dis[MAX_N + 5];

void dfs(int k, int a, int total) {
    if (dis[a] <= k) return ;
    dis[a] = k;
    if (a + to[a] <= total) {
        dfs(k + 1, a + to[a], total);
    }
    if (a - to[a] >= 1) {
        dfs(k + 1, a - to[a], total);
    }
    return ;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> to[i];
    for (int i = 1; i <= n; i++) dis[i] = n + 1;
    dfs(0, a, n);
    cout << (dis[b] == n + 1 ? -1 : dis[b]) << endl;
    return 0;
}
