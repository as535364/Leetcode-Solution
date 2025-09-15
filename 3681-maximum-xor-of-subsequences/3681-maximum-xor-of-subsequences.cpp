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
            for (int i = 30; i >= 0; --i) {
                if (!((num >> i) & 1)) continue;
                if (basis[i] == 0 ) {
                    basis[i] = num;
                    break;
                }
                num ^= basis[i];
            }
        }

        int maxXOR = 0;
        for (int i = 30; i >= 0; --i) {
            maxXOR = max(maxXOR ^ basis[i], maxXOR);
        }
        return maxXOR;
    }
};