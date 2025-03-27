class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        int dominant = nums[0], dominantCnt = 0;
        for (int num : nums) {
            if (dominant == num) {
                dominantCnt++;
            }
            else {
                dominantCnt--;
            }
            if (dominantCnt == 0) {
                dominant = num;
                dominantCnt = 1;
            }
        }

        int xCnt = 0;
        for (int num : nums) xCnt += num == dominant;
        
        int nowXCnt = 0;
        for (int i = 0; i < n; ++i) {
            nowXCnt += nums[i] == dominant;
            int leftPartLen = i + 1, rightPartLen = n - i - 1;
            int leftPartDominant = nowXCnt, rightPartDominant = xCnt - nowXCnt;
            if (leftPartDominant > leftPartLen / 2 && rightPartDominant > rightPartLen / 2) return i;
        }
        return -1;
    }
};