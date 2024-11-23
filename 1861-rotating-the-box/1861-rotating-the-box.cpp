class Solution {
    static const char STONE = '#';
    static const char OBSTACLE = '*';
    static const char EMPTY = '.';

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        for (auto &row : box) {
            int lastEmptyIdx = n - 1;
            for (int i = n - 1; i >= 0; --i) {
                if (row[i] == OBSTACLE) {
                    lastEmptyIdx = i - 1;
                }
                if (row[i] == STONE) {
                    row[i] = EMPTY;
                    row[lastEmptyIdx--] = STONE;
                }
            }
        }
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = box[m - j - 1][i];
            }
        }
        return res;
    }
};