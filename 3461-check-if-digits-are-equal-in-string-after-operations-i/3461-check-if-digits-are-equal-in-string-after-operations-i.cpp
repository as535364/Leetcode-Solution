class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string newStr(s.size() - 1, ' ');
            for (int i = 0; i + 1 < s.size(); ++i) {
                newStr[i] = (s[i] - '0' + s[i + 1] - '0') % 10;
            }
            s = newStr;
        }
        return s[0] == s[1];
    }
};