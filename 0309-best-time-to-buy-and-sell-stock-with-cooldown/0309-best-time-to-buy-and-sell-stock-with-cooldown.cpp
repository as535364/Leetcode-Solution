class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2));
        for (int i = n - 1; i >= 0; --i) {
            for (int holding = 0; holding < 2; ++holding) {
                dp[i][holding] = dp[i + 1][holding]; // skip
                if (holding) { // sell
                    dp[i][holding] = max(dp[i][holding], prices[i] + dp[i + 2][0]);
                }
                else { // buy
                    dp[i][holding] = max(dp[i][holding], -prices[i] + dp[i + 1][1]);
                }
            }
        }
        return dp[0][0];
    }
};