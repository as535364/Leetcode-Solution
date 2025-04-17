class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long pre = 0;
        int ans = 0;
        unordered_map<long long, int> sum2Idx;
        sum2Idx[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            if (sum2Idx.find(pre - k) != sum2Idx.end()) {
                ans = max(ans, i - sum2Idx[pre - k]);
            }
            if (sum2Idx.find(pre) == sum2Idx.end()) {
                sum2Idx[pre] = i;
            }
        }
        return ans;
    }
};