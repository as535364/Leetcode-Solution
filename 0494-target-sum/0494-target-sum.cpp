class Solution {
    int count, target_;
    void dfs(vector<int> &nums, int idx, int sum) {
        if (idx == nums.size() && sum == target_) count++;
        if (idx == nums.size()) return;
        dfs(nums, idx + 1, sum + nums[idx]);
        dfs(nums, idx + 1, sum - nums[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0, target_ = target;
        dfs(nums, 0, 0);
        return count;
    }
};