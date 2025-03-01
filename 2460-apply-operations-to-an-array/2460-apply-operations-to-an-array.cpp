class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        int l = n - 1, r = n - 1; // zero, non zero
        while (l >= 0) {
            swap(nums[l], nums[r]);
            while (r >= 0 && nums[r] == 0) --r;
            l = r - 1;
            while (l >= 0 && nums[l] != 0) --l;
        }
        return nums;
    }
};