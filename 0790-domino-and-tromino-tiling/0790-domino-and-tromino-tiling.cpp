class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        vector<int> p(max(4, n + 1)), f(max(4, n + 1));
        p[0] = 1;
        p[1] = 1;
        p[2] = 2;
        p[3] = 5;
        f[0] = 1;
        f[1] = 2;
        f[2] = 4;
        f[3] = 9;

        for (int i = 4; i <= n; ++i) {
            p[i] = (p[i - 1] + p[i - 2]) % mod;
            p[i] = (p[i] + 2 * f[i - 3] % mod) % mod;
            f[i] = (f[i - 1] + p[i]) % mod;
        }
        return p[n];
    }
};