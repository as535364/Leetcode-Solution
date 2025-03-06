class Solution {
public:
    int numTrees(int n) {
        // long C = 1;
        // for (int i = 2; i <= n; ++i) {
        //     C = 2 * (2 * (i - 1) + 1) * C / (i + 1);
        // }
        // return (int)C;
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};