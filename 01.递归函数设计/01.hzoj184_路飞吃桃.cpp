/*************************************************************************
	> File Name: 01.hzoj184_路飞吃桃.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Jun 2024 03:30:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int func(int n) {
    if (n == 1) return 1;
    return 2 * (func(n - 1) + 1);
}

int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}
