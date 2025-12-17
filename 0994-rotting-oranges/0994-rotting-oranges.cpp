class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh_orange_count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh_orange_count;
            }
        }

        int time = 0;
        while (fresh_orange_count > 0 && !q.empty()) {
            int level_size = q.size();
            ++time;
            for (int i = 0; i < level_size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                    grid[nr][nc] = 2;
                    --fresh_orange_count;
                    q.push({nr, nc});
                }
            }
        }
        return fresh_orange_count == 0 ? time : -1;
    }
};