class Solution {
public:
    int minSteps(string s, string t) {
        int sCnt[26] = {}, tCnt[26] = {};
        
        for (char c : s) {
            sCnt[c - 'a']++;
        }
        for (char c : t) {
            tCnt[c - 'a']++;
        }
        
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += abs(tCnt[i] - sCnt[i]);
        }
        return res / 2;
    }
};