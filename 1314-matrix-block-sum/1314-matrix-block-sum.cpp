class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int r = max(0, i - k); r <= min(m - 1, i + k); ++r) {
                    for (int c = max(0, j - k); c <= min(n - 1, j + k); ++c) {
                        res[i][j] += mat[r][c];
                    }
                }
            }
        }
        return res;
    }
};