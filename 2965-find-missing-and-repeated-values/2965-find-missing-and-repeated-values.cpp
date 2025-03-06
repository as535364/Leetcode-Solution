class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a = -1, b = -1, n = grid.size();
        vector<int> cnt(n * n + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++cnt[grid[i][j]];
                if (cnt[grid[i][j]] == 2) a = grid[i][j];
            }
        }
        for (int i = 1; i <= n * n; ++i) {
            if (cnt[i] == 0) {
                b = i;
                break;
            }
        }
        return {a, b};
    }
};