class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        unordered_set<int> ballIdxs;
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1') {
                ballIdxs.insert(i);
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            for (auto idx : ballIdxs) {
                ans[i] += abs(i - idx);
            }
        }
        return ans;
    }
};