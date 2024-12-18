class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(prices.size());
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) break;
            }
            if (j != n) {
                ans[i] = prices[i] - prices[j];
            }
            else {
                ans[i] = prices[i];
            }
        }
        return ans;
    }
};