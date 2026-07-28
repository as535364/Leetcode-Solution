class Solution {
public:
    string smallestPalindrome(string s) {
        int cnts[26] = {};
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            cnts[s[i] - 'a']++;
        }
        int left = 0, right = n - 1;
        for (int i = 0; i < 26; ++i) {
            while (cnts[i]) {
                char c = i + 'a';
                s[left] = s[right] = c;
                ++left, --right;
                cnts[i]--;
            }
        }
        return s;
    }
};