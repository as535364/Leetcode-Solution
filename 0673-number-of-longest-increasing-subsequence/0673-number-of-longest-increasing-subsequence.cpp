class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1}); // dp[i] means ends at i, (length, count)

        int maxLen = 0, maxLenCnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] <= nums[j]) continue;
                if (dp[j].first + 1 > dp[i].first) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = dp[j].second;
                }
                else if (dp[j].first + 1 == dp[i].first) {
                    dp[i].second += dp[j].second;
                }
            }

            if (maxLen < dp[i].first) {
                maxLen = dp[i].first;
                maxLenCnt = dp[i].second;
            }
            else if (maxLen == dp[i].first) {
                maxLenCnt += dp[i].second;
            }
        }
        return maxLenCnt;
    }
};