class Solution {
    const int MOD = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        // for (int l = 0; l < n; ++l) {
        //     int r = upper_bound(nums.begin(), nums.end(), target - nums[l]) - nums.begin();
        //     if (l <= r) ans = (ans + PowerMod(2, r - l - 1, MOD)) % MOD;
        // }
        int left = 0, right = n - 1;
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = power[i - 1] * 2 % MOD;
        }
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + power[right - left]) % MOD;
                ++left;
            }
            else {
                --right;
            }
        }
        return ans;
    }
    typedef long long ll;
    ll PowerMod(ll a, ll b, ll c){
        if (b < 0) return 0;
        ll ans = 1;
        a %= c;
        while (b) {
            if (b&1)
                ans = (ans * a) % c;
            b = b >> 1;
            a = (a * a) % c;
        }
        return ans;
    }
};