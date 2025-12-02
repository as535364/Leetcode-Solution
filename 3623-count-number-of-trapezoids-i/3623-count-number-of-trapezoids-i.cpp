class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> sameyPoints;
        for (const auto &point : points) {
            int x = point[0], y = point[1];
            sameyPoints[y]++;
        }

        int ans = 0, previous = 0;

        for (const auto [_, cnt1] : sameyPoints) {
            int nowPairs = ((long long)cnt1 * (cnt1 - 1) / 2) % MOD;
            ans = (ans + (long long)nowPairs * previous % MOD) % MOD;
            previous = (previous + nowPairs) % MOD;
        }
        return ans;
    }
};