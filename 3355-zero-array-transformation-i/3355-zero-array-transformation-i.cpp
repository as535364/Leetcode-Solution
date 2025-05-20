class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n);
        for (auto &query : queries) {
            int l = query[0], r = query[1];
            prefix[l]++;
            if (r + 1 < n) prefix[r + 1]--;
        }
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += prefix[i];
            if (sum < nums[i]) return false;
        }
        return true;
    }
};