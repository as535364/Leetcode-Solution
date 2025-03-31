class Solution {
private:
    const long long MAX_VAL = LLONG_MAX / 2;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // loop i
        // i % k
        // preMin[k]

        // preMin[2]
        // 0: -5
        // 1: -4
        // ans: 3

        vector<long long> preMin(k, MAX_VAL);
        preMin.back() = 0;

        long long prefixSum = 0, ans = -MAX_VAL;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            ans = max(ans, prefixSum - preMin[i % k]);
            preMin[i % k] = min(preMin[i % k], prefixSum);
        }
        return ans;
    }
};