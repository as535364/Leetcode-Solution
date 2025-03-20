class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        vector<int> diff(n + 1);
        int flipCnt = 0;
        for (int i = 0; i < n; ++i) {
            flipCnt += diff[i];
            if ((nums[i] + flipCnt) % 2 == 0) {
                if (i > n - k) return -1;
                diff[i + k] -= 1;
                ++res;
                ++flipCnt;
            }
        }
        // n - 1 - () + 1 < k -> () > n - k
        return res;
    }
};