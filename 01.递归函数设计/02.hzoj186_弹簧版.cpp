/*************************************************************************
	> File Name: 02.hzoj186_弹簧版.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Jun 2024 03:43:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000

int a[MAX_N + 5], num;

int func(int ind, int cnt) {
    if (ind >= num) return 0; 
    return func(ind + a[ind], num) + 1;
}

int main() {
    
    cin >> num;

    for (int i = 0; i < num; i++) cin >> a[i];
    cout << func(0, num) << endl;
    return 0;
}
