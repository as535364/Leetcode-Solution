class Solution {
public:
    int maximumLength(string s) {
        int lastCount = 0, ans = -1;
        char lastChar = '-';
        unordered_map<string, int> count;
        s += '.';

        for (char c : s) {
            if (c != lastChar) {
                for (int i = 1; i <= lastCount; ++i) {
                    string k = lastChar + to_string(i);
                    count[k] += lastCount - i + 1;
                    if (count[k] >= 3) ans = max(ans, i);
                }
                lastCount = 0;
                lastChar = c;
            }
            lastCount++;
        }
        return ans;
    }
};