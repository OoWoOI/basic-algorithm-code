class UnionSet {
public :
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionSet u(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 0) continue;
                u.merge(i, j);
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (s.find(u.find(i)) != s.end()) continue;
            s.insert(u.find(i)); 
        }
        return s.size();
    }
};
