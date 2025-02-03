class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<int> dp(len2 + 1), prev(len2 + 1);

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1]) dp[j] = prev[j - 1] + 1;
                else dp[j] = max(prev[j], dp[j - 1]);
            }
            prev = dp;
        }
        return dp[len2];
    }
};