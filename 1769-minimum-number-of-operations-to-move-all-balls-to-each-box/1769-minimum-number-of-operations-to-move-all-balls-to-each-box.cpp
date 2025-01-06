class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        
        int ballsLeft = 0, disLeftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] += disLeftSum;
            ballsLeft += (boxes[i] == '1');
            disLeftSum += ballsLeft;
        }

        int ballsRight = 0, disRightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] += disRightSum;
            ballsRight += (boxes[i] == '1');
            disRightSum += ballsRight;
        }

        return ans;
    }
};