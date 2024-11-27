class Solution {
private:
    vector<int> dp;
    int cal(int n, int idx, const vector<vector<int>> &graph) {
        for (int i = idx; i >= 0; --i) {
            for (const int neighbor : graph[i]) {
                dp[i] = min(dp[i], dp[neighbor] + 1);
            }
        }
        return dp[0];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        dp.resize(n, INT_MAX - 5);
        dp[n - 1] = 0;

        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }

        vector<int> ans(queries.size());
        cal(n, n - 2, graph);
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            graph[u].push_back(v);
            ans[i] = cal(n, u , graph);
        }
        return ans;
    }
};