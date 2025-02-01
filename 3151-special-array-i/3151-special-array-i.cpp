class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (((nums[i] ^ nums[i + 1]) & 1) == 0) return false;
        }
        return true;
    }
};