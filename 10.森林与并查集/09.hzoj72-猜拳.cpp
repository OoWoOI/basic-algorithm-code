/*************************************************************************
	> File Name: 09.hzoj72-猜拳.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Aug 2024 06:54:51 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class WeightedUnionSet{
public :
    WeightedUnionSet(int n) : fa(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }   

    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);//获取根节点
        val[x] = (val[x] + val[fa[x]]) % 3;
        return fa[x] = root;
    }

    void merge(int x, int y, int t) {
        int xx = get(x), yy = get(y);
        if (xx == yy) return ;
        val[xx] = (t - val[x] + val[y] + 3) % 3;
        fa[xx] = yy;
        return ;
    }

    vector<int> fa, val;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    WeightedUnionSet u(n);
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            u.merge(b, c, 2);
            continue;
        }
        if (u.get(b) != u.get(c)) {
            printf("Unknown\n");
        } else {
            switch ((u.val[b] - u.val[c] + 3) % 3) {
                case 0: printf("Tie\n");  break;
                case 1: printf("Loss\n"); break;
                case 2: printf("Win\n");  break;
            }
        }
    }
    
    return 0;
}
