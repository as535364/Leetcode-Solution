class Solution {
private:
    int change(const string &s, const string &t) {
        int len = s.length(), change_cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] != t[i]) ++change_cnt;
        }
        return change_cnt;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for (const string &q : queries) {
            int min_edit = INT_MAX;
            for (const string &d : dictionary) {
                min_edit = min(min_edit, change(q, d));
            }
            if (min_edit <= 2) res.push_back(q);
        }
        
        return res;
    }
};