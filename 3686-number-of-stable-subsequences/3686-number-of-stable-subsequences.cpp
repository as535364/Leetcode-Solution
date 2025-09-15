class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(2)));
        // 前 i 個, 最後一個奇偶, 連續幾個奇偶

        for (int i = 1; i <= n; ++i) {
           int x = nums[i - 1] % 2;
           dp[i][x][0] = (dp[i - 1][x][0] + dp[i - 1][x ^ 1][0] + dp[i - 1][x ^ 1][1] + 1) % mod;
           dp[i][x][1] = (dp[i - 1][x][1] + dp[i - 1][x][0]) % mod;

           dp[i][x ^ 1][0] = dp[i-1][x ^ 1][0];
           dp[i][x ^ 1][1] = dp[i-1][x ^ 1][1];
        }
        return (dp[n][0][0] + dp[n][1][0] + dp[n][0][1] + dp[n][1][1]) % mod;
    }
};