class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff_counts(100001);

        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            if (a < b) swap(a, b);
            ++diff_counts[a - b];
        }

        long long k = static_cast<long long>(k1) + static_cast<long long>(k2);
        for (int d = 100000; d > 0 && k > 0; --d) {
            long long cnt = static_cast<long long>(diff_counts[d]);
            long long move = min(cnt, k);
            diff_counts[d] -= move;
            diff_counts[d - 1] += move;
            k -= move;
        }

        long long suqare_sum = 0;

        for (int d = 100000; d > 0; --d) {
            long long cnt = static_cast<long long>(diff_counts[d]);
            suqare_sum += cnt * d * d;    
        }

        return suqare_sum;
    }
};