class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); ++i) {
            auto &q = queries[i];
            if (q[0] > q[1]) swap(q[0], q[1]);
            q.push_back(i);
        }

        sort(queries.begin(), queries.end(), [](const auto &a, const auto &b){
            return a[1] > b[1];
        });

        int n = heights.size(), idx = n - 1;
        vector<int> res(queries.size());
        map<int, int> height2Idx;
        for (auto &q : queries) {
            int a = q[0], b = q[1], qIdx = q[2];

            while (idx > b) {
                while (!height2Idx.empty() && height2Idx.begin() -> first <= heights[idx]) {
                    height2Idx.erase(height2Idx.begin());
                }
                height2Idx[heights[idx]] = idx;
                idx--;
            }

            if (a == b || heights[a] < heights[b]) {
                res[qIdx] = b;
                continue;
            }

            auto it = height2Idx.upper_bound(max(heights[a], heights[b]));
            if (it != height2Idx.end()) {
                res[qIdx] = it -> second;
            }
            else {
                res[qIdx] = -1;
            }
        }
        return res;
    }
};