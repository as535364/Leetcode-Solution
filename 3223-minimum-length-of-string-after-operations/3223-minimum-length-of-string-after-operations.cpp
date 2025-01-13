class Solution {
public:
    int minimumLength(string s) {
        vector<int> charCount(26);
        for (char c : s) {
            charCount[c - 'a']++;
        }

        int remainSize = 0;
        for (int i = 0; i < 26; ++i) {
            while (charCount[i] >= 3) {
                charCount[i] -= 2;
            }
            remainSize += charCount[i];
        }
        return remainSize;
    }
    // bacbcbb
};