class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> marked(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }

        long long score = 0;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            if (marked[idx]) continue;

            score += num;
            if (idx + 1 < nums.size()) marked[idx + 1] = true;;
            if (idx - 1 >= 0) marked[idx - 1] = true;
        }
        return score;
    }
};