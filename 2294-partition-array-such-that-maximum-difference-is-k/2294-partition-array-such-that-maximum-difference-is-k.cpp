class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, x = nums[0], n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i] - x > k){
                ++ans;
                x = nums[i];
            }
        }
        return ans;
    }
};