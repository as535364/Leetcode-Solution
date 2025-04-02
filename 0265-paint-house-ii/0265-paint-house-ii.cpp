class Solution {
private:
    const int inf = INT_MAX >> 1;
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(2, vector<int>(k, inf));
        dp[0] = costs[0];

        int prevBest = inf, prevBestIdx = -1, prevSecondBest = inf;
        for (int i = 0; i < k; ++i) {
            if (dp[0][i] <= prevBest) {
                prevSecondBest = prevBest;
                prevBest = dp[0][i];
                prevBestIdx = i;
            }
            else if (dp[0][i] <= prevSecondBest) {
                prevSecondBest = dp[0][i];
            }
        }

        for (int i = 1; i < n; ++i) {
            int nowBest = inf, nowBestIdx = -1, nowSecondBest = inf;
            for (int j = 0; j < k; ++j) {
                if (j != prevBestIdx) dp[i % 2][j] = prevBest + costs[i][j];
                else dp[i % 2][j] = prevSecondBest + costs[i][j];

                if (dp[i % 2][j] <= nowBest) {
                    nowSecondBest = nowBest;
                    nowBest = dp[i % 2][j];
                    nowBestIdx = j;
                }
                else if (dp[i % 2][j] <= nowSecondBest) {
                    nowSecondBest = dp[i % 2][j];
                }
            }
            prevBest = nowBest;
            prevBestIdx = nowBestIdx;
            prevSecondBest = nowSecondBest;
        }
        return prevBest;
    }
};