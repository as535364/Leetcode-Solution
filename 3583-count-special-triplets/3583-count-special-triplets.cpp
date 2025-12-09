class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> multiply2(n);
        unordered_map<int, int> prev, next;
        
        for (int i = 0; i < n; ++i) {
            multiply2[i].first = prev[nums[i] * 2];
            ++prev[nums[i]];
        }

        for (int i = n - 1; i >= 0; --i) {
            multiply2[i].second = next[nums[i] * 2];
            ++next[nums[i]];
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)multiply2[i].first * multiply2[i].second) % MOD;
        }
        return res;
    }
};