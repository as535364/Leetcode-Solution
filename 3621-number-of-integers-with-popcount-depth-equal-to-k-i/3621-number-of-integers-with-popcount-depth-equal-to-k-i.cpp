class Solution {
public:
    long long popcountDepth(long long x, int k) {
        int n = bit_width((uint64_t)x);
        if (k == 0) return 1;
        if (k == 1) return n - 1;

        vector<vector<long long>> memo(n, vector<long long>(n + 1, -1));
        auto dfs = [&](this auto &&dfs, int i, int left1, bool isLimit) -> long long {
            if (i < 0) {
                return left1 == 0;
            }
            if (!isLimit && memo[i][left1] != -1) {
                return memo[i][left1];
            }

            int up = isLimit ? x >> i & 1 : 1;
            long long res = 0;
            for (int d = 0; d <= min(up, left1); ++d) {
                res += dfs(i - 1, left1 - d, isLimit && d == up);
            }
            if (!isLimit) {
                memo[i][left1] = res;
            }
            return res;
        };

        
        long long ans = 0;
        vector<int> f(n + 1);
        for (uint32_t i = 2; i <= n; ++i) {
            f[i] = f[popcount(i)] + 1;
            if (f[i] == k - 1) {
                ans += dfs(n - 1, i, true);
            }
            cout << i << ' ' << f[i] << ' ' << dfs(n - 1, i, true) << endl;
        }
        return ans;
    }
};