class Solution {
private:
    vector<bool> isPrime;
    void cal(int n) {
        isPrime.resize(n + 1, true);
        isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        cal(100);
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        for (auto &[_, c] : count) {
            if (isPrime[c]) return true;
        }
        return false;
    }
};