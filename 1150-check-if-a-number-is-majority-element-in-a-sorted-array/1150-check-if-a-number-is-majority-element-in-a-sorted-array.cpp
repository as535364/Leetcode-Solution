class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int idxStart = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return idxStart + nums.size() / 2 < nums.size() && nums[idxStart + nums.size() / 2] == target;
    }
};