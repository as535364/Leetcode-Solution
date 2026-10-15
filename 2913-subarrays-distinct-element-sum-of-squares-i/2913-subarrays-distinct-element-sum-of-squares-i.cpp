class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> unique_set;
            for (int j = i; j < n; ++j) {
                unique_set.insert(nums[j]);
                res += unique_set.size() * unique_set.size();
            }
        }
        
        return res;
    }
};