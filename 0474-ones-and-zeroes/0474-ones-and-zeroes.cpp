class Solution {
private:
    vector<vector<vector<int>>> dp;
    int topDown(int idx, int m, int n, vector<pair<int, int>> &s) {
        if (m == 0 && n == 0) return 0;
        if (idx == s.size()) return 0;
        if (dp[idx][m][n] != -1) return dp[idx][m][n];

        int zeroCnt = s[idx].first, oneCnt = s[idx].second;
        if (m < zeroCnt || n < oneCnt) {
            dp[idx][m][n] = topDown(idx + 1, m, n, s);
        }
        else {
            int notPick = topDown(idx + 1, m, n, s);
            int pick = topDown(idx + 1, m - zeroCnt, n - oneCnt, s) + 1;
            dp[idx][m][n] = max(pick, notPick);
        }
        return dp[idx][m][n];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> s;
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

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
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    int notPick = dp[i - 1][j][k];
                    if (j < zeroCnt || k < oneCnt) {
                        dp[i][j][k] = notPick;
                    }
                    else {
                        int pick = dp[i - 1][j - zeroCnt][k - oneCnt] + 1;
                        dp[i][j][k] = max(notPick, pick);
                    }
                }
            }
        }
        return dp[len][m][n];
    }
};