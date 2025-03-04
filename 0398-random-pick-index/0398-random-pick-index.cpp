class Solution {
private:
    unordered_map<int, vector<int>> num2Idx;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            num2Idx[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int x = rand() % num2Idx[target].size();
        return num2Idx[target][x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */