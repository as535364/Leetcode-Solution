class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int strLen = s.length(), spaceCount = spaces.size();
        string res;
        res.resize(strLen + spaceCount);

        int i = 0, j = 0;
        for (int k = 0; k < res.size(); ++k) {
            if (j < spaceCount && i == spaces[j]) {
                res[k] = ' ';
                j++;
            }
            else if (i < strLen) {
                res[k] = s[i++];
            }
        }
        return res;
    }
};