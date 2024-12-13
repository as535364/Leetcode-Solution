class Solution {
public:
    long long findScore(vector<int>& nums) {
        nums.push_back(1e6);

        long long score = 0;
        int start = -1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) continue;
            for (int j = i - 1; j > start; j -= 2) {
                score += nums[j];
            }
            start = i;
            ++i;
        }
        return score;
    }
};