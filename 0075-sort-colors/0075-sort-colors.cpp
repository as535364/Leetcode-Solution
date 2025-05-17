class Solution {
public:
    void sortColors(vector<int>& nums) {
        // two pass
        // int colorCounts[3];
        // for (int num : nums) {
        //     ++colorCounts[num];
        // }
        // int i = 0;
        // while (colorCounts[0]--) nums[i++] = 0;
        // while (colorCounts[1]--) nums[i++] = 1;
        // while (colorCounts[2]--) nums[i++] = 2;
        
        // one pass
        int p0 = 0, p2 = nums.size() - 1, curr = 0;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[p0]);
                ++p0; ++curr;
            }
            else if (nums[curr] == 2) {
                swap(nums[curr], nums[p2]);
                --p2;
            }
            else {
                ++curr;
            }
        }
    }
};