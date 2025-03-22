class Solution {
private:
    vector<vector<vector<int>>> dp;
    int topDown(int idx, int m, int n, vector<pair<int, int>> &s) {
        if (m == 0 && n == 0) return 0;
        if (idx == s.size()) return 0;
        if (dp[idx][m][n] != -1) return dp[idx][m][n];

        int zeroCnt = s[idx].first, oneCnt = s[idx].second;
        int notPick = topDown(idx + 1, m, n, s);
        if (m < zeroCnt || n < oneCnt) {
            dp[idx][m][n] = notPick;
        }
        else {
            int pick = pick = topDown(idx + 1, m - zeroCnt, n - oneCnt, s) + 1;
            dp[idx][m][n] = max(notPick, pick);
        }
        return dp[idx][m][n];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> s;
        dp = vector<vector<vector<int>>>(len, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        for (string &str : strs) {
            int zeroCnt = 0, oneCnt = 0;
            for (char c : str) {
                if (c == '0') ++zeroCnt;
                else ++oneCnt;
            }
            s.push_back({zeroCnt, oneCnt});
        }
        return topDown(0, m, n, s);
    }
};