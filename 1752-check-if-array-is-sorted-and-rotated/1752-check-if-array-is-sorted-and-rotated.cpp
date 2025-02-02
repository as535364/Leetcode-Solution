class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), inversionCnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) inversionCnt++;
        }
        if (nums[0] < nums[n - 1]) inversionCnt++;
        return inversionCnt <= 1;
    }
};