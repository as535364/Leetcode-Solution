class Solution {
private:
    long long nCr_iterative (int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    if (r == 0 || r == n) {
        return 1;
    }
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}
public:
    long long distributeCandies(int n, int limit) {
        long long res = nCr_iterative(n + 2, 2);
        res -= 3 * nCr_iterative(n - limit + 1, 2);
        res += 3 * nCr_iterative(n - 2 * limit, 2);
        res -= nCr_iterative(n - 3 * limit - 1, 2);
        return res;
    }
};