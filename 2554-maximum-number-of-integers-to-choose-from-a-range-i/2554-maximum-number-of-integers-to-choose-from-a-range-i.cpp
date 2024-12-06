class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int takenCount = 0;
        unordered_set<int> banSet;

        for (int b : banned) {
            banSet.insert(b);
        }

        for (int i = 1; i <= n; ++i) {
            if (banSet.count(i)) continue;
            if (maxSum - i < 0) return takenCount;
            maxSum -= i;
            takenCount++;
        }
        return takenCount;
    }
};