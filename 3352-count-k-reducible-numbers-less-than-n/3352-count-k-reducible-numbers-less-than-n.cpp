class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));

        // f(i) 代表 __builtin_popcount(i)
        // f*(i) 代表 i 變成 1 的操作次數
        // f*(i) <= k 的暴力解： O(2^n)

        // dfs(left1) 代表多少個 [1, n) 的數字恰好有 left1 個 1
        auto dfs = [&](this auto &&self, int i, int left1, bool isLimit) -> int {
            if (i == n) {
                return !isLimit && left1 == 0;
            }
            if (!isLimit && memo[i][left1] != -1) {
                return memo[i][left1];
            }
            int up = isLimit ? s[i] - '0' : 1;
            int res = 0;
            for (int d = 0; d <= min(up, left1); d++) {
                res = (res + self(i + 1, left1 - d, isLimit && d == up)) % MOD;
            }
            if (!isLimit) {
                memo[i][left1] = res;
            }
            return res;
        };
        

        // f[i] 代表 i 個 1 的數字要幾次迭代才會變為 1 停止
        long long ans = 0;
        vector<int> f(n);
        for (int i = 1; i < n; ++i) {
            f[i] = f[__builtin_popcount(i)] + 1;
            if (f[i] <= k) {
                ans += dfs(0, i, true);
            }
        }
        return ans % MOD;
    }
};