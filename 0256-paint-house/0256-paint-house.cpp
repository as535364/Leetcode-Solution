class Solution {
private:
    const int inf = INT_MAX >> 1;
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, inf));
        dp[0] = costs[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};