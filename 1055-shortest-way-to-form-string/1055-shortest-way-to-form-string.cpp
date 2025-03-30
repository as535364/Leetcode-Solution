class Solution {
public:
    int shortestWay(string source, string target) {
        int cnt = 0, sIdx = -1, sLen = source.length();
        vector<bool> charExist(26);

        for (char c : source) charExist[c - 'a'] = true;

        for (char c : target) {
            if (!charExist[c - 'a']) return -1;

            sIdx++;
            while (c != source[sIdx % sLen]) {
                sIdx++;
            }
        }
        return 1 + sIdx / sLen;
    }
};