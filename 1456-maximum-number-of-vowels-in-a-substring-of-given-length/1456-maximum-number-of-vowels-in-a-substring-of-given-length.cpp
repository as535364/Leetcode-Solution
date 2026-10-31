class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelCnt = 0, n = s.size();
        for (int i = 0; i < k; ++i) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++vowelCnt;
            }
        }
        int ans = vowelCnt;
        for (int i = k; i < n; ++i) {
            char c = s[i - k];
            vowelCnt -= (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            c = s[i];
            vowelCnt += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            ans = max(ans, vowelCnt);
        }
        return ans;
    }
};