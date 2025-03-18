class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        vector<int> squares;
        for (int i = 1; i <= 100 && i * i <= n; ++i) {
            squares.push_back(i * i);
            dp[i * i] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            if (dp[i] == 1) {
                continue;
            }
            for (int j = 0; j < squares.size() && i > squares[j]; ++j) {
                int sq = squares[j];
                dp[i] = min(dp[i], dp[i - sq] + 1);
            }
        }
        return dp[n];
    }
};