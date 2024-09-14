/*************************************************************************
	> File Name: 08.p1032_字符串转换.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Sep 2024 01:06:19 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>

using namespace std;
#define MAX_NUM 100
int ans = MAX_NUM, trans_cnt = 0, ans_k;
string A, B;
string from[15], to[15];
map<string, int> dp;

void dfs(string &now, int step) {
    if (step > ans_k) return ;
    dp[now] = step;
    if (step > 10) return ;
    if (now == B) {
        ans = step;
        return ;
    }
    
    for (int i = 0; i < trans_cnt; i++) {
        int pos = -1;
        pos = now.find(from[i]);
        string changed;
        while (pos != -1) {
            changed = now;
            changed.erase(pos, from[i].size());
            changed.insert(pos, to[i]);
            if (dp.find(changed) == dp.end() || dp[changed] > step + 1) {
                dfs(changed, step + 1);
            }
            pos = now.find(from[i], pos + 1);
        }
    }

    return ;
}

int main() {
    cin >> A >> B;    
    while (cin >> from[trans_cnt] >> to[trans_cnt]) trans_cnt++;
    for (int i = 1; i <= 10; i++) {
        ans_k = i;
        dp.clear();
        dfs(A, 0);
        if (ans != MAX_NUM) break;
    }
    if (ans == MAX_NUM) cout << "NO ANSWER!" << endl;
    else cout << ans << endl;
    return 0;
}
