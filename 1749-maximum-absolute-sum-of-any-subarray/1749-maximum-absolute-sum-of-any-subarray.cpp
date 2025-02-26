class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSoFar = max(0, nums[0]), minSoFar = min(0, nums[0]);
        int res = max(maxSoFar, abs(minSoFar));
        for (int i = 1; i < nums.size(); ++i) {
            maxSoFar = max(0, maxSoFar + nums[i]);
            minSoFar = min(0, minSoFar + nums[i]);
            res = max(max(res, maxSoFar), abs(minSoFar));
        }
        return res;
    }
};