class Solution {
private:
    bool ans;
    const long long inf = 1e15;
    bool isOK(int threshold, vector<vector<pair<int, int>>>& graph, int n, long long k) {
        vector<long long> costs(n, inf);
        
        auto dfs = [&](this auto&& self, int x) -> long long {
            if (x == n - 1) return 0;
            if (costs[x] != inf) return costs[x];

            long long res = inf;
            for (auto [neighbor, weight] : graph[x]) {
                if (weight >= threshold) {
                    res = min(res, weight + self(neighbor));
                }
            }
            return costs[x] = res;
        };
        return dfs(0) <= k;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // 最大最小值 二分搜？
        int n = online.size();
        int left = INT_MAX, right = 0;
        ans = false;
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!online[u] || !online[v]) continue;
            graph[u].push_back({v, w});
            
            left = min(left, w);
            right = max(right, w);
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            vector<long long> costs(n, inf);
            if (isOK(mid, graph, n, k)) {
                left = mid + 1;
                ans = true;
            }
            else {
                right = mid - 1;
            }
        }
        return ans ? right : -1;
    }
    // 1 1 1 1 1 0 0 0
};