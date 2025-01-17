class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(n); // dp[i] means s[0] ~ s[i] can be segmented
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 && words.count(s.substr(j, i - j + 1))) {
                    dp[i] = true;
                    break;
                }
                else if (words.count(s.substr(j, i - j + 1)) && dp[j - 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};