class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        /*
        dp[i][op1][op2] means first i elements, with remain op1 op2 total sum min
        transition formula
        dp[i][op1][op2] = min(
            dp[i - 1][op1][op2] + nums[i]
            dp[i - 1][op1 + 1][op2] + nums[i] / 2
            dp[i - 1][op1][op2 + 1] + nums[i] - k if nums[i] >= k
            dp[i - 1][op1 + 1][op2 + 1] + min(nums[i] / 2 - k, (nums[i] - k) / 2)
        )
        */
        const int inf = 1e9;
        int n = nums.size();
        int dp[2][101][101] = {};

        for (int i = 1; i <= n; ++i) {
            int num = nums[i - 1];
            int keep = num;
            int half = (num + 1) / 2;
            int cut = num >= k ? num - k : inf;
            int both = inf;
            if (half >= k) both = min(both, half - k);
            if (num >= k) both = min(both, (num - k + 1) / 2);

            for (int remain1 = 0; remain1 <= op1; ++remain1) {
                for (int remain2 = 0; remain2 <= op2; ++remain2) {
                    auto &cur = dp[i % 2][remain1][remain2];
                    auto &prev = dp[(i - 1) % 2];
                    bool has1 = remain1 + 1 <= op1, has2 = remain2 + 1 <= op2;

                    cur = prev[remain1][remain2] + keep;
                    if (has1) cur = min(cur, prev[remain1 + 1][remain2] + half);
                    if (has2) cur = min(cur, prev[remain1][remain2 + 1] + cut);
                    if (has1 && has2) cur = min(cur, prev[remain1 + 1][remain2 + 1] + both);
                }
            }
        }
        return dp[n % 2][0][0];
    }
};