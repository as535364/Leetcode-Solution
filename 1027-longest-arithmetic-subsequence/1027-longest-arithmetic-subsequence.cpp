class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        int bound = *max_element(begin(nums), end(nums));
        vector<vector<int>> dp(bound + 1, vector<int>(2 * bound + 1)); // nums, diff (-500 ~ 500)

        for (int a : nums) {
            for (int diff = -bound; diff <= bound; ++diff) {
                int beforeA = 0, d = diff + bound;
                if (a - diff >= 0 && a - diff <= bound) {
                    beforeA = dp[a - diff][d];
                }
                dp[a][d] = beforeA + 1;
                ans = max(ans, dp[a][d]);
            }
        }
        return ans;
    }
};