class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diffArr(1002);
        for (const auto trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            diffArr[from] += num;
            diffArr[to] -= num;
        }
        int last = 0;
        for (int diff : diffArr) {
            last += diff;
            if (last > capacity) return false;
        }
        return true;
    }
};