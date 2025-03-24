class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> merged;

        sort(meetings.begin(), meetings.end());
        for (const auto &meeting : meetings) {
            if (merged.empty() || merged.back()[1] < meeting[0]) {
                merged.push_back(meeting);
            }
            else {
                merged.back()[1] = max(merged.back()[1], meeting[1]);
            }
        }

        for (const auto &meeting : merged) {
            days -= meeting[1] - meeting[0] + 1;
        }
        return days;
    }
};