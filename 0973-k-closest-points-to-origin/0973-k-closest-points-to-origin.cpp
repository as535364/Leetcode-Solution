class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;

        for (const auto& point : points) {
            pq.push({point[0], point[1]});
        }

        vector<vector<int>> res;
        while (k--) {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};