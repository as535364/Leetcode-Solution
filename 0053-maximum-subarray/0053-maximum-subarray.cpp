class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -INT_MAX, curr_sum = 0;
        for (int num : nums) {
            curr_sum += num;
            res = max(res, curr_sum);
            if (curr_sum <= 0) curr_sum = 0;
        }
        return res;
    }
};