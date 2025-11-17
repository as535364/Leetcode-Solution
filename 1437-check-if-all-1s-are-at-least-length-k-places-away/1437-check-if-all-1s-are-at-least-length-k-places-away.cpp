class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOne = -k - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if (i - lastOne <= k) return false;
                lastOne = i;
            }
        }
        return true;
    }
};