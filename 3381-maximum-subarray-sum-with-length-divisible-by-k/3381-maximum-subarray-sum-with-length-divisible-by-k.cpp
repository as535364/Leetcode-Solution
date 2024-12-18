class Solution {
private:
    const long long maxVal = 1LL << 48;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> preMin(k, maxVal);
        preMin[k - 1] = 0;

        long long res = -maxVal, pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            res = max(res, pre - preMin[i % k]);
            preMin[i % k] = min(preMin[i % k], pre);
        }
        return res;
    }
};