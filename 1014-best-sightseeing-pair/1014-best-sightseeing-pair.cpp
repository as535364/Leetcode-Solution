class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxValuesI = INT_MIN, ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, values[i] - i + maxValuesI);
            maxValuesI = max(maxValuesI, values[i] + i);
        }
        return ans;
    }
};