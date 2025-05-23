class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int target = *max_element(nums.begin(), nums.end()), targetCount = 0;
        long long res = 0;

        int left = 0;

        for (int num : nums) {
            if (num == target) ++targetCount;
            while (targetCount >= k) {
                if (nums[left] == target) --targetCount;
                ++left;
            }
            res += left;
        }
        return res;
    }
};