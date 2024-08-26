/*************************************************************************
	> File Name: 07.hzoj264_最大矩形面积.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Aug 2024 11:17:58 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main() {
    long long n;
    cin >> n;
    vector<long long> b;
    b.push_back(-1);
    for (long long i = 0, a; i < n; i++) {
        cin >> a;
        b.push_back(a);
    }
    b.push_back(-1);
    //单调栈
    stack<long long> s;
    vector<long long> l(n + 2), r(n + 2);
    
    for (long long i = 1; i <= n + 1; i++) {
        while (!s.empty() && b[s.top()] > b[i]) {
            r[s.top()] = i; 
            s.pop();
        }
        s.push(i);
    } 
    
    while (!s.empty()) s.pop();

    for (long long i = n; i >= 0; i--) {
        while (!s.empty() && b[s.top()] > b[i]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    long long ans = 0;

    for (long long i = 1; i <= n; i++) {
        long long height = b[i], width = (r[i] - l[i] - 1);
        ans = max(height * width, ans);
    }
    cout << ans << endl;

    return 0;
}
