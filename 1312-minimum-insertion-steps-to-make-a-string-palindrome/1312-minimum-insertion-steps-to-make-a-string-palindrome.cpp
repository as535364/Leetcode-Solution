class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t(s.rbegin(), s.rend());
        vector<int> dp(n + 1), prev(n + 1);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) dp[j] = prev[j - 1] + 1;
                else dp[j] = max(prev[j], dp[j - 1]);
            }
            prev = dp;
        }
        return n - dp[n];
    }
};