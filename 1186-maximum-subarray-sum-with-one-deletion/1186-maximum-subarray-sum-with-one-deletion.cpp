class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));

        dp[0][0] = arr[0];
        dp[0][1] = arr[0];
        int ans = max(dp[0][0], dp[0][1]);

        for (int i = 1; i < n; ++i) {
            // without deletion
            dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);

            // with deletion used before or here
            dp[i][1] = max(
                max(
                    dp[i-1][1] + arr[i],
                    dp[i-1][0]
                ),
                arr[i]
            );

            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};