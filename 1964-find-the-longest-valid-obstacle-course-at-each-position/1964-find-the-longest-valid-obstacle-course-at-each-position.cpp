class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> LISvec, res(n);

        for (int i = 0; i < n; ++i) {
            if (LISvec.empty() || LISvec.back() <= obstacles[i]) {
                LISvec.push_back(obstacles[i]);
                res[i] = LISvec.size();
            }
            else {
                auto it = upper_bound(LISvec.begin(), LISvec.end(), obstacles[i]);
                *it = obstacles[i];
                res[i] = it - LISvec.begin() + 1;
            }
        }
        return res;
    }
};