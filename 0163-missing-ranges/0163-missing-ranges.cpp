class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            return {{lower, upper}};
        }
        
        vector<vector<int>> res;
        
        int last = lower;
        
        if (lower != nums[0]) {
            res.push_back({lower, nums[0] - 1});
        }
        last = nums[0];
        
        for (int num : nums) {
            if (num > last + 1) {
                res.push_back({last + 1, num - 1});
            }
            last = num;
        }
        
        if (upper > last) {
            res.push_back({last + 1, upper});
        }
        return res;
    }
};