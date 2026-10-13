class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int &num : nums) num *= num;
        ranges::sort(nums);

        int n = nums.size();

        return -accumulate(nums.begin(), nums.begin() + n / 2, 0LL) +
                accumulate(nums.begin() + n / 2, nums.end(), 0LL);
    }
};