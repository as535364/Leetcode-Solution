class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> matPos;
        unordered_map<int, int> matRowCnt, matColCnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matPos[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < m * n; ++i) {
            auto &[row, col] = matPos[arr[i]];
            ++matRowCnt[row];
            ++matColCnt[col];
            if (matRowCnt[row] >= n || matColCnt[col] >= m) return i;
        }
        return 0;
    }
};