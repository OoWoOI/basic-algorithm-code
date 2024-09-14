/*************************************************************************
	> File Name: 09.p2404_自然数拆分问题.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Sep 2024 01:57:19 PM CST
 ************************************************************************/

#include<iostream>

using namespace std;
int num;
int ans[20] = {0};

void print_one_ret(int n) {
    if (n < 2) return ;
    for (int i = 0; i < n; i++) {
        if (i) printf("+");
        printf("%d", ans[i]);
    }
    printf("\n");
    return ;
}

void dfs(int k, int s_sum, int n) {
    if (n == 0) {
        print_one_ret(k);
        return ;
    }
    if (s_sum > num) return ;
    for (int i = s_sum; i <= n; i++) {
        ans[k] = i;
        dfs(k + 1, i, n - i);
    }
    return ;
}

int main() {
    cin >> num;  
    dfs(0, 1, num);
    return 0;
}
