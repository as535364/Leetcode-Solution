class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

    bool isValid(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }

    int dijkstra(int srcR, int srcC, int dstR, int dstC, const vector<vector<int>> &grid) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n));

        vis[srcR][srcC] = true;
        pq.push({0, srcR, srcC});

        while (!pq.empty()) {
            auto [dis, row, col] = pq.top();
            pq.pop();

            if (row == dstR && col == dstC) return dis;

            for (const auto &dir : dirs) {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (!isValid(newRow, newCol) || vis[newRow][newCol]) continue;
                vis[newRow][newCol] = true;
                pq.push({dis + grid[newRow][newCol], newRow, newCol});
            }
        }
        return -1;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        return dijkstra(0, 0, m - 1, n - 1, grid);
    }
};