class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long fairPairs = 0;

        auto count = [&](int limit) -> long long {
            long long ans = 0;
            for (int i = 0, j = nums.size() - 1; i < j; ++i) {
                while (i < j && nums[i] + nums[j] > limit) {
                    --j;
                }
                ans += j - i;
            }
            return ans;
        };
        return count(upper) - count(lower - 1);
    }
};