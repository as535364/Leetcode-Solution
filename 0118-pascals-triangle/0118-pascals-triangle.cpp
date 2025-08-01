class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res{{1}};
        vector<int> prev({1});

        for (int i = 2; i <= numRows; ++i) {
            vector<int> now(i);
            for (int j = 0; j < i; ++j) {
                if (j == 0 || j == i - 1) now[j] = 1;
                else now[j] = prev[j - 1] + prev[j];
            }
            res.push_back(now);
            prev = now;
        }
        return res;
    }
};