class Solution {
private:
    int m, n;
    const int MOD = 1e9 + 7;
    const int MAXORVAL = 15; // 8 + 4 + 2 + 1 = 15

    bool isValid(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(MAXORVAL + 1, 0)));
        dp[0][0][grid[0][0]]++;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l <= MAXORVAL; ++l) {
                    int targetVal = l ^ grid[i][j];
                    if (isValid(i - 1, j)) {
                        dp[i][j][targetVal] = (dp[i][j][targetVal] + dp[i - 1][j][l]) % MOD;
                    }
                    if (isValid(i, j - 1)) {
                        dp[i][j][targetVal] = (dp[i][j][targetVal] + dp[i][j - 1][l]) % MOD;
                    }
                }
            }
        }
        return dp[m - 1][n - 1][k];
    }
};