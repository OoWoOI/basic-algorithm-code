/*************************************************************************
	> File Name: 11.p2392_考试前临时抱佛脚.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Sep 2024 09:55:25 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 5
#define MAX_M 20
#define MAX_NUM 9999999
int s[MAX_N + 5];
int t[MAX_N + 5][MAX_M + 5];//存储第I科目的第J道题所需时间
int ans;

void dfs(int k, int x, int l, int r) {
    if (k == s[x]) {
        ans = min(ans, max(l, r));
        return ;
    }
    //TODO
    l += t[x][k];
    dfs(k + 1, x, l, r);
    l -= t[x][k];
    //TODO
    r += t[x][k];
    dfs(k + 1, x, l, r);
    r -= t[x][k];
    return ;
}

int main() {
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> t[i][j];
        }
    }
    int total = 0;
    for (int i = 0; i < 4; i++) {
        ans = MAX_NUM;
        dfs(0, i, 0, 0);
        total += ans;
    }
    cout << total << endl;
    return 0;
}

