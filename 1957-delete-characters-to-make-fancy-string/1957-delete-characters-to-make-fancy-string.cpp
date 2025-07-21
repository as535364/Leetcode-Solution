class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) return s;
        int i = 2, j = 2;
        for (; j < s.size(); ++j) {
            if (s[j] == s[i - 1] && s[j] == s[i - 2]) continue;
            s[i++] = s[j];
        }
        s.resize(i);
        return s;
    }
};