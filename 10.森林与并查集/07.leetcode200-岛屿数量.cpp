class UnionSet {
public:
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int find(int x) {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }
    void merge(int a, int b) {
        if (find(a) == find(b)) return ;
        fa[find(a)] = find(b);
        return ;
    }
    vector<int> fa;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        UnionSet u(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ind = i * m + j + 1;
                if (grid[i][j] == '0') {
                    u.merge(ind, 0);
                    continue;
                }
                if (i + 1 < n && grid[i + 1][j] == '1') u.merge(ind, ind + m);
                if (j + 1 < m && grid[i][j + 1] == '1') u.merge(ind, ind + 1);

            }
        }
        unordered_set<int> s;
        for (int i = 0, I = n * m; i <= I ; i++) {
            if (s.find(u.find(i)) != s.end()) continue;
            s.insert(u.find(i));
        }
        return s.size() - 1;
    }
};
