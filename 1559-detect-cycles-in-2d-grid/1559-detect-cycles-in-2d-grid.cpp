class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

    bool isValid(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }

    bool dfs(int r, int c, int pr, int pc, 
                vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        bool res = false;
        for (auto &dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (!isValid(nr, nc)) continue;
            if (grid[nr][nc] != grid[r][c]) continue;
            if (nr == pr && nc == pc) continue;
            if (vis[nr][nc]) return true;
            vis[nr][nc] = true;
            res |= dfs(nr, nc, r, c, grid, vis);
        }
        return res;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j]) continue;
                vis[i][j] = true;
                if (dfs(i, j, -1, -1, grid, vis)) return true;
            }
        }
        return false;
    }
};