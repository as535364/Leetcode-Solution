class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> count;
        for (const auto &row : matrix) {
            string rowStr;
            int first = row[0];
            for (int r : row) {
                if (r == first) rowStr += "T";
                else rowStr += "F";
            }
            ++count[rowStr];
        }
        int ans = 0;
        for (auto &[k, v] : count) {
            ans = max(ans, v);
        }
        return ans;
    }
};