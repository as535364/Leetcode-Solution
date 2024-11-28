class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

    bool isValid(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }

    int dijkstra(int src, int dst, const vector<vector<pair<int, int>>> &graph) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> vis;

        vis.insert(src);
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (node == dst) return dis;

            for (auto [w, v] : graph[node]) {
                if (vis.find(v) != vis.end()) continue;
                vis.insert(v);
                pq.push({dis + w, v});
                // int row = node / n, col = node % n;
                // int newRow = v / n, newCol = v % n;
                // cout << "from: " << row << ' ' << col << " to " << newRow << ' ' << newCol << endl;
            }
        }
        return -1;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int>>> graph(m * n);

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int node = r * n + c;
                for (auto dir : dirs) {
                    int newRow = r + dir[0], newCol = c + dir[1];
                    if (!isValid(newRow, newCol)) continue;

                    int neighborNode = newRow * n + newCol;
                    graph[node].push_back({grid[newRow][newCol], neighborNode});
                }
            }
        }
        return dijkstra(0, m * n - 1, graph);
    }
};