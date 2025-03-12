class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto itZero = lower_bound(nums.begin(), nums.end(), 0);
        auto itPositive = upper_bound(nums.begin(), nums.end(), 0);
        return max(nums.end() - itPositive, itZero - nums.begin());
    }
};