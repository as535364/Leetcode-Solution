class Solution {
public:
    bool canChange(string start, string target) {
        int sLen = start.length(), tLen = target.length();
        int i = 0, j = 0;
        while (i < sLen || j < tLen) {
            while (i < sLen && start[i] == '_') i++;
            while (j < tLen && target[j] == '_') j++;
            if (i == sLen || j == tLen) {
                return i == sLen && j == tLen;
            }

            if (start[i] != target[j] ||
                (start[i] == 'L' && j > i) ||
                (start[i] == 'R' && j < i)) return false;
            i++, j++;
        }
        return true;
    }
};