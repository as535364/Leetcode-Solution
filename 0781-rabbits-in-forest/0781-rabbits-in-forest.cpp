class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int res = 0, last = -1, lastCnt = 0;

        for (int a : answers) {
            if (a != last || lastCnt == 0) {
                lastCnt = a;
                res += a + 1;
            }
            else {
                lastCnt--;
            }
            last = a;
        }
        return res;
    }
};