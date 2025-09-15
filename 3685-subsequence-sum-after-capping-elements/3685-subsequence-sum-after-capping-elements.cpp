class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> ans(n);
        vector<bool> dp(k + 1);
        dp[0] = true;

        sort(nums.begin(), nums.end());
        // 2 3 4 4
        int i = 0;
        for (int x = 1; x <= n; ++x) {
            while (i < n && nums[i] == x) {
                for (int j = k; j >= nums[i]; --j) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
                i++;
            }

            for (int j = 0; j <= min(n - i, k / x); ++j) {
                if (dp[k - j * x]) {
                    ans[x - 1] = true;
                    break;
                }
            }
        }
        return ans;
    }
};