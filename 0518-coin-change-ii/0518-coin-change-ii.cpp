class Solution {
private:
    vector<vector<int>> dp;
    int waysToAmount(int idx, int amount, const vector<int>& coins) {
        if (amount == 0) return 1;
        if (idx == coins.size()) return 0;
        if (dp[idx][amount] != -1) return dp[idx][amount];

        if (coins[idx] > amount) {
            dp[idx][amount] = waysToAmount(idx + 1, amount, coins);
        }
        else {
            dp[idx][amount] = waysToAmount(idx + 1, amount, coins) + 
                            waysToAmount(idx, amount - coins[idx], coins);
        }
        return dp[idx][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        // dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -1));
        vector<vector<unsigned long long>> dp(coins.size() + 1, vector<unsigned long long>(amount + 1));
        int n = coins.size();

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                int coin = coins[i - 1];
                if (coin > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coin];
                }
            }
        }
        return dp[n][amount];
    }
};