class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int num : nums) res += num % 3 != 0;
        return res;
    }
};