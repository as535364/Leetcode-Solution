class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size(), maxNumber = *max_element(nums.begin(), nums.end());
        vector<int> res(n - k + 1);
        vector<int> counts(maxNumber + 1);

        int distinctCount = 0;
        for (int i = 0; i < k; ++i) {
            if(++counts[nums[i]] == 1) ++distinctCount;
        }
        res[0] = distinctCount;

        for (int i = k; i < n; ++i) {
            if(++counts[nums[i]] == 1) ++distinctCount;
            if (--counts[nums[i - k]] == 0) --distinctCount;
            res[i - k + 1] = distinctCount;
        }
        return res;
    }
};