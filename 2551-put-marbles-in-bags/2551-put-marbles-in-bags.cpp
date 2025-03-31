class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> possibleCost(n - 1);
        for (int i = 1; i < n; ++i) {
            possibleCost[i - 1] = weights[i - 1] + weights[i];
        }
        sort(possibleCost.begin(), possibleCost.end());

        long long res = 0;
        for (int i = 0; i < k - 1; ++i) {
            res += possibleCost[n - 2 - i] - possibleCost[i];
        }
        return res;
    }
};