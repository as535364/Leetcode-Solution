class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -1e9, free = 0;
        for (int i = 0; i < n; ++i) {
            int prevHold = hold, prevFree = free;
            hold = max(prevHold, prevFree- prices[i]);
            free = max(prevFree, prevHold + prices[i] - fee);
        }
        return free;                                              
    }
};