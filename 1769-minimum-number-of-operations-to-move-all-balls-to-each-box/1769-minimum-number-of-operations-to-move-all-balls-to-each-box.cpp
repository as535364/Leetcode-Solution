class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        
        int ballsLeft = 0, disLeftSum = 0;
        int ballsRight = 0, disRightSum = 0;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            ans[i] += disLeftSum;
            ans[j] += disRightSum;
            ballsLeft += (boxes[i] == '1');
            disLeftSum += ballsLeft;
            ballsRight += (boxes[j] == '1');
            disRightSum += ballsRight;
        }
        return ans;
    }
};