class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int now = 0, n = nums.size();
        vector<bool> res(n);

        for (int i = 0; i < n; ++i) {
            now = now << 1 | nums[i];
            now = now % 5;
            if (now == 0) res[i] = true;
        }
        return res;
    }
};