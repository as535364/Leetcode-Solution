class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int num : nums) ++cnt[num];
        
        int dominant = -1;
        for (auto [num, c] : cnt) {
            if (c > n / 2) {
                dominant = num;
                break;
            }
        }

        vector<int> prefix(n);
        prefix[0] = (nums[0] == dominant);
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (nums[i] == dominant);
        }
        
        for (int i = 0; i < n; ++i) {
            int leftPartLen = i + 1, rightPartLen = n - i - 1;
            int leftPartDominant = prefix[i], rightPartDominant = prefix[n - 1] - prefix[i];
            if (leftPartDominant > leftPartLen / 2 && rightPartDominant > rightPartLen / 2) return i;
        }
        return -1;
    }
};