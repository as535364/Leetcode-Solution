class Solution {
private:
    bool isOK(const vector<int>& nums, int maxOperations, int maxPenalty) {
        for (int num : nums) {
            maxOperations -= (num - 1) / maxPenalty;
            if (maxOperations < 0) return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int m = l + (r - l) / 2, count = 0;
            for (int num : nums) {
                count += (num - 1) / m;
            }
            if (count <= maxOperations) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};