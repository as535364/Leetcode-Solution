class Solution {
    int bfs(int n, const vector<vector<int>> &graph) {
        queue<int> q;
        unordered_set<int> vis;
        int ans = 0;

        q.push(0);
        vis.insert(0);
        
        while (!q.empty()) {
            int layerSize = q.size();
            for (int i = 0; i < layerSize; ++i) {
                int node = q.front();
                q.pop();
                if (node == n - 1) return ans;
                for (int neighbor : graph[node]) {
                    if (vis.count(neighbor)) continue;
                    vis.insert(neighbor);
                    q.push(neighbor);
                }
            }
            ans++;
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