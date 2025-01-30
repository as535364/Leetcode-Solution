class Solution {
private:
    int maxGroupComponent(int root, int id, vector<int>& groupId, int n, vector<vector<int>>& graph) {
        vector<int> color(n + 1, -1);
        queue<int> q;
        int level = 0;

        q.push(root);
        color[root] = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int node = q.front(); q.pop();
                groupId[node] = id;
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == color[node]) return -1;
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                }
            }
            level++;
        }
        return level;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        vector<int> color(n + 1, -1);

        for (const auto &e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int res = 0, id = 1;
        unordered_map<int, int> groupMax;
        vector<int> groupId(n + 1, -1);

        for (int i = 1; i <= n; ++i) {
            if (color[i] != -1) continue;
            int nodeGroupId = (groupId[i] == -1 ? id++ : groupId[i]);
            int groupSize = maxGroupComponent(i, nodeGroupId, groupId, n, graph);
            groupMax[nodeGroupId] = max(groupMax[nodeGroupId], groupSize);
            if (groupSize == -1) return -1;
        }

        for (const auto [_, size] : groupMax) {
            res += size;
        }
        return res;
    }
};