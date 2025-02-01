class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        unordered_map<int, int> counts;

        for (int i = 0; i < k; ++i) ++counts[nums[i]];
        res[0] = counts.size();

        for (int i = k; i < n; ++i) {
            ++counts[nums[i]];
            if (--counts[nums[i - k]] == 0) counts.erase(nums[i - k]);
            res[i - k + 1] = counts.size();
        }
        return res;
    }
};