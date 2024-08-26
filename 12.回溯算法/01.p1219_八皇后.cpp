/*************************************************************************
	> File Name: 01.p1219_八皇后.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Aug 2024 05:30:24 PM CST
 ************************************************************************/

#include<iostream>
#include<unordered_map>

using namespace std;

#define MASK(n) ((1<<(n + 1)) - 2)
unordered_map<int, int> ind;
int arr[20] = {0};
int total_ans;
void print_one_ret(int n) {
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    total_ans -= 1;
    return ;
}

int dfs(int i, int t1, int t2, int t3, int n) {
    if (i > n) {
        if (total_ans) print_one_ret(n);
        return 1;
    }
    int ans = 0;
    for (int t = t1; t; t -= (-t & t)) {
        int j = ind[-t & t];
        if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n)))) {
            arr[i] = j;
            ans += dfs(
                i + 1, //第 i + 1 行
                t1 ^ (1 << j),//标记第j列被使用
                t2 ^ (1 << (i + j - 1)),//标记第i + j - 1斜线上被使用
                t3 ^ (1 << (i - j + n)),//标记第i - j + n反斜线被使用
                n//表示n行
               );
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    total_ans = 3;
    for (int i = 0; i < 2 * n; i++) ind[1 << i] = i;
    int ans = dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1), n);
    cout << ans << endl;
    return 0;
}
