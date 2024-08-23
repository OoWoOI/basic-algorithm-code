/*************************************************************************
	> File Name: 01.monotonic_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Aug 2024 02:25:41 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

//TODO : 单调队列代码演示


void output(vector<int> &arr) {
    int len = 0;
    for (auto x : arr) {
        len += printf("%3d", x);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");

    return ;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    output(arr);

    //单调队列操作
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        while (!q.empty() && x < arr[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        printf("[%d, %d] = arr[%d] = %d\n", 
            max(i - k + 1, 0), i,
            q.front(), arr[q.front()]
        );
    }
    return 0;
}
