class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        /* dp
        int n = pairs.size();
        vector<int> dp(n, 1);
        sort(begin(pairs), end(pairs));
        // a[0] < a[1] b[0] < b[1] c[0] < c[1] d[0] < d[1]
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] >= pairs[i][0]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
        */

        // greedy
        int n = pairs.size();
        sort(begin(pairs), end(pairs), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });
        int ans = 0, lastEnd = -1001;
        for (int i = 0; i < n; ++i) {
            if (pairs[i][0] > lastEnd) {
                ans++;
                lastEnd = pairs[i][1];
            }
        }
        return ans;
    }
};