class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.length();
        vector<int> lastCharIdx(26, -1);

        for (int i = len - 1; i >= 0; --i) {
            char c = s[i];
            if (lastCharIdx[c - 'a'] == -1) lastCharIdx[c - 'a'] = i;
        }

        int lastIncludeIdx = 0, lastStartIdx = 0;
        vector<int> res;

        for (int i = 0; i < len; ++i) {
            if (i > lastIncludeIdx) {
                res.push_back(i - lastStartIdx);
                lastStartIdx = i;
            }
            char c = s[i];
            lastIncludeIdx = max(lastIncludeIdx, lastCharIdx[c - 'a']);
        }
        res.push_back(len - lastStartIdx);
        return res;
    }
};