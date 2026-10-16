class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        vector<int> sum_end(1e5 + 2), cnt_end(1e5 + 2);

        int res = 0;
        
        for (int num : nums) {
            int cnt_lower = num - 1 < 0 ? 0 : cnt_end[num - 1];
            int cnt_upper = cnt_end[num + 1];
            int sum_lower = num - 1 < 0 ? 0 : sum_end[num - 1];
            int sum_upper = sum_end[num + 1];
            res = (0LL + res + num + 1LL * cnt_lower * num + 1LL * cnt_upper * num + sum_lower + sum_end[num + 1]) % MOD;
            sum_end[num] = (sum_end[num] + 1LL * cnt_lower * num + 1LL * cnt_upper * num) % MOD;
            sum_end[num] = (0LL + sum_end[num] + sum_lower + sum_end[num + 1] + num) % MOD;
            cnt_end[num] = (0LL + cnt_end[num] + cnt_lower + cnt_upper  + 1) % MOD;
        }
        return res;
    }
};