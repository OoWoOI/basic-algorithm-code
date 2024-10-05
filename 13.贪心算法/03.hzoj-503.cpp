/*************************************************************************
	> File Name: 03.hzoj-503.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Sep 2024 12:22:40 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int w, n;
vector<int> arr;

int main() {
    cin >> w >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size() - 1;
    int cnt = 0;
    while (l <= r) {
        if (l != r && arr[l] + arr[r] <= w) {
            l++;
            r--;
        } else if (l != r && arr[l] + arr[r] > w) {
            r--;  
        } else {
            l++;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
