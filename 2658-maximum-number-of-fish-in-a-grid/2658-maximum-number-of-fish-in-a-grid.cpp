class Solution {
private:
    int dir[4][2]= {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int sum = grid[r][c];
        grid[r][c] = 0;
        for (auto &d : dir) {
            int nr = r + d[0], nc = c + d[1];
            if (0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] > 0) {
                sum += dfs(grid, nr, nc);
            }
        }
        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};