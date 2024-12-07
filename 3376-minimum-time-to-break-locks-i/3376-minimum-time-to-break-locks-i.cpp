class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        sort(strength.begin(), strength.end());
        int minTime = INT_MAX;

        do {
            int time = 0, X = 1;
            for (int st : strength) {
                time += (st + X - 1) / X;
                X += K;
            }
            minTime = min(minTime, time);
        } while(next_permutation(strength.begin(), strength.end()));

        return minTime;
    }
};