class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i) {
            left[i] = i + 1;
            right[i] = n - i;
        }

        stack<int> st1, st2;

        for (int i = 0; i < n; ++i) {
            while (!st1.empty() && arr[st1.top()] > arr[i]) {
                st1.pop();
            }
            left[i] = st1.empty() ? i + 1 : i - st1.top();
            st1.push(i);
        }

        for (int i = 0; i < n; ++i) {
            while (!st2.empty() && arr[st2.top()] > arr[i]) {
                right[st2.top()] = i - st2.top();
                st2.pop();
            }
            st2.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long)left[i] * right[i] % MOD * arr[i] % MOD;
            ans %= MOD;
        }
        return ans;
    }
};