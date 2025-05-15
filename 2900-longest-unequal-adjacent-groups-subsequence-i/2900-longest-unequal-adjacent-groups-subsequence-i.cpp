class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), maxIdx = -1, maxLen = 0;
        vector<pair<int, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            int fromIdx = -1, maxPrefixLen = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (groups[i] == groups[j]) continue;
                if (dp[j].second > maxPrefixLen) {
                    maxPrefixLen = dp[j].second;
                    fromIdx = j;
                }
            }
            dp[i].second = maxPrefixLen + 1;
            dp[i].first = fromIdx;
            if (maxLen < dp[i].second) {
                maxLen = dp[i].second;
                maxIdx = i;
            }
        }

        vector<string> res(maxLen);

        for (int i = maxLen - 1, tmpIdx = maxIdx; i >= 0; --i) {
            res[i] = words[tmpIdx];
            tmpIdx = dp[tmpIdx].first;
        }
        return res;
    }
};