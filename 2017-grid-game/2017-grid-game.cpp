class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        int res = INT_MAX, up = 0, down = 0;
        int upSum = accumulate(grid[0].begin(), grid[0].end(), 0);
        for (int i = 0; i < n; ++i) {
            // 1st turn down at index i
            // we have two choice: 
            // 1. grid[0][i + 1] ~ grid[0][n - 1]
            // 2. grid[1][0] ~ grid[0][i - 1]
            up += grid[0][i];
            res = min(res, max(upSum - up, down));
            down += grid[1][i];
        }
        return res;
    }
};