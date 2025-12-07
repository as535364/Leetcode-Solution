class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end());
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval);
        intervals.insert(it, newInterval);        
        
        vector<vector<int>> res;
        for (const auto &i : intervals) {
            if (res.empty() || res.back()[1] < i[0]) {
                res.push_back(i);
            }
            else {
                res.back()[1] = max(res.back()[1], i[1]);
            }
        }
        return res;
    }
};