class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<tuple<int, int, int>> sortedList(n * m);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sortedList[i * n + j] = {grid[i][j], i, j};
            }
        }
        sort(sortedList.begin(), sortedList.end());

        vector<int> rowMax(m), colMax(n);
        vector<vector<int>> ans(m, vector<int>(n));
        for (const auto &tuple : sortedList) {
            auto [_, row, col] = tuple;
            ans[row][col] = max(rowMax[row], colMax[col]) + 1;
            rowMax[row] = colMax[col] = ans[row][col];
        }
        return ans;
    }
};