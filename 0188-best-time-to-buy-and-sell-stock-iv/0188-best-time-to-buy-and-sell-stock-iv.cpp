class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> dpCost(k, INT_MAX);
        vector<int> dpProfit(k, 0);

        for (int price : prices) {
            dpCost[0] = min(dpCost[0], price);
            dpProfit[0] = max(dpProfit[0], price - dpCost[0]);
            
            for (int j = 1; j < k; ++j) {
                dpCost[j] = min(dpCost[j], price - dpProfit[j - 1]);
                dpProfit[j] = max(dpProfit[j], price - dpCost[j]);
            }
        }
        return dpProfit[k - 1];
    }
};