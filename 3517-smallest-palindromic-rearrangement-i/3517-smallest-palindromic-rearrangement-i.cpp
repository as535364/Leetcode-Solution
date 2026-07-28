class Solution {
public:
    string smallestPalindrome(string s) {
        int cnts[26] = {};
        for (char c : s) {
            cnts[c - 'a']++;
        }
        string res;
        char middle = '#';

        for (int i = 0; i < 26; ++i) {
            while (cnts[i] > 1) {
                res += (i + 'a');
                cnts[i] -= 2;
            }
            if (cnts[i]) middle = i + 'a';
        }
        string last = res;
        reverse(last.begin(), last.end());
        if (middle != '#') res =  res + middle + last;
        else res = res + last;
        return res;
    }
};