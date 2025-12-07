class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // vector<vector<int>> res;
        // int i = 0, n = intervals.size();
        // // no overlapping
        // while (i < n && intervals[i][1] < newInterval[0]) {
        //     res.push_back(intervals[i]);
        //     ++i;
        // }
        // // overlapping
        // while (i < n && intervals[i][0] <= newInterval[1]) {
        //     newInterval[0] = min(intervals[i][0], newInterval[0]);
        //     newInterval[1] = max(intervals[i][1], newInterval[1]);
        //     ++i;
        // }
        // res.push_back(newInterval);
        // // no overlapping
        // while (i < n) {
        //     res.push_back(intervals[i]);
        //     ++i;
        // }

        // binary search version
        vector<vector<int>> res;
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval);
        intervals.insert(it, newInterval);
        for (int i = 0; i < intervals.size(); ++i) {
            if (res.empty() || res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            }
            else {
                res.back()[0] = min(intervals[i][0], res.back()[0]);
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};