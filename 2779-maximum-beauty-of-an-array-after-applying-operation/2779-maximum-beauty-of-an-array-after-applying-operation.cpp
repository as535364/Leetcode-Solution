class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> diffArr(maxNum + 2);
        for (int num : nums) {
            diffArr[max(0, num - k)]++;
            diffArr[min(maxNum + 1, num + k + 1)]--;
        }
        int soFar = 0, ans = 0;
        for (int diff : diffArr) {
            soFar += diff;
            ans = max(soFar, ans);
        }
        return ans;
    }
};