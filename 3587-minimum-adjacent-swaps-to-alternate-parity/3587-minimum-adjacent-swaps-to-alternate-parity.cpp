class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> oddPos;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2) oddPos.push_back(i);
        }

        int m = oddPos.size();

        auto calc = [&](int start) {
            if ((n - start + 1) / 2 != m) return INT_MAX;

            int moves = 0;
            for (int i = 0; i < m; ++i) {
                moves += abs((i * 2 + start) - oddPos[i]);
            }
            return moves;
        };

        int res = min(calc(0), calc(1));
        return res == INT_MAX ? -1 : res;
    }
};