class Solution {
public:
    bool isStrobogrammatic(string num) {
        string newNum = num;
        int numMap[] = {0, 1, -1, -1, -1, 2, 9, -1, 8, 6};
        for (char &c : newNum) {
            if (numMap[c - '0'] == -1) return false;
            else c = numMap[c - '0'] + '0';
        }
        reverse(newNum.begin(), newNum.end());
        return num == newNum;
    }
};