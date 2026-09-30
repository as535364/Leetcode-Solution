class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        /*
        dp[i][op1][op2] means first i elements, with reamini op1 op2 total sum min
        transition formula
        dp[i][op1][op2] = min(
            dp[i - 1][op1][op2] + nums[i]
            dp[i - 1][op1 + 1][op2] + nums[i] / 2
            dp[i - 1][op1][op2 + 1] + nums[i] - k if nums[i] >= k
            dp[i - 1][op1 + 1][op2 + 1] + min(nums[i] / 2 - k, (nums[i] - k) / 2)
        )
        */
        int n = nums.size(), res = 1e9;
        int dp[101][101][101] = {};

        for (int i = 1; i <= n; ++i) {
            int num = nums[i - 1];
            for (int j = 0; j <= op1; ++j) {
                for (int l = 0; l <= op2; ++l) {
                    dp[i][j][l] = dp[i - 1][j][l] + num;
                    if (j + 1 <= op1)
                        dp[i][j][l]  = min(dp[i][j][l], dp[i - 1][j + 1][l] + (num + 1) / 2);
                    if (num >= k && l + 1 <= op2)
                        dp[i][j][l]  = min(dp[i][j][l], dp[i - 1][j][l + 1] + num - k);
                    if (num >= k && j + 1 <= op1 && l + 1 <= op2) {
                        dp[i][j][l]  = min(dp[i][j][l], dp[i - 1][j + 1][l + 1] + (num - k + 1) / 2);
                    }
                    if ((num + 1) / 2 >= k && j + 1 <= op1 && l + 1 <= op2) {
                        dp[i][j][l]  = min(dp[i][j][l], dp[i - 1][j + 1][l + 1] + (num + 1) / 2 - k);
                    }
                    
                }
            }
        }
        return dp[n][0][0];
    }
};