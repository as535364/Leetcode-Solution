class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // 26 43 -> 2 * 1 / 2 * 2 * 2
        // 1 10 2 5
        // 10 2 4 5 -> n * (n - 1) * 4
        sort(nums.begin(), nums.end());
        unordered_map<int, int> counts;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++counts[nums[i] * nums[j]];
            }
        }
        int res = 0;
        for (auto [mul, count] : counts) {
            res += count * (count - 1) * 4;
        }
        return res;
    }
};