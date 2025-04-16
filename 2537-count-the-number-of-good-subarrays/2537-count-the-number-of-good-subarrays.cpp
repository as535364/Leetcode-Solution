class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0, n = nums.size();
        long long res = 0;

        int pairs = 0;
        for (int right = 0; right < n; ++right) {
            pairs += count[nums[right]];
            ++count[nums[right]];
            while (pairs >= k) {
                pairs -= count[nums[left]] - 1;
                --count[nums[left]];
                ++left;
            }
            res += left;
        }
        return res;
    }
};