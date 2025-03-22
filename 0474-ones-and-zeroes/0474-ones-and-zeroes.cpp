class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> s;
        vector<vector<int>> dp(vector<vector<int>>(m + 1, vector<int>(n + 1)));

        for (string &str : strs) {
            int zeroCnt = 0, oneCnt = 0;
            for (char c : str) {
                if (c == '0') ++zeroCnt;
                else ++oneCnt;
            }
            s.push_back({zeroCnt, oneCnt});
        }
    
        for (int i = 1; i <= len; ++i) {
            int zeroCnt = s[i - 1].first, oneCnt = s[i - 1].second;
            for (int j = m; j >= zeroCnt; --j) {
                for (int k = n; k >= oneCnt; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zeroCnt][k - oneCnt] + 1);
                }
            }
        }
        return dp[m][n];
    }
};