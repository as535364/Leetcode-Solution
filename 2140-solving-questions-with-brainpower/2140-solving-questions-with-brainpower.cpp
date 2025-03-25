class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        
        for (int i = n - 1; i >= 0; --i) {
            int point = questions[i][0], brainpower = questions[i][1];
            long long solve = i + brainpower + 1 >= n ? 0 : dp[i + brainpower + 1];
            long long skip = i + 1 >= n ? 0 : dp[i + 1];
            dp[i] = max({dp[i], solve + point, skip});
        }
        return dp[0];
    }
};