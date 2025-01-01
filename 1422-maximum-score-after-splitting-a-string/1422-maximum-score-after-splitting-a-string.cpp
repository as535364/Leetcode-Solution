class Solution {
public:
    int maxScore(string s) {
        int maxSum = 0;
        for (int i = 1; i < s.size(); ++i) {
            // string a = s.substr(0, i), b = s.substr(i);
            int zeroInA = count(s.begin(), s.begin() + i, '0');
            int oneInB = count(s.begin() + i, s.end(), '1');
            maxSum = max(maxSum, zeroInA + oneInB);
        }
        return maxSum;
    }
};