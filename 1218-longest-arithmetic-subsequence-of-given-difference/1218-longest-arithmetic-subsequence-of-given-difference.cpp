class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), ans = 1;
        unordered_map<int, int> dp;
        for (int i = 0; i < n; ++i) {
            int target = arr[i] - difference;
            if (!dp.count(target)) {
                if (!dp.count(arr[i])) dp[arr[i]] = 1;
                continue;
            }
            if (dp[arr[i]] < dp[target] + 1) {
                dp[arr[i]] = dp[target] + 1;
            }
            ans = max(ans, dp[arr[i]]);
            if (!dp.count(arr[i])) dp[arr[i]] = 1;
        }
        return ans;
    }
};