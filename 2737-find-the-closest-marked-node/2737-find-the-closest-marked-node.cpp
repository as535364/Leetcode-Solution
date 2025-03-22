class Solution {
private:
    const int inf = 1e9;
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<vector<int>> graph(n, vector<int>(n, inf));
        vector<int> dis(n, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (const auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u][v] = min(graph[u][v], w);
        }

        pq.push({0, s});
        dis[s] = 0;
        while (!pq.empty()) {
            auto [nodeDis, node] = pq.top(); pq.pop();
            for (int i = 0; i < n; ++i) {
                if (nodeDis + graph[node][i] < dis[i]) {
                    dis[i] = nodeDis + graph[node][i];
                    pq.push({dis[i], i});
                }
            }
        }

        int res = inf;
        for (int m : marked) {
            res = min(res, dis[m]);
        }
        return res == inf ? -1 : res;
    }
};