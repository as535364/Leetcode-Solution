class Solution {
private:
    const int MOD = 1e9 + 7;

    // int C(int n, int m) {
    //     if (m < 0 || m > n)
    //         return 0;
    //     if (m == 0 || m == n)
    //         return 1;
    //     if (m > n - m)
    //         m = n - m;

    //     long long res = 1;
    //     for (int i = 1; i <= m; ++i) {
    //         res = res * (n - m + i) / i % MOD;
    //     }
    //     return res;
    // }
    vector<vector<int>> comb;

    void init(int n, int k) {
        for (int i = 0; i < n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j < min(i + 1, k); ++j) {
                comb[i][j] = 0LL + (comb[i - 1][j] +  comb[i - 1][j - 1]) % MOD;
            }
        }
    }

public:
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;

        comb.resize(n, vector<int>(k));
        init(n, k);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k - 1; ++j) {
                res += 1LL * nums[i] * comb[n - i - 1][j] % MOD;
                res += 1LL * nums[i] * comb[i][j] % MOD;
                res %= MOD;
            }
        }
        return res;
    }
};