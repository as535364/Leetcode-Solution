class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;

        for (int i = 0; i < s.size(); i += k) {
            res.push_back(s.substr(i, k));
        }

        if (res.back().length() != k) {
            res.back() += string(k - res.back().length(), fill);
        }
        return res;
    }
};