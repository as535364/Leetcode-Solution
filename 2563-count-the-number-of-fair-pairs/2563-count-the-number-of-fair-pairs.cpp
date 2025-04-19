class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long fairPairs = 0;
        int n = nums.size();
        
        auto leftBound = nums.begin();
        for (int i = 0; i < n; ++i) {
            ++leftBound;
            int right = upper_bound(leftBound, nums.end(), upper - nums[i]) - nums.begin();
            int left = lower_bound(leftBound, nums.end(), lower - nums[i]) - nums.begin();
            fairPairs += right - left;
        }
        return fairPairs;
    }
};