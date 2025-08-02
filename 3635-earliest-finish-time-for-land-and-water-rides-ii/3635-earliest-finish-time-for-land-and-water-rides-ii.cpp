class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minLand = INT_MAX, minWater = INT_MAX;
        int landWater = INT_MAX, waterLand = INT_MAX;

        for (int i = 0; i < n; ++i) {
            minLand = min(minLand, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < m; ++i) {
            landWater = min(landWater, max(minLand, waterStartTime[i]) + waterDuration[i]);
            minWater = min(minWater, waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < n; ++i) {
            waterLand = min(waterLand, max(minWater, landStartTime[i]) + landDuration[i]);
        }
        return min(waterLand, landWater);
    }
};