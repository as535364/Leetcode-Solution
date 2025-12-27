class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, bool>> times;
        for (const auto &interval : intervals) {
            times.push_back({interval[0], 1});
            times.push_back({interval[1], 0});
        }
        
        sort(times.begin(), times.end());
        int res = -1, curr = 0;
        for (const auto &time : times) {
            int t = time.first;
            bool isStart = time.second;
            if (isStart) ++curr;
            else --curr;
            res = max(res, curr);
        }
        return res;
    }
};