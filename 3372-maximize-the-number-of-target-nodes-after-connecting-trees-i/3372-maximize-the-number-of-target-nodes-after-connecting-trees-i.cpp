class Solution {
private:
    int targetCnt(int node, int parent, int k, vector<vector<int>>& graph) {
        if (k < 0) return 0;
        int res = 1;
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            res += targetCnt(neighbor, node, k - 1, graph);
        }
        return res;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);

        if (k == 0) return vector<int>(n, 1);

        for (const auto& edge : edges1) {
            int a = edge[0], b = edge[1];
            graph1[a].push_back(b);
            graph1[b].push_back(a);
        }

        for (const auto& edge : edges2) {
            int a = edge[0], b = edge[1];
            graph2[a].push_back(b);
            graph2[b].push_back(a);
        }

        int preCalWithKMax = 0;
        for (int i = 0; i < m; ++i) {
            int preCalI = targetCnt(i, -1, k - 1, graph2);
            preCalWithKMax = max(preCalWithKMax, preCalI);
        }

        vector<int> res(n);
        for(int i = 0; i < n; ++i) {
            res[i] = targetCnt(i, -1, k, graph1) + preCalWithKMax;
        }
        return res;
    }
};