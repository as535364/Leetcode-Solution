class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [min_val, max_val] = ranges::minmax(nums);
        return gcd(min_val, max_val);
    }
};