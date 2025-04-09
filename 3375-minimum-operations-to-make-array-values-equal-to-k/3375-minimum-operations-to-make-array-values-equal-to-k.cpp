class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minVal = *min_element(nums.begin(), nums.end());
        if (minVal < k) return -1;
        set<int> s;
        for (int num : nums) s.insert(num);
        if (minVal == k) return s.size() - 1;
        else return s.size();        
    }
};