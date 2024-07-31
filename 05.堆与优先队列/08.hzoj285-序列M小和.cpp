/*************************************************************************
	> File Name: 08.hzoj285-序列M小和.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Jul 2024 02:38:16 PM CST
 ************************************************************************/

#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int main() {
    int n, m, t = 0;
    set<PII> s;
    cin >> n >> m;
    s.insert({0, t++});
    for (int i = 0; i < n; i++) {
        
        vector<int> tmp;
        for (auto x : s) {
            tmp.push_back(x.first);
        }
        s.clear();
        
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            for (auto x : tmp) {
                if (s.size() <  m || x - a > s.begin()->first) {
                    s.insert({x - a, t++});
                }

                if (s.size() > m) {
                    s.erase(s.begin());
                }
            } 
        }
    }
    int flag = 0;
    for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
        if (flag) cout << " ";
        cout << -iter->first;
        flag = 1;
    }
    cout << endl;

    return 0;
}
