/*************************************************************************
	> File Name: 06.hzoj-255.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Sep 2024 12:29:44 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cinttypes>
#include<cmath>
using namespace std;
#define MAX_N 1000
int n, d;
struct Node {
    double l, r;
};
Node arr[MAX_N + 5];

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        //TODO : calc l, r;
        if (y > d) {
            cout << -1 << endl;
            return 0;
        } else {
            arr[i].l = x - sqrt(d * d - y * y);
            arr[i].r = sqrt(d * d - y * y) + x;
        }
    }
    sort(arr, arr + n, [&](Node a, Node b)->bool {
        if (a.r == b.r) return a.l < b.l;
        return a.r < b.r;
    });
    int cnt = 0;
    double pos = INT32_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i].l <= pos) continue;
        pos = arr[i].r;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
