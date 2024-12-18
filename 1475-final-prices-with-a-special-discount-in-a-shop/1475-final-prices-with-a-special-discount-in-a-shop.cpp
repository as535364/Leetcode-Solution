class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top().second >= prices[i]) {
                auto [idx, _] = st.top();
                st.pop();
                ans[idx] -= prices[i];
            }
            st.push({i, prices[i]});
        }
        return ans;
    }
};