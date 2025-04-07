class Solution {
private:
    bool isPartitionable = false;
    // void dfs(const vector<int>& nums, int leftRemain, int rightRemain, int idx) {
    //     if (idx == nums.size()) {
    //         if (rightRemain == 0 && leftRemain == 0) isPartitionable = true;
    //         return;
    //     }
    //     dfs(nums, leftRemain - nums[idx], rightRemain, idx + 1);
    //     dfs(nums, leftRemain, rightRemain - nums[idx], idx + 1);
    // }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2, n = nums.size();
        vector<int> dp(target + 1);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= 0; --j) {
                if (j >= nums[i]) dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};