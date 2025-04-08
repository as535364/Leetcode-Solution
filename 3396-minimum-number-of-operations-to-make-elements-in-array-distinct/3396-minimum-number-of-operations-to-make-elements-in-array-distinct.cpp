class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> numSet;
        for (int num : nums) ++numSet[num];
        if (numSet.size() == n) return 0;

        for (int i = 0; i < n; i += 3) {
            int bound = min(i + 3, n);
            for (int j = i; j < bound; ++j) {
                if(--numSet[nums[j]] == 0) numSet.erase(nums[j]);
            }
            if (numSet.size() == n - bound) return i / 3 + 1;
        }
        return -1;
    }
};