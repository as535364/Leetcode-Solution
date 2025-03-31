class Solution {
private:
    const long long inf = 1LL << 61;
    const int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> graph(n);
        for (const auto &road : roads) {
            int u = road[0], v = road[1], t = road[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        vector<long long> ways(n, 0), dis(n, inf);
        using timeNode = pair<long long, int>;
        priority_queue<timeNode, vector<timeNode>, greater<timeNode>> pq;
        pq.push({0, 0});
        ways[0] = 1;
        dis[0] = 0;

        while (!pq.empty()) {
            auto [time, currNode] = pq.top();
            pq.pop();
            for (const auto [neighbor, t] : graph[currNode]) {
                if (time + t > dis[neighbor]) continue;
                else if (time + t < dis[neighbor]) {
                    dis[neighbor] = time + t;
                    ways[neighbor] = ways[currNode];
                    pq.push({dis[neighbor], neighbor});
                }
                else {
                    ways[neighbor] += ways[currNode];
                    ways[neighbor] %= mod;
                }
            }
        }
        return ways[n - 1];
    }
};