class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            double diffa = ((double)a[0] + 1) / (a[1] + 1) - (double)a[0] / a[1];
            double diffb = ((double)b[0] + 1) / (b[1] + 1) - (double)b[0] / b[1];
            return diffa < diffb;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
        for (const auto &c : classes) {
            pq.push(c);
        }

        while (extraStudents--) {
            auto now = pq.top();
            pq.pop();
            now[0] += 1;
            now[1] += 1;
            pq.push(now);
        }

        double ans = 0;
        while (!pq.empty()) {
            auto now = pq.top();
            pq.pop();
            ans += (double)now[0] / now[1];
        }
        return ans / classes.size();
    }
};
// 3/5 -> 4/6 
// 4/5 -> 5/6