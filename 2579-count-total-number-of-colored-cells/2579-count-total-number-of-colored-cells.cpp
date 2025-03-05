class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1) return 1;
        long long ans = 1, last = 0;
        for (int i = 1; i < n; ++i) {
            last += 4;
            ans += last;
        }
        return ans;
    }
    // 1, 1 + 4, 1 + 4 + 8, 1 + 4 + 8 + 12
};