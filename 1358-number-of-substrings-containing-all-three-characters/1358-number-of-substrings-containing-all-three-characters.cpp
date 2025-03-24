class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<int> lastPos(3, -1);
        for (int i = 0; i < n; ++i) {
            lastPos[s[i] - 'a'] = i;
            res += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }
        return res;
    }
};