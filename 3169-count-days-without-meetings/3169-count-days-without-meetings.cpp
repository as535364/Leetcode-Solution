class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int lastEnd = -1;
        for (const auto &meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (lastEnd == -1 || lastEnd < start) {
                days -= end - start + 1;
                lastEnd = end;
            }
            else if (lastEnd < end) {
                days -= end - lastEnd;
                lastEnd = end;
            }
        }

        return days;
    }
};