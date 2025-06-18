class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), groupCnt = n / 3, groupSize = 3;
        
        vector<vector<int>> res;
        for (int i = 0; i < groupCnt; ++i) {
            if (nums[i * groupSize + 2] - nums[i * groupSize] > k) return {};
            res.push_back({nums[i * groupSize], nums[i * groupSize + 1], nums[i * groupSize + 2]});
        }
        return res;
    }
};