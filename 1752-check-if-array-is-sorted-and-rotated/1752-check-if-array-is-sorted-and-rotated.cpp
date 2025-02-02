class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            bool isStart = true;
            for (int j = i + 1, len = 0; len < n - 1; ++j, ++len) {
                if (nums[j % n] < nums[(j - 1) % n]) {
                    isStart = false;
                    break;
                }
            }
            if (isStart) return true;
        }
        return false;
    }
};