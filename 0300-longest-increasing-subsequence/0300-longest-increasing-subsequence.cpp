class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        for (int i = 0; i < n; ++i) {
            if (sub.empty() || sub.back() < nums[i]) {
                sub.push_back(nums[i]);
            }
            else {
                auto it = lower_bound(begin(sub), end(sub), nums[i]);
                *it = nums[i];
            }
        }
        return sub.size();
    }
};