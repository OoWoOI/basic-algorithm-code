/*************************************************************************
	> File Name: hzoj245-货仓选址.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Jul 2024 01:36:34 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int p = arr[(n / 2)];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(arr[i] - p);
    }
    cout << ans << endl;

    return 0;
}
