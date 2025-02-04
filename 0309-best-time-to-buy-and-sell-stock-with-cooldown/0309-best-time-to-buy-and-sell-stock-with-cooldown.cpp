class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(2, -5000005));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = -prices[i];
            for (int j = 0; j < i - 1; ++j) {
                dp[i][0] = max(dp[i][0], dp[j][1] - prices[i]); // buy
                dp[i][1] = max(dp[i][1], dp[j][0] + prices[i]); // sell
            }
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + prices[i]);
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
    // dp[i][0] means buy at day i
    // dp[i][0] = max(dp[j][1]) - prices[i] for all 0 <= j < i - 1
    // dp[i][1] means sell at day i
    // dp[i][1] = max(dp[j][0]) + prices[i] for all 0 <= j < i
};