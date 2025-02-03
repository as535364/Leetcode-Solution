class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int decrease = 1, increase = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[j - 1]) increase++;
                else break;
            }
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[j - 1]) decrease++;
                else break;
            }
            res = max(res, max(decrease, increase));
        }
        return res;
    }
};