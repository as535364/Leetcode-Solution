class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = reduce(nums.begin(), nums.end());

        // int res = 0, prefix = 0;
        // for (int i = 0; i < nums.size() - 1; ++i) {
        //     prefix += nums[i];
        //     if ((sum - 2 * prefix) % 2 == 0) ++res;
        // }
        // return res;

        if (sum % 2 == 0) return nums.size() - 1;
        else return 0;
    }
};