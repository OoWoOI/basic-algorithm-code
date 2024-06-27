/*************************************************************************
	> File Name: 03.hzoj235-递归实现指数型枚举.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Jun 2024 11:25:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10
int f[MAX_N + 5], n;

void print(int n) {
    for (int i = 0; i <= n; i++) {
        if (i) cout << " ";
        cout << f[i];
    }
    cout << endl;
    return ;
}

void func(int i, int j, int n) {
    if (j > n) return ;

    for (int k = j; k <= n; k++) {
        f[i] = k;
        print(i);
        func(i + 1, k + 1, n);
    }
    
    return ;
}

int main() {
    
    cin >> n;
    func(0, 1, n);
    
    return 0;
}
