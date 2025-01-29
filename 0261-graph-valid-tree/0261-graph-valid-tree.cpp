class Solution {
private:
    int dfs(vector<vector<int>>& graph, vector<bool>& vis, int x) {
        int cnt = 1;
        for (int neighbor : graph[x]) {
            if (vis[neighbor]) continue;
            vis[neighbor] = true;
            cnt += dfs(graph, vis, neighbor);
        }
        return cnt;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n);
        for (const auto &e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n);
        vis[0] = true;
        return dfs(graph, vis, 0) == n;
    }
};