class Solution {
private:
    bool ans;
    const long long inf = 1e15;
    bool isOK(int threshold, vector<long long> costs, vector<vector<pair<int, int>>>& graph, int n, long long k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dis, node] = pq.top(); pq.pop();
            if (node == n - 1) return dis <= k;

            for (const auto [neighbor, weight] : graph[node]) {
                if (weight < threshold) continue;
                if (dis + weight > costs[neighbor]) continue;
                costs[neighbor] = dis + weight;
                pq.push({dis + weight, neighbor});
            }
        }
        return false;
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
            if (isOK(mid, costs, graph, n, k)) {
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