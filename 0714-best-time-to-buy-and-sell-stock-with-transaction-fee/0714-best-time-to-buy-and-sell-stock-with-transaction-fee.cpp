class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> sold(n + 1, -1e9), reset(n + 1, -1e9), held(n + 1, -1e9);
        reset[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int price = prices[i - 1];
            held[i] = max(held[i - 1], max(sold[i - 1], reset[i - 1]) - price);
            reset[i] = max(reset[i - 1], sold[i - 1]);
            sold[i] = held[i - 1] + price - fee;
        }
        return max(sold[n], reset[n]);
    }
};

// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.