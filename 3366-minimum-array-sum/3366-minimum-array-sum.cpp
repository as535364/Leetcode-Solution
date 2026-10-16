class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int dp[2][101][101] = {};
        int n = nums.size();

        for (int i = 1; i <= n; ++i) {
            int num = nums[i - 1];
            auto &prev = dp[(i - 1) % 2];

            int half = (num + 1) / 2;
            int cut = num >= k ? num - k : inf;
            int both = inf;
            if (num >= k) both = min((num - k + 1) / 2, both);
            if (half >= k) both = min(half - k, both);

            for (int o1 = 0; o1 <= op1; ++o1) {
                for (int o2 = 0; o2 <= op2; ++o2) {
                    auto &curr = dp[i % 2][o1][o2];
                    bool has1 = o1 + 1 <= op1, has2 = o2 + 1 <= op2;
                    curr = prev[o1][o2] + num;

                    if (has1) curr = min(curr, prev[o1 + 1][o2] + half);
                    if (has2) curr = min(curr, prev[o1][o2 + 1] + cut);
                    if (has1 && has2) curr = min(curr, prev[o1 + 1][o2 + 1] + both);
                }
            }
        }
        return dp[n % 2][0][0];
    }
private:
    const int inf = 1e9;
};