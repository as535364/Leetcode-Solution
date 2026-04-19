class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dis = 0;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                max_dis = max(max_dis, j - i);
                ++j;
            }
            else {
                ++i;
            }
        }
        return max_dis;
    }
};