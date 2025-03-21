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
        dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return waysToAmount(0, amount, coins);
    }
};