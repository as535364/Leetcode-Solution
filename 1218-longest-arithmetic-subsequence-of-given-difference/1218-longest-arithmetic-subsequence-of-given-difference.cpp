class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), ans = 1;
        unordered_map<int, int> dp;
        for (int i = 0; i < n; ++i) {
            auto prevTargetMaxIt = dp.find(arr[i] - difference);
            if (prevTargetMaxIt == dp.end()) {
                dp[arr[i]] = 1;
            }
            else {
                dp[arr[i]] = prevTargetMaxIt -> second + 1;
            }
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};