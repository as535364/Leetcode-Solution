class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = INT_MIN, n = nums.size();
        for (int i = 0; i < n; ++i) {
            res = max(res, abs(nums[i] - nums[(i + 1) % n]));
        }
        return res;
    }
};