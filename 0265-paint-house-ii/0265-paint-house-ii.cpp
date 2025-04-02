class Solution {
private:
    const int inf = INT_MAX >> 1;
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(2, vector<int>(k, inf));
        dp[0] = costs[0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                int res = inf;
                for (int l = 0; l < k; ++l) {
                    if (j == l) continue;
                    res = min(res, dp[(i - 1) % 2][l]);
                }
                dp[i % 2][j] = res + costs[i][j];
            }
        }
        return *min_element(dp[(n - 1) % 2].begin(), dp[(n - 1) % 2].end());
    }
};