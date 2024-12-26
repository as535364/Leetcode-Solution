class Solution {
    const int maxn = 1000;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(maxn + maxn + 1));

        dp[0][nums[0] + maxn] += 1;
        dp[0][-nums[0] + maxn] += 1;

        for (int i = 1; i < n; ++i) {
            for (int j = -maxn; j <= maxn; ++j) {
                if (j - nums[i] >= -maxn)
                    dp[i][j + maxn] += dp[(i - 1)][(j - nums[i]) + maxn];
                if (j + nums[i] < maxn + 1)
                    dp[i][j + maxn] += dp[(i - 1)][(j + nums[i]) + maxn];
            }
        }
        return dp[(n - 1)][target + maxn];
    }
};