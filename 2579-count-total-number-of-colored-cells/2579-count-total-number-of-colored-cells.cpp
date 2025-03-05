class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 2 * ((long long)n * (n - 1));
    }
    // 1, 1 + 4, 1 + 4 + 8, 1 + 4 + 8 + 12, 1 + 4 + 8 + 12 + 16
    // 1 + sig(4i) i = n - 1
};