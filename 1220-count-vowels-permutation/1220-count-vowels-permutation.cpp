class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(2, vector<int>(5));
        dp[0] = {1, 1, 1, 1, 1};

        for (int i = 1; i < n; ++i) {
            // a
            dp[i % 2][0] = dp[(i - 1) % 2][1];
            // e
            dp[i % 2][1] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][2]) % MOD;
            // i
            dp[i % 2][2] = ((dp[(i - 1) % 2][0] + dp[(i - 1) % 2][1]) % MOD + (dp[(i - 1) % 2][3] + dp[(i - 1) % 2][4]) % MOD) % MOD;
            // o
            dp[i % 2][3] = (dp[(i - 1) % 2][2] + dp[(i - 1) % 2][4]) % MOD;
            // u
            dp[i % 2][4] = dp[(i - 1) % 2][0];
        }

        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum = (sum + dp[(n - 1) % 2][i]) % MOD;
        }
        return sum;
    }
};