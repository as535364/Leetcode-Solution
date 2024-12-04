class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int m = str1.length(), n = str2.length();
        while (i < m && j < n) {
            if (test(str1[i], str2[j])) {
                ++i, ++j;
            }
            else {
                ++i;
            }
        }
        return n == j;
    }
    bool test(char a, char b) {
        return a == b || (a - 'a' + 1) % 26 + 'a' == b;
    }
};