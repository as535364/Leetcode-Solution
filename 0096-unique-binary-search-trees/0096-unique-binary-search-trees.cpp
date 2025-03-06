class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = 2LL * (2 * (i - 1) + 1) * dp[i - 1] / (i + 1);
        }
        return dp[n];
    }
};