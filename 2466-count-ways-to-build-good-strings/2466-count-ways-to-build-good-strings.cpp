class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[zero] += 1;
        dp[one] += 1;

        int res = 0;
        for (int i = min(zero, one); i <= high; ++i) {
            if (i >= zero) dp[i] += dp[i - zero];
            if (i >= one) dp[i] += dp[i - one];
            dp[i] %= mod;
            if (low <= i && i <= high) res += dp[i];
            res %= mod;
        }
        return res;
    }
};