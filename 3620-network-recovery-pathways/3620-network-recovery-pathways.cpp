class Solution {
private:
    const long long inf = 1e15;
    bool isOK(int threshold, vector<vector<pair<int, int>>>& graph, long long k) {
        int n = graph.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> costs(n, inf);

        pq.push({0, 0});
        costs[0] = 0;

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (costs[node] < dis) continue;
            if (node == n - 1) return dis <= k;

            for (const auto [neighbor, weight] : graph[node]) {
                if (threshold > weight) continue;
                if (costs[neighbor] > weight + dis) {
                    pq.push({weight + dis, neighbor});
                    costs[neighbor] = weight + dis;
                }
            }
        }
        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        // graph[u] {{v1, w1}, {v2, w2}}
        int left = INT_MAX, right = 0;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (online[u] && online[v]) {
                graph[u].push_back({v, w});
                left = min(left, w);
                right = max(right, w);
            }
        }

        bool ans = false;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isOK(mid, graph, k)) {
                left = mid + 1;
                ans = true;
            }
            else {
                right = mid - 1;
            }
        }
        return ans ? right : -1;
    }
};
// 1 1 1 1 1 0 0 0 0

// dijkstra O((V+E)logV)
// 限制： >= threshold

// 10: False
// 3: True



// TC: O(log(Diff) * (V+E)logV)
// SC: O(1 + V + V + E)