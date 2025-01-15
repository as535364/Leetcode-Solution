class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size(), goodCount = 1;
        vector<vector<bool>> dp(n, vector<bool>(2));
        map<int, int> num2Idx;
        
        dp[n - 1][0] = dp[n - 1][1] = true;
        num2Idx[arr[n - 1]] = n - 1;
        
        for (int i = n - 2; i >= 0; --i) {
            int oddJumpIdx = -1, evenJumpIdx = -1;

            auto iter1 = num2Idx.lower_bound(arr[i]);
            if (iter1 != num2Idx.end()) {
                oddJumpIdx = iter1 -> second;
                dp[i][1] = dp[oddJumpIdx][0];
            }

            auto iter2 = num2Idx.upper_bound(arr[i]);
            if (iter2 != num2Idx.begin()) {
                evenJumpIdx = prev(iter2) -> second;
                dp[i][0] = dp[evenJumpIdx][1];
            }

            num2Idx[arr[i]] = i;
            goodCount += dp[i][1];
        }
        return goodCount;
    }
};