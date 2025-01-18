class Solution {
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n, MAXCOST = 1e6;
    bool isValid(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> costs(m, vector<int>(n, MAXCOST));
        deque<pair<int, int>> dq;

        costs[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                int cost = (i + 1) != grid[x][y];

                if (!isValid(nx, ny))continue;

                if (costs[x][y] + cost < costs[nx][ny]) {
                    costs[nx][ny] = costs[x][y] + cost;
                    if (cost) dq.push_back({nx, ny});
                    else dq.push_front({nx, ny});
                }
            }
        }
        return costs[m - 1][n - 1];
    }
};