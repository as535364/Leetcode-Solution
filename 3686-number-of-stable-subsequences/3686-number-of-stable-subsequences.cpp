/* space: O(n x 2 x 2)
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

           // backup the prev state
           dp[i][x ^ 1][0] = dp[i-1][x ^ 1][0];
           dp[i][x ^ 1][1] = dp[i-1][x ^ 1][1];
        }
        return (dp[n][0][0] + dp[n][1][0] + dp[n][0][1] + dp[n][1][1]) % mod;
    }
};
*/


// space: O(1)
class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long dp[2][2] = {};
        // 最後一個奇偶, 連續幾個奇偶

        for (int i = 1; i <= n; ++i) {
           int x = nums[i - 1] % 2;
           dp[x][1] = (dp[x][1] + dp[x][0]) % mod;
           dp[x][0] = (dp[x][0] + dp[x ^ 1][0] + dp[x ^ 1][1] + 1) % mod;
           
        }
        return (dp[0][0] + dp[1][0] + dp[0][1] + dp[1][1]) % mod;
    }
};