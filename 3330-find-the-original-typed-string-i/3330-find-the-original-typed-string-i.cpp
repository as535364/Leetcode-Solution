class Solution {
public:
    int possibleStringCount(string word) {
        word.push_back('*');
        int consecutiveCount = 1, res = 1;
        char last = '\0';

        for (char c : word) {
            if (last == c) {
                ++consecutiveCount;
            }
            else {
                res += consecutiveCount - 1;
                consecutiveCount = 1;
            }
            last = c;
        }
        return res;
    }
};