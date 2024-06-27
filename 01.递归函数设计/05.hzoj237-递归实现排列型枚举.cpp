/*************************************************************************
	> File Name: 05.hzoj237-递归实现排列型枚举.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Jun 2024 12:15:38 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10
int f[MAX_N + 5], vis[MAX_N + 5] = {0}, N;

void print() {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << f[i];
    }
    cout << endl;
    return ;
}

void func(int i, int n) {
    
    if (i == n) {
        print();//满足输出条件
        return ;
    }

    for (int k = 1; k <= n; k++) {
        if (vis[k]) continue;
        f[i] = k;
        vis[k] = 1;
        func(i + 1, n);
        vis[k] = 0;
    }
    
    return ;
}


int main() {
    
    cin >> N;

    func(0, N);
    
    return 0;
}
