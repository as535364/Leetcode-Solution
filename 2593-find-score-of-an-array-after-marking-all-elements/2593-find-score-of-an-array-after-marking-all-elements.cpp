class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> marked;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }

        long long score = 0;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            if (marked.count(idx)) continue;

            score += num;
            marked.insert(idx + 1);
            marked.insert(idx - 1);
        }
        return score;
    }
};