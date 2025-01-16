class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int res = 0;
        if (n & 1) {
            for (int num : nums1) {
                res ^= num;
            }
        }
        if (m & 1) {
            for (int num : nums2) {
                res ^= num;
            }
        }
        return res;
    }
};