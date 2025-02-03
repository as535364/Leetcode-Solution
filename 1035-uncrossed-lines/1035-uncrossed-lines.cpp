class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 < len2) {
            swap(nums1, nums2);
            swap(len1, len2);
        }
        vector<int> dp(len2 + 1), prev(len2 + 1);

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) dp[j] = prev[j - 1] + 1;
                else dp[j] = max(prev[j], dp[j - 1]);
            }
            prev = dp;
        }
        return dp[len2];
    }
};