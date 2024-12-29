class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));

        dp[0][0] = nums[0];
        dp[0][1] = nums[0] * nums[0];
        int ans = max(dp[0][0], dp[0][1]);

        for (int i = 1; i < n; ++i) {
            // ending with nums[i] without operation on index i
            dp[i][0] = max(
                dp[i-1][0] + nums[i],
                nums[i]
            );
            // ending with nums[i] with operation used before or on index i
            dp[i][1] = max(
                max(dp[i-1][0] + nums[i] * nums[i], 
                    dp[i-1][1] + nums[i]), 
                nums[i] * nums[i]
            );

            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};