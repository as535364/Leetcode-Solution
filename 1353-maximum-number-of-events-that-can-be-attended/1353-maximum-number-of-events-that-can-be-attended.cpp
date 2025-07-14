class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxEndDay = 0;
        for (auto &event : events) {
            maxEndDay = max(maxEndDay, event[1]);
        }
        sort(events.begin(), events.end());

        int cnt = 0;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int i = 1, j = 0; i <= maxEndDay; ++i) {
            while (!minHeap.empty() && minHeap.top() < i) {
                minHeap.pop();
            }

            while (j < events.size() && events[j][0] <= i) {
                minHeap.push(events[j][1]);
                ++j;
            }

            if (!minHeap.empty()) {
                ++cnt;
                minHeap.pop();
            }
        }
        return cnt;
    }
};