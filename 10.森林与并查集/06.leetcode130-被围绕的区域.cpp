class Solution {
public:
    class UnionSet {
    public :
        UnionSet(int n) : fa(n + 1)  {
            for (int i = 0; i <= n; i++) {
                fa[i] = i;
            }
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
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        UnionSet u(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ind = i * n + j + 1;
                if (board[i][j] != 'O') continue;
                if (i == 0 || i == m - 1) u.merge(ind, 0);
                if (j == 0 || j == n - 1) u.merge(ind, 0);
                if (i + 1 < m && board[i + 1][j] == 'O') u.merge(ind, ind + n);
                if (j + 1 < n && board[i][j + 1] == 'O') u.merge(ind, ind + 1);
            }
        }

        //update
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] != 'O') continue;
                int ind = i * n + j + 1;
                if (u.find(ind) == u.find(0)) continue;
                board[i][j] = 'X';
            }
        }

        return ;
    }
};
