class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[i + 1]) {
                ++i;
            }
            else {
                return false;
            }
        }
        return true;
    }
};