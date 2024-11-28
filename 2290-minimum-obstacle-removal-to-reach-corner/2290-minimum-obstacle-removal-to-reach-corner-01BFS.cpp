class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

    bool isValid(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }

    int BFS01(int srcR, int srcC, int dstR, int dstC, const vector<vector<int>> &grid) {
        deque<tuple<int, int, int>> dq;
        vector<vector<bool>> vis(m, vector<bool>(n));

        vis[srcR][srcC] = true;
        dq.push_front({0, srcR, srcC});

        while (!dq.empty()) {
            auto [dis, row, col] = dq.front();
            dq.pop_front();

            if (row == dstR && col == dstC) return dis;

            for (const auto &dir : dirs) {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (!isValid(newRow, newCol) || vis[newRow][newCol]) continue;
                vis[newRow][newCol] = true;

                if (grid[newRow][newCol])
                    dq.push_back({dis + 1, newRow, newCol});
                else 
                    dq.push_front({dis, newRow, newCol});
                
            }
        }
        return -1;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        return BFS01(0, 0, m - 1, n - 1, grid);
    }
};