class Solution {
    int m, n;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        grid[r][c] = 0;
        int communicateCount = 0;
        for (int i = 0; i < n; ++i) {
            if (grid[r][i]) {
                communicateCount += dfs(grid, r, i);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (grid[i][c]) {
                communicateCount += dfs(grid, i, c);
            }
        }
        return communicateCount + 1;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) continue;
                int count = dfs(grid, i, j);
                if (count > 1) res += count;
            }
        }
        return res;
    }
};