/*************************************************************************
	> File Name: 07.p1019_单词接龙.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Aug 2024 09:53:49 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

#define MAX_N 20

int n, ans = 0, vis[MAX_N + 5] = {0};
string str[MAX_N + 5], start;
int d[MAX_N + 5][MAX_N + 5] = {0};

int f(string &s1, string &s2) {
    for (int i = s1.size() - 1; i >= 1; i--) {
        int flag = 1;
        for (int j = 0; j < s1.size() - i; j++) {
            if (s1[i + j] == s2[j]) continue;
            flag = 0;
            break;
        }
        if (flag == 1) return s1.size() - i; 
    }
    
    return 0;
}

void dfs(int now, int L) {
    vis[now] += 1;
    if (L > ans) {
        ans = L;
    }
    for (int i = 0; i < n; i++) {
        if (d[now][i] == 0) continue;
        if (vis[i] == 2) continue;
        dfs(i, L + str[i].size() - d[now][i]);
    }
    vis[now] -= 1;
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    cin >> start;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = f(str[i], str[j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (str[i][0] != start[0]) continue;
        dfs(i, str[i].size());
    }
    cout << ans << endl;
    return 0;
}
