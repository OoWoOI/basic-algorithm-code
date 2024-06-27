/*************************************************************************
	> File Name: 04.hzoj236-递归实现排列型枚举.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Jun 2024 11:42:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10
int f[MAX_N + 5], n, m;

void print() {
    for (int i = 0; i < m; i++) {
        if (i) cout << " ";
        cout << f[i];
    }
    cout << endl;
    return ;
}

void func(int i, int j, int n) {
    
    if (i == m) {
        print();
        return ;
    }

    for (int k = j; k <= n && m - i - 1 <= n - k; k++) {
        f[i] = k;
        func(i + 1, k + 1, n);
    }
    
    return ;
}


int main() {
    
    cin >> n >> m;

    func(0, 1, n);
    
    return 0;
}
