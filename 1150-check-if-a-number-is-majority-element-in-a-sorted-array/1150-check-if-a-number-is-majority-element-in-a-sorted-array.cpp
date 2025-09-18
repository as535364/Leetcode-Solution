class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int, int> cnts;
        for (int num : nums) ++cnts[num];
        return cnts[target] > nums.size() / 2;
    }
};