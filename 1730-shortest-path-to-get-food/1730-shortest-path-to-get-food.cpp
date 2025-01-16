class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    bool isValid(const vector<vector<char>>& grid, int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n && grid[x][y] != 'X';
    }
public:
    int getFood(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    q.push({i, j});
                }
            }
        }

        int level = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (int dirI = 0; dirI < 4; ++dirI) {
                    int nx = x + dir[dirI][0], ny = y + dir[dirI][1];
                    if (isValid(grid, nx, ny)) {
                        if (grid[nx][ny] == '#') return level;
                        grid[nx][ny] = 'X';
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};