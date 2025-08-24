class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCnt = 0, left = 0;
        int ans = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zeroCnt;
            while (zeroCnt > 1) {
                if (nums[left] == 0) --zeroCnt;
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans - 1;
    }
};