/*************************************************************************
	> File Name: 01.hzoj-505.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Sep 2024 08:30:46 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



int main() {
    vector<string> arr;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), [&](const string a, const string b) {
        return a + b > b + a;
    });
    
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
