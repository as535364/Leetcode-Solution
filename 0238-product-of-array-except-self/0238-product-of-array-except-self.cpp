class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroIdx = -1, n = nums.size();
        int mulAll = 1;
        vector<int> res(n);
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0 && zeroIdx == -1) zeroIdx = i;
            else if (nums[i] == 0) {
                return res;
            }
            else {
                mulAll *= nums[i];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (zeroIdx != -1 && i == zeroIdx) {
                res[i] = mulAll;
            }
            else if (zeroIdx != -1 && i != zeroIdx) {
                res[i] = 0;
            }
            else {
                res[i] = mulAll / nums[i];
            }
        }
        return res;
    }
};