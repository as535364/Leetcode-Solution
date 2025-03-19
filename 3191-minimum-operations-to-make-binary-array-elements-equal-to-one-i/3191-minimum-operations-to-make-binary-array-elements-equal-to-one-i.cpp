class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++res;
            }
        }
        if (nums[n - 1] && nums[n - 2]) return res;
        else return -1;
    }
};