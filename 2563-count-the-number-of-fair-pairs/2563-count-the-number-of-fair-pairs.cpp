class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long fairPairs = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            auto leftBound = next(nums.begin(), i + 1);
            int right = upper_bound(leftBound, nums.end(), upper - nums[i]) - nums.begin();
            int left = lower_bound(leftBound, nums.end(), lower - nums[i]) - nums.begin();
            fairPairs += max(0, right - left);
        }
        return fairPairs;
    }
};