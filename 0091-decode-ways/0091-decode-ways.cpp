class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            char nowChar = s[i - 1];
            if (nowChar != '0') dp[i] += dp[i - 1];
            if (i > 1) {
                char lastChar = s[i - 2];
                int num = (lastChar - '0') * 10 + (nowChar - '0');
                if (10 <= num && num <= 26) dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};