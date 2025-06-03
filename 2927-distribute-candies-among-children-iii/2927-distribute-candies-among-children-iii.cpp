class Solution {
private:
    long long nCr_iterative (int n, int r) {
    // 處理 nCr = nC(n-r) 的情況，選擇較小的 r
    if (r < 0 || r > n) {
        return 0; // 不合法的情況
    }
    if (r == 0 || r == n) {
        return 1;
    }
    if (r > n / 2) {
        r = n - r;
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