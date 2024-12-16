class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        for (const auto &c : classes) {
            double diff = (double)(c[0] + 1) / (c[1] + 1) - (double)c[0] / c[1];
            pq.push({diff, c[0], c[1]});
        }

        while (extraStudents--) {
            auto [_, a, b] = pq.top();
            pq.pop();

            double diff = (double)(a + 2) / (b + 2) - (double)(a + 1) / (b + 1);
            pq.push({diff, a + 1, b + 1});
        }

        double ans = 0;
        while (!pq.empty()) {
            auto [_, a, b] = pq.top();
            pq.pop();
            ans += (double)a / b;
        }
        return ans / classes.size();
    }
};
// 3/5 -> 4/6 
// 4/5 -> 5/6