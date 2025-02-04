class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, j = 0, n = nums.size();
        for (int i = 0; i < n; i = j) {
            int startFromI = nums[j];
            for (j = i + 1; j < n; ++j) {
                if (nums[j] > nums[j - 1]) startFromI += nums[j];
                else break;
            }
            res = max(res, startFromI);
        }
        return res;
    }
};