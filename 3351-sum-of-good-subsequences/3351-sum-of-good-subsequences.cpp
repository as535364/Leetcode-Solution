class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        vector<long long> sum_end(1e5 + 2), cnt_end(1e5 + 2);

        int res = 0;
        
        for (int num : nums) {
            long long cnt_lower = num - 1 < 0 ? 0 : cnt_end[num - 1];
            long long cnt_upper = cnt_end[num + 1];
            long long sum_lower = num - 1 < 0 ? 0 : sum_end[num - 1];
            long long sum_upper = sum_end[num + 1];
            res = (res + num + cnt_lower * num + cnt_upper * num + sum_lower + sum_end[num + 1]) % MOD;
            sum_end[num] = (sum_end[num] + cnt_lower * num + cnt_upper * num) % MOD;
            sum_end[num] = (sum_end[num] + sum_lower + sum_end[num + 1] + num) % MOD;
            cnt_end[num] = (cnt_end[num] + cnt_lower + cnt_upper  + 1) % MOD;
        }
        return res;
    }
};