class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto itStart = lower_bound(nums.begin(), nums.end(), target);
        auto itEnd = upper_bound(nums.begin(), nums.end(), target);
        return itEnd - itStart > nums.size() / 2;
    }
};