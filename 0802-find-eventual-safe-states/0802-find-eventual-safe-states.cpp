class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> reverseAdj(n);
        vector<int> deg(n);
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                int u = i, v = graph[i][j];
                reverseAdj[v].push_back(u);
                deg[u]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) q.push(i);
        }

        vector<bool> isSafe(n);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            isSafe[now] = true;
            for (int neighbor : reverseAdj[now]) {
                if(--deg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (isSafe[i]) res.push_back(i);
        }
        return res;
    }
};