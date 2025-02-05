class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> hold(n + 1, -1e9), free(n + 1, -1e9);
        free[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int price = prices[i - 1];
            hold[i] = max(hold[i - 1], free[i - 1] - price);
            free[i] = max(free[i - 1], hold[i - 1] + price - fee);
        }
        return free[n];                                              
    }
};