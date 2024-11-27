class Solution {
private:
    int cal(int n, const vector<vector<int>> &graph) {
        vector<int> dp(n, INT_MAX - 5);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (const int neighbor : graph[i]) {
                dp[i] = min(dp[i], dp[neighbor] + 1);
            }
        }
        return dp[0];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            graph[u].push_back(v);
            ans[i] = cal(n , graph);
        }
        return ans;
    }
};