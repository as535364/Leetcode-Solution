class Solution {
private:
    int swapToTarget(int target, vector<int>& row) {
        int res = 0;
        for (int num : row) {
            if (num != target) ++res;
        }
        return res;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> cnts(7);
        for (int i = 0; i < n; ++i) {
            if (tops[i] == bottoms[i]) ++cnts[tops[i]];
            else {
                ++cnts[tops[i]];
                ++cnts[bottoms[i]];
            }
        }
        
        int target1 = -1, target2 = -1;
        for (int i = 1; i <= 6; ++i) {
            if (cnts[i] >= n && target1 == -1) {
                target1 = i;
            }
            else if (cnts[i] >= n) {
                target2 = i;
            }
        }
        
        if (target1 == -1 && target2 == -1) return -1;
        
        int res = INT_MAX;
        res = min(swapToTarget(target1, tops), swapToTarget(target1, bottoms));
        if (target2 != -1) {
            res = min(swapToTarget(target2, tops), swapToTarget(target2, bottoms));
        }
        return res;
    }
};