/*************************************************************************
	> File Name: 10.hzoj372_双生序列.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Aug 2024 01:20:51 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    
    deque<int> ap, bp;

    int p = 0;
    for (p; p < n; p++) {
        while (!ap.empty() &&  a[p] < ap.back()) {
            ap.pop_back();
        }
        while (!bp.empty() && b[p] < bp.back()) {
            bp.pop_back();
        }
        ap.push_back(a[p]);
        bp.push_back(b[p]);
        if (ap.size() != bp.size()) break;

    }

    cout << p << endl;
    
    return 0;
}
