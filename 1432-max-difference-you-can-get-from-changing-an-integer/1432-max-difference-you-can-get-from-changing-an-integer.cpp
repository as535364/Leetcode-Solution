class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;

        for (int i = 0; i < t.size(); ++i) {
            if (i == 0 && t[i] != '1') {
                char c = t[0];
                replace(t.begin(), t.end(), c, '1');
                break;
            }
            else if (t[i] != t[0] && t[i] != '0') {
                char c = t[i];
                replace(t.begin(), t.end(), c, '0');
                break;
            }
        }

        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char c = s[pos];
            replace(s.begin(), s.end(), c, '9');
        }
        cout << s << ' ' << t << endl;
        return stoi(s) - stoi(t);
    }
};