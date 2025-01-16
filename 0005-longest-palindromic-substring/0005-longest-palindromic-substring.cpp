class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        int longestStart = 0, longestLen = 1;
        for (int len = 2; len <= n; ++len) {
            for (int start = 0; start + len - 1 < n; ++start) {
                int end = start + len - 1;
                if (s[start] == s[end] && (start + 1 == end || dp[start + 1][end - 1])) {
                    dp[start][end] = true;

                    if (len > longestLen) {
                        longestLen = len;
                        longestStart = start;
                    }
                }
            }
        }
        return s.substr(longestStart, longestLen);
    }
};