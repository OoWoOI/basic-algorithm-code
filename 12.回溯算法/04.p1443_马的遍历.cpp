/*************************************************************************
	> File Name: 04.p1443_马的遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Aug 2024 01:33:13 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

#define MAX_N 400
int n, m;
int dis[MAX_N + 5][MAX_N + 5];
int dir[8][2] = {
    {2, 1}, {-2, 1}, {-2, -1}, {2, -1},
    {1, 2}, {1, -2}, {-1, -2}, {-1, 2}
};

/**
void dfs(int x, int y, int step) {
    if (dis[x][y] != -1 && dis[x][y] <= step) {
        return ;
    }

    dis[x][y] = step;

    for (int i = 0; i < 8; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (dx < 1 || dx > n) continue;
        if (dy < 1 || dy > m) continue;
        dfs(dx, dy, step + 1);
    }
    
    return ;
}

**/
struct Node {
    Node(int x, int y, int s) : x(x), y(y), s(s) {} 
    int x, y, s;
};


void bfs(int x, int y) {
    queue<Node> q;
    q.push(Node(x, y, 0));
    dis[x][y] = 0;
    while (!q.empty()) {
        Node now = q.front();    
        q.pop();
        for (int i = 0; i < 8; i++) {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if (dx < 1 || dx > n) continue;
            if (dy < 1 || dy > m) continue;
            if (dis[dx][dy] != -1) continue;
            dis[dx][dy] = now.s + 1;
            q.push(Node(dx, dy, now.s + 1));
        }
    }
    return ;
}


int main() {
    int x, y;
    cin >> n >> m >> x >> y;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dis[i][j] = -1;
        }
    }
    
    // dfs(x, y, 0);
    bfs(x, y);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            printf("%d", dis[i][j]);
        }
        printf("\n");
    }

    return 0;
}
