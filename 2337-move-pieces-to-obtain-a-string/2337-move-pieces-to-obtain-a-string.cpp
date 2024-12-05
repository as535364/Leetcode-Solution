class Solution {
public:
    bool canChange(string start, string target) {
        int len = start.length();
        int i = 0, j = 0;
        while (i < len || j < len) {
            while (i < len && start[i] == '_') i++;
            while (j < len && target[j] == '_') j++;
            if (i == len || j == len) {
                return i == len && j == len;
            }

            if (start[i] != target[j] ||
                (start[i] == 'L' && j > i) ||
                (start[i] == 'R' && j < i)) return false;
            i++, j++;
        }
        return true;
    }
};