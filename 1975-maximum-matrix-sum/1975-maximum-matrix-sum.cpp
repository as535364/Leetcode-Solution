class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minAbs = INT_MAX;
        long long ans = 0;
        bool isNegOdd = false;
        for (const auto &row : matrix) {
            for (const int num : row) {
                if (num < 0) isNegOdd = !isNegOdd;
                ans += abs(num);
                minAbs = min(minAbs, abs(num));
            }
        }
        if (!isNegOdd) return ans;
        else return ans - 2 * minAbs;
    }
};