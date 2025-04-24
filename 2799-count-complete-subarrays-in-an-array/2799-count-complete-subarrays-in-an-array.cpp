class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        unordered_map<int, int> curr;
        int left = 0, ans = 0, n = nums.size();

        for (int right = 0; right < n; ++right) {
            ++curr[nums[right]];
            while (curr.size() >= us.size()) {
                if (--curr[nums[left]] == 0) curr.erase(nums[left]);
                left++;
            }
            ans += left;
        }
        return ans;
    }
};