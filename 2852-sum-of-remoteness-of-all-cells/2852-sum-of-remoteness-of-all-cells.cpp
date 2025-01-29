class Solution {
private:
    int m, n;
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool isValid(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }
    vector<vector<bool>> vis;
    pair<long long, int> dfs(int r, int c, vector<vector<int>>& grid) {
        long long sum = grid[r][c];
        int count = 1;
        for (auto &d : dir) {
            int nr = r + d[0], nc = c + d[1];
            if (!isValid(nr, nc) || grid[nr][nc] == -1) continue;
            if (!vis[nr][nc]) {
                vis[nr][nc] = true;
                auto [s, c] = dfs(nr, nc, grid);
                sum += s;
                count += c;
            }
        }
        return {sum, count};
    }
public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n));
        long long res = 0, sum = 0;

        for (const auto& row : grid) {
            for (int val : row) {
                if (val != -1) sum += val;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != -1 && !vis[i][j]) {
                    vis[i][j] = true;
                    auto [componentSum, componentCount] = dfs(i, j, grid);
                    res += (sum - componentSum) * componentCount;
                }
            }
        }
        return res;
    }
};