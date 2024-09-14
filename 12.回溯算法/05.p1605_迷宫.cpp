/*************************************************************************
	> File Name: 05.p1605_迷宫.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Aug 2024 02:35:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#define MAX_N 25

int n, m, t, ans = 0;

int dir[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int dis[MAX_N + 5][MAX_N + 5];
int sx, sy, fx, fy;//起始和终点


void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans += 1;
        return ;//找到一组方案
    }
    dis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (dx < 1 || dx > n) continue;
        if (dy < 1 || dy > m) continue;
        if (dis[dx][dy] == 1) continue;
        dfs(dx, dy);
    }
    dis[x][y] = 0;
    return ;
}

int main() {
    
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dis[i][j] = 0;//可以通过
        }
    }
    
    cin >> sx >> sy >> fx >> fy;//输入起始、重点位置

    //障碍物
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        dis[x][y] = 1;//不可以通过
    }

    dfs(sx, sy);//每个方格只能经过一次

    cout << ans << endl;
    
    return 0;
}
