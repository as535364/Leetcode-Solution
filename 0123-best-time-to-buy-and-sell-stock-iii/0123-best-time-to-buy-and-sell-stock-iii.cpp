class Solution {
private:
    const int inf = 1e9;
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int t1Cost = INT_MAX, t2Cost = INT_MAX;
        int t1Profit = 0, t2Profit = 0;
        for (int price : prices) {
            t2Cost = min(t2Cost, price - t1Profit);
            t2Profit = max(t2Profit, price - t2Cost);
            t1Cost = min(t1Cost, price);
            t1Profit = max(t1Profit, price - t1Cost);
        }
        return max(t1Profit, t2Profit);
    }
};