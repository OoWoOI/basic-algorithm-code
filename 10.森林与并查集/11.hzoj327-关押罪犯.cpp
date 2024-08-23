/*************************************************************************
	> File Name: 11.hzoj327-关押罪犯.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Aug 2024 11:28:08 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct Data {
    int a, b, c;
};

class UnionSet {
public :
    UnionSet(int n) : fa(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }

    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        return fa[x] = root;
    }

    void merge(int a, int b, int t) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        val[aa] = (t - val[a] + val[b] + 2) % 2;
        fa[aa] = bb;
        return ;
    }
    
    vector<int> fa, val;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Data> arr(m);
    for (int i = 0; i < m; i++) {
        Data &x = arr[i]; 
        scanf("%d%d%d", &x.a, &x.b, &x.c);
    }

    sort(arr.begin(), arr.end(), [&](const Data a, const Data b)->bool {
        return a.c > b.c;
    });

    UnionSet u(n);
    int flag = 1, ans = 0;
    for (int i = 0; i < m; i++) {
        int a = arr[i].a, b = arr[i].b, c = arr[i].c;
        if (u.get(a) == u.get(b)) {
            if ((u.val[a] + u.val[b]) % 2 == 0) {
                flag = 0;
                ans = c;
                break;
            }
        } else {
            u.merge(a, b, 1);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
