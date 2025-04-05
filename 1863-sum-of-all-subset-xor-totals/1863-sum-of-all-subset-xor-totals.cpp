class Solution {
private:
    int dfs(int idx, int xorVal, const vector<int> &nums) {
        if (idx == nums.size()) return xorVal;
        int sum = 0;
        sum += dfs(idx + 1, xorVal, nums);
        sum += dfs(idx + 1, xorVal ^= nums[idx], nums);
        return sum;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(0, 0, nums);
    }
};