class Solution {
private:
    const int inf = 1e7;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        days.push_back(400);
        vector<int> dp(n + 1, inf);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            int Day1Idx = i + 1;
            int Day7Idx = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
            int Day30Idx = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();

            int buy1Cost = dp[Day1Idx] + costs[0];
            int buy7Cost = dp[Day7Idx] + costs[1];
            int buy30Cost = dp[Day30Idx] + costs[2];
            dp[i] = min({dp[i], buy1Cost, buy7Cost, buy30Cost});
        }
        return dp[0];
    }
};