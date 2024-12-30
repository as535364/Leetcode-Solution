class Solution {
    const int MOD = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int> dp(high + 1);
        dp[0] = 1;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) dp[i] = dp[i - zero];
            if (i >= one) dp[i] += dp[i - one];
            dp[i] %= MOD;
            if (low <= i && i <= high) {
                ans += dp[i];
                ans %= MOD;
            }
        }
        return ans;
    }
};