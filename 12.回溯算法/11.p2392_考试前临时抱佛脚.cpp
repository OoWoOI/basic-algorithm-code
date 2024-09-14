/*************************************************************************
	> File Name: 11.p2392_考试前临时抱佛脚.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Sep 2024 09:55:25 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 20
int s1[MAX_N + 5], s2[MAX_N + 5], s3[MAX_N + 5], s4[MAX_N + 5];
int a, b, c, d;

int dfs(int *arr, int l, int r, int sum) {
    if (l > r) return 0;
    if (l == r) return arr[l] - sum;
    return dfs(arr, l + 1, r - 1, arr[r] - arr[l]) + arr[r];
}


int main() {
    cin >> a >> b >> c >> d;
    
    for (int i = 0; i < a; i++) cin >> s1[i];
    for (int i = 0; i < b; i++) cin >> s2[i];
    for (int i = 0; i < c; i++) cin >> s3[i];
    for (int i = 0; i < d; i++) cin >> s4[i];

    sort(s1, s1 + a);
    sort(s2, s2 + b);
    sort(s3, s3 + c);
    sort(s4, s4 + d);

    int ans = dfs(s1, 0, a - 1, 0) + dfs(s2, 0, b - 1, 0) + dfs(s3, 0, c - 1, 0) + dfs(s4, 0, d - 1, 0);
    cout << ans << endl;
    return 0;
}
