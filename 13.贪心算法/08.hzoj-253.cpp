/*************************************************************************
	> File Name: 08.hzoj-253.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 09:05:40 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 2500

int n, m;
struct Node {
    int a, b;
} cow[MAX_N + 5], iterm[MAX_N + 5];

bool cmp(const Node &a, const Node &b) {
    if (a.b != b.b) return a.b < b.b;
    return a.a < b.a;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> cow[i].a >> cow[i].b;
    for (int i = 0; i < m; i++) cin >> iterm[i].b >> iterm[i].a;
    sort(cow, cow + n, cmp);
    sort(iterm, iterm + m, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (iterm[j].a == 0) continue;
            if (iterm[j].b >= cow[i].a && iterm[j].b <= cow[i].b) {
                flag = 1;
                iterm[j].a -= 1;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}
