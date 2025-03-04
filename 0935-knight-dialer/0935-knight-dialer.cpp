class Solution {
private:
    const long long mod = 1e9 + 7;
public:
    int knightDialer(int n) {
        vector<long long> prev(10, 1), now(10);
        while (--n) {
            now[0] = prev[4] + prev[6];
            now[1] = prev[6] + prev[8];
            now[2] = prev[7] + prev[9];
            now[3] = prev[4] + prev[8];
            now[4] = prev[0] + prev[3] + prev[9];
            now[5] = 0;
            now[6] = prev[1] + prev[7] + prev[0];
            now[7] = prev[2] + prev[6];
            now[8] = prev[1] + prev[3];
            now[9] = prev[2] + prev[4];
            for (long long &d : now) d %= mod;
            prev = now;
        }
        long long sum = 0;
        for (long long &d : prev) {
            sum = (sum + d) % mod;
        }
        return sum;
    }
};