class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), ans = 1;
        unordered_map<int, int> dp, visIdx;
        for (int num : arr) dp[num] = 1;

        for (int i = 0; i < n; ++i) {
            int prevTarget = arr[i] - difference;
            if (!visIdx.count(prevTarget)) {
                visIdx[arr[i]] = i;
                continue;
            }

            if (dp[arr[i]] < dp[prevTarget] + 1) {
                dp[arr[i]] = dp[prevTarget] + 1;
            }
            visIdx[arr[i]] = i;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};