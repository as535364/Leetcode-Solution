class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, min_ever = INT_MAX;
        for (int price : prices) {
            res = max(res, price - min_ever);
            min_ever = min(min_ever, price);
        }
        return res;
    }
};