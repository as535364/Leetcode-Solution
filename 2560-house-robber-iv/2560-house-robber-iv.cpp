class Solution {
private:
    inline bool isOK(int c, const vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= c) {
                ++cnt;
                ++i;
            }
        }
        return cnt >= k;
    }
public:
    inline int minCapability(vector<int>& nums, int k) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isOK(mid, nums, k)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};