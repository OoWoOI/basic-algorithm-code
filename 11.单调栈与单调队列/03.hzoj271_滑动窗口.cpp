/*************************************************************************
	> File Name: 03.hzoj271_滑动窗口.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Aug 2024 04:03:12 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    //极小值
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] > arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - q.front() == k) {
            q.pop_front();
        }
        if (i >= k - 1) ans.push_back(q.front());
    }
    
    for (int i = 0, I = ans.size(); i < I; i++) {
        if (i) cout << " ";
        cout << arr[ans[i]];
    }
    cout << endl;

    q.clear();
    ans.clear();

    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] < arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - q.front() == k) {
            q.pop_front();
        }
        if (i >= k - 1) ans.push_back(q.front());
    }
    
    for (int i = 0, I = ans.size(); i < I; i++) {
        if (i) cout << " ";
        cout << arr[ans[i]];
    }
    cout << endl;


    return 0;
}
