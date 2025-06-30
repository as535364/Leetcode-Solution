class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counts;

        for (int num : nums) {
            ++counts[num];
        }

        int res = 0;
        for (auto it = counts.begin(); it != prev(counts.end()); ++it) {
            if (next(it) -> first - it -> first > 1) continue;
            int firstCount = it -> second, secondCount = next(it) -> second;
            res = max(res, firstCount + secondCount);
        }
        return res;
    }
};