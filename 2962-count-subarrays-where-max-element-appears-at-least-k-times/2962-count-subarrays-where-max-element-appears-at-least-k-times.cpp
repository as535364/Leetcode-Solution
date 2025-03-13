class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int target = *max_element(nums.begin(), nums.end());
        long long res = 0;
        unordered_map<int, int> count;

        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            ++count[nums[right]];
            while (count[target] >= k) {
                --count[nums[left]];
                ++left;
            }
            res += left;
        }
        return res;
    }
};