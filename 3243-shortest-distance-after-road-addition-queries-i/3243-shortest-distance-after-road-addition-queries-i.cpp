class Solution {
    int bfs(int n, const vector<vector<int>> &graph) {
        int ansDis = INT_MAX;
        queue<pair<int, int>> q;
        unordered_set<int> vis;

        q.push({0, 0});
        vis.insert(0);
        while (!q.empty()) {
            auto [dis, node] = q.front();
            q.pop();
            if (node == n - 1) return dis;
            for (int neighbor : graph[node]) {
                if (vis.count(neighbor)) continue;
                vis.insert(neighbor);
                q.push({dis + 1, neighbor});
            }
        }
        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0 ; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }
        
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            graph[u].push_back(v);
            ans[i] = bfs(n, graph);
        }
        return ans;
    }
};