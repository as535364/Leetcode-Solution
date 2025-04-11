class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        vector<int> dp(max(4, n + 1));
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
            for (int j = i - 3; j >= 0; --j) {
                dp[i] = (dp[i] + 2 * dp[j] % mod) % mod;
            }
        }
        return dp[n];
    }
};