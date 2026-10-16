class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        int n = nums.size();
        unordered_map<int, int> sum_end, cnt_end;

        int res = 0;
        
        for (int num : nums) {
            res = (0LL + res + num + 1LL * cnt_end[num - 1] * num + 1LL * cnt_end[num + 1] * num + sum_end[num - 1] + sum_end[num + 1]) % MOD;
            sum_end[num] = (sum_end[num] + 1LL * cnt_end[num - 1] * num + 1LL * cnt_end[num + 1] * num) % MOD;
            sum_end[num] = (0LL + sum_end[num] + sum_end[num - 1] + sum_end[num + 1] + num) % MOD;
            cnt_end[num] = (0LL + cnt_end[num] + cnt_end[num - 1] + cnt_end[num + 1]  + 1) % MOD;
        }
        return res;
    }
};