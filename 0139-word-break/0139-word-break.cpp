class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] s[0] ~ s[i] can be construct
        // dp[i] |= dp[i - n] && wordDict.count(n)
        // if (i - n < 0) return true;
        int n = s.size();
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = wordDictSet.count(s.substr(0, i + 1));
            if (dp[i]) continue;
            for (int j = 0; j < i; ++j) {
                // s[0] ~ s[j], s[j + 1] ~ s[i]
                dp[i] = dp[i] || (dp[j] && wordDictSet.count(s.substr(j + 1, i - j)));
                if (dp[i]) break;
            }
        }
        return dp[n - 1];
    }
};