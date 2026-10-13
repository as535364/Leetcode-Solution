class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            return x * x < y * y;
        });

        int i = 0, j = nums.size() - 1;
        long long res = 0;

        while (i < j) {
            res += 1LL * nums[j] * nums[j];
            res -= 1LL * nums[i] * nums[i];
            ++i, --j;
        }
        if (i == j) res += 1LL * nums[i] * nums[i];
        return res;
    }
};