class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char c = s[pos];
            replace(s.begin(), s.end(), c, '9');
        }

        char c = t[0];
        replace(t.begin(), t.end(), c, '0');
        return stoi(s) - stoi(t);
    }
};