class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> prefix2Cnt;
        int n = nums.size();
        long long ans = 0;
        vector<int> prefix(n);

        prefix[0] = (nums[0] % modulo == k);
        ans = prefix[0] % modulo == k;
        ++prefix2Cnt[prefix[0] % modulo];

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (nums[i] % modulo == k);
            int toFind = prefix[i] - k;
            ans += (prefix[i] % modulo == k) + prefix2Cnt[toFind];
            ++prefix2Cnt[prefix[i] % modulo];
        }
        return ans;
    }
};
// 7 8 mod: 3


//      3 2 4
// mod: 1 0 0
// pre: 1 1 1


//      3 1 9 6
// mod: 0 1 0 0
// pre: 1 1 2 3

