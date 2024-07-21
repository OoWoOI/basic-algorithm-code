/*************************************************************************
	> File Name: 12.hzoj287-合并果子.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Jul 2024 01:13:24 PM CST
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;
typedef pair<int, int> PII;
int main() {
    set<PII> s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        PII p = {a, i};
        s.insert(p);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        ans += (a + b);
        PII p = {a + b, n + i};
        s.insert(p);
    }

    cout << ans << endl;
    return 0;
}
