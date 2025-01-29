class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), ans = 1;
        unordered_map<int, int> dp;
        for (int i = 0; i < n; ++i) {
            int target = arr[i] - difference;
            int prevTargetMax = dp.find(target) == dp.end() ? 0 : dp[target];
            dp[arr[i]] = prevTargetMax + 1;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};