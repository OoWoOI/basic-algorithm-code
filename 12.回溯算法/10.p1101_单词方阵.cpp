/*************************************************************************
	> File Name: 10.p1101_单词方阵.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Sep 2024 02:28:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100

int dir[8][2] = {
    {1, 0}, {0, 1}, {1, 1}, {1, -1},
    {-1, 0},{0, -1}, {-1, -1}, {-1, 1}
};//八个方向

int N;
char match[15] = "yizhong";
char g[MAX_N + 5][MAX_N + 5] = {0};
int ans[MAX_N + 5][MAX_N + 5] = {0}, vis[MAX_N + 5][MAX_N + 5] = {0};

void get_ans(int x, int y) {
    
    for (int i = 0; i < 8; i++) {
        int flag = 1;
        for (int step = 0; match[step]; step++) {
            int dx = dir[i][0] * step + x;
            int dy = dir[i][1] * step + y;
            if (g[dx][dy] == match[step]) continue;
            flag = 0;
            break;
        }

        if (flag) {
            //染色
            for (int step = 0; match[step]; step++) {
                int dx = dir[i][0] * step + x;
                int dy = dir[i][1] * step + y;
                ans[dx][dy] = 1;//标记
            }
        }
    }
    
    return ;
}

void dfs(int x, int y) {
    if (g[x][y] == '\0') return ;
    if (g[x][y] == 'y') {
        get_ans(x, y);//字符串起始位置
    }
    if (vis[x][y]) return ;//访问过
    vis[x][y] = 1;
    dfs(x + 1, y);
    dfs(x, y + 1);
    return ;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> (g[i] + 1);
    }
    dfs(1, 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (ans[i][j] == 0) cout << "*";
            else cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}
