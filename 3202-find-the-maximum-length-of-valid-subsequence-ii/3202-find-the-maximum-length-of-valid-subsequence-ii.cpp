class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector<vector<int>> dp(k , vector<int>(k));
        for (int num: nums) {
            for (int i = 0; i < k; ++i) {
                int r = num % k;
                dp[r][i] = dp[i][r] + 1;
                ans = max(ans, dp[r][i]);
            }
        }
        return ans;
    }
};