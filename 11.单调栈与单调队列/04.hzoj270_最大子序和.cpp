/*************************************************************************
	> File Name: 04.hzoj270_最大自序和.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Aug 2024 04:29:38 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<deque>
#include<cinttypes>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    
    deque<int> q;
    int ans = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q.front()]);
        while (!q.empty() && arr[q.back()] > arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - m == q.front()) q.pop_front();
    }
    cout << ans << endl;
    return 0;
}
