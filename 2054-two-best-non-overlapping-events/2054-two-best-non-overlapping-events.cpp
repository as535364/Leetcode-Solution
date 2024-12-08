class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tuple<int, int, int>> times;
        for (const auto &e : events) {
            times.push_back({e[0], 0, e[2]});
            times.push_back({e[1], 1, e[2]});
        }
        sort(begin(times), end(times));
        
        int maxSoFar = 0, ans = 0;
        for (int i = 0; i < times.size(); ++i) {
            auto [time, type, val] = times[i];

            if (!type) { // start
                ans = max(ans, val + maxSoFar);
            }
            else { // end
                maxSoFar = max(maxSoFar, val);
            }
        }
        return ans;
    }
};