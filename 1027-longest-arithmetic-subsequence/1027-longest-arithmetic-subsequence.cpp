class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        int bound = *max_element(begin(nums), end(nums));
        vector<vector<int>> dp(501, vector<int>(1001)); // nums, diff (-500 ~ 500)

        for (int a : nums) {
            for (int diff = -500; diff <= 500; ++diff) {
                int beforeA = 0;
                if (a - diff >= 0 && a - diff <= 500) {
                    beforeA = dp[a - diff][diff + 500];
                }
                dp[a][diff + 500] = beforeA + 1;
                ans = max(ans, dp[a][diff + 500]);
            }
        }
        return ans;
    }
};