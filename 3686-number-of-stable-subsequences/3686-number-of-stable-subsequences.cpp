class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2)));
        // 前 i 個, 最後一個奇偶, 連續幾個奇偶

        for (int i = 1; i <= n; ++i) {
           int x = nums[i - 1];
        }
    }
};