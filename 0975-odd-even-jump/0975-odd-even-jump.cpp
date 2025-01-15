class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size(), goodCount = 1;
        vector<vector<bool>> dp(n, vector<bool>(2));
        set<int> s;
        unordered_map<int, int> num2Idx;
        
        dp[n - 1][0] = dp[n - 1][1] = true;
        s.insert(arr[n - 1]);
        num2Idx[arr[n - 1]] = n - 1;
        
        for (int i = n - 2; i >= 0; --i) {
            int oddJumpIdx = -1, evenJumpIdx = -1;

            auto iter1 = s.lower_bound(arr[i]);
            if (iter1 != s.end()) {
                oddJumpIdx = num2Idx[*iter1];
            }

            auto iter2 = s.upper_bound(arr[i]);
            if (iter2 != s.begin()) {
                evenJumpIdx = num2Idx[*(--iter2)];
            }

            s.insert(arr[i]);
            num2Idx[arr[i]] = i;
            cout << i << " odd jump to " << oddJumpIdx << endl;
            cout << i << " even jump to " << evenJumpIdx << endl;
            
            if (evenJumpIdx != -1) dp[i][0] = dp[evenJumpIdx][1];
            if (oddJumpIdx != -1) dp[i][1] = dp[oddJumpIdx][0];
            goodCount += dp[i][1];
        }
        return goodCount;
    }
};