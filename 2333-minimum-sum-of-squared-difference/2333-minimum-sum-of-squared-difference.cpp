class Solution {
private:
    static constexpr int kMaxDiff = 100'000;
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff_counts(kMaxDiff + 1);

        for (int i = 0; i < n; ++i) {
            ++diff_counts[abs(nums1[i] - nums2[i])];
        }

        long long remaining_ops = (long long){k1} + k2;
        for (int d = kMaxDiff; d > 0 && remaining_ops > 0; --d) {
            long long cnt = diff_counts[d];
            long long move = min(cnt, remaining_ops);
            diff_counts[d] -= move;
            diff_counts[d - 1] += move;
            remaining_ops -= move;
        }

        long long square_sum = 0;

        for (int d = kMaxDiff; d > 0; --d) {
            square_sum += diff_counts[d] * d * d;
        }

        return square_sum;
    }
};