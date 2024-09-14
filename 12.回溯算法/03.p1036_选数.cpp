/*************************************************************************
	> File Name: 03.p1036_选树.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Aug 2024 12:46:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 20
int val[MAX_N + 5];
long long ans = 0;

int is_primer(int x) {
    
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    
    return 1;
}

void dfs(int num, int ind, int k, int n, int sum) {
    if (num == k) {
        if (is_primer(sum)) ans += 1;
        return ;
    }
    
    for (int i = ind; i <= n; i++) {
        //select i
        dfs(num + 1, i + 1, k, n, sum + val[i]);
    }

    return ;
}


int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> val[i];
    dfs(0, 1, k, n, 0);
    cout << ans << endl;
    return 0;
}
