class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        // X ^ Y means each element in nums can be used for 0, 1, 2 times
        // consider about an array nums * 2
        // using twice means using zero times
        // so just consider about nums
        // Gaussian Elimination?
        
        vector<int> basis(31);
        for (int num : nums) {
            for (int j = 31; j >= 0; --j) {
                if (!((num >> j) & 1)) continue;
                basis[j] ^= num;
            }
        }

        int maxXOR = 0;
        for (int b : basis) {
            maxXOR = max(maxXOR ^ b, maxXOR);
        }
        return maxXOR;
    }
};