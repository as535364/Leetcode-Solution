class Solution {
private:
    const long long minVal = -(1LL << 48);
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> groupSum(n - k + 1);

        int left = 0;
        long long sum = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            if (right - left + 1== k) {
                groupSum[left % k].push_back(sum);
                sum -= nums[left];
                left++;
            }
        }

        long long ans = minVal;
        for (const auto &g : groupSum) {
            long long curr = 0;
            long long groupAns = minVal;
            for (long long gs : g) {
                if (curr < 0) curr = gs;
                else curr += gs;
                groupAns = max(groupAns, curr);
            }
            ans = max(ans, groupAns);
        }
        return ans;
    }
};